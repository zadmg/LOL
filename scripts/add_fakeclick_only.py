#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
只添加假点击功能到原始 PE2（不添加 Jinx）
- 基础: 原始 flyinput.dll (beifen_orig_unpacked.dll)
- 修改: 只 hook TimerFunc + 添加假点击函数
- 不修改: BST、跳转表、cmp（保留所有原始英雄功能）
"""
import pefile
import struct
import shutil
import os

# ==================== 配置 ====================
INPUT_FILE = r'D:\SRC\SRC\enhr_embedded\beifen_orig_unpacked.dll'
OUTPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_fakeclick_only.exe'

TIMERFUNC_RVA = 0x14020
TIMERFUNC_RETURN_RVA = 0x14025
SENDINPUT_IAT_RVA = 0x17B08

# 假点击函数和状态变量放在 .text 节区末尾的空洞或新增节区
# 原始 PE2 没有 .newtext，需要新增
NEWTEXT_RVA = 0x1D000  # 对齐到 SizeOfImage
FAKECLICK_OFFSET_IN_NEWTEXT = 0x0000  # 直接放在 .newtext 开头
STATE_OFFSET_IN_NEWTEXT = 0x0800     # 状态变量放在 0x800 偏移

FAKECLICK_RVA = NEWTEXT_RVA + FAKECLICK_OFFSET_IN_NEWTEXT
STATE_RVA = NEWTEXT_RVA + STATE_OFFSET_IN_NEWTEXT

ORIGINAL_HEADER = bytes([0x56, 0x48, 0x83, 0xEC, 0x20])  # push rsi; sub rsp, 20h

# 状态变量布局
OFF_STEP = 0
OFF_DX   = 4
OFF_DY   = 4 + 32
STATE_SIZE = 4 + 32 + 32  # 68 bytes

STACK_ALLOC = 0x50  # 80 bytes


# ==================== CodeBuilder ====================
class CodeBuilder:
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
        next_rip = self.cur_rva() + len(prefix) + 4 + len(suffix)
        disp = target_rva - next_rip
        self.emit(prefix)
        self.emit(struct.pack('<i', disp))
        self.emit(suffix)

    def emit_jmp(self, label):
        self.fixups.append((self.pos() + 1, label, 4))
        self.emit(b'\xE9\x00\x00\x00\x00')

    def emit_jcc32(self, cc2byte, label):
        self.fixups.append((self.pos() + 2, label, 4))
        self.emit(cc2byte)
        self.emit(b'\x00\x00\x00\x00')

    def emit_jcc8(self, cc1byte, label):
        self.fixups.append((self.pos() + 1, label, 1))
        self.emit(cc1byte)
        self.emit(b'\x00')

    def finalize(self):
        for offset, label, rel_size in self.fixups:
            target = self.labels[label]
            if rel_size == 4:
                rel = target - (offset + 4)
                self.code[offset:offset+4] = struct.pack('<i', rel)
            elif rel_size == 1:
                rel = target - (offset + 1)
                if rel < -128 or rel > 127:
                    raise ValueError(f"rel8 超出范围: {rel}")
                self.code[offset:offset+1] = struct.pack('<b', rel)


# ==================== 构造假点击函数 v3 ====================
def build_fakeclick_v3():
    cb = CodeBuilder(FAKECLICK_RVA)

    # 1. 原始头部
    cb.emit(b'\x56')
    cb.emit(b'\x48\x83\xEC\x20')

    # 1.5 保存寄存器
    cb.emit(b'\x50')           # push rax
    cb.emit(b'\x51')           # push rcx
    cb.emit(b'\x52')           # push rdx
    cb.emit(b'\x41\x50')       # push r8
    cb.emit(b'\x41\x51')       # push r9
    cb.emit(b'\x53')           # push rbx

    # 2. 读 fc_step
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x0F\xB6\x05')

    # 3. 检查状态
    cb.emit(b'\x3C\xFF')
    cb.emit_jcc32(b'\x0F\x85', 'execute')

    # 4. 空闲: 概率触发
    cb.emit(b'\x0F\x31')  # rdtsc
    cb.emit(b'\x81\xE1\x7F\x00\x00\x00')  # and ecx, 0x7F
    cb.emit(b'\x83\xF9\x01')  # cmp ecx, 1
    cb.emit_jcc32(b'\x0F\x87', 'done')

    # 5. 生成 8 步轨迹
    cb.emit(b'\x31\xDB')  # xor ebx, ebx
    cb.mark('gen_loop')
    cb.emit(b'\x0F\x31')  # rdtsc
    cb.emit(b'\x89\xC1')  # mov ecx, eax
    cb.emit(b'\x83\xE1\x07')  # and ecx, 7
    cb.emit(b'\x83\xE9\x03')  # sub ecx, 3
    cb.emit_rip32(STATE_RVA + OFF_DX, prefix=b'\x48\x8D\x15')
    cb.emit(b'\x89\x0C\x9A')  # mov [rdx + rbx*4], ecx
    cb.emit(b'\xC1\xE8\x08')  # shr eax, 8
    cb.emit(b'\x83\xE0\x07')  # and eax, 7
    cb.emit(b'\x83\xE8\x03')  # sub eax, 3
    cb.emit_rip32(STATE_RVA + OFF_DY, prefix=b'\x48\x8D\x15')
    cb.emit(b'\x89\x04\x9A')  # mov [rdx + rbx*4], eax
    cb.emit(b'\xFF\xC3')  # inc ebx
    cb.emit(b'\x83\xFB\x08')  # cmp ebx, 8
    cb.emit_jcc8(b'\x72', 'gen_loop')

    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\xC6\x05', suffix=b'\x00')
    cb.emit_jmp('done')

    # 6. 执行轨迹步
    cb.mark('execute')
    cb.emit_rip32(STATE_RVA + OFF_DX, prefix=b'\x48\x8D\x15')
    cb.emit(b'\x8B\x0C\x82')  # mov ecx, [rdx + rax*4]
    cb.emit_rip32(STATE_RVA + OFF_DY, prefix=b'\x48\x8D\x15')
    cb.emit(b'\x44\x8B\x04\x82')  # mov r8d, [rdx + rax*4]

    # 7. 构造 INPUT + SendInput
    cb.emit(b'\x48\x83\xEC\x50')  # sub rsp, 50h
    cb.emit(b'\x31\xC0')  # xor eax, eax
    cb.emit(b'\x89\x04\x24')  # mov [rsp], eax
    cb.emit(b'\x89\x4C\x24\x08')  # mov [rsp+8], ecx
    cb.emit(b'\x44\x89\x44\x24\x0C')  # mov [rsp+0Ch], r8d
    cb.emit(b'\xC7\x44\x24\x14\x01\x00\x00\x00')  # mov dword [rsp+14h], 1
    cb.emit(b'\xB9\x01\x00\x00\x00')  # mov ecx, 1
    cb.emit(b'\x48\x8D\x14\x24')  # lea rdx, [rsp]
    cb.emit(b'\x41\xB8\x28\x00\x00\x00')  # mov r8d, 28h
    cb.emit_rip32(SENDINPUT_IAT_RVA, prefix=b'\xFF\x15')
    cb.emit(b'\x48\x83\xC4\x50')  # add rsp, 50h

    # 8. 步进/重置
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x0F\xB6\x05')
    cb.emit(b'\xFF\xC0')  # inc eax
    cb.emit(b'\x83\xF8\x08')  # cmp eax, 8
    cb.emit_jcc8(b'\x72', 'keep')
    cb.emit(b'\xB0\xFF')  # mov al, 0xFF
    cb.mark('keep')
    cb.emit_rip32(STATE_RVA + OFF_STEP, prefix=b'\x88\x05')

    # 8.5 恢复寄存器
    cb.mark('done')
    cb.emit(b'\x5B')  # pop rbx
    cb.emit(b'\x41\x59')  # pop r9
    cb.emit(b'\x41\x58')  # pop r8
    cb.emit(b'\x5A')  # pop rdx
    cb.emit(b'\x59')  # pop rcx
    cb.emit(b'\x58')  # pop rax

    # 9. 返回 TimerFunc+5
    rel = TIMERFUNC_RETURN_RVA - (cb.cur_rva() + 5)
    cb.emit(b'\xE9')
    cb.emit(struct.pack('<i', rel))

    cb.finalize()
    return bytes(cb.code)


def build_timerfunc_jmp():
    code = bytearray()
    code += b'\xE9'
    rel = FAKECLICK_RVA - (TIMERFUNC_RVA + 5)
    code += struct.pack('<i', rel)
    return bytes(code)


def rva_to_offset(pe, rva):
    for section in pe.sections:
        if section.VirtualAddress <= rva < section.VirtualAddress + section.Misc_VirtualSize:
            return section.PointerToRawData + (rva - section.VirtualAddress)
    return None


# ==================== 主函数 ====================
def main():
    print("=" * 60)
    print("只添加假点击功能到原始 PE2（不添加 Jinx）")
    print("=" * 60)

    if not os.path.exists(INPUT_FILE):
        print(f"[错误] 输入文件不存在: {INPUT_FILE}")
        return
    print(f"输入: {INPUT_FILE}")
    print(f"输出: {OUTPUT_FILE}")

    shutil.copy2(INPUT_FILE, OUTPUT_FILE)

    pe = pefile.PE(INPUT_FILE)
    imgbase = pe.OPTIONAL_HEADER.ImageBase
    file_align = pe.OPTIONAL_HEADER.FileAlignment
    section_align = pe.OPTIONAL_HEADER.SectionAlignment

    print(f"ImageBase: 0x{imgbase:X}")
    print(f"原节区数: {len(pe.sections)}")

    tf_offset = rva_to_offset(pe, TIMERFUNC_RVA)
    si_iat_offset = rva_to_offset(pe, SENDINPUT_IAT_RVA)
    print(f"TimerFunc 偏移: 0x{tf_offset:X}")
    print(f"SendInput IAT 偏移: 0x{si_iat_offset:X}")

    # 验证 TimerFunc 原始头部
    with open(INPUT_FILE, 'rb') as f:
        f.seek(tf_offset)
        orig_header = f.read(5)
    print(f"TimerFunc 原始头部: {orig_header.hex()}")
    if orig_header != ORIGINAL_HEADER:
        print(f"[错误] TimerFunc 头部不匹配!")
        return
    print("[OK] TimerFunc 头部匹配")

    # 确定新 section 位置
    last_section = pe.sections[-1]
    new_va = (pe.OPTIONAL_HEADER.SizeOfImage + section_align - 1) & ~(section_align - 1)
    file_size = os.path.getsize(INPUT_FILE)
    new_rawptr = (file_size + file_align - 1) & ~(file_align - 1)
    new_rawsize = 0x10000
    new_vsize = 0x10000

    print(f"\n新 section .newtext:")
    print(f"  VA: 0x{new_va:X}")
    print(f"  RawPtr: 0x{new_rawptr:X}")
    print(f"  Size: 0x{new_rawsize:X}")

    # 构建假点击函数
    fc_code = build_fakeclick_v3()
    print(f"\n假点击函数大小: {len(fc_code)} bytes")
    print(f"假点击函数 RVA: 0x{FAKECLICK_RVA:X}")

    jmp_code = build_timerfunc_jmp()
    print(f"TimerFunc 跳转: {jmp_code.hex()}")

    # 状态变量
    state_data = bytearray(STATE_SIZE)
    state_data[0] = 0xFF

    # 读取原始文件
    with open(INPUT_FILE, 'rb') as f:
        raw = bytearray(f.read())

    # 添加新 section header
    pe_sig_off = struct.unpack_from('<I', raw, 0x3C)[0]
    num_sections_off = pe_sig_off + 6
    size_opt_hdr_off = pe_sig_off + 20
    section_table_off = pe_sig_off + 24 + struct.unpack_from('<H', raw, size_opt_hdr_off)[0]
    num_sections = struct.unpack_from('<H', raw, num_sections_off)[0]

    new_header = bytearray(40)
    new_header[0:8] = b'.newtext'
    struct.pack_into('<I', new_header, 8, new_vsize)
    struct.pack_into('<I', new_header, 12, new_va)
    struct.pack_into('<I', new_header, 16, new_rawsize)
    struct.pack_into('<I', new_header, 20, new_rawptr)
    struct.pack_into('<I', new_header, 36, 0xE0000040)

    new_header_off = section_table_off + num_sections * 40
    raw[new_header_off:new_header_off+40] = new_header
    struct.pack_into('<H', raw, num_sections_off, num_sections + 1)

    size_of_image_off = pe_sig_off + 24 + 56
    new_size_of_image = new_va + new_vsize
    struct.pack_into('<I', raw, size_of_image_off, new_size_of_image)
    print(f"SizeOfImage: 0x{new_size_of_image:X}")
    print(f"NumberOfSections: {num_sections + 1}")

    pe.close()

    # 对齐文件
    while len(raw) < new_rawptr:
        raw += b'\x00'

    # 创建 section 数据
    section_data = bytearray(new_rawsize)
    # 写入假点击函数
    section_data[FAKECLICK_OFFSET_IN_NEWTEXT:FAKECLICK_OFFSET_IN_NEWTEXT+len(fc_code)] = fc_code
    # 写入状态变量
    section_data[STATE_OFFSET_IN_NEWTEXT:STATE_OFFSET_IN_NEWTEXT+len(state_data)] = state_data

    raw += section_data

    # 修改 TimerFunc 跳转
    # 注意: TimerFunc 在 .text 节区，文件偏移不变
    raw[tf_offset:tf_offset+5] = jmp_code
    print(f"\n[写入] TimerFunc 跳转 @ 0x{tf_offset:X}: {jmp_code.hex()}")

    # 保存
    with open(OUTPUT_FILE, 'wb') as f:
        f.write(raw)
    print(f"\n输出文件: {OUTPUT_FILE}")
    print(f"文件大小: {len(raw)} bytes")

    # 验证
    print("\n" + "=" * 60)
    print("验证")
    print("=" * 60)
    pe2 = pefile.PE(OUTPUT_FILE)
    print(f"节区数: {len(pe2.sections)}")
    for s in pe2.sections:
        name = s.Name.rstrip(b'\x00').decode()
        print(f"  {name:10s} VA=0x{s.VirtualAddress:08X} VSize=0x{s.Misc_VirtualSize:08X}")

    off = pe2.get_offset_from_rva(TIMERFUNC_RVA)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(off)
        actual = f.read(5)
    print(f"\nTimerFunc 跳转: {actual.hex()} (期望: {jmp_code.hex()})")
    assert actual == jmp_code

    # 验证假点击函数
    off2 = pe2.get_offset_from_rva(FAKECLICK_RVA)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(off2)
        fc_header = f.read(5)
    print(f"假点击函数开头: {fc_header.hex()}")
    assert fc_header == ORIGINAL_HEADER

    # 验证状态变量
    off3 = pe2.get_offset_from_rva(STATE_RVA)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(off3)
        step = f.read(1)
    print(f"fc_step 初始值: 0x{step[0]:02X}")
    assert step[0] == 0xFF

    # 验证原始跳转表未被修改
    jt_off = pe2.get_offset_from_rva(0x172B0)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(jt_off)
        jt = f.read(80)
    print(f"\n原始跳转表（未修改）:")
    for i in range(10):
        ptr = struct.unpack('<Q', jt[i*8:(i+1)*8])[0]
        print(f"  [{i:2d}] = 0x{ptr:016X}")

    # 验证 BST 未被修改
    bst_off = pe2.get_offset_from_rva(0x169C)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(bst_off)
        bst = f.read(6)
    print(f"\nBST @ 0x169C（未修改）: {bst.hex()}")
    assert bst == b'\x0f\x85\xb8\x00\x00\x00', "BST 被修改了!"
    print("[OK] BST 未被修改")

    # 验证 cmp 未被修改
    cmp_off = pe2.get_offset_from_rva(0x3415)
    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(cmp_off)
        cmp_bytes = f.read(4)
    print(f"cmp @ 0x3415（未修改）: {cmp_bytes.hex()}")
    assert cmp_bytes == b'\x48\x83\xF8\x09', "cmp 被修改了!"
    print("[OK] cmp rax, 9 未被修改（保留原始 10 英雄）")

    print("\n[成功] 假点击功能已添加，原始英雄功能完整保留!")
    print(f"\n支持的英雄（原始 10 个）:")
    print("  Ashe, Kaisa, Kalista, KogMaw, Sivir,")
    print("  Tristana, TwistedFate, Twitch, Xayah, Yunara")


if __name__ == '__main__':
    main()
