#!/usr/bin/env python3
"""
flyinput.dll 深度分析 v3
- 提取所有 GetAsyncKeyState 调用和虚拟键码
- 提取所有游戏内存偏移
- 分析英雄专属逻辑
- 分析结构体布局
"""

import pefile
from capstone import *
from capstone.x86 import *
import struct
import re

pe = pefile.PE(r"D:\SRC\SRC\enhr_embedded\enhr_pe2_unpacked.exe")
IMAGE_BASE = 0x180000000

# 获取段数据
text_section = pe.sections[0]  # .text
text_data = text_section.get_data()
text_va = text_section.VirtualAddress

# 字符串表
strings = {}
for s in pe.sections:
    data = s.get_data()
    va = s.VirtualAddress
    current = bytearray()
    current_offset = 0
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7F:
            if len(current) == 0:
                current_offset = i
            current.append(b)
        else:
            if len(current) >= 4:
                s_str = current.decode('ascii', errors='replace')
                strings[IMAGE_BASE + va + current_offset] = s_str
            current = bytearray()
    if len(current) >= 4:
        s_str = current.decode('ascii', errors='replace')
        strings[IMAGE_BASE + va + current_offset] = s_str

# 导入表 IAT 地址
iat_entries = {}
if hasattr(pe, 'DIRECTORY_ENTRY_IMPORT'):
    for entry in pe.DIRECTORY_ENTRY_IMPORT:
        dll = entry.dll.decode('utf-8', errors='replace')
        for imp in entry.imports:
            if imp.name:
                name = imp.name.decode('utf-8', errors='replace')
            else:
                name = f"Ordinal({imp.ordinal})"
            iat_entries[IMAGE_BASE + imp.address] = name

# 获取 IAT 地址
GETASYNCKEYSTATE_IAT = None
SENDINPUT_IAT = None
SETTIMER_IAT = None
KILLTIMER_IAT = None
MAPVIRTUALKEY_IAT = None
for addr, name in iat_entries.items():
    if name == 'GetAsyncKeyState':
        GETASYNCKEYSTATE_IAT = addr
    elif name == 'SendInput':
        SENDINPUT_IAT = addr
    elif name == 'SetTimer':
        SETTIMER_IAT = addr
    elif name == 'KillTimer':
        KILLTIMER_IAT = addr
    elif name == 'MapVirtualKeyA':
        MAPVIRTUALKEY_IAT = addr

print(f"GetAsyncKeyState IAT: {hex(GETASYNCKEYSTATE_IAT)}")
print(f"SendInput IAT: {hex(SENDINPUT_IAT)}")
print(f"SetTimer IAT: {hex(SETTIMER_IAT)}")
print(f"KillTimer IAT: {hex(KILLTIMER_IAT)}")
print(f"MapVirtualKeyA IAT: {hex(MAPVIRTUALKEY_IAT)}")

# 创建反汇编器
md = Cs(CS_ARCH_X86, CS_MODE_64)
md.detail = True
md.syntax = CS_OPT_SYNTAX_INTEL

