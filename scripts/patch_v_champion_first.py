#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""V键改为优先攻击英雄，再攻击小兵

修改: 将 V 键第一个遍历列表从 qword_180019380 (防御塔) 改为 qword_180019378 (英雄)
原理: V 键遍历三个列表，修改第一个列表指针即可让英雄优先

流程:
1. 从 beifen_orig_unpacked.dll 修改
2. 修改 RVA 0x5251 处的 RIP 偏移 (qword_180019380 → qword_180019378)
3. UPX 加壳
4. 部署到 16.13.exe 和 flyinput.dll
"""
import os, struct, shutil, subprocess

SRC = r"D:\SRC\SRC"
ENHR_DIR = os.path.join(SRC, "enhr_embedded")

UNPACKED_DLL = os.path.join(ENHR_DIR, "beifen_orig_unpacked.dll")
EXE = os.path.join(SRC, "16.13.exe")
KEYSTREAM = os.path.join(SRC, "rc4_keystream.bin")
UPX_EXE = r"D:\SRC\Tools\upx-4.2.4-win64\upx.exe"

MODIFIED_UNPACKED = os.path.join(ENHR_DIR, "beifen_v_champion_first_unpacked.dll")
MODIFIED_PACKED = os.path.join(ENHR_DIR, "beifen_v_champion_first_packed.dll")
OUTPUT_EXE = os.path.join(SRC, "16.13_v_champion_first.exe")
FLYINPUT_DEST = r"C:\Users\Public\FlyPY\flyinput.dll"

PE2_OFFSET = 0xF1D0
PE2_SLOT_SIZE = 31232
OVERLAY_OFFSET = 0x121000
OVERLAY_HEADER = bytes.fromhex("D6F4ED6029E9C894")

# ==================== 修改点 ====================
# 反汇编 RVA 0x5251: mov rsi, cs:qword_180019380
# 机器码: 48 8B 35 XX XX XX XX (7 bytes, RIP-relative)
# 文件偏移 = 0x4651 (.text RawPtr=0x400 + (0x5251-0x1000))
# RIP位移 = 目标地址 - (RVA + 7)
# 原始: 0x19380 - (0x5251 + 7) = 0x19380 - 0x5258 = 0x14128
# 目标: 0x19378 - 0x5258 = 0x19378 - 0x5258 = 0x14120
PATCH_RVA = 0x5251              # 反汇编 RVA
PATCH_OFFSET = 0x4651           # 文件偏移 (.text @ 0x400, RVA 0x1000)
ORIG_TARGET_RVA = 0x19380   # 防御塔列表 (RVA, 去掉 ImageBase 0x180000000)
NEW_TARGET_RVA  = 0x19378   # 英雄列表 (RVA)

print("=" * 70)
print("V键: 优先攻击英雄 → 再攻击小兵/野怪/防御塔")
print("=" * 70)

# ==================== 1. 修改解壳 DLL ====================
print("\n[1] 修改解壳 DLL")
with open(UNPACKED_DLL, "rb") as f:
    data = bytearray(f.read())

# 验证原始字节
orig_bytes = data[PATCH_OFFSET:PATCH_OFFSET+7]
print(f"  原始 @ file 0x{PATCH_OFFSET:X} (RVA 0x{PATCH_RVA:X}): {orig_bytes.hex()}")
assert orig_bytes[0:3] == b'\x48\x8B\x35', f"不是 mov rsi, [rip+...] 指令!"

# 计算新旧偏移
orig_offset = struct.unpack('<i', orig_bytes[3:7])[0]
expected_orig = ORIG_TARGET_RVA - (PATCH_RVA + 7)
print(f"  原始偏移: 0x{orig_offset:08X} (期望 0x{expected_orig:08X})")
assert orig_offset == expected_orig, f"偏移不匹配! 原始 0x{orig_offset:08X} vs 期望 0x{expected_orig:08X}"

new_offset = NEW_TARGET_RVA - (PATCH_RVA + 7)
print(f"  新偏移:   0x{new_offset:08X} (qword_180019378 英雄列表)")

# 写入新偏移
struct.pack_into('<i', data, PATCH_OFFSET + 3, new_offset)
new_bytes = data[PATCH_OFFSET:PATCH_OFFSET+7]
print(f"  修改后 @ file 0x{PATCH_OFFSET:X}: {new_bytes.hex()}")

# 验证
verify_offset = struct.unpack('<i', new_bytes[3:7])[0]
assert verify_offset == new_offset, f"写入验证失败!"

with open(MODIFIED_UNPACKED, "wb") as f:
    f.write(data)
print(f"  输出: {MODIFIED_UNPACKED}")

# ==================== 2. UPX 加壳 ====================
print("\n[2] UPX 加壳")
if os.path.exists(MODIFIED_PACKED):
    os.remove(MODIFIED_PACKED)

cmd = [UPX_EXE, "--ultra-brute", "-f", "-o", MODIFIED_PACKED, MODIFIED_UNPACKED]
result = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
print(f"  退出码: {result.returncode}")
for line in result.stdout.split('\n'):
    if any(k in line for k in ['Compressed', 'File size', 'Ratio', 'format']):
        print(f"  {line.strip()}")
if result.returncode != 0:
    cmd = [UPX_EXE, "-9", "-f", "-o", MODIFIED_PACKED, MODIFIED_UNPACKED]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=120)

packed_size = os.path.getsize(MODIFIED_PACKED)
print(f"  加壳后大小: {packed_size} (0x{packed_size:X})")
assert packed_size <= PE2_SLOT_SIZE, f"超出槽位! {packed_size} > {PE2_SLOT_SIZE}"
print(f"  剩余空间: {PE2_SLOT_SIZE - packed_size} bytes")

# ==================== 3. 部署到 16.13.exe ====================
print("\n[3] 部署到 16.13.exe")
with open(EXE, "rb") as f:
    exe_data = bytearray(f.read())
with open(KEYSTREAM, "rb") as f:
    keystream = f.read()
with open(MODIFIED_PACKED, "rb") as f:
    packed_pe2 = f.read()

overlay = exe_data[OVERLAY_OFFSET:]
assert overlay[:8] == OVERLAY_HEADER
encrypted = overlay[8:]
decrypted = bytearray(a ^ b for a, b in zip(encrypted, keystream))

# 验证关键位置
assert decrypted[:2] == b'MZ', "外层 MZ 丢失!"
assert decrypted[PE2_OFFSET:PE2_OFFSET+2] == b'MZ', "PE2 MZ 丢失!"
assert decrypted[0xB9F0:0xB9F0+2] == b'MZ', "PE1 MZ 丢失!"

# 替换 PE2
pe2_padded = packed_pe2 + b'\x00' * (PE2_SLOT_SIZE - len(packed_pe2))
decrypted[PE2_OFFSET:PE2_OFFSET+PE2_SLOT_SIZE] = pe2_padded

# 重新加密
new_encrypted = bytes(a ^ b for a, b in zip(decrypted, keystream))

# 回写
new_exe = bytearray(exe_data[:OVERLAY_OFFSET])
new_exe += OVERLAY_HEADER
new_exe += new_encrypted
assert len(new_exe) == len(exe_data)

with open(OUTPUT_EXE, "wb") as f:
    f.write(new_exe)
print(f"  输出: {OUTPUT_EXE} ({len(new_exe)} bytes)")

# ==================== 4. 部署 flyinput.dll ====================
print("\n[4] 部署 flyinput.dll")
os.makedirs(os.path.dirname(FLYINPUT_DEST), exist_ok=True)
with open(FLYINPUT_DEST, "wb") as f:
    f.write(pe2_padded)
print(f"  {FLYINPUT_DEST} ({len(pe2_padded)} bytes)")

# ==================== 5. 验证 ====================
print("\n[5] 验证")
with open(OUTPUT_EXE, "rb") as f:
    vfy = f.read()
vfy_ov = vfy[OVERLAY_OFFSET:]
vfy_dec = bytes(a ^ b for a, b in zip(vfy_ov[8:], keystream))
vfy_pe2 = vfy_dec[PE2_OFFSET:PE2_OFFSET+PE2_SLOT_SIZE]

# 验证网络验证补丁
p1 = vfy[0x142CB:0x142CB+6]
p2 = vfy[0x16B43:0x16B43+6]
print(f"  补丁1 @0x142CB: {p1.hex()} {'OK' if p1 == bytes.fromhex('E90B00000090') else 'FAIL'}")
print(f"  补丁2 @0x16B43: {p2.hex()} {'OK' if p2 == bytes.fromhex('909090909090') else 'FAIL'}")
print(f"  PE2 MZ: {'OK' if vfy_pe2[:2] == b'MZ' else 'FAIL'}")
print(f"  flyinput.dll 匹配 PE2: {'OK' if open(FLYINPUT_DEST,'rb').read() == vfy_pe2 else 'FAIL'}")

print(f"\n{'='*70}")
print(f"✅ 完成!")
print(f"{'='*70}")
print(f"输出: {OUTPUT_EXE}")
print(f"")
print(f"修改: RVA 0x5251, qword_180019380→qword_180019378")
print(f"V键新优先级: 英雄 > 野怪 > 小兵")
print(f"")
print(f"V键行为:")
print(f"  1. 先遍历英雄列表 (qword_180019378)")
print(f"     - 找敌方 + 存活 + 可见 + 在攻击范围内")
print(f"     - 找到 → 攻击英雄 (无血量限制)")
print(f"  2. 没英雄 → 遍历野怪列表 (qword_180019390)")
print(f"  3. 没野怪 → 遍历小兵列表 (qword_180019388)")
print(f"     - 只攻击 玩家AD ≤ 小兵血量 的目标 (不清线不抢刀)")