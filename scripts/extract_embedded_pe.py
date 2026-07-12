"""
在 MJTVPFeD_dumped.exe 中搜索所有嵌入的 PE (MZ 头)
并提取 UPX 加壳的负载
"""
import struct
import os
import sys

SRC = r'D:\SRC\SRC\MJTVPFeD_dumped.exe'
OUT_DIR = r'D:\SRC\SRC\embedded_pe'

# 重定向输出到文件
LOG = open(r'D:\SRC\SRC\extract_embedded_pe.log', 'w', encoding='utf-8')
class Tee:
    def write(self, s):
        LOG.write(s)
        sys.__stdout__.write(s)
    def flush(self):
        LOG.flush()
        sys.__stdout__.flush()
sys.stdout = Tee()

os.makedirs(OUT_DIR, exist_ok=True)

with open(SRC, 'rb') as f:
    data = f.read()

print(f"File size: {len(data)} bytes (0x{len(data):X})")
print(f"Image base (from filename analysis): 0x7FF71BC60000")
print()

# 搜索所有 MZ 头
print("=== Searching for MZ headers ===")
mz_offsets = []
pos = 0
while True:
    idx = data.find(b'MZ', pos)
    if idx == -1:
        break
    # 验证 e_lfanew 是否合理
    if idx + 0x40 < len(data):
        e_lfanew = struct.unpack_from('<I', data, idx + 0x3C)[0]
        if 0x40 <= e_lfanew < 0x1000:
            # 验证 PE 签名
            pe_off = idx + e_lfanew
            if pe_off + 4 <= len(data):
                pe_sig = data[pe_off:pe_off+4]
                if pe_sig == b'PE\x00\x00':
                    print(f"  Found valid PE at offset 0x{idx:X}")
                    print(f"    e_lfanew = 0x{e_lfanew:X}")
                    print(f"    PE sig at 0x{pe_off:X}: {pe_sig!r}")
                    mz_offsets.append(idx)
                else:
                    print(f"  MZ at 0x{idx:X}, e_lfanew=0x{e_lfanew:X}, but PE sig invalid: {pe_sig!r}")
    pos = idx + 2

print()
print(f"=== Found {len(mz_offsets)} valid PE files ===")

# 分析每个 PE
for i, off in enumerate(mz_offsets):
    print(f"\n--- PE #{i} at offset 0x{off:X} ---")
    # PE 头
    e_lfanew = struct.unpack_from('<I', data, off + 0x3C)[0]
    pe_off = off + e_lfanew
    # COFF header
    machine, num_sections = struct.unpack_from('<HH', data, pe_off + 4)
    timestamp = struct.unpack_from('<I', data, pe_off + 8)[0]
    # Optional header
    opt_magic = struct.unpack_from('<H', data, pe_off + 0x18)[0]
    is_pe32_plus = (opt_magic == 0x20B)
    print(f"  Machine: 0x{machine:X} ({'x64' if machine == 0x8664 else 'x86' if machine == 0x14C else 'unknown'})")
    print(f"  Sections: {num_sections}")
    print(f"  Opt magic: 0x{opt_magic:X} ({'PE32+' if is_pe32_plus else 'PE32'})")
    
    # Section table
    sect_off = pe_off + 0x18 + (240 if is_pe32_plus else 224)
    print(f"  Section table at 0x{sect_off:X}:")
    total_raw_size = 0
    last_raw_end = 0
    sects = []
    for s in range(num_sections):
        so = sect_off + s * 40
        name = data[so:so+8].rstrip(b'\x00').decode('ascii', errors='replace')
        vsize, vaddr, raw_size, raw_offset = struct.unpack_from('<IIII', data, so + 8)
        chars = struct.unpack_from('<I', data, so + 36)[0]
        print(f"    [{s}] {name!r}: vaddr=0x{vaddr:X} vsize=0x{vsize:X} raw_off=0x{raw_offset:X} raw_size=0x{raw_size:X} chars=0x{chars:X}")
        sects.append((name, vsize, vaddr, raw_size, raw_offset))
        if raw_offset + raw_size > last_raw_end:
            last_raw_end = raw_offset + raw_size
    
    # 提取整个 PE (从 MZ 头到最后一个 section 末尾)
    # 简单方法: 提取从 MZ 到文件末尾或下一个 MZ
    next_mz = len(data)
    for j, o in enumerate(mz_offsets):
        if o > off:
            next_mz = o
            break
    
    # 实际大小 = 最后 section 末尾 (raw)
    extract_size = min(last_raw_end, next_mz - off)
    print(f"  Extract size: 0x{extract_size:X} ({extract_size} bytes)")
    
    out_path = os.path.join(OUT_DIR, f'embedded_{i}_at_0x{off:X}.exe')
    with open(out_path, 'wb') as f:
        f.write(data[off:off + extract_size])
    print(f"  Written to: {out_path}")
    
    # 尝试 UPX 解壳
    print(f"  Checking UPX markers in extracted file...")
    upx_markers = []
    for marker in [b'UPX0', b'UPX1', b'UPX!']:
        if marker in data[off:off + extract_size]:
            upx_markers.append(marker.decode())
    if upx_markers:
        print(f"    UPX markers found: {upx_markers}")
        # 尝试用 UPX 解壳
        import subprocess
        upx_out = out_path + '_unpacked.exe'
        result = subprocess.run(
            [r'D:\SRC\Tools\upx-4.2.4-win64\upx.exe', '-d', out_path, '-o', upx_out],
            capture_output=True, text=True
        )
        print(f"    UPX -d exit code: {result.returncode}")
        if result.stdout:
            print(f"    UPX stdout: {result.stdout}")
        if result.stderr:
            print(f"    UPX stderr: {result.stderr}")
        if os.path.exists(upx_out):
            print(f"    Unpacked file: {upx_out} ({os.path.getsize(upx_out)} bytes)")
    else:
        print(f"    No UPX markers in this PE")

print()
print("=== Done ===")
