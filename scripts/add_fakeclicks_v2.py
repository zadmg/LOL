#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
假点击 v2: 8 步人类化鼠标轨迹
- 1/128 概率触发
- 生成 8 步随机轨迹（每步 ±3 像素）
- 8ms 完成（8 个 TimerFunc 周期）
- 状态机：空闲 → 生成轨迹 → 执行 8 步 → 空闲
"""

import pefile
import struct
import shutil
import os

# ==================== 配置 ====================
INPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_jinx.exe'
OUTPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_jinx_fakeclick2.exe'

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


# ==================== CodeBuilder ====================
class CodeBuilder:
    """管理代码生成 + label + fixup"""

    def __init__(self, base_rva):
        self.code = bytearray()
        self.base_rva = base_rva
        self.labels = {}    # name -> code offset
        self.fixups = []    # (rel_offset_in_code, label_name, rel_size)

    def emit(self, data):
        self.code += bytes(data)

    def pos(self):
        return len(self.code)

    def cur_rva(self):
        return self.base_rva + len(self.code)

    def mark(self, name):
        self.labels[name] = len(self.code)

    def emit_rip32(self, target_rva, prefix=b'', suffix=b''):
        """emit RIP-relative disp32 指令
        next_rip = cur_rva + len(prefix) + 4 + len(suffix)
        disp = target_rva - next_rip
        """
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


# ==================== 构造假点击函数 ====================
def build_fakeclick_v2():
    cb = CodeBuilder(FAKECLICK_RVA)

    # === 1. 原始头部 ===
    cb.emit(b'\x56')                # push rsi
    cb.emit(b'\x48\x83\xEC\x20')   # sub rsp, 20h

    # === 2. 读 fc_step ===
    # movzx eax, byte [rip+fc_step]
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x0F\xB6\x05')

    # === 3. 检查状态 ===
    # cmp al, 0xFF
    cb.emit(b'\x3C\xFF')
    # jne .execute  (如果 step != 0xFF，跳到执行)
    cb.emit_jcc32(b'\x0F\x85', 'execute')

    # === 4. 空闲：概率触发 ===
    # rdtsc
    cb.emit(b'\x0F\x31')
    # and ecx, 0x7F  (1/128 概率)
    cb.emit(b'\x81\xE1\x7F\x00\x00\x00')
    # cmp ecx, 1
    cb.emit(b'\x83\xF9\x01')
    # ja .done  (未触发，跳到 done)
    cb.emit_jcc32(b'\x0F\x87', 'done')

    # === 5. 触发：生成 8 步轨迹 ===
    # xor ebx, ebx  (i = 0)
    cb.emit(b'\x31\xDB')

    cb.mark('gen_loop')
    # rdtsc
    cb.emit(b'\x0F\x31')
    # mov ecx, eax
    cb.emit(b'\x89\xC1')
    # and ecx, 7
    cb.emit(b'\x83\xE1\x07')
    # sub ecx, 3   (dx = -3..+4)
    cb.emit(b'\x83\xE9\x03')
    # lea rdx, [rip+fc_dx]
    cb.emit_rip32(STATE_RVA + OFF_DX, prefix=b'\x48\x8D\x15')
    # mov [rdx + rbx*4], ecx
    cb.emit(b'\x89\x0C\x9A')
    # shr eax, 8
    cb.emit(b'\xC1\xE8\x08')
    # and eax, 7
    cb.emit(b'\x83\xE0\x07')
    # sub eax, 3   (dy = -3..+4)
    cb.emit(b'\x83\xE8\x03')
    # lea rdx, [rip+fc_dy]
    cb.emit_rip32(STATE_RVA + OFF_DY, prefix=b'\x48\x8D\x15')
    # mov [rdx + rbx*4], eax
    cb.emit(b'\x89\x04\x9A')
    # inc ebx
    cb.emit(b'\xFF\xC3')
    # cmp ebx, 8
    cb.emit(b'\x83\xFB\x08')
    # jb .gen_loop
    cb.emit_jcc8(b'\x72', 'gen_loop')

    # 设置 fc_step = 0
    # mov byte [rip+fc_step], 0
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\xC6\x05', suffix=b'\x00')

    # jmp .done  (跳过执行部分)
    cb.emit_jmp('done')

    # === 6. 执行轨迹步 ===
    cb.mark('execute')

    # 读 fc_dx[step]: lea rdx, [rip+fc_dx]; mov ecx, [rdx + rax*4]
    # eax 当前 = fc_step (来自 movzx)
    cb.emit_rip32(STATE_RVA + OFF_DX, prefix=b'\x48\x8D\x15')
    # mov ecx, [rdx + rax*4]
    cb.emit(b'\x8B\x0C\x82')   # mov ecx, [rdx + rax*4]

    # 读 fc_dy[step]: lea rdx, [rip+fc_dy]; mov r8d, [rdx + rax*4]
    cb.emit_rip32(STATE_RVA + OFF_DY, prefix=b'\x48\x8D\x15')
    # mov r8d, [rdx + rax*4]
    cb.emit(b'\x44\x8B\x04\x82')  # mov r8d, [rdx + rax*4]

    # === 7. 构造 INPUT 结构 + SendInput ===
    # sub rsp, 28h  (40 bytes for INPUT)
    cb.emit(b'\x48\x83\xEC\x28')
    # xor eax, eax
    cb.emit(b'\x31\xC0')
    # mov [rsp], eax  (type = 0 = INPUT_MOUSE)
    cb.emit(b'\x89\x04\x24')
    # mov [rsp+8], ecx  (dx)
    cb.emit(b'\x89\x4C\x24\x08')
    # mov [rsp+0Ch], r8d  (dy)
    cb.emit(b'\x44\x89\x44\x24\x0C')
    # mov dword [rsp+14h], 1  (dwFlags = MOUSEEVENTF_MOVE = 0x0001)
    cb.emit(b'\xC7\x44\x24\x14\x01\x00\x00\x00')
    # mov ecx, 1  (cInputs)
    cb.emit(b'\xB9\x01\x00\x00\x00')
    # lea rdx, [rsp]  (pInputs)
    cb.emit(b'\x48\x8D\x14\x24')
    # mov r8d, 28h  (cbSize = 40)
    cb.emit(b'\x41\xB8\x28\x00\x00\x00')
    # call [rip+SendInput]
    cb.emit_rip32(SENDINPUT_IAT_RVA, prefix=b'\xFF\x15')
    # add rsp, 28h
    cb.emit(b'\x48\x83\xC4\x28')

    # === 8. 步进/重置 ===
    # 重新读 fc_step
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x0F\xB6\x05')
    # inc eax
    cb.emit(b'\xFF\xC0')
    # cmp eax, 8
    cb.emit(b'\x83\xF8\x08')
    # jb .keep  (step < 8, 保留)
    cb.emit_jcc8(b'\x72', 'keep')
    # mov al, 0xFF  (完成，回到空闲)
    cb.emit(b'\xB0\xFF')

    cb.mark('keep')
    # mov [rip+fc_step], al
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x88\x05')

    # === 9. 返回 TimerFunc+5 ===
    cb.mark('done')
    # jmp TimerFunc+5 (rel32)
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
    print("假点击 v2: 8 步人类化鼠标轨迹")
    print("=" * 60)

    # 检查输入文件
    if not os.path.exists(INPUT_FILE):
        print(f"[错误] 输入文件不存在: {INPUT_FILE}")
        return
    print(f"输入: {INPUT_FILE}")
    print(f"输出: {OUTPUT_FILE}")

    # 复制
    shutil.copy2(INPUT_FILE, OUTPUT_FILE)

    # 加载 PE
    pe = pefile.PE(INPUT_FILE, fast_load=True)
    image_base = pe.OPTIONAL_HEADER.ImageBase
    print(f"ImageBase: 0x{image_base:X}")

    # 计算文件偏移
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
        print(f"[错误] TimerFunc 头部不匹配! 期望: {ORIGINAL_HEADER.hex()}")
        return
    print("[OK] TimerFunc 头部匹配")

    # 验证 SendInput IAT
    with open(INPUT_FILE, 'rb') as f:
        f.seek(si_iat_offset)
        si_ptr = f.read(8)
    si_rva = struct.unpack('<Q', si_ptr)[0] - image_base
    print(f"SendInput IAT 值: 0x{struct.unpack('<Q', si_ptr)[0]:X} (RVA=0x{si_rva:X})")

    # 构建假点击函数
    fc_code = build_fakeclick_v2()
    print(f"\n假点击函数大小: {len(fc_code)} bytes")
    print(f"假点击函数 RVA: 0x{FAKECLICK_RVA:X}")

    # 构建跳转
    jmp_code = build_timerfunc_jmp()
    print(f"TimerFunc 跳转: {jmp_code.hex()} ({len(jmp_code)} bytes)")

    # 构建状态变量初始值
    state_data = bytearray(STATE_SIZE)
    state_data[0] = 0xFF  # fc_step = 0xFF (空闲)
    print(f"状态变量大小: {len(state_data)} bytes")
    print(f"状态变量 RVA: 0x{STATE_RVA:X}")

    # 写入文件
    with open(OUTPUT_FILE, 'r+b') as f:
        # 1. 写入假点击函数
        f.seek(fc_offset)
        f.write(fc_code)
        print(f"\n[写入] 假点击函数 @ 文件偏移 0x{fc_offset:X}")

        # 2. 写入状态变量
        f.seek(st_offset)
        f.write(state_data)
        print(f"[写入] 状态变量 @ 文件偏移 0x{st_offset:X}")

        # 3. 写入 TimerFunc 跳转
        f.seek(tf_offset)
        f.write(jmp_code)
        print(f"[写入] TimerFunc 跳转 @ 文件偏移 0x{tf_offset:X}")

    # 验证
    print("\n" + "=" * 60)
    print("验证")
    print("=" * 60)
    with open(OUTPUT_FILE, 'rb') as f:
        # 验证 TimerFunc 跳转
        f.seek(tf_offset)
        actual = f.read(5)
        print(f"TimerFunc 跳转: {actual.hex()} (期望: {jmp_code.hex()})")
        assert actual == jmp_code, "TimerFunc 跳转不匹配!"

        # 验证假点击函数开头
        f.seek(fc_offset)
        actual = f.read(5)
        print(f"假点击函数开头: {actual.hex()} (期望: {ORIGINAL_HEADER.hex()})")
        assert actual == ORIGINAL_HEADER, "假点击函数开头不匹配!"

        # 验证状态变量
        f.seek(st_offset)
        actual = f.read(1)
        print(f"fc_step 初始值: 0x{actual[0]:02X} (期望: 0xFF)")
        assert actual[0] == 0xFF, "fc_step 初始值不匹配!"

    print("\n[成功] 所有验证通过!")
    print(f"输出文件: {OUTPUT_FILE}")
    print(f"文件大小: {os.path.getsize(OUTPUT_FILE)} bytes")

    # 打印函数反汇编提示
    print("\n" + "=" * 60)
    print("假点击函数结构")
    print("=" * 60)
    print(f"位置: .newtext + 0x{FAKECLICK_OFFSET:X} (RVA 0x{FAKECLICK_RVA:X})")
    print(f"大小: {len(fc_code)} bytes")
    print(f"状态变量: .newtext + 0x{STATE_OFFSET:X} (RVA 0x{STATE_RVA:X})")
    print(f"状态大小: {STATE_SIZE} bytes")
    print()
    print("逻辑:")
    print("  1. 执行原始 TimerFunc 头部 (push rsi; sub rsp, 20h)")
    print("  2. 读 fc_step:")
    print("     - 0xFF (空闲) → rdtsc 1/128 概率触发")
    print("       触发 → 生成 8 步轨迹 (dx/dy 各 ±3 像素) → step=0")
    print("     - 0-7 (执行中) → 读 dx/dy[step] → SendInput → step++")
    print("       step≥8 → step=0xFF (回到空闲)")
    print("  3. jmp TimerFunc+5")


if __name__ == '__main__':
    main()
