#!/usr/bin/env python3
"""
完整打包部署脚本:
1. 读取 ENHRmteD_restored.dat (明文)
2. 用 enhr_pe2_jinx_packed.dll 替换 PE2 @ 0xF1D0
3. 用 rc4_keystream.bin 重新加密 (XOR)
4. 回写 16.13.exe overlay (header + 加密数据)
5. 输出 16.13.exe.jinx
"""
import os
import struct
import shutil

SRC = r"D:\SRC\SRC"

# 输入文件
ENHR_PLAINTEXT = os.path.join(SRC, "ENHRmteD_restored.dat")   # 明文 ENHRmteD.dat
JINX_PACKED = os.path.join(SRC, "enhr_embedded", "enhr_pe2_fakeclick_only_ub.dll")
KEYSTREAM = os.path.join(SRC, "rc4_keystream.bin")
ORIGINAL_EXE = os.path.join(SRC, "16.13.exe")

# 输出文件
OUTPUT_EXE = os.path.join(SRC, "16.13.exe.jinx_fc")
BACKUP_EXE = os.path.join(SRC, "16.13.exe.bak2")

# 常量
PE2_OFFSET = 0xF1D0          # PE2 在 ENHRmteD.dat 中的偏移
PE2_SIZE = 31232              # PE2 大小
OVERLAY_HEADER = bytes.fromhex("D6F4ED6029E9C894")
OVERLAY_OFFSET = 0x121000     # overlay 在 16.13.exe 中的偏移

print("=" * 70)
print("打包部署: 将修改后的 flyinput.dll (含 Jinx) 部署到 16.13.exe")
print("=" * 70)

# ==================== 1. 读取所有文件 ====================
print("\n[1] 读取文件...")
with open(ENHR_PLAINTEXT, "rb") as f:
    plaintext = bytearray(f.read())
with open(JINX_PACKED, "rb") as f:
    jinx_packed = f.read()
with open(KEYSTREAM, "rb") as f:
    keystream = f.read()
with open(ORIGINAL_EXE, "rb") as f:
    exe_data = bytearray(f.read())

print(f"  ENHRmteD 明文: {len(plaintext)} 字节")
print(f"  Jinx packed PE2: {len(jinx_packed)} 字节")
print(f"  RC4 密钥流: {len(keystream)} 字节")
print(f"  16.13.exe: {len(exe_data)} 字节")

# ==================== 2. 验证大小 ====================
print("\n[2] 验证大小...")
assert len(plaintext) == len(keystream), "明文与密钥流大小不匹配!"
if len(jinx_packed) < PE2_SIZE:
    pad_needed = PE2_SIZE - len(jinx_packed)
    print(f"  packed DLL 小于槽位, 补 {pad_needed} bytes 0 填充")
    jinx_packed = jinx_packed + b'\x00' * pad_needed
elif len(jinx_packed) > PE2_SIZE:
    raise ValueError(f"Jinx PE2 太大: {len(jinx_packed)} > {PE2_SIZE}")
assert len(jinx_packed) == PE2_SIZE, f"PE2 大小不匹配: {len(jinx_packed)} vs {PE2_SIZE}"
print(f"  ✓ 所有大小匹配 (PE2 = {PE2_SIZE} bytes)")

# ==================== 3. 替换 PE2 ====================
print(f"\n[3] 替换 PE2 @ 0x{PE2_OFFSET:X}...")
# 验证原始 PE2 位置
assert plaintext[PE2_OFFSET:PE2_OFFSET+2] == b'MZ', "PE2 位置无 MZ 头!"
# 保存原始 PE2 用于对比
original_pe2 = bytes(plaintext[PE2_OFFSET:PE2_OFFSET+PE2_SIZE])
# 验证修改后 PE2 也是有效的 PE
assert jinx_packed[:2] == b'MZ', "Jinx PE2 无 MZ 头!"
# 替换
plaintext[PE2_OFFSET:PE2_OFFSET+PE2_SIZE] = jinx_packed
print(f"  ✓ PE2 已替换 ({PE2_SIZE} 字节)")

# 验证替换后的明文结构
assert plaintext[0:2] == b'MZ', "外层 EXE MZ 头丢失!"
assert plaintext[PE2_OFFSET:PE2_OFFSET+2] == b'MZ', "新 PE2 MZ 头异常!"
# 检查 PE1 是否完好 (在 0xB9F0)
assert plaintext[0xB9F0:0xB9F0+2] == b'MZ', "PE1 MZ 头丢失!"
print(f"  ✓ 外层 EXE MZ 头完好")
print(f"  ✓ PE1 @ 0xB9F0 MZ 头完好")
print(f"  ✓ 新 PE2 @ 0x{PE2_OFFSET:X} MZ 头完好")

# ==================== 4. RC4 重新加密 (XOR) ====================
print(f"\n[4] RC4 重新加密 (XOR keystream)...")
# RC4 是流密码, 加密和解密相同: ciphertext = plaintext XOR keystream
encrypted = bytes(a ^ b for a, b in zip(plaintext, keystream))
print(f"  ✓ 加密完成 ({len(encrypted)} 字节)")
print(f"  加密前16字节: {encrypted[:16].hex()}")
print(f"  原始加密前16字节: {bytes(exe_data[OVERLAY_OFFSET+8:OVERLAY_OFFSET+24]).hex()}")

