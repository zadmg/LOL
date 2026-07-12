#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
对 BeiFen/16.13.exe 应用网络验证绕过补丁
- 参考之前在 16.13.exe.bak2 中使用的补丁方法
- 补丁 1 @ 0x0142CB: jz(6字节) -> jmp(5字节) + nop, rel32 调整 0x0A -> 0x0B
- 补丁 2 @ 0x016B43: jz(6字节) -> 6 个 nop
"""
import shutil
import os

SRC = r"D:\SRC\SRC"
BEIFEN = os.path.join(SRC, "BeiFen", "16.13.exe")
OUTPUT = os.path.join(SRC, "BeiFen", "16.13_patched.exe")

# 补丁定义
PATCHES = [
    {
        "offset": 0x0142CB,
        "orig":    bytes.fromhex("0F840A000000"),    # jz rel32 (6 字节)
        "patched": bytes.fromhex("E90B00000090"),    # jmp rel32(0x0B) + nop (6 字节)
        "desc":    "0x0142CB: jz(6字节) -> jmp(5字节) + nop, rel32 调整 0x0A->0x0B",
    },
    {
        "offset": 0x016B43,
        "orig":    bytes.fromhex("0F8484000000"),    # jz rel32
        "patched": bytes.fromhex("909090909090"),    # 6 个 nop
        "desc":    "0x016B43: jz -> 6 个 nop (跳过网络验证)",
    },
]

print("=" * 60)
print("网络验证绕过补丁 - BeiFen/16.13.exe")
print("=" * 60)
print(f"输入: {BEIFEN}")
print(f"输出: {OUTPUT}")
print()

# 读取原始文件
with open(BEIFEN, "rb") as f:
    data = bytearray(f.read())
print(f"文件大小: {len(data)} bytes")
print()

# 验证并应用补丁
for i, patch in enumerate(PATCHES, 1):
    off = patch["offset"]
    orig = patch["orig"]
    patched = patch["patched"]
    actual = bytes(data[off:off + len(orig)])

    print(f"[补丁 {i}] 0x{off:X}")
    print(f"  期望原始: {orig.hex()}")
    print(f"  实际读取: {actual.hex()}")
    print(f"  补丁为:   {patched.hex()}")
    print(f"  说明:     {patch['desc']}")

    if actual != orig:
        print(f"  [错误] 原始字节不匹配!")
        # 检查是否已经打过补丁
        if actual == patched:
            print(f"  [提示] 文件已经打过此补丁，跳过")
            continue
        else:
            raise ValueError(f"0x{off:X} 字节不匹配")

    # 应用补丁
    data[off:off + len(patched)] = patched
    print(f"  [OK] 补丁已应用")
    print()

# 保存
with open(OUTPUT, "wb") as f:
    f.write(data)
print(f"[完成] 输出文件: {OUTPUT}")
print(f"文件大小: {len(data)} bytes")

# 验证补丁
print()
print("=" * 60)
print("验证补丁")
print("=" * 60)
with open(OUTPUT, "rb") as f:
    verify = f.read()

for i, patch in enumerate(PATCHES, 1):
    off = patch["offset"]
    patched = patch["patched"]
    actual = verify[off:off + len(patched)]
    ok = actual == patched
    status = "[OK]" if ok else "[FAIL]"
    print(f"  {status} 补丁 {i} @ 0x{off:X}: {actual.hex()} (期望 {patched.hex()})")

# 与 bak2 比较补丁位置
print()
print("=" * 60)
print("与 bak2 对比（验证补丁一致性）")
print("=" * 60)
with open(os.path.join(SRC, "16.13.exe.bak2"), "rb") as f:
    bak = f.read()

all_match = True
for patch in PATCHES:
    off = patch["offset"]
    patched = patch["patched"]
    bak_bytes = bak[off:off + len(patched)]
    out_bytes = verify[off:off + len(patched)]
    match = bak_bytes == out_bytes
    status = "[OK]" if match else "[WARN]"
    print(f"  {status} 0x{off:X}: bak2={bak_bytes.hex()} output={out_bytes.hex()}")
    if not match:
        all_match = False

if all_match:
    print()
    print("[成功] 所有补丁与 bak2 完全一致")
else:
    print()
    print("[警告] 部分补丁与 bak2 不一致（可能 bak2 还有其他修改）")

# 检查与 bak2 的总差异
print()
print("=" * 60)
print("与 bak2 总差异对比")
print("=" * 60)
diffs = []
for i in range(min(len(verify), len(bak))):
    if verify[i] != bak[i]:
        diffs.append(i)
print(f"差异字节数: {len(diffs)}")
if len(diffs) > 0:
    print(f"差异范围: 0x{diffs[0]:X} - 0x{diffs[-1]:X}")
    if len(diffs) <= 20:
        for off in diffs:
            print(f"  0x{off:06X}: bak={bak[off]:02X}  output={verify[off]:02X}")
    # 检查差异是否都在 PE2 范围
    pe2_start = 0x121008 + 0xF1D0  # = 0x1301D8
    pe2_end = pe2_start + 31232
    non_pe2_diffs = [d for d in diffs if not (pe2_start <= d < pe2_end)]
    print(f"非 PE2 区域差异: {len(non_pe2_diffs)}")
    if non_pe2_diffs:
        print("  (bak2 的 PE2 已修改为含 Jinx 版本，这是正常的)")
        print(f"  PE2 范围: 0x{pe2_start:X} - 0x{pe2_end:X}")
