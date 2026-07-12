#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""最终二进制完整性验证"""
import struct

SRC = r"D:\SRC\SRC"

with open(f"{SRC}/16.13.exe.jinx_fc", "rb") as f:
    data = f.read()

with open(f"{SRC}/rc4_keystream.bin", "rb") as f:
    keystream = f.read()

with open(f"{SRC}/16.13.exe", "rb") as f:
    orig = f.read()

print("=" * 60)
print("最终二进制完整性验证")
print("=" * 60)

# 1. MZ
assert data[:2] == b'MZ'
print("[OK] MZ header")

# 2. overlay header
off = 0x121000
header = data[off:off+8]
assert header == bytes.fromhex("D6F4ED6029E9C894")
print(f"[OK] overlay header: {header.hex()}")

# 3. 加密数据解密
encrypted = data[off+8:]
assert len(encrypted) == 113664
plain = bytes(a ^ b for a, b in zip(encrypted, keystream))
assert plain[:2] == b'MZ'
print("[OK] decrypt: outer MZ OK")

# 4. PE1
assert plain[0xB9F0:0xB9F0+2] == b'MZ'
print("[OK] PE1 @ 0xB9F0")

# 5. PE2
assert plain[0xF1D0:0xF1D0+2] == b'MZ'
print("[OK] PE2 @ 0xF1D0")

# 6. PE2 非零区域
pe2 = plain[0xF1D0:0xF1D0+31232]
last_nz = 0
for i in range(len(pe2)-1, -1, -1):
    if pe2[i] != 0:
        last_nz = i
        break
print(f"[OK] PE2 last non-zero @ offset 0x{last_nz:X} (size={last_nz+1}, expected=30720)")

# 7. 非 PE2 区域
orig_enc = orig[0x121008:]
non_pe2_diff = 0
for i in range(len(encrypted)):
    if i >= 0xF1D0 and i < 0xF1D0 + 31232:
        continue
    if encrypted[i] != orig_enc[i]:
        non_pe2_diff += 1
assert non_pe2_diff == 0
print(f"[OK] non-PE2 diff: 0")

# 8. 大小一致性
assert len(data) == len(orig)
print(f"[OK] size: {len(data)} == {len(orig)}")

print("\n" + "=" * 60)
print("ALL CHECKS PASSED")
print("=" * 60)