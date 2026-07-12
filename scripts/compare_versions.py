#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""对比当前 16.13.exe 与最新 jinx_fc 版本"""
import os

SRC = r"D:\SRC\SRC"
CURRENT = os.path.join(SRC, "16.13.exe")
LATEST  = os.path.join(SRC, "16.13.exe.jinx_fc")
BAK2    = os.path.join(SRC, "16.13.exe.bak2")

with open(CURRENT, "rb") as f:
    cur = f.read()
with open(LATEST, "rb") as f:
    lat = f.read()
with open(BAK2, "rb") as f:
    bak = f.read()

print(f"当前 16.13.exe:     {len(cur)} bytes")
print(f"最新 jinx_fc:       {len(lat)} bytes")
print(f"bak2:               {len(bak)} bytes")
print()

# 检查补丁点1/2 是否在当前 exe 中
print("=" * 60)
print("补丁点检查（当前 16.13.exe）")
print("=" * 60)
p1 = cur[0x0142CB:0x0142CB+6]
p2 = cur[0x016B43:0x016B43+6]
print(f"补丁点1 @ 0x142CB: {p1.hex()}")
print(f"  绕过版: e90b00000090")
print(f"  原始版: 0f840a000000")
print(f"补丁点2 @ 0x16B43: {p2.hex()}")
print(f"  绕过版: 909090909090")
print(f"  原始版: 0f8484000000")
print()

# 对比当前 vs 最新
print("=" * 60)
print("当前 16.13.exe vs 最新 jinx_fc 差异")
print("=" * 60)
diffs = []
for i in range(min(len(cur), len(lat))):
    if cur[i] != lat[i]:
        diffs.append(i)
print(f"差异字节数: {len(diffs)}")
print(f"差异范围: 0x{diffs[0]:X} - 0x{diffs[-1]:X}" if diffs else "无差异")

# 检查差异是否都在 PE2 范围
pe2_start = 0x121008 + 0xF1D0
pe2_end = pe2_start + 31232
non_pe2 = [d for d in diffs if not (pe2_start <= d < pe2_end)]
print(f"非 PE2 区域差异: {len(non_pe2)}")
if non_pe2:
    print(f"  非PE2差异范围: 0x{non_pe2[0]:X} - 0x{non_pe2[-1]:X}")
    for off in non_pe2[:10]:
        print(f"  0x{off:06X}: cur={cur[off]:02X}  latest={lat[off]:02X}")
