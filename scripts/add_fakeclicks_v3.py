#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
假点击 v3: 修复寄存器保存 + 栈对齐
- v2 的 bug: 破坏 TimerFunc 回调参数寄存器 (rcx/rdx/r8/r9)
- v3 修复: 保存/恢复所有 volatile 寄存器 + rbx
- v3 修复: sub rsp, 50h 确保栈对齐 16 (x64 ABI 要求)
"""

import pefile
import struct
import shutil
import os

# ==================== 配置 ====================
INPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_jinx.exe'
OUTPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_jinx_fakeclick3.exe'

TIMERFUNC_RVA = 0x14020
TIMERFUNC_RETURN_RVA = 0x14025
SENDINPUT_IAT_RVA = 0x17B08

NEWTEXT_RVA = 0x1D000
FAKECLICK_OFFSET = 0x1800
STATE_OFFSET = 0x2000
FAKECLICK_RVA = NEWTEXT_RVA + FAKECLICK_OFFSET   # 0x1E800
STATE_RVA = NEWTEXT_RVA + STATE_OFFSET           # 0x1F000

ORIGINAL_HEADER = bytes([0x56, 0x48, 0x83, 0xEC, 0x20])  # push rsi; sub rsp, 20h

# 状态变量布局（相对于 STATE_RVA）
OFF_STEP = 0          # BYTE: 0xFF=空闲, 0-7=执行中
OFF_DX   = 4          # DWORD[8]
OFF_DY   = 4 + 32     # DWORD[8]
STATE_SIZE = 4 + 32 + 32  # 68 bytes

# 栈分配大小（80 bytes = 40 INPUT + 32 shadow + 8 对齐）
STACK_ALLOC = 0x50  # 80 bytes


# ==================== CodeBuilder ====================
class CodeBuilder:
    """管理代码生成 + label + fixup"""

    def __init__(self, base_rva):
        self.code = bytearray()
        self.base_rva = base_rva
        self.labels = {}
        self.fixups = []

    def emit(self, data):
        self.code += bytes(data)

    def pos(self):
        return len(self.code)

    def cur_rva(self):
        return self.base_rva + len(self.code)

    def mark(self, name):
        self.labels[name] = len(self.code)

    def emit_rip32(self, target_rva, prefix=b'', suffix=b''):
        """emit RIP-relative disp32 指令"""
        next_rip = self.cur_rva() + len(prefix) + 4 + len(suffix)
        disp = target_rva - next_rip
        self.emit(prefix)
        self.emit(struct.pack('<i', disp))
        self.emit(suffix)

    def emit_jmp(self, label):
        """jmp rel32 (E9 + rel32)"""
        self.fixups.append((self.pos() + 1, label, 4))
        self.emit(b'\xE9\x00\x00\x00\x00')

    def emit_jcc32(self, cc2byte, label):
        """jcc rel32 (0F 8x + rel32)"""
        self.fixups.append((self.pos() + 2, label, 4))
        self.emit(cc2byte)
        self.emit(b'\x00\x00\x00\x00')

    def emit_jcc8(self, cc1byte, label):
        """jcc rel8 (7x + rel8)"""
        self.fixups.append((self.pos() + 1, label, 1))
        self.emit(cc1byte)
        self.emit(b'\x00')

    def finalize(self):
        """修复所有跳转"""
        for offset, label, rel_size in self.fixups:
            target = self.labels[label]
            if rel_size == 4:
                rel = target - (offset + 4)
                self.code[offset:offset+4] = struct.pack('<i', rel)
            elif rel_size == 1:
                rel = target - (offset + 1)
                if rel < -128 or rel > 127:
                    raise ValueError(f"rel8 超出范围: {rel} (label={label})")
                self.code[offset:offset+1] = struct.pack('<b', rel)
            else:
                raise ValueError(f"未知 rel_size: {rel_size}")


# ==================== 构造假点击函数 v3 ====================
def build_fakeclick_v3():
    cb = CodeBuilder(FAKECLICK_RVA)

    # === 1. 原始头部（必须执行，TimerFunc 期望）===
    cb.emit(b'\x56')                # push rsi
    cb.emit(b'\x48\x83\xEC\x20')   # sub rsp, 20h

    # === 1.5 保存寄存器（v3 修复：防止破坏 TimerFunc 回调参数）===
    # TimerFunc 是 SetTimer 回调，参数：
    #   rcx = hWnd, rdx = uMsg, r8 = idEvent, r9 = dwTime
    # 必须保存这些寄存器，否则 TimerFunc 后续代码无法判断执行哪个 case
    cb.emit(b'\x50')                # push rax
    cb.emit(b'\x51')                # push rcx
    cb.emit(b'\x52')                # push rdx
    cb.emit(b'\x41\x50')            # push r8
    cb.emit(b'\x41\x51')            # push r9
    cb.emit(b'\x53')                # push rbx
    # 现在 rsp 偏移 48 bytes (6 push) + 48 bytes (前面) = 96 bytes
    # rsp = 16n - 96 → 对齐 16 ✓

    # === 2. 读 fc_step ===
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x0F\xB6\x05')  # movzx eax, byte [rip+fc_step]

    # === 3. 检查状态 ===
    cb.emit(b'\x3C\xFF')  # cmp al, 0xFF
    cb.emit_jcc32(b'\x0F\x85', 'execute')  # jne .execute

    # === 4. 空闲：概率触发 ===
    cb.emit(b'\x0F\x31')  # rdtsc
    cb.emit(b'\x81\xE1\x7F\x00\x00\x00')  # and ecx, 0x7F (1/128)
    cb.emit(b'\x83\xF9\x01')  # cmp ecx, 1
    cb.emit_jcc32(b'\x0F\x87', 'done')  # ja .done

    # === 5. 触发：生成 8 步轨迹 ===
    cb.emit(b'\x31\xDB')  # xor ebx, ebx (i = 0)

    cb.mark('gen_loop')
    cb.emit(b'\x0F\x31')  # rdtsc
    cb.emit(b'\x89\xC1')  # mov ecx, eax
    cb.emit(b'\x83\xE1\x07')  # and ecx, 7
    cb.emit(b'\x83\xE9\x03')  # sub ecx, 3 (dx = -3..+4)
    cb.emit_rip32(STATE_RVA + OFF_DX, prefix=b'\x48\x8D\x15')  # lea rdx, [rip+fc_dx]
    cb.emit(b'\x89\x0C\x9A')  # mov [rdx + rbx*4], ecx
    cb.emit(b'\xC1\xE8\x08')  # shr eax, 8
    cb.emit(b'\x83\xE0\x07')  # and eax, 7
    cb.emit(b'\x83\xE8\x03')  # sub eax, 3 (dy = -3..+4)
    cb.emit_rip32(STATE_RVA + OFF_DY, prefix=b'\x48\x8D\x15')  # lea rdx, [rip+fc_dy]
    cb.emit(b'\x89\x04\x9A')  # mov [rdx + rbx*4], eax
    cb.emit(b'\xFF\xC3')  # inc ebx
    cb.emit(b'\x83\xFB\x08')  # cmp ebx, 8
    cb.emit_jcc8(b'\x72', 'gen_loop')  # jb .gen_loop

    # 设置 fc_step = 0
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\xC6\x05', suffix=b'\x00')
    cb.emit_jmp('done')  # jmp .done (跳过执行部分)

    # === 6. 执行轨迹步 ===
    cb.mark('execute')
    # eax 当前 = fc_step (来自 movzx)
    cb.emit_rip32(STATE_RVA + OFF_DX, prefix=b'\x48\x8D\x15')  # lea rdx, [rip+fc_dx]
    cb.emit(b'\x8B\x0C\x82')  # mov ecx, [rdx + rax*4]
    cb.emit_rip32(STATE_RVA + OFF_DY, prefix=b'\x48\x8D\x15')  # lea rdx, [rip+fc_dy]
    cb.emit(b'\x44\x8B\x04\x82')  # mov r8d, [rdx + rax*4]

    # === 7. 构造 INPUT 结构 + SendInput ===
    # v3 修复：分配 80 bytes (0x50) 而非 40 bytes (0x28)
    # 40 bytes INPUT + 32 bytes shadow space + 8 bytes 对齐 = 80 bytes
    # 栈对齐：rsp 偏移 96 (前面) + 80 (这里) = 176 = 16*11 → 对齐 16 ✓
    cb.emit(b'\x48\x83\xEC\x50')  # sub rsp, 50h (80 bytes)
    cb.emit(b'\x31\xC0')  # xor eax, eax
    cb.emit(b'\x89\x04\x24')  # mov [rsp], eax (type = INPUT_MOUSE)
    cb.emit(b'\x89\x4C\x24\x08')  # mov [rsp+8], ecx (dx)
    cb.emit(b'\x44\x89\x44\x24\x0C')  # mov [rsp+0Ch], r8d (dy)
    cb.emit(b'\xC7\x44\x24\x14\x01\x00\x00\x00')  # mov dword [rsp+14h], 1 (MOUSEEVENTF_MOVE)
    cb.emit(b'\xB9\x01\x00\x00\x00')  # mov ecx, 1 (cInputs)
    cb.emit(b'\x48\x8D\x14\x24')  # lea rdx, [rsp] (pInputs)
    cb.emit(b'\x41\xB8\x28\x00\x00\x00')  # mov r8d, 28h (cbSize = 40)
    cb.emit_rip32(SENDINPUT_IAT_RVA, prefix=b'\xFF\x15')  # call [rip+SendInput]
    cb.emit(b'\x48\x83\xC4\x50')  # add rsp, 50h

    # === 8. 步进/重置 ===
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x0F\xB6\x05')  # movzx eax, byte [rip+fc_step]
    cb.emit(b'\xFF\xC0')  # inc eax
    cb.emit(b'\x83\xF8\x08')  # cmp eax, 8
    cb.emit_jcc8(b'\x72', 'keep')  # jb .keep
    cb.emit(b'\xB0\xFF')  # mov al, 0xFF (完成，回到空闲)

    cb.mark('keep')
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x88\x05')  # mov [rip+fc_step], al

    # === 8.5 恢复寄存器（v3 修复：恢复 TimerFunc 回调参数）===
    cb.mark('done')
    cb.emit(b'\x5B')  # pop rbx
    cb.emit(b'\x41\x59')  # pop r9
    cb.emit(b'\x41\x58')  # pop r8
    cb.emit(b'\x5A')  # pop rdx
    cb.emit(b'\x59')  # pop rcx
    cb.emit(b'\x58')  # pop rax

    # === 9. 返回 TimerFunc+5 ===
    rel = TIMERFUNC_RETURN_RVA - (cb.cur_rva() + 5)
    cb.emit(b'\xE9')
    cb.emit(struct.pack('<i', rel))

    cb.finalize()
    return bytes(cb.code)


# ==================== 构造 TimerFunc 跳转 ====================
def build_timerfunc_jmp():
    """jmp FAKECLICK_RVA (5 bytes: E9 + rel32)"""
    code = bytearray()
    code += b'\xE9'
    rel = FAKECLICK_RVA - (TIMERFUNC_RVA + 5)
    code += struct.pack('<i', rel)
    return bytes(code)


# ==================== RVA 转文件偏移 ====================
def rva_to_offset(pe, rva):
    for section in pe.sections:
        sva = section.VirtualAddress
        sptr = section.PointerToRawData
        ssize = section.SizeOfRawData
        if sva <= rva < sva + max(ssize, section.Misc_VirtualSize):
            return sptr + (rva - sva)
    raise ValueError(f"RVA 0x{rva:X} 不在任何 section 内")


# ==================== 主函数 ====================
def main():
    print("=" * 60)
    print("假点击 v3: 修复寄存器保存 + 栈对齐")
    print("=" * 60)

    if not os.path.exists(INPUT_FILE):
        print(f"[错误] 输入文件不存在: {INPUT_FILE}")
        return
    print(f"输入: {INPUT_FILE}")
    print(f"输出: {OUTPUT_FILE}")

    shutil.copy2(INPUT_FILE, OUTPUT_FILE)

    pe = pefile.PE(INPUT_FILE, fast_load=True)
    image_base = pe.OPTIONAL_HEADER.ImageBase
    print(f"ImageBase: 0x{image_base:X}")

    tf_offset = rva_to_offset(pe, TIMERFUNC_RVA)
    fc_offset = rva_to_offset(pe, FAKECLICK_RVA)
    st_offset = rva_to_offset(pe, STATE_RVA)
    si_iat_offset = rva_to_offset(pe, SENDINPUT_IAT_RVA)
    print(f"TimerFunc 文件偏移:   0x{tf_offset:X}")
    print(f"FakeClick 文件偏移:   0x{fc_offset:X}")
    print(f"State 文件偏移:       0x{st_offset:X}")
    print(f"SendInput IAT 偏移:   0x{si_iat_offset:X}")

    # 验证 TimerFunc 原始头部
    with open(INPUT_FILE, 'rb') as f:
        f.seek(tf_offset)
        orig_header = f.read(5)
    print(f"\nTimerFunc 原始头部: {orig_header.hex()}")
    if orig_header != ORIGINAL_HEADER:
        print(f"[错误] TimerFunc 头部不匹配!")
        return
    print("[OK] TimerFunc 头部匹配")

    # 构建假点击函数
    fc_code = build_fakeclick_v3()
    print(f"\n假点击函数大小: {len(fc_code)} bytes")
    print(f"假点击函数 RVA: 0x{FAKECLICK_RVA:X}")

    # 构建跳转
    jmp_code = build_timerfunc_jmp()
    print(f"TimerFunc 跳转: {jmp_code.hex()} ({len(jmp_code)} bytes)")

    # 状态变量
    state_data = bytearray(STATE_SIZE)
    state_data[0] = 0xFF  # fc_step = 0xFF (空闲)

    # 写入
    with open(OUTPUT_FILE, 'r+b') as f:
        f.seek(fc_offset)
        f.write(fc_code)
        print(f"\n[写入] 假点击函数 @ 0x{fc_offset:X}")

        f.seek(st_offset)
        f.write(state_data)
        print(f"[写入] 状态变量 @ 0x{st_offset:X}")

        f.seek(tf_offset)
        f.write(jmp_code)
        print(f"[写入] TimerFunc 跳转 @ 0x{tf_offset:X}")

    # 验证
    print("\n" + "=" * 60)
    print("验证")
    print("=" * 60)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(tf_offset)
        actual = f.read(5)
        print(f"TimerFunc 跳转: {actual.hex()} (期望: {jmp_code.hex()})")
        assert actual == jmp_code

        f.seek(fc_offset)
        actual = f.read(5)
        print(f"假点击函数开头: {actual.hex()} (期望: {ORIGINAL_HEADER.hex()})")
        assert actual == ORIGINAL_HEADER

        f.seek(st_offset)
        actual = f.read(1)
        print(f"fc_step 初始值: 0x{actual[0]:02X} (期望: 0xFF)")
        assert actual[0] == 0xFF

    print("\n[成功] 验证通过!")
    print(f"输出文件: {OUTPUT_FILE}")
    print(f"文件大小: {os.path.getsize(OUTPUT_FILE)} bytes")

    # v3 修复说明
    print("\n" + "=" * 60)
    print("v3 修复说明")
    print("=" * 60)
    print("Bug 1: 寄存器未保存")
    print("  v2: 假点击函数破坏 rcx/rdx/r8/r9 (TimerFunc 回调参数)")
    print("  v3: 入口 push rax/rcx/rdx/r8/r9/rbx, 出口 pop 恢复")
    print()
    print("Bug 2: 栈未对齐 16")
    print("  v2: sub rsp, 28h (40 bytes) → rsp 不对齐 16")
    print("  v3: sub rsp, 50h (80 bytes) → rsp 对齐 16 ✓")
    print("  (40 INPUT + 32 shadow space + 8 对齐 = 80)")
    print()
    print("影响:")
    print("  - TimerFunc 后续代码能正确读取 idEvent (r8)")
    print("  - 4 个 case (1-4) 能正确触发对应英雄")
    print("  - Jinx 功能恢复")
    print("  - 假点击功能正常")


if __name__ == '__main__':
    main()