# VK_ 键码映射
vk_names = {
    0x01: 'VK_LBUTTON', 0x02: 'VK_RBUTTON', 0x04: 'VK_MBUTTON',
    0x08: 'VK_BACK', 0x09: 'VK_TAB', 0x0D: 'VK_RETURN',
    0x10: 'VK_SHIFT', 0x11: 'VK_CONTROL', 0x12: 'VK_MENU',
    0x13: 'VK_PAUSE', 0x14: 'VK_CAPITAL', 0x1B: 'VK_ESCAPE',
    0x20: 'VK_SPACE',
    0x21: 'VK_PRIOR', 0x22: 'VK_NEXT', 0x23: 'VK_END',
    0x24: 'VK_HOME', 0x25: 'VK_LEFT', 0x26: 'VK_UP',
    0x27: 'VK_RIGHT', 0x28: 'VK_DOWN',
    0x2D: 'VK_INSERT', 0x2E: 'VK_DELETE',
    0x30: 'VK_0', 0x31: 'VK_1', 0x32: 'VK_2', 0x33: 'VK_3',
    0x34: 'VK_4', 0x35: 'VK_5', 0x36: 'VK_6', 0x37: 'VK_7',
    0x38: 'VK_8', 0x39: 'VK_9',
    0x41: 'VK_A', 0x42: 'VK_B', 0x43: 'VK_C', 0x44: 'VK_D',
    0x45: 'VK_E', 0x46: 'VK_F', 0x47: 'VK_G', 0x48: 'VK_H',
    0x49: 'VK_I', 0x4A: 'VK_J', 0x4B: 'VK_K', 0x4C: 'VK_L',
    0x4D: 'VK_M', 0x4E: 'VK_N', 0x4F: 'VK_O', 0x50: 'VK_P',
    0x51: 'VK_Q', 0x52: 'VK_R', 0x53: 'VK_S', 0x54: 'VK_T',
    0x55: 'VK_U', 0x56: 'VK_V', 0x57: 'VK_W', 0x58: 'VK_X',
    0x59: 'VK_Y', 0x5A: 'VK_Z',
    0x70: 'VK_F1', 0x71: 'VK_F2', 0x72: 'VK_F3',
    0x73: 'VK_F4', 0x74: 'VK_F5', 0x75: 'VK_F6',
    0x76: 'VK_F7', 0x77: 'VK_F8', 0x78: 'VK_F9',
    0x79: 'VK_F10', 0x7A: 'VK_F11', 0x7B: 'VK_F12',
    0xA0: 'VK_LSHIFT', 0xA1: 'VK_RSHIFT',
    0xA2: 'VK_LCONTROL', 0xA3: 'VK_RCONTROL',
    0xA4: 'VK_LMENU', 0xA5: 'VK_RMENU',
    0xBB: 'VK_OEM_PLUS', 0xBD: 'VK_OEM_MINUS',
    0xBE: 'VK_OEM_PERIOD', 0xBF: 'VK_OEM_2',
    0xC0: 'VK_OEM_3', 0xDB: 'VK_OEM_4', 0xDC: 'VK_OEM_5',
    0xDD: 'VK_OEM_6', 0xDE: 'VK_OEM_7',
}

# 反汇编整个.text段
print("\n" + "=" * 100)
print("分析 GetAsyncKeyState 调用 - 提取所有虚拟键码")
print("=" * 100)

all_insns = list(md.disasm(text_data, IMAGE_BASE + text_va))

vk_calls = []
# 对于每个 call GetAsyncKeyState，往前找 ecx 的设置
for i, insn in enumerate(all_insns):
    if insn.mnemonic == 'call' and insn.op_str.startswith('0x'):
        target = int(insn.op_str, 16)
        if target == GETASYNCKEYSTATE_IAT:
            # 反向查找 ecx (第一个参数) 的设置
            vk = None
            for j in range(i-1, max(0, i-10), -1):
                prev = all_insns[j]
                if prev.mnemonic == 'mov' and ('ecx' in prev.op_str or 'cx' in prev.op_str):
                    # 提取立即数
                    match = re.search(r'(0x[0-9a-fA-F]+|\d+)', prev.op_str.split(',')[-1].strip())
                    if match:
                        vk = int(match.group(1), 16 if '0x' in match.group(1) else 10)
                        break
                elif prev.mnemonic == 'xor' and 'ecx' in prev.op_str and 'ecx' in prev.op_str:
                    vk = 0
                    break
            if vk is not None:
                vk_name = vk_names.get(vk, f'0x{vk:02X}')
                func_rva = insn.address - IMAGE_BASE
                vk_calls.append((func_rva, vk, vk_name, insn.address))

print(f"\n找到 {len(vk_calls)} 个 GetAsyncKeyState 调用:\n")
for rva, vk, vk_name, addr in sorted(set(vk_calls)):
    print(f"  RVA 0x{rva:05X}: GetAsyncKeyState({vk_name}) - VK=0x{vk:02X}")

