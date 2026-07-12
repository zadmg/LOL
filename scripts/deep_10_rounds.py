"""
MJTVPFeD.dat 10轮深度源码分析
每轮输出到独立文件,层层递进深入
"""
import sys, os, re, struct

sys.path.append(r'D:\SRC\Tools\idapro93\python')
os.environ['IDAUSR'] = r'D:\SRC\Tools\idapro93'
os.environ['IDADIR'] = r'D:\SRC\Tools\idapro93'

import idapro, idautils, ida_bytes, ida_nalt, ida_funcs, ida_segment
import ida_hexrays, ida_entry, ida_name, idc, ida_idaapi, ida_ua, ida_lines, ida_xref

OUT = r'D:\SRC\SRC\deep_rounds'
os.makedirs(OUT, exist_ok=True)

def log_file(round_name, content):
    path = os.path.join(OUT, f'{round_name}.txt')
    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)
    print(f"  -> {path} ({len(content)} bytes)")

def log_file_append(round_name, content):
    path = os.path.join(OUT, f'{round_name}.txt')
    with open(path, 'a', encoding='utf-8') as f:
        f.write(content)

# ============================================================
# ROUND 1: flyinput sub_180001180 调用链全追踪
# ============================================================
def round1():
    print("Round 1: sub_180001180 调用链全追踪")
    path = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 1: flyinput.dll sub_180001180 完整调用链追踪")
    out.append("=" * 80)

    # 从 sub_180001180 开始递归追踪所有调用
    visited = set()
    call_order = []

    def trace_calls(ea, depth=0):
        if ea in visited or depth > 10:
            return
        visited.add(ea)
        f = ida_funcs.get_func(ea)
        if not f:
            return
        name = ida_funcs.get_func_name(ea)
        call_order.append((depth, ea, f.end_ea, name))
        # 找该函数内的所有调用
        cur = ea
        while cur < f.end_ea:
            insn = ida_ua.insn_t()
            length = ida_ua.decode_insn(insn, cur)
            if length == 0:
                cur += 1
                continue
            # 检查是否是 call (通过 mnemonic)
            mnem = idc.print_insn_mnem(cur)
            if mnem == 'call':
                for xref in idautils.XrefsFrom(cur, 0):
                    if xref.iscode:
                        target = xref.to
                        t_func = ida_funcs.get_func(target)
                        if t_func:
                            trace_calls(target, depth + 1)
            cur += length

    # 从主函数开始
    trace_calls(0x180001180)

    prefix = "  "
    for depth, ea, end_ea, name in call_order:
        indent = prefix * depth
        out.append(f"{indent}[d={depth}] 0x{ea:X} {name} (0x{end_ea-ea:X} bytes)")

    out.append(f"\nTotal unique callees: {len(visited)}")

    # 反编译主函数开头(前200行)
    out.append("\n\n=== sub_180001180 反编译开头 ===")
    try:
        cfunc = ida_hexrays.decompile(0x180001180)
        lines = str(cfunc).split('\n')
        for l in lines[:200]:
            out.append(l)
    except:
        out.append("(decompile failed)")

    idapro.close_database(False)
    log_file("round1_calltrace", '\n'.join(out))

