"""RC4 密钥流分析 - 已知明文攻击"""
import struct
import os
import hashlib
from collections import Counter

SRC = r"D:\SRC\SRC"

# Read encrypted overlay from 16.13.exe
# Overlay at 0x121000: 8-byte header + 113,664 byte encrypted body
with open(os.path.join(SRC, "16.13.exe"), "rb") as f:
    f.seek(0x121000)
    overlay_header = f.read(8)
    encrypted = f.read(113664)

print(f"Overlay header: {overlay_header.hex()}")
print(f"Encrypted body: {len(encrypted)} bytes")

# Read decrypted = ENHRmteD.dat
with open(os.path.join(SRC, "ENHRmteD.dat"), "rb") as f:
    decrypted = f.read()

assert len(encrypted) == len(decrypted), "Size mismatch!"

# XOR keystream
keystream = bytes(a ^ b for a, b in zip(encrypted, decrypted))

# Save keystream
with open(os.path.join(SRC, "rc4_keystream.bin"), "wb") as f:
    f.write(keystream)

print(f"\n=== Keystream Analysis ===")
print(f"Size: {len(keystream)} bytes")
print(f"First 64 bytes: {keystream[:64].hex()}")

# Entropy
counter = Counter(keystream)
total = len(keystream)
import math
entropy = -sum((n/total) * math.log2(n/total) for n in counter.values())
print(f"Entropy: {entropy:.4f}")
print(f"Unique bytes: {len(counter)}")

# Frequency analysis
print(f"\nTop 10 most frequent bytes:")
for byte_val, count in counter.most_common(10):
    print(f"  0x{byte_val:02X} ('{chr(byte_val) if 32<=byte_val<127 else '?'}'): {count} ({100*count/total:.2f}%)")

# Check for repeating patterns
print(f"\n=== Pattern Analysis ===")
# RC4 keystream should be pseudo-random - check if it repeats
for period in [256, 512, 1024, 2048, 4096, 8192]:
    if len(keystream) >= period * 2:
        match = sum(1 for i in range(period) if keystream[i] == keystream[i + period])
        print(f"  Period {period}: {match}/{period} match ({100*match/period:.1f}%)")

# Check first 256 bytes pattern (RC4 often starts with a recognizable pattern)
print(f"\nFirst 256 bytes unique values: {len(set(keystream[:256]))}")
print(f"First 32 bytes as ASCII: {''.join(chr(b) if 32<=b<127 else '.' for b in keystream[:32])}")

# Check if keystream XOR with itself at different offsets reveals anything
# RC4 key scheduling: if key is K, S[i] = identity permutation, then KSA mixes
# RC4 drops first N bytes (often 256 or 768 or 3072)
# Try to find the drop count by looking at statistical properties
print(f"\n=== RC4 Drop Analysis ===")
for drop in [0, 256, 768, 1024, 2048, 3072]:
    if drop < len(keystream):
        sample = keystream[drop:drop+256]
        unique = len(set(sample))
        print(f"  Drop {drop}: bytes[{drop}:{drop+256}] unique={unique}, entropy={-sum((n/256)*math.log2(n/256) for n in Counter(sample).values()):.4f}")

# Try to find the key from known plaintext
# RC4: keystream[i] = S[S[i] + S[j]] where i increments, j += S[i]
# With known keystream, we can recover the internal state after KSA
# But we can't directly recover the key from the state
# However, if the key is short, we can try to brute-force it

# The key is derived from hardware fingerprint: CPUInfo + HDInfo + ENode
# Let's try common derivation patterns

# First, check if the key is embedded somewhere in the binary
print(f"\n=== Key Search in Binary ===")
with open(os.path.join(SRC, "16.13.exe"), "rb") as f:
    exe_data = f.read()

# Look for the keystream prefix in the binary (unlikely but worth checking)
for prefix_len in [8, 16, 32]:
    prefix = keystream[:prefix_len]
    idx = exe_data.find(prefix)
    if idx != -1:
        print(f"  Keystream prefix ({prefix_len}B) found at 0x{idx:X}!")
    else:
        print(f"  Keystream prefix ({prefix_len}B) not found in binary")

# Check if keystream is derived from common strings
test_strings = [
    b'Uayj5ffxmYk9',  # banned card key
    b'16.13.exe',
    b'ENHRmteD',
    b'MJTVPFeD',
    b'xbzhan',
    b'api2.xbzhan.com',
    b'zoukan',
    b'\xe8\xb5\xb0\xe7\xa0\x8d',  # 走砍 UTF-8
]

for s in test_strings:
    # Try as direct key (RC4 key can be any length)
    # Generate RC4 keystream with this key
    S = list(range(256))
    j = 0
    key = s
    key_len = len(key)
    for i in range(256):
        j = (j + S[i] + key[i % key_len]) % 256
        S[i], S[j] = S[j], S[i]
    
    # Generate keystream
    i = j = 0
    test_ks = bytearray()
    for _ in range(64):
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        test_ks.append(S[(S[i] + S[j]) % 256])
    
    if bytes(test_ks[:32]) == keystream[:32]:
        print(f"  KEY FOUND: {s}")
    else:
        print(f"  Key '{s.decode(errors='replace')}' ({len(s)}B): first 32B mismatch")

# Try MD5/SHA256 of test strings as key
for s in test_strings:
    for hash_func, hash_name in [(hashlib.md5, 'MD5'), (hashlib.sha256, 'SHA256')]:
        h = hash_func(s).digest()
        S = list(range(256))
        j = 0
        key = h
        key_len = len(key)
        for i in range(256):
            j = (j + S[i] + key[i % key_len]) % 256
            S[i], S[j] = S[j], S[i]
        i = j = 0
        test_ks = bytearray()
        for _ in range(64):
            i = (i + 1) % 256
            j = (j + S[i]) % 256
            S[i], S[j] = S[j], S[i]
            test_ks.append(S[(S[i] + S[j]) % 256])
        if bytes(test_ks[:32]) == keystream[:32]:
            print(f"  KEY FOUND: {hash_name}({s.decode(errors='replace')})")

print("\nDone!")