# 分析 SendInput 调用
print("\n" + "=" * 100)
print("分析 SendInput 调用")
print("=" * 100)

# 分析游戏内存偏移
print("\n" + "=" * 100)
print("分析游戏内存偏移 (从基址偏移)")
print("=" * 100)

# 收集所有 lea rcx, [rax + offset] 和 mov rdx, [rax + offset] 模式
offsets = set()
for insn in all_insns:
    if insn.mnemonic in ['mov', 'lea']:
        op_str = insn.op_str
        # 匹配 [reg + 0xXXXXXXXX] 模式
        for match in re.finditer(r'\[(\w+)\s*\+\s*(0x[0-9a-fA-F]+)\]', op_str):
            reg = match.group(1)
            off = int(match.group(2), 16)
            if off > 0x100000:  # 大偏移，可能是游戏内存
                offsets.add(off)
        # 匹配 [reg + 0xXXXXXXXX] 含乘法的
        for match in re.finditer(r'\[(\w+)\s*\+\s*(\w+)\*(\d)\s*\+\s*(0x[0-9a-fA-F]+)\]', op_str):
            off = int(match.group(4), 16)
            if off > 0x100000:
                offsets.add(off)

# 静态分析 - 直接从代码中提取已知偏移
known_offsets = set()
for insn in all_insns:
    if insn.mnemonic in ['mov', 'lea', 'add']:
        for match in re.finditer(r'0x[0-9a-fA-F]{5,8}', insn.op_str):
            val = int(match.group(0), 16)
            if 0x100000 <= val <= 0x3FFFFFFF:
                known_offsets.add(val)

print("\n从指令中提取的偏移常量:")
for off in sorted(known_offsets):
    print(f"  0x{off:08X}")

# 分析关键字符串引用
print("\n" + "=" * 100)
print("分析英雄相关字符串引用")
print("=" * 100)

hero_strings = [
    'PickACar', 'BlueCard', 'GoldCard', 'RedCard',  # 卡牌
    'AsheQCasM9', 'Ashe',  # 寒冰
    'KaisaE', 'Kaisa',  # 卡莎
    'kalistae', 'Kalista',  # 卡莉斯塔
    'TwitchDe', 'Twitch',  # 老鼠
    'sru_drag', 'SRU_Baro', 'SRU_Atak',  # 野怪
    'PickACarI98',  # 卡牌变体
]

for hero_str in hero_strings:
    found = False
    for addr, s in strings.items():
        if hero_str in s:
            found = True
            rva = addr - IMAGE_BASE
            print(f"\n  字符串: \"{s}\"")
            print(f"  位置: RVA 0x{rva:05X}")
            # 查找引用
            for insn in all_insns:
                if insn.mnemonic == 'lea':
                    # 检查 RIP 相对寻址
                    match = re.search(r'rip\s*([\+\-])\s*(0x[0-9a-fA-F]+)', insn.op_str)
                    if match:
                        off = int(match.group(2), 16)
                        if match.group(1) == '-':
                            off = -off
                        target_va = insn.address + insn.size + off
                        if target_va == addr:
                            func_rva = insn.address - IMAGE_BASE
                            print(f"  引用位置: RVA 0x{func_rva:05X}: {insn.mnemonic} {insn.op_str}")

# 分析结构体布局
print("\n" + "=" * 100)
print("分析结构体布局")
print("=" * 100)

# 从 sub_180001180 中分析结构体字段
# 观察到的结构体访问模式:
# [rsi + 0x20] - 对比 VK_SPACE (0x20)，这是结构体字段而不是VK码
# [r14 + 0x28] - 对比 0x28
# [r14 + 0x30] - 对比 0x30
# [r14 + 0x38] - 对比 0x38
# [rax + 0x10] - 对比 0x10

print("""
从 sub_180001180 中观察到的结构体:
struct HeroConfig {
    +0x00: ???
    +0x10: ??? (可能是 VK_SHIFT 相关)
    +0x20: ??? (可能是 VK_SPACE 相关 - 走砍键)
    +0x28: ??? (可能是另一个键绑定)
    +0x30: ??? (可能是另一个键绑定)
    +0x38: ??? (可能是另一个键绑定)
};
""")

