# -*- coding: utf-8 -*-
"""Dump MJTVPFeD.dat from 64-bit process - v4"""
import ctypes
from ctypes import wintypes
import struct
import os

PROCESS_QUERY_INFORMATION = 0x0400
PROCESS_VM_READ = 0x0010

kernel32 = ctypes.WinDLL('kernel32', use_last_error=True)

def dump_process(pid, base_addr, size, output_path):
    h_process = kernel32.OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, False, pid)
    if not h_process:
        print("OpenProcess failed: %d" % ctypes.get_last_error())
        return False

    print("Process handle: 0x%X" % h_process)
    print("Base: 0x%X, Size: 0x%X (%d)" % (base_addr, size, size))

    # Read entire image in chunks
    image_buf = bytearray(size)
    chunk_size = 0x1000
    total_read = 0
    for off in range(0, size, chunk_size):
        to_read = min(chunk_size, size - off)
        chunk = (ctypes.c_ubyte * to_read)()
        bytes_read = ctypes.c_size_t()
        if kernel32.ReadProcessMemory(h_process, ctypes.c_void_p(base_addr + off),
                                      chunk, to_read, ctypes.byref(bytes_read)):
            image_buf[off:off+bytes_read.value] = bytes(chunk)[:bytes_read.value]
            total_read += bytes_read.value

    print("Total read: %d / %d bytes" % (total_read, size))

    with open(output_path, 'wb') as f:
        f.write(image_buf)
    print("Written to %s" % output_path)

    # Verify PE header
    if image_buf[0:2] == b'MZ':
        print("PE header: MZ verified")
        e_lfanew = struct.unpack_from('<I', image_buf, 0x3C)[0]
        print("e_lfanew = 0x%X" % e_lfanew)
        if image_buf[e_lfanew:e_lfanew+4] == b'PE\x00\x00':
            print("PE signature verified")
            opt_offset = e_lfanew + 24
            magic = struct.unpack_from('<H', image_buf, opt_offset)[0]
            print("Magic: 0x%X (%s)" % (magic, "PE32" if magic == 0x10b else "PE32+ (64-bit)"))
            # Read sections
            num_sections = struct.unpack_from('<H', image_buf, e_lfanew + 6)[0]
            size_opt_hdr = struct.unpack_from('<H', image_buf, e_lfanew + 20)[0]
            print("NumberOfSections = %d" % num_sections)
            sections_offset = e_lfanew + 24 + size_opt_hdr
            max_raw_end = 0
            for i in range(num_sections):
                sec_off = sections_offset + i * 40
                sec_name = image_buf[sec_off:sec_off+8].rstrip(b'\x00').decode('ascii', errors='replace')
                raw_size = struct.unpack_from('<I', image_buf, sec_off + 16)[0]
                raw_ptr = struct.unpack_from('<I', image_buf, sec_off + 20)[0]
                virt_size = struct.unpack_from('<I', image_buf, sec_off + 8)[0]
                virt_ptr = struct.unpack_from('<I', image_buf, sec_off + 12)[0]
                print("  Section '%s': Raw=0x%X@0x%X Virt=0x%X@0x%X" % (
                    sec_name, raw_size, raw_ptr, virt_size, virt_ptr))
                raw_end = raw_ptr + raw_size
                if raw_end > max_raw_end:
                    max_raw_end = raw_end
            print("Max raw end: 0x%X (%d)" % (max_raw_end, max_raw_end))
        else:
            print("Invalid PE signature")
    else:
        print("Invalid header: %s" % image_buf[0:2].hex())

    kernel32.CloseHandle(h_process)
    return True

if __name__ == '__main__':
    pid = 11520
    base_addr = 0x7FF71BC60000
    size = 0x20000  # 131072
    output = r'D:\SRC\SRC\MJTVPFeD_dumped.exe'
    print("Dumping process %d (base 0x%X, size 0x%X) to %s" % (pid, base_addr, size, output))
    if dump_process(pid, base_addr, size, output):
        actual_size = os.path.getsize(output)
        print("\nFinal file size: %d bytes" % actual_size)
    else:
        print("Dump failed")
