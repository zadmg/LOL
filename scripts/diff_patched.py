#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""对比 16.13.exe 和 16.13_patched.exe 的差异"""
import os

SRC = r"D:\SRC\SRC\BeiFen"
ORIG = os.path.join(SRC, "16.13.exe")
PATCHED = os.path.join(SRC, "16.13_patched.exe")

with open(ORIG, "rb") as f:
    orig = f.read()
with open(PATCHED, "rb") as f:
    patched = f.read()

print(f"orig size: {len(orig)}")
print(f"patched size: {len(patched)}")

diffs = []
n = min(len(orig), len(patched))
for i in range(n):
    if orig[i] != patched[i]:
        diffs.append((i, orig[i], patched[i]))

print(f"Total diffs: {len(diffs)}")
print(f"{'Offset':<12} {'Orig':<6} {'Patched':<8} {'OrigChr':<8} {'PatchedChr':<8}")
for off, o, p in diffs:
    oc = chr(o) if 32 <= o < 127 else '.'
    pc = chr(p) if 32 <= p < 127 else '.'
    print(f"0x{off:<10X} 0x{o:02X}   0x{p:02X}     {oc:<8} {pc:<8}")