# 分析 sub_180001180 中的核心逻辑
print("\n" + "=" * 100)
print("sub_180001180 核心逻辑分析")
print("=" * 100)

print("""
这个函数是反作弊/反调试检测函数:
1. 调用 GetModuleHandleA("ntdll.dll") 获取ntdll
2. 调用 GetProcAddress(ntdll, "NtSetInformationThread") 获取函数地址
3. 调用 GetCurrentThread() 获取当前线程
4. 调用 NtSetInformationThread(thread, 0x11, 0, 0) - ThreadHideFromDebugger
5. 如果失败 (eax==0)，则跳转到正常逻辑
6. 正常逻辑中:
   - 调用一些函数获取游戏状态
   - 比较值 0x16e3600 和 0x989680 (可能是游戏版本检测)
   - 使用 0x3b9aca00 (1,000,000,000) 进行时间/计数计算
   - 通过 [base + 0x1ead040] 等偏移访问游戏内存
   - 使用 0x5265c00 和 0x4e94914f0000 等魔法数字
""")

# 分析 TimerFunc (0x14020)
print("\n" + "=" * 100)
print("TimerFunc (0x14020) 分析")
print("=" * 100)

# 找到 TimerFunc 的指令
timer_insns = [i for i in all_insns if 0x14020 <= i.address - IMAGE_BASE < 0x14240]
for insn in timer_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 StartAddress (0x12C10)
print("\n" + "=" * 100)
print("StartAddress 线程入口 (0x12C10) 分析")
print("=" * 100)

start_insns = [i for i in all_insns if 0x12C10 <= i.address - IMAGE_BASE < 0x12DA0]
for insn in start_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_180012700 (初始化)
print("\n" + "=" * 100)
print("sub_180012700 初始化函数")
print("=" * 100)

init_insns = [i for i in all_insns if 0x12700 <= i.address - IMAGE_BASE < 0x12960]
for insn in init_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_180012DA0 (游戏内存读写)
print("\n" + "=" * 100)
print("sub_180012DA0 游戏内存读写")
print("=" * 100)

mem_insns = [i for i in all_insns if 0x12DA0 <= i.address - IMAGE_BASE < 0x13070]
for insn in mem_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_1800134E0 (主循环)
print("\n" + "=" * 100)
print("sub_1800134E0 主循环")
print("=" * 100)

loop_insns = [i for i in all_insns if 0x134E0 <= i.address - IMAGE_BASE < 0x13E90]
for insn in loop_insns[:120]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_1800150E0 (PickACard - 卡牌切牌)
print("\n" + "=" * 100)
print("sub_1800150E0 卡牌切牌 (PickACarI98)")
print("=" * 100)

pick_insns = [i for i in all_insns if 0x150E0 <= i.address - IMAGE_BASE < 0x15490]
for insn in pick_insns[:100]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_1800049F0 (寒冰/卡莎处理)
print("\n" + "=" * 100)
print("sub_1800049F0 大处理函数")
print("=" * 100)

proc_insns = [i for i in all_insns if 0x49F0 <= i.address - IMAGE_BASE < 0x4BB0]
for insn in proc_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_180004BB0 (含 "AsheQCasM9")
print("\n" + "=" * 100)
print("sub_180004BB0 含 'AsheQCasM9'")
print("=" * 100)

ashe_insns = [i for i in all_insns if 0x4BB0 <= i.address - IMAGE_BASE < 0x6130]
for insn in ashe_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

# 分析 sub_180006130 (含 "KaisaE")
print("\n" + "=" * 100)
print("sub_180006130 含 'KaisaE'")
print("=" * 100)

kaisa_insns = [i for i in all_insns if 0x6130 <= i.address - IMAGE_BASE < 0x76B0]
for insn in kaisa_insns[:80]:
    rva = insn.address - IMAGE_BASE
    print(f"  {rva:05X}: {insn.mnemonic:8s} {insn.op_str}")

pe.close()