#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""验证假点击 v3 机器码"""
import struct
import os

OUTPUT_FILE = r'D:\SRC\SRC\enhr_embedded\enhr_pe2_jinx_fakeclick3.exe'

FAKECLICK_OFFSET = 0x19000
FAKECLICK_RVA = 0x1E800
STATE_RVA = 0x1F000
TIMERFUNC_RVA = 0x14020
TIMERFUNC_RETURN_RVA = 0x14025
SENDINPUT_IAT_RVA = 0x17B08

try:
    from capstone import *
    HAS_CAPSTONE = True
except ImportError:
    HAS_CAPSTONE = False


def main():
    print(f"文件: {OUTPUT_FILE}")
    print(f"假点击函数 RVA: 0x{FAKECLICK_RVA:X}")

    if not os.path.exists(OUTPUT_FILE):
        print("[错误] 文件不存在!")
        return

    with open(OUTPUT_FILE, 'rb') as f:
        f.seek(FAKECLICK_OFFSET)
        code = f.read(256)
    print(f"读取 {len(code)} bytes\n")

    # 手动验证关键修复点
    print("=" * 60)
    print("v3 修复验证")
    print("=" * 60)

    # 1. 原始头部
    assert code[0:5] == b'\x56\x48\x83\xEC\x20', "原始头部错误"
    print("[OK] 1. 原始头部 (push rsi; sub rsp, 20h)")

    # 2. 寄存器保存（v3 新增）
    # push rax(50) push rcx(51) push rdx(52) push r8(41 50) push r9(41 51) push rbx(53)
    expected_save = bytes([0x50, 0x51, 0x52, 0x41, 0x50, 0x41, 0x51, 0x53])
    actual_save = code[5:13]
    assert actual_save == expected_save, f"寄存器保存错误: {actual_save.hex()} vs {expected_save.hex()}"
    print(f"[OK] 2. 寄存器保存: {actual_save.hex()}")

    # 3. 寄存器恢复（v3 新增，在 done label 处）
    # pop rbx(5B) pop r9(41 59) pop r8(41 58) pop rdx(5A) pop rcx(59) pop rax(58)
    expected_restore = bytes([0x5B, 0x41, 0x59, 0x41, 0x58, 0x5A, 0x59, 0x58])
    # 搜索恢复序列
    found_restore = False
    restore_offset = 0
    for i in range(len(code) - 8):
        if code[i:i+8] == expected_restore:
            found_restore = True
            restore_offset = i
            break
    assert found_restore, "未找到寄存器恢复序列!"
    print(f"[OK] 3. 寄存器恢复 @ offset 0x{restore_offset:X}: {expected_restore.hex()}")

    # 4. 栈分配（v3 修复：50h 而非 28h）
    # sub rsp, 50h = 48 83 EC 50
    expected_sub = bytes([0x48, 0x83, 0xEC, 0x50])
    found_sub = False
    sub_offset = 0
    for i in range(len(code) - 4):
        if code[i:i+4] == expected_sub:
            found_sub = True
            sub_offset = i
            break
    assert found_sub, "未找到 sub rsp, 50h"
    print(f"[OK] 4. 栈分配: sub rsp, 50h @ offset 0x{sub_offset:X}")

    # 5. 栈恢复
    # add rsp, 50h = 48 83 C4 50
    expected_add = bytes([0x48, 0x83, 0xC4, 0x50])
    found_add = False
    for i in range(sub_offset, len(code) - 4):
        if code[i:i+4] == expected_add:
            found_add = True
            break
    assert found_add, "未找到 add rsp, 50h"
    print(f"[OK] 5. 栈恢复: add rsp, 50h")

    # 6. jmp TimerFunc+5（最后一条指令）
    # E9 + rel32，目标 0x14025
    # 找最后一个 E9
    last_e9 = -1
    for i in range(len(code) - 5, -1, -1):
        if code[i] == 0xE9:
            rel = struct.unpack('<i', code[i+1:i+5])[0]
            target = FAKECLICK_RVA + i + 5 + rel
            if target == TIMERFUNC_RETURN_RVA:
                last_e9 = i
                break
    assert last_e9 >= 0, "未找到 jmp TimerFunc+5"
    print(f"[OK] 6. jmp TimerFunc+5 @ offset 0x{last_e9:X}")

    # Capstone 反汇编
    if HAS_CAPSTONE:
        print("\n" + "=" * 60)
        print("Capstone 反汇编")
        print("=" * 60)
        md = Cs(CS_ARCH_X86, CS_MODE_64)
        for insn in md.disasm(code, FAKECLICK_RVA):
            rip_note = ""
            if 'rip' in insn.op_str:
                import re
                m = re.search(r'\[rip[+-]0x([0-9a-fA-F]+)\]', insn.op_str)
                if m:
                    disp = int(m.group(1), 16)
                    if '-' in insn.op_str and 'rip-' in insn.op_str:
                        disp = -disp
                    target = insn.address + insn.size + disp
                    rip_note = f"  ; -> 0x{target:X}"
            print(f"  0x{insn.address:X}: {insn.mnemonic} {insn.op_str}{rip_note}")
            if insn.mnemonic == 'jmp' and '0x' in insn.op_str:
                try:
                    target = int(insn.op_str.split('0x')[1], 16)
                    if target == TIMERFUNC_RETURN_RVA:
                        print(f"  ; ^ jmp TimerFunc+5 OK")
                        break
                except:
                    pass

    print("\n" + "=" * 60)
    print("[成功] v3 所有关键修复验证通过")
    print("=" * 60)


if __name__ == '__main__':
    main()
