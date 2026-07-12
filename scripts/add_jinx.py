#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
为 flyinput.dll 添加 Jinx (金克丝) 英雄支持
基于克隆 Ashe 函数 + 扩展跳转表 + BST 插入

修改点:
1. 添加 .newtext section (64KB, RWX)
2. 新跳转表 (15项, 前10项复制原表, 第11项指向 Jinx 函数)
3. Jinx 函数 (克隆自 Ashe 0x180004BB0, 5499字节)
4. BST 插入代码 (比较 Jinx 哈希, 设置模式索引 10)
5. 修改 cmp rax,9 → cmp rax,10
6. 修改 lea 指令指向新跳转表
7. 修改 jnz → jmp BST代码
"""

import pefile
import struct
import shutil
import os
import sys

# ==================== 配置 ====================
INPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_unpacked.exe'
OUTPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_jinx.exe'
BACKUP_FILE = INPUT_FILE + '.bak'

JINX_HASH = 0x7E5859EA35269A8A  # Jinx 的 FNV-1a 哈希
ASHE_FUNC_RVA = 0x4BB0          # Ashe 函数起始 RVA
ASHE_FUNC_END_RVA = 0x612B      # Ashe 函数结束 RVA
ASHE_FUNC_SIZE = ASHE_FUNC_END_RVA - ASHE_FUNC_RVA  # 0x157B = 5499 字节

# 原跳转表 (10个函数指针)
ORIGINAL_JUMPTABLE_RVA = 0x172B0
ORIGINAL_FUNC_PTRS = [
    0x180004BB0,  # [0] Ashe
    0x180006130,  # [1] Kaisa
    0x1800076B0,  # [2] Kalista
    0x180008CD0,  # [3] KogMaw
    0x18000A3A0,  # [4] Sivir
    0x18000B8D0,  # [5] Tristana
    0x18000CE80,  # [6] TwistedFate
    0x18000E660,  # [7] Twitch
    0x18000FC20,  # [8] Xayah
    0x1800111D0,  # [9] Yunara
]

# 关键修改点 (RVA)
CMP_RVA = 0x3415          # cmp rax, 9
LEA_RVA = 0x341B           # lea rcx, [rip+offset]
JNZ_RVA = 0x169C            # jnz loc_18000175A (TwistedFate 不匹配时跳转)
WORD_MODEIDX_RVA = 0x193FA  # word_1800193FA (模式索引变量)
MAINLOOP_RVA = 0x340E       # 主循环入口
FAIL_RVA = 0x175A           # BST 匹配失败处

# ==================== 工具函数 ====================
def rva_to_offset(pe, rva):
    """RVA 转文件偏移"""
    for section in pe.sections:
        if section.VirtualAddress <= rva < section.VirtualAddress + section.Misc_VirtualSize:
            return section.PointerToRawData + (rva - section.VirtualAddress)
    return None

def calc_jmp_rel32(src_rva, dst_rva, instr_len=5):
    """计算 jmp rel32 的偏移"""
    return dst_rva - (src_rva + instr_len)

def build_bst_code(code_rva):
    """构建 BST 插入代码 (比较 Jinx 哈希, 设置模式索引 10)"""
    code = bytearray()

    # 1. mov rdx, JINX_HASH (10 bytes)
    # 机器码: 48 BA <8字节立即数>
    code += b'\x48\xBA'
    code += struct.pack('<Q', JINX_HASH)

    # 2. cmp rax, rdx (3 bytes)
    # 机器码: 48 39 D0
    code += b'\x48\x39\xD0'

    # 3. jz set_jinx_index (2 bytes, short jump)
    # 跳过下面的 jmp fail
    jmp_fail_len = 5  # E9 xx xx xx xx
    code += b'\x74' + bytes([jmp_fail_len])

    # 4. jmp FAIL_RVA (5 bytes, rel32)
    # 跳到 BST 匹配失败
    offset = calc_jmp_rel32(code_rva + len(code), FAIL_RVA)
    code += b'\xE9' + struct.pack('<i', offset)

    # --- set_jinx_index ---
    # 5. mov word ptr [rip+offset], 0x000A (9 bytes: 66 C7 05 + 4字节disp + 2字节imm)
    # 设置 word_1800193FA = 10
    set_jinx_rva = code_rva + len(code)
    instr_len_mov = 9  # 实际指令长度 9 字节 (不是 8)
    next_rva = set_jinx_rva + instr_len_mov
    rip_offset = WORD_MODEIDX_RVA - next_rva
    code += b'\x66\xC7\x05'
    code += struct.pack('<i', rip_offset)
    code += b'\x0A\x00'

    # 6. jmp MAINLOOP_RVA (5 bytes, rel32)
    # 跳到主循环
    offset = calc_jmp_rel32(code_rva + len(code), MAINLOOP_RVA)
    code += b'\xE9' + struct.pack('<i', offset)

    return bytes(code)


def build_new_jumptable(jinx_func_va, num_original=10):
    """构建新跳转表 (15项)"""
    table = bytearray()
    # 前 10 项: 复制原函数指针
    for ptr in ORIGINAL_FUNC_PTRS[:num_original]:
        table += struct.pack('<Q', ptr)
    # 第 11 项 (索引10): Jinx 函数
    table += struct.pack('<Q', jinx_func_va)
    # 填充到 15 项 (索引 11-14 设为 0, 暂时指向主循环)
    for _ in range(4):
        table += struct.pack('<Q', 0)
    return bytes(table)


# ==================== 主逻辑 ====================
def main():
    print(f'读取 PE: {INPUT_FILE}')
    pe = pefile.PE(INPUT_FILE)
    imgbase = pe.OPTIONAL_HEADER.ImageBase
    file_align = pe.OPTIONAL_HEADER.FileAlignment
    section_align = pe.OPTIONAL_HEADER.SectionAlignment

    print(f'ImageBase: 0x{imgbase:X}')
    print(f'FileAlignment: 0x{file_align:X}')
    print(f'SectionAlignment: 0x{section_align:X}')

    # 确定 .newtext 的 VA
    last_section = pe.sections[-1]
    new_va = (last_section.VirtualAddress + last_section.Misc_VirtualSize + section_align - 1) & ~(section_align - 1)
    # 或者用 SizeOfImage 对齐
    new_va = (pe.OPTIONAL_HEADER.SizeOfImage + section_align - 1) & ~(section_align - 1)

    # 确定新 section 的 RawPtr (文件末尾对齐)
    file_size = os.path.getsize(INPUT_FILE)
    new_rawptr = (file_size + file_align - 1) & ~(file_align - 1)

    # 新 section 大小 (64KB)
    new_rawsize = 0x10000
    new_vsize = 0x10000

    print(f'\n=== 新 section .newtext ===')
    print(f'VA (RVA): 0x{new_va:X}')
    print(f'RawPtr: 0x{new_rawptr:X}')
    print(f'VSize: 0x{new_vsize:X}')
    print(f'RawSize: 0x{new_rawsize:X}')

    # 新 section 内部布局:
    # 0x0000: 新跳转表 (15 × 8 = 120 字节)
    # 0x0100: BST 代码 (~33 字节)
    # 0x0200: Jinx 函数 (5499 字节)

    NEW_JT_RVA = new_va + 0x0000     # 新跳转表 RVA
    BST_CODE_RVA = new_va + 0x0100   # BST 代码 RVA
    JINX_FUNC_RVA = new_va + 0x0200   # Jinx 函数 RVA
    JINX_FUNC_VA = imgbase + JINX_FUNC_RVA

    print(f'新跳转表 VA: 0x{imgbase + NEW_JT_RVA:X}')
    print(f'BST 代码 VA: 0x{imgbase + BST_CODE_RVA:X}')
    print(f'Jinx 函数 VA: 0x{imgbase + JINX_FUNC_RVA:X}')

    # ==================== 准备新 section 数据 ====================
    section_data = bytearray(new_rawsize)

    # 1. 新跳转表 (偏移 0x0000)
    jt_data = build_new_jumptable(JINX_FUNC_VA)
    section_data[0:len(jt_data)] = jt_data
    print(f'\n新跳转表: {len(jt_data)} 字节, {len(jt_data)//8} 项')

    # 2. BST 代码 (偏移 0x0100)
    bst_code = build_bst_code(BST_CODE_RVA)
    section_data[0x100:0x100+len(bst_code)] = bst_code
    print(f'BST 代码: {len(bst_code)} 字节')

    # 3. Jinx 函数 (偏移 0x0200) - 克隆 Ashe
    ashe_offset = rva_to_offset(pe, ASHE_FUNC_RVA)
    ashe_data = pe.get_data(ASHE_FUNC_RVA, ASHE_FUNC_SIZE)
    section_data[0x200:0x200+ASHE_FUNC_SIZE] = ashe_data
    print(f'Jinx 函数 (克隆 Ashe): {ASHE_FUNC_SIZE} 字节')

    # ==================== 修改原始代码 ====================
    # 读取原始文件到 bytearray
    with open(INPUT_FILE, 'rb') as f:
        raw = bytearray(f.read())

    # 修改 1: cmp rax, 9 → cmp rax, 10
    cmp_off = rva_to_offset(pe, CMP_RVA)
    print(f'\n修改 cmp: file offset 0x{cmp_off:X}')
    print(f'  原始: {raw[cmp_off:cmp_off+5].hex()}')
    # 48 83 F8 09 → 48 83 F8 0A
    raw[cmp_off] = 0x48
    raw[cmp_off+1] = 0x83
    raw[cmp_off+2] = 0xF8
    raw[cmp_off+3] = 0x0A  # 9 → 10
    print(f'  修改后: {raw[cmp_off:cmp_off+5].hex()}')

    # 修改 2: lea rcx, [rip+offset] → 指向新跳转表
    lea_off = rva_to_offset(pe, LEA_RVA)
    print(f'\n修改 lea: file offset 0x{lea_off:X}')
    print(f'  原始: {raw[lea_off:lea_off+7].hex()}')
    # 48 8D 0D <4字节偏移>
    # lea 指令长度 7, 下一条指令 RVA = LEA_RVA + 7
    next_rva = LEA_RVA + 7
    new_lea_offset = NEW_JT_RVA - next_rva
    raw[lea_off] = 0x48
    raw[lea_off+1] = 0x8D
    raw[lea_off+2] = 0x0D
    struct.pack_into('<i', raw, lea_off+3, new_lea_offset)
    print(f'  新偏移: 0x{new_lea_offset:X}')
    print(f'  修改后: {raw[lea_off:lea_off+7].hex()}')
    # 验证
    verify_va = imgbase + next_rva + new_lea_offset
    print(f'  验证: 0x{verify_va:X} (应为 0x{imgbase + NEW_JT_RVA:X})')

    # 修改 3: jnz loc_18000175A → jmp BST_CODE
    jnz_off = rva_to_offset(pe, JNZ_RVA)
    print(f'\n修改 jnz→jmp: file offset 0x{jnz_off:X}')
    print(f'  原始: {raw[jnz_off:jnz_off+6].hex()}')
    # 0F 85 B8 00 00 00 (6字节) → E9 xx xx xx xx 90 (5+1=6字节)
    # jmp rel32 指令长度 5, 下一条指令 RVA = JNZ_RVA + 5
    next_rva_jmp = JNZ_RVA + 5
    jmp_offset = BST_CODE_RVA - next_rva_jmp
    raw[jnz_off] = 0xE9
    struct.pack_into('<i', raw, jnz_off+1, jmp_offset)
    raw[jnz_off+5] = 0x90  # NOP
    print(f'  跳转偏移: 0x{jmp_offset:X}')
    print(f'  修改后: {raw[jnz_off:jnz_off+6].hex()}')
    # 验证
    verify_va = imgbase + next_rva_jmp + jmp_offset
    print(f'  验证: 0x{verify_va:X} (应为 0x{imgbase + BST_CODE_RVA:X})')

    pe.close()

    # ==================== 添加新 section header ====================
    # 解析 PE header
    pe_sig_off = struct.unpack_from('<I', raw, 0x3C)[0]  # e_lfanew
    num_sections_off = pe_sig_off + 6  # NumberOfSections
    size_opt_hdr_off = pe_sig_off + 20  # SizeOfOptionalHeader
    section_table_off = pe_sig_off + 24 + struct.unpack_from('<H', raw, size_opt_hdr_off)[0]

    num_sections = struct.unpack_from('<H', raw, num_sections_off)[0]
    print(f'\n原 NumberOfSections: {num_sections}')

    # 新 section header (40 字节)
    # 注意: section name 字段固定 8 字节, bytearray 初始化已为 0, 不要追加 \x00
    # (否则 bytearray 切片赋值会扩展数组, 导致整个文件偏移错位)
    new_header = bytearray(40)
    new_header[0:8] = b'.newtext'  # Name (正好 8 字节, 不带结尾 \x00)
    struct.pack_into('<I', new_header, 8, new_vsize)    # VirtualSize
    struct.pack_into('<I', new_header, 12, new_va)      # VirtualAddress
    struct.pack_into('<I', new_header, 16, new_rawsize) # SizeOfRawData
    struct.pack_into('<I', new_header, 20, new_rawptr)  # PointerToRawData
    struct.pack_into('<I', new_header, 24, 0)           # PointerToRelocations
    struct.pack_into('<I', new_header, 28, 0)           # PointerToLinenumbers
    struct.pack_into('<H', new_header, 32, 0)           # NumberOfRelocations
    struct.pack_into('<H', new_header, 34, 0)           # NumberOfLinenumbers
    # Characteristics: CODE | EXECUTE | READ | WRITE
    struct.pack_into('<I', new_header, 36, 0xE0000040)

    # 在 section table 末尾添加
    new_header_off = section_table_off + num_sections * 40
    raw[new_header_off:new_header_off+40] = new_header

    # 更新 NumberOfSections
    struct.pack_into('<H', raw, num_sections_off, num_sections + 1)
    print(f'新 NumberOfSections: {num_sections + 1}')

    # 更新 SizeOfImage
    size_of_image_off = pe_sig_off + 24 + 56  # SizeOfImage 在 OptionalHeader 中
    old_size_of_image = struct.unpack_from('<I', raw, size_of_image_off)[0]
    new_size_of_image = new_va + new_vsize
    struct.pack_into('<I', raw, size_of_image_off, new_size_of_image)
    print(f'SizeOfImage: 0x{old_size_of_image:X} → 0x{new_size_of_image:X}')

    # ==================== 添加 section 数据 ====================
    # 确保文件对齐到 new_rawptr
    while len(raw) < new_rawptr:
        raw += b'\x00'

    # 添加 section 数据
    raw += section_data

    print(f'\n最终文件大小: {len(raw)} 字节 (0x{len(raw):X})')

    # ==================== 保存 ====================
    # 备份
    if not os.path.exists(BACKUP_FILE):
        shutil.copy2(INPUT_FILE, BACKUP_FILE)
        print(f'备份: {BACKUP_FILE}')

    with open(OUTPUT_FILE, 'wb') as f:
        f.write(raw)
    print(f'\n输出: {OUTPUT_FILE}')

    # ==================== 验证 ====================
    print('\n=== 验证修改后的 PE ===')
    pe2 = pefile.PE(OUTPUT_FILE)
    print(f'Sections: {len(pe2.sections)}')
    for s in pe2.sections:
        name = s.Name.rstrip(b'\x00').decode()
        print(f'  {name:10s} VA=0x{s.VirtualAddress:08X} VSize=0x{s.Misc_VirtualSize:08X} '
              f'RawPtr=0x{s.PointerToRawData:08X} RawSize=0x{s.SizeOfRawData:08X}')

    # 验证新跳转表
    jt_check = pe2.get_data(NEW_JT_RVA, 88)
    print(f'\n新跳转表 @0x{imgbase+NEW_JT_RVA:X}:')
    for i in range(11):
        val = struct.unpack('<Q', jt_check[i*8:(i+1)*8])[0]
        print(f'  [{i:2d}] = 0x{val:016X}')

    # 验证 Jinx 函数前 16 字节
    jinx_check = pe2.get_data(JINX_FUNC_RVA, 16)
    ashe_check = pe2.get_data(ASHE_FUNC_RVA, 16)
    print(f'\nJinx 函数前16字节: {jinx_check.hex()}')
    print(f'Ashe 函数前16字节: {ashe_check.hex()}')
    print(f'克隆匹配: {"✓" if jinx_check == ashe_check else "✗"}')

    pe2.close()
    print('\n✅ 移植完成!')


if __name__ == '__main__':
    main()
