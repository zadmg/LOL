#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""检查 PE2 槽位后的空间，判断是否可扩展"""

import os

SRC = r"D:\SRC\SRC"
ENHR_PLAINTEXT = os.path.join(SRC, "ENHRmteD_restored.dat")

PE2_OFFSET = 0xF1D0
OLD_PE2_SIZE = 31232
PE2_END = PE2_OFFSET + OLD_PE2_SIZE

# 新 packed DLL 大小
NEW_PACKED_SIZE = 31744
EXTRA_NEEDED = NEW_PACKED_SIZE - OLD_PE2_SIZE  # 512

with open(ENHR_PLAINTEXT, "rb") as f:
    data = f.read()

print(f"ENHRmteD.dat 总大小: {len(data)} (0x{len(data):X})")
print(f"PE2 偏移: 0x{PE2_OFFSET:X}")
print(f"PE2 旧大小: {OLD_PE2_SIZE} (0x{OLD_PE2_SIZE:X})")
print(f"PE2 结束: 0x{PE2_END:X}")
print(f"新 packed 大小: {NEW_PACKED_SIZE}")
print(f"需要额外: {EXTRA_NEEDED} bytes")
print()

# 检查 PE2 后面的数据
remaining = len(data) - PE2_END
print(f"PE2 后剩余数据: {remaining} bytes (0x{remaining:X})")
print()

# 查看 PE2 后 1024 bytes 的内容
print("PE2 后 1024 bytes (十六进制):")
after_pe2 = data[PE2_END:PE2_END + 1024]
for i in range(0, min(len(after_pe2), 1024), 16):
    hex_str = ' '.join(f'{b:02X}' for b in after_pe2[i:i+16])
    ascii_str = ''.join(chr(b) if 32 <= b < 127 else '.' for b in after_pe2[i:i+16])
    print(f"  0x{PE2_END+i:X}: {hex_str:<48} {ascii_str}")

# 检查是否有连续的 0 填充
print()
zero_run = 0
max_zero_run = 0
max_zero_start = 0
cur_zero_start = 0
for i in range(remaining):
    if data[PE2_END + i] == 0:
        if zero_run == 0:
            cur_zero_start = PE2_END + i
        zero_run += 1
        if zero_run > max_zero_run:
            max_zero_run = zero_run
            max_zero_start = cur_zero_start
    else:
        zero_run = 0

print(f"PE2 后最大连续 0 填充: {max_zero_run} bytes @ 0x{max_zero_start:X}")

# 检查 PE2 结束处是否有 MZ 头（表示另一个 PE 开始）
# 也检查是否有其他结构
print()

# 检查 PE2 之后的非零数据段
nonzero_segments = []
in_nonzero = False
seg_start = 0
for i in range(remaining):
    if data[PE2_END + i] != 0:
        if not in_nonzero:
            seg_start = PE2_END + i
            in_nonzero = True
    else:
        if in_nonzero:
            nonzero_segments.append((seg_start, PE2_END + i))
            in_nonzero = False
if in_nonzero:
    nonzero_segments.append((seg_start, PE2_END + remaining))

print(f"PE2 后非零数据段: {len(nonzero_segments)}")
for start, end in nonzero_segments[:10]:
    size = end - start
    print(f"  0x{start:X} - 0x{end:X} ({size} bytes)")
    # 显示前 16 bytes
    preview = data[start:start+16]
    print(f"    {preview.hex()}")

# 判断是否可以安全扩展
print()
if max_zero_run >= EXTRA_NEEDED and max_zero_start == PE2_END:
    print(f"[OK] PE2 后紧接 {max_zero_run} bytes 的 0 填充，可以安全扩展 {EXTRA_NEEDED} bytes")
    print(f"  新 PE2_SIZE = {NEW_PACKED_SIZE}")
elif max_zero_run >= EXTRA_NEEDED:
    print(f"[可能] PE2 后有 {max_zero_run} bytes 的 0 填充 @ 0x{max_zero_start:X}")
    print(f"  但不在 PE2 紧接位置，需要检查中间数据")
else:
    print(f"[警告] PE2 后没有足够的 0 填充空间")
    print(f"  最大连续 0: {max_zero_run} bytes")
    print(f"  需要: {EXTRA_NEEDED} bytes")
    print(f"  选项: 1) 减少 v2 代码量 2) 检查是否可覆盖其他数据")
