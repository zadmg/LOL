# -*- coding: utf-8 -*-
"""Apply corrected patches - only 2 patches needed"""
import shutil

EXE = r'D:\SRC\SRC\16.13.exe'
BAK = r'D:\SRC\SRC\16.13.exe.bak'

# Restore from backup first
shutil.copyfile(BAK, EXE)
print("Restored from backup")

patches = [
    # Patch 1: sub_4141FA "200" check - bypass return 0, continue to save account/password
    # 0x4142CB: jz loc_4142DB (rel32=0x0A, 6 bytes) -> jmp loc_4142DB (rel32=0x0B, 5 bytes) + nop
    # CRITICAL: rel32 must be 0x0B (not 0x0A) because jmp is 5 bytes, jz is 6 bytes
    (0x142CB,
     bytes.fromhex('0f840a000000'),   # original: jz rel32=0x0A (target 0x4142DB)
     bytes.fromhex('e90b00000090'),   # patch: jmp rel32=0x0B (target 0x4142DB) + nop
     '0x4142CB: jz -> jmp (bypass sub_4141FA 200 check, continue save account)'),

    # Patch 2: button handler return value check - always call sub_416C53
    # 0x416B43: jz loc_416BCD (6 bytes) -> NOP x 6
    (0x16B43,
     bytes.fromhex('0f8484000000'),   # original: jz rel32=0x84
     bytes.fromhex('909090909090'),   # patch: NOP x 6
     '0x416B43: jz -> NOP (bypass button handler return check, always call sub_416C53)'),
]

with open(EXE, 'r+b') as f:
    for offset, expected, patched, desc in patches:
        f.seek(offset)
        actual = f.read(len(expected))
        if actual != expected:
            print("ERROR at 0x%X: expected %s, got %s" % (
                offset, expected.hex(), actual.hex()))
            print("  Description: %s" % desc)
            continue
        f.seek(offset)
        f.write(patched)
        # Verify
        f.seek(offset)
        verify = f.read(len(patched))
        ok = verify == patched
        status = 'OK' if ok else 'FAIL'
        print("[%s] 0x%X: %s -> %s" % (status, offset, expected.hex(), patched.hex()))
        print("    %s" % desc)

print("\nDone. Patches applied.")