# ============================================================
# ROUND 2: TimerFunc + SendInput 按键模拟链
# ============================================================
def round2():
    print("Round 2: TimerFunc + SendInput 按键模拟链")
    path = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 2: TimerFunc + SendInput 按键模拟链深度分析")
    out.append("=" * 80)

    # 反编译 TimerFunc
    out.append("\n=== TimerFunc (0x180014020) 完整反编译 ===")
    try:
        cfunc = ida_hexrays.decompile(0x180014020)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 StartAddress (线程函数)
    out.append("\n\n=== StartAddress (0x180012C10) 完整反编译 ===")
    try:
        cfunc = ida_hexrays.decompile(0x180012C10)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180012700 (靠近 StartAddress)
    out.append("\n\n=== sub_180012700 (0x180012700) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180012700)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180012960
    out.append("\n\n=== sub_180012960 (0x180012960) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180012960)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180012DA0
    out.append("\n\n=== sub_180012DA0 (0x180012DA0) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180012DA0)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180013070
    out.append("\n\n=== sub_180013070 (0x180013070) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180013070)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_1800134E0 (最大的辅助函数)
    out.append("\n\n=== sub_1800134E0 (0x1800134E0, 0x95A bytes) ===")
    try:
        cfunc = ida_hexrays.decompile(0x1800134E0)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180013F80
    out.append("\n\n=== sub_180013F80 (0x180013F80) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180013F80)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180013E90
    out.append("\n\n=== sub_180013E90 (0x180013E90) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180013E90)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 Function (0x180013E40)
    out.append("\n\n=== Function (0x180013E40) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180013E40)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_1800133E0
    out.append("\n\n=== sub_1800133E0 (0x1800133E0) ===")
    try:
        cfunc = ida_hexrays.decompile(0x1800133E0)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180012D60, sub_180012D80, sub_180012D90
    for addr in [0x180012D60, 0x180012D80, 0x180012D90]:
        out.append(f"\n\n=== sub_0x{addr:X} ({addr:#x}) ===")
        try:
            cfunc = ida_hexrays.decompile(addr)
            out.append(str(cfunc))
        except Exception as e:
            out.append(f"Error: {e}")

    idapro.close_database(False)
    log_file("round2_timerfunc_sendinput", '\n'.join(out))

# ============================================================
# ROUND 3: FNV-1a 哈希值反向解析 + 所有比较分支
# ============================================================
def round3():
    print("Round 3: FNV-1a 哈希值反向解析")
    path = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 3: FNV-1a 哈希值反向解析 + 所有比较分支")
    out.append("=" * 80)

    # 反编译 sub_180001180 中所有 FNV 比较部分
    out.append("\n=== sub_180001180 完整反编译 (搜索 FNV) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180001180)
        code = str(cfunc)
        out.append(code)
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_1800147A0 (FNV-1a 哈希计算函数)
    out.append("\n\n=== sub_1800147A0 (FNV-1a 哈希计算) ===")
    try:
        cfunc = ida_hexrays.decompile(0x1800147A0)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_1800149F0
    out.append("\n\n=== sub_1800149F0 (0x1800149F0, 0x602 bytes) ===")
    try:
        cfunc = ida_hexrays.decompile(0x1800149F0)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译 sub_180014240
    out.append("\n\n=== sub_180014240 (0x180014240, 0x535 bytes) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180014240)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 提取所有 FNV-1a 常量
    out.append("\n\n=== FNV-1a 哈希常量分析 ===")
    out.append("FNV prime: 0x100000001B3")
    out.append("FNV basis: 0xCBF29CE484222325")
    out.append("")
    # 从反编译结果中提取所有 0x100000001B3 乘法
    for line in code.split('\n'):
        if '0x100000001B3' in line or '0xCBF29CE484222325' in line:
            out.append(f"  {line.strip()}")

    # 提取所有哈希比较值
    out.append("\n\n=== 哈希比较分支表 ===")
    hash_values = [
        (0x112D788B5B855BEE, 0x112D788B5B855BED),
        (0x19BF8DB558FEDB42, 0x19BF8DB558FEDB41),
        (0x1A47746099CAAD97, 0x1A47746099CAAD96),
        (0x77EE2DDFA384BEA0, 0x77EE2DDFA384BE9F),
        (0x7A22BC4C07AC1888, 0x7A22BC4C07AC1887),
        (0x98DD22A3CCBC7773, 0x98DD22A3CCBC7772),
        (0xAD1C144669DB1514, 0xAD1C144669DB1513),
        (0xB173594E60E46B49, 0xB173594E60E46B48),
        (0xDE3BC2BFB3A73E2A, 0xDE3BC2BFB3A73E29),
        (0x0D1C29E7AD935C17, 0x0D1C29E7AD935C16),
    ]
    for val, threshold in hash_values:
        out.append(f"  Hash: 0x{val:016X} (threshold 0x{threshold:016X}) -> code at unk_1800172XX")

    # 反编译所有 10 个子逻辑函数
    sub_funcs = [
        0x180004BB0, 0x180006130, 0x1800076B0, 0x180008CD0, 0x18000A3A0,
        0x18000B8D0, 0x18000CE80, 0x18000E660, 0x18000FC20, 0x1800111D0,
    ]
    for i, addr in enumerate(sub_funcs):
        out.append(f"\n\n=== 子逻辑 {i+1}: sub_0x{addr:X} ===")
        try:
            cfunc = ida_hexrays.decompile(addr)
            out.append(str(cfunc))
        except Exception as e:
            out.append(f"Error: {e}")

    idapro.close_database(False)
    log_file("round3_fnv_hash_analysis", '\n'.join(out))

# ============================================================
# ROUND 4: 游戏内存偏移结构体完整还原
# ============================================================
def round4():
    print("Round 4: 游戏内存偏移结构体还原")
    path = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 4: 游戏内存偏移结构体完整还原")
    out.append("=" * 80)

    # 反编译 sub_180001180 中所有偏移访问并提取
    out.append("\n=== 从 sub_180001180 提取所有内存偏移访问 ===")
    try:
        cfunc = ida_hexrays.decompile(0x180001180)
        code = str(cfunc)
        # 提取所有 *((_QWORD *)_RAX + ...) 和 *(_QWORD *)(... + ...) 模式
        offsets = set()
        for line in code.split('\n'):
            # 匹配各种偏移模式
            m = re.findall(r'[+]\s*(\d+)LL?\s*[)]', line)
            for mm in m:
                offsets.add(int(mm))
            m = re.findall(r'[+]\s*(\d+)\s*[)]', line)
            for mm in m:
                offsets.add(int(mm))
        sorted_offsets = sorted(offsets)
        out.append(f"\nTotal unique offsets: {len(sorted_offsets)}")
        out.append("")
        for off in sorted_offsets:
            out.append(f"  +{off:>10d} (0x{off:08X})")
    except Exception as e:
        out.append(f"Error: {e}")

    # 从主函数中提取大偏移(>1000000)
    out.append("\n\n=== 大偏移访问 (游戏数据区) ===")
    try:
        big_offsets = []
        for line in code.split('\n'):
            m = re.findall(r'[+]\s*(\d{7,})', line)
            for mm in m:
                v = int(mm)
                if v > 1000000:
                    big_offsets.append((v, line.strip()))
        for v, line in sorted(set(big_offsets)):
            out.append(f"  +{v:>10d} (0x{v:08X}): {line[:120]}")
    except:
        pass

    # 反编译 sub_180001180 结尾部分(主循环)
    out.append("\n\n=== sub_180001180 完整反编译 ===")
    try:
        out.append(code)
    except:
        pass

    idapro.close_database(False)
    log_file("round4_memory_offsets", '\n'.join(out))

# ============================================================
# ROUND 5: 线程创建/同步/互斥锁
# ============================================================
def round5():
    print("Round 5: 线程创建/同步/互斥锁")
    path = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 5: 线程创建/同步/互斥锁完整分析")
    out.append("=" * 80)

    # 反编译所有 Concurrency/thread 相关函数
    thread_funcs = [
        (0x180015040, "Concurrency::agent::~agent"),
        (0x180015690, "Concurrency::agent::~agent (2)"),
        (0x1800156E0, "Concurrency::cancel_current_task"),
        (0x180015700, "Concurrency::cancel_current_task (2)"),
        (0x180015730, "sub_180015730 (Concurrency scheduler)"),
        (0x180015000, "sub_180015000"),
        (0x180015060, "sub_180015060"),
        (0x1800150A0, "sub_1800150A0"),
        (0x1800150E0, "sub_1800150E0"),
        (0x180015200, "sub_180015200"),
        (0x180015290, "sub_180015290"),
        (0x1800152C0, "sub_1800152C0"),
        (0x180015300, "sub_180015300"),
        (0x1800153A0, "sub_1800153A0"),
        (0x1800153F0, "sub_1800153F0"),
        (0x180015420, "sub_180015420"),
        (0x180015460, "sub_180015460"),
        (0x180015490, "sub_180015490"),
        (0x1800154E0, "sub_1800154E0"),
        (0x180015560, "sub_180015560"),
        (0x1800155A0, "sub_1800155A0"),
        (0x1800155E0, "sub_1800155E0"),
        (0x180015600, "sub_180015600"),
        (0x180015630, "sub_180015630"),
        (0x180015660, "sub_180015660"),
        (0x1800156B0, "sub_1800156B0"),
        (0x1800159E0, "sub_1800159E0"),
        (0x1800159F0, "?__uncaught_exception@@YA_NXZ"),
        (0x180015A20, "sub_180015A20"),
        (0x180015B30, "sub_180015B30"),
        (0x180015BD0, "sub_180015BD0"),
        (0x180015C30, "sub_180015C30"),
    ]
    for addr, name in thread_funcs:
        out.append(f"\n\n=== {name} (0x{addr:X}) ===")
        try:
            cfunc = ida_hexrays.decompile(addr)
            out.append(str(cfunc))
        except Exception as e:
            out.append(f"Error: {e}")

    idapro.close_database(False)
    log_file("round5_threads_sync", '\n'.join(out))

# ============================================================
# ROUND 6: DLL入口 + 初始化链
# ============================================================
def round6():
    print("Round 6: DLL入口 + 初始化链")
    path = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 6: DLL入口 + 初始化链完整分析")
    out.append("=" * 80)

    # 反编译 DllEntryPoint
    out.append("\n=== DllEntryPoint (0x180015D70) ===")
    try:
        cfunc = ida_hexrays.decompile(0x180015D70)
        out.append(str(cfunc))
    except Exception as e:
        out.append(f"Error: {e}")

    # 反编译初始化链
    init_funcs = [
        0x180015DB0, 0x180015E70, 0x180015E80, 0x180015E90,
        0x180015EB0, 0x180015EC0, 0x180015ED0, 0x180015EE0,
        0x180015F30, 0x180015F80, 0x180015F90,
    ]
    for addr in init_funcs:
        f = ida_funcs.get_func(addr)
        if f:
            name = ida_funcs.get_func_name(addr)
            out.append(f"\n\n=== {name} (0x{addr:X}) ===")
            try:
                cfunc = ida_hexrays.decompile(addr)
                out.append(str(cfunc))
            except Exception as e:
                out.append(f"Error: {e}")

    # 反编译 sub_180001000, sub_180001080, sub_180001100 (前3个小函数)
    for addr in [0x180001000, 0x180001080, 0x180001100]:
        out.append(f"\n\n=== sub_0x{addr:X} ===")
        try:
            cfunc = ida_hexrays.decompile(addr)
            out.append(str(cfunc))
        except Exception as e:
            out.append(f"Error: {e}")

    idapro.close_database(False)
    log_file("round6_dll_entry_init", '\n'.join(out))

# ============================================================
# ROUND 7: 外层 PE 文件释放/注册表/进程枚举全流程
# ============================================================
def round7():
    print("Round 7: 外层 PE 全流程")
    path = r'D:\SRC\SRC\MJTVPFeD_dumped.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 7: 外层 PE 文件释放/注册表/进程枚举全流程")
    out.append("=" * 80)

    # 反编译所有外层函数
    funcs = [
        (0x7FF71BC61F60, "sub_7FF71BC61F60"),
        (0x7FF71BC61F80, "sub_7FF71BC61F80"),
        (0x7FF71BC655E0, "sub_7FF71BC655E0 (path append)"),
        (0x7FF71BC65CE0, "sub_7FF71BC65CE0 (main path logic)"),
        (0x7FF71BC662C0, "sub_7FF71BC662C0 (path resize)"),
        (0x7FF71BC663E0, "sub_7FF71BC663E0"),
        (0x7FF71BC66400, "sub_7FF71BC66400 (path expand)"),
        (0x7FF71BC689E0, "sub_7FF71BC689E0 (malloc)"),
        (0x7FF71BC68A30, "sub_7FF71BC68A30 (free)"),
        (0x7FF71BC69770, "start"),
        (0x7FF71BC69820, "sub_7FF71BC69820"),
        (0x7FF71BC699A0, "sub_7FF71BC699A0"),
        (0x7FF71BC6A0D0, "sub_7FF71BC6A0D0"),
        (0x7FF71BC6A0E0, "sub_7FF71BC6A0E0 (main init)"),
        (0x7FF71BC6A710, "sub_7FF71BC6A710 (destructor)"),
        (0x7FF71BC6A790, "sub_7FF71BC6A790 (memcpy_t)"),
        (0x7FF71BC6A7A0, "sub_7FF71BC6A7A0 (thunk)"),
    ]
    for addr, name in funcs:
        out.append(f"\n\n=== {name} (0x{addr:X}) ===")
        try:
            cfunc = ida_hexrays.decompile(addr)
            out.append(str(cfunc))
        except Exception as e:
            out.append(f"Error: {e}")

    # 提取所有 API 调用 xref
    out.append("\n\n=== API 调用交叉引用 ===")
    imports = [
        "CreateFileA", "WriteFile", "ShellExecuteA", "CreateProcessA",
        "RegOpenKeyExA", "RegQueryValueExA", "OpenProcess",
        "CreateToolhelp32Snapshot", "Process32First", "Process32Next",
        "QueryFullProcessImageNameA", "LoadLibraryA", "GetProcAddress",
        "VirtualProtect", "MessageBoxA",
    ]
    for imp_name in imports:
        out.append(f"\n--- {imp_name} ---")
        for ea in idautils.Strings():
            try:
                if str(ea) == imp_name:
                    for xref in idautils.XrefsTo(ea.ea):
                        f = ida_funcs.get_func(xref.frm)
                        if f:
                            out.append(f"  xref from 0x{xref.frm:X} in {ida_funcs.get_func_name(f.start_ea)}")
                        else:
                            out.append(f"  xref from 0x{xref.frm:X}")
            except:
                pass

    idapro.close_database(False)
    log_file("round7_outer_pe_full", '\n'.join(out))

# ============================================================
# ROUND 8: 假 dbgcore 转发机制 + 导出函数全路径
# ============================================================
def round8():
    print("Round 8: 假 dbgcore 转发机制")
    path = r'D:\SRC\SRC\embedded_pe\embedded_1_at_0xC7F0.exe_unpacked.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 8: 假 dbgcore.dll 转发机制 + 导出函数全路径")
    out.append("=" * 80)

    # 反编译所有函数
    funcs = []
    for ea in idautils.Functions():
        f = ida_funcs.get_func(ea)
        if f:
            name = ida_funcs.get_func_name(ea)
            funcs.append((ea, f.end_ea, name))

    for ea, end_ea, name in funcs:
        out.append(f"\n\n=== {name} (0x{ea:X} - 0x{end_ea:X}) ===")
        try:
            cfunc = ida_hexrays.decompile(ea)
            out.append(str(cfunc))
        except Exception as e:
            out.append(f"Error: {e}")

    # 导出详情
    out.append("\n\n=== 导出函数详情 ===")
    qty = ida_entry.get_entry_qty()
    for i in range(qty):
        ord_num = ida_entry.get_entry_ordinal(i)
        ea = ida_entry.get_entry(ord_num)
        name = ida_entry.get_entry_name(ord_num)
        out.append(f"  #{ord_num}: 0x{ea:X} {name}")
        # 反编译导出函数
        try:
            cfunc = ida_hexrays.decompile(ea)
            out.append(f"    {str(cfunc).replace(chr(10), chr(10) + '    ')}")
        except:
            pass

    # 数据段分析(全局变量 qword_180003158, qword_180003160, qword_180003170)
    out.append("\n\n=== 全局变量分析 ===")
    globals_of_interest = [0x180003158, 0x180003160, 0x180003170, 0x1800030E0]
    for gva in globals_of_interest:
        out.append(f"\n  Global at 0x{gva:X}:")
        for xref in idautils.XrefsTo(gva):
            f = ida_funcs.get_func(xref.frm)
            if f:
                out.append(f"    xref from 0x{xref.frm:X} in {ida_funcs.get_func_name(f.start_ea)} (type={xref.type})")
            else:
                out.append(f"    xref from 0x{xref.frm:X} (type={xref.type})")
        # 读取当前值
        data = ida_bytes.get_bytes(gva, 8)
        if data:
            val = struct.unpack_from('<Q', data)[0] if len(data) >= 8 else 0
            out.append(f"    current value: 0x{val:016X}")

    idapro.close_database(False)
    log_file("round8_dbgcore_forwarding", '\n'.join(out))

# ============================================================
# ROUND 9: 16.13.exe 嵌入 MJTVPFeD 的提取逻辑
# ============================================================
def round9():
    print("Round 9: 16.13.exe 嵌入 MJTVPFeD 提取逻辑")
    path = r'D:\SRC\SRC\16.13.exe'
    idapro.open_database(path, True)
    out = []
    out.append("=" * 80)
    out.append("ROUND 9: 16.13.exe 嵌入 MJTVPFeD 的提取逻辑")
    out.append("=" * 80)

    # 搜索 MJTVPFeD 相关字符串
    out.append("\n=== 搜索 MJTVPFeD 相关字符串 ===")
    for s in idautils.Strings():
        try:
            sv = str(s)
            if any(kw in sv.lower() for kw in ['mjtvpfed', 'flypy', 'dbgcore', 'flyinput', '.dat']):
                out.append(f"  0x{s.ea:X}: {sv!r}")
                for xref in idautils.XrefsTo(s.ea):
                    f = ida_funcs.get_func(xref.frm)
                    if f:
                        out.append(f"    xref from 0x{xref.frm:X} in {ida_funcs.get_func_name(f.start_ea)}")
                    else:
                        out.append(f"    xref from 0x{xref.frm:X}")
        except:
            pass

    # 搜索 CreateFileA / WriteFile 的 xref
    out.append("\n\n=== WriteFile xref (释放 MJTVPFeD) ===")
    for s in idautils.Strings():
        try:
            if str(s) == 'WriteFile':
                for xref in idautils.XrefsTo(s.ea):
                    f = ida_funcs.get_func(xref.frm)
                    if f:
                        func_name = ida_funcs.get_func_name(f.start_ea)
                        out.append(f"  WriteFile xref from 0x{xref.frm:X} in {func_name}")
                        # 反编译该函数
                        out.append(f"\n  --- {func_name} ---")
                        try:
                            cfunc = ida_hexrays.decompile(f.start_ea)
                            out.append(str(cfunc))
                        except:
                            out.append("  (decompile failed)")
        except:
            pass

    # 搜索 CreateProcessA / ShellExecuteA / WinExec xref
    out.append("\n\n=== CreateProcessA/ShellExecuteA/WinExec xref (启动 MJTVPFeD) ===")
    for api in ['CreateProcessA', 'ShellExecuteA', 'WinExec']:
        for s in idautils.Strings():
            try:
                if str(s) == api:
                    for xref in idautils.XrefsTo(s.ea):
                        f = ida_funcs.get_func(xref.frm)
                        if f:
                            func_name = ida_funcs.get_func_name(f.start_ea)
                            out.append(f"  {api} xref from 0x{xref.frm:X} in {func_name}")
                            out.append(f"\n  --- {func_name} ---")
                            try:
                                cfunc = ida_hexrays.decompile(f.start_ea)
                                out.append(str(cfunc))
                            except:
                                out.append("  (decompile failed)")
            except:
                pass

    # 反编译 sub_4141FA (登录调用) 和 sub_416C53 (释放调用)
    out.append("\n\n=== sub_416C53 (释放 MJTVPFeD 的调用方) ===")
    try:
        cfunc = ida_hexrays.decompile(0x416C53)
        out.append(str(cfunc))
    except:
        out.append("(decompile failed)")

    # 反编译所有 CreateFileA/WriteFile 相关函数
    out.append("\n\n=== 文件操作函数组 (0x4B904C-0x4C59C6) ===")
    for addr in [0x4B904C, 0x4BECC0, 0x4C1A70, 0x4C5824, 0x4C597B]:
        try:
            cfunc = ida_hexrays.decompile(addr)
            out.append(f"\n--- sub_0x{addr:X} ---")
            out.append(str(cfunc))
        except:
            out.append(f"\n--- sub_0x{addr:X} --- (decompile failed)")

    # 反编译按钮点击处理函数
    out.append("\n\n=== 按钮点击处理函数 (0x416B20) ===")
    try:
        cfunc = ida_hexrays.decompile(0x416B20)
        out.append(str(cfunc))
    except:
        out.append("(decompile failed)")

    idapro.close_database(False)
    log_file("round9_16_13_embed_extract", '\n'.join(out))

# ============================================================
# ROUND 10: 全模块交叉引用 + 完整调用图 + 数据流分析
# ============================================================
def round10():
    print("Round 10: 全模块交叉引用 + 完整调用图 + 数据流")
    out = []
    out.append("=" * 80)
    out.append("ROUND 10: 全模块交叉引用 + 完整调用图 + 数据流分析")
    out.append("=" * 80)

    # 分析 PE#2 flyinput
    out.append("\n\n========== PE#2 (flyinput.dll) 完整调用图 ==========")
    path2 = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path2, True)
    
    # 构建调用图
    callers = {}
    callees = {}
    for ea in idautils.Functions():
        f = ida_funcs.get_func(ea)
        if not f:
            continue
        name = ida_funcs.get_func_name(ea)
        callees[name] = set()
        if name not in callers:
            callers[name] = set()
        cur = ea
        while cur < f.end_ea:
            insn = ida_ua.insn_t()
            length = ida_ua.decode_insn(insn, cur)
            if length == 0:
                cur += 1
                continue
            mnem = idc.print_insn_mnem(cur)
            if mnem == 'call':
                for xref in idautils.XrefsFrom(cur, 0):
                    if xref.iscode:
                        target = xref.to
                        t_func = ida_funcs.get_func(target)
                        if t_func:
                            tname = ida_funcs.get_func_name(t_func.start_ea)
                            callees[name].add(tname)
                            if tname not in callers:
                                callers[tname] = set()
                            callers[tname].add(name)
            cur += length

    out.append(f"\nTotal functions: {len(callees)}")
    out.append(f"\n=== Call Graph (caller -> callees) ===")
    for name in sorted(callees.keys()):
        c = callees[name]
        if c:
            out.append(f"\n  {name}:")
            for callee in sorted(c):
                out.append(f"    -> {callee}")

    out.append(f"\n\n=== Reverse Call Graph (callee -> callers) ===")
    for name in sorted(callers.keys()):
        c = callers[name]
        if c and not name.startswith('sub_180016'):  # skip thunks
            out.append(f"\n  {name} is called by:")
            for caller in sorted(c):
                out.append(f"    <- {caller}")

    # API 调用汇总
    out.append(f"\n\n=== API 调用汇总 ===")
    for name in sorted(callees.keys()):
        c = callees[name]
        apis = [x for x in c if not x.startswith('sub_') and not x.startswith('?') and not x.startswith('_') and not x.startswith('j_')]
        if apis:
            out.append(f"  {name} calls: {', '.join(apis)}")

    idapro.close_database(False)

    # 分析 PE#1 dbgcore
    out.append("\n\n========== PE#1 (dbgcore.dll) 完整调用图 ==========")
    path1 = r'D:\SRC\SRC\embedded_pe\embedded_1_at_0xC7F0.exe_unpacked.exe'
    idapro.open_database(path1, True)
    
    callers1 = {}
    callees1 = {}
    for ea in idautils.Functions():
        f = ida_funcs.get_func(ea)
        if not f:
            continue
        name = ida_funcs.get_func_name(ea)
        callees1[name] = set()
        if name not in callers1:
            callers1[name] = set()
        cur = ea
        while cur < f.end_ea:
            insn = ida_ua.insn_t()
            length = ida_ua.decode_insn(insn, cur)
            if length == 0:
                cur += 1
                continue
            mnem = idc.print_insn_mnem(cur)
            if mnem == 'call':
                for xref in idautils.XrefsFrom(cur, 0):
                    if xref.iscode:
                        target = xref.to
                        t_func = ida_funcs.get_func(target)
                        if t_func:
                            tname = ida_funcs.get_func_name(t_func.start_ea)
                            callees1[name].add(tname)
                            if tname not in callers1:
                                callers1[tname] = set()
                            callers1[tname].add(name)
            cur += length

    for name in sorted(callees1.keys()):
        c = callees1[name]
        if c:
            out.append(f"\n  {name}:")
            for callee in sorted(c):
                out.append(f"    -> {callee}")

    out.append(f"\n\n=== Reverse Call Graph (dbgcore) ===")
    for name in sorted(callers1.keys()):
        c = callers1[name]
        if c:
            out.append(f"\n  {name} is called by:")
            for caller in sorted(c):
                out.append(f"    <- {caller}")

    idapro.close_database(False)

    # 数据流: 全局变量 xref
    out.append("\n\n========== 全局数据流分析 (flyinput) ==========")
    path2 = r'D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe'
    idapro.open_database(path2, True)

    # 关键全局变量
    key_globals = [
        (0x180019350, "qword_180019350 (game module base)"),
        (0x180019330, "qword_180019330 (flag byte)"),
        (0x180019338, "qword_180019338 (toggle flag)"),
        (0x180019340, "qword_180019340 (camera value)"),
        (0x180019348, "qword_180019348 (camera value 2)"),
        (0x180019368, "qword_180019368 (game data ptr)"),
        (0x180019370, "qword_180019370 (hero data)"),
        (0x180019378, "qword_180019378 (hero list)"),
        (0x180019380, "qword_180019380 (game object)"),
        (0x180019388, "qword_180019388 (skill data)"),
        (0x180019390, "qword_180019390 (item data)"),
        (0x180019398, "qword_180019398 (window handle)"),
        (0x1800193A0, "qword_1800193A0 (game ptr 2)"),
        (0x1800193B0, "qword_1800193B0 (game ptr 3)"),
        (0x1800193B8, "qword_1800193B8 (game ptr 4)"),
        (0x1800193C0, "qword_1800193C0 (game ptr 5)"),
        (0x1800193C8, "ymmword_1800193C8 (16 bytes)"),
        (0x1800193E8, "xmmword_1800193E8 (16 bytes)"),
        (0x1800193F8, "byte_1800193F8 (data array)"),
        (0x1800193F9, "byte_1800193F9 (key state)"),
        (0x1800193FA, "word_1800193FA (mode/hero index)"),
        (0x1800193FC, "dword_1800193FC (float)"),
        (0x180019400, "dword_180019400 (float)"),
        (0x180019404, "dword_180019404 (float)"),
        (0x180019410, "qword_180019410 (game ptr 6)"),
        (0x18001908C, "byte_18001908C (main loop flag)"),
    ]
    for gva, desc in key_globals:
        out.append(f"\n  {desc} (0x{gva:X}):")
        for xref in idautils.XrefsTo(gva):
            f = ida_funcs.get_func(xref.frm)
            if f:
                fname = ida_funcs.get_func_name(f.start_ea)
                out.append(f"    xref from 0x{xref.frm:X} in {fname} (type={xref.type})")
            else:
                out.append(f"    xref from 0x{xref.frm:X} (type={xref.type})")

    idapro.close_database(False)
    log_file("round10_full_callgraph_dataflow", '\n'.join(out))


# ========== 执行所有 10 轮 ==========
print("=" * 80)
print("MJTVPFeD.dat 10轮深度源码分析开始")
print("=" * 80)

round1()
round2()
round3()
round4()
round5()
round6()
round7()
round8()
round9()
round10()

print("\n" + "=" * 80)
print("10轮分析全部完成!")
print(f"输出目录: {OUT}")
print("=" * 80)