# 验证: 由于 PE2 部分已改变, 加密结果应仅在 PE2 对应位置不同
# PE2 在明文中的偏移 0xF1D0, 在加密数据中也是 0xF1D0 (因为 XOR 是逐字节的)
diff_count = sum(1 for i in range(len(encrypted)) if encrypted[i] != exe_data[OVERLAY_OFFSET+8+i])
print(f"  与原始加密数据差异字节数: {diff_count}")
print(f"  差异比例: {100*diff_count/len(encrypted):.2f}%")

# 验证非 PE2 区域应与原始加密数据相同
# PE2 范围: 0xF1D0 ~ 0xF1D0+31232 = 0x16BD0
non_pe2_diff = 0
for i in range(len(encrypted)):
    if i >= PE2_OFFSET and i < PE2_OFFSET + PE2_SIZE:
        continue  # 跳过 PE2 区域
    if encrypted[i] != exe_data[OVERLAY_OFFSET+8+i]:
        non_pe2_diff += 1
print(f"  非 PE2 区域差异: {non_pe2_diff} (应为 0)")
assert non_pe2_diff == 0, "非 PE2 区域有差异!"
print(f"  ✓ 非 PE2 区域完全一致")

# ==================== 5. 回写 16.13.exe ====================
print(f"\n[5] 回写 16.13.exe overlay...")

# 备份原始 16.13.exe
if not os.path.exists(BACKUP_EXE):
    shutil.copy2(ORIGINAL_EXE, BACKUP_EXE)
    print(f"  备份: {BACKUP_EXE}")
else:
    print(f"  备份已存在: {BACKUP_EXE}")

# 构造新 exe: 保留前 OVERLAY_OFFSET 字节 + header + 加密数据
new_exe = bytearray(exe_data[:OVERLAY_OFFSET])
new_exe += OVERLAY_HEADER
new_exe += encrypted

# 验证新 exe 大小
expected_size = OVERLAY_OFFSET + 8 + len(encrypted)
assert len(new_exe) == expected_size, f"大小不匹配: {len(new_exe)} vs {expected_size}"
assert len(new_exe) == len(exe_data), f"与原始 exe 大小不一致: {len(new_exe)} vs {len(exe_data)}"
print(f"  ✓ 新 exe 大小: {len(new_exe)} 字节 (与原始一致)")

# 保存
with open(OUTPUT_EXE, "wb") as f:
    f.write(new_exe)
print(f"  输出: {OUTPUT_EXE}")

# ==================== 6. 最终验证 ====================
print(f"\n[6] 最终验证...")
# 读取新 exe 验证
with open(OUTPUT_EXE, "rb") as f:
    verify_data = f.read()

# 验证 PE 头
assert verify_data[:2] == b'MZ', "新 exe 无 MZ 头!"
# 验证 overlay header
verify_overlay = verify_data[OVERLAY_OFFSET:]
assert verify_overlay[:8] == OVERLAY_HEADER, "overlay header 不匹配!"
# 验证加密数据
assert verify_overlay[8:8+len(encrypted)] == encrypted, "加密数据不匹配!"
# 验证可以通过解密还原
verify_encrypted = verify_overlay[8:8+113664]
verify_plaintext = bytes(a ^ b for a, b in zip(verify_encrypted, keystream))
assert verify_plaintext[:2] == b'MZ', "解密后无 MZ 头!"
assert verify_plaintext[PE2_OFFSET:PE2_OFFSET+2] == b'MZ', "解密后 PE2 无 MZ 头!"
# 验证 PE2 是修改后的版本
assert verify_plaintext[PE2_OFFSET:PE2_OFFSET+PE2_SIZE] == jinx_packed, "解密后 PE2 不是修改版本!"
# 验证 PE1 完好
assert verify_plaintext[0xB9F0:0xB9F0+2] == b'MZ', "解密后 PE1 无 MZ 头!"

print(f"  ✓ 新 exe MZ 头完好")
print(f"  ✓ overlay header 正确")
print(f"  ✓ 加密数据写入正确")
print(f"  ✓ 解密验证通过 (明文 MZ 头完好)")
print(f"  ✓ PE1 @ 0xB9F0 完好")
print(f"  ✓ PE2 @ 0x{PE2_OFFSET:X} 是修改后版本 (含 Jinx)")
print(f"  ✓ 外层 EXE 数据未改变")

print(f"\n{'=' * 70}")
print(f"✅ 打包部署完成!")
print(f"{'=' * 70}")
print(f"输出文件: {OUTPUT_EXE}")
print(f"文件大小: {len(verify_data)} 字节")
print(f"")
print(f"部署说明:")
print(f"  1. 将 16.13.exe.jinx 重命名为 16.13.exe")
print(f"  2. 运行 16.13.exe")
print(f"  3. 程序会自动释放 MJTVPFeD.dat (含修改后的 flyinput.dll)")
print(f"  4. MJTVPFeD.dat 释放 dbgcore.dll + flyinput.dll 到 C:\\Users\\Public\\FlyPY\\")
print(f"  5. 启动 LeagueClient.exe 时, flyinput.dll 被加载, 含 Jinx 英雄支持")
print(f"")
print(f"原始备份: {BACKUP_EXE}")
