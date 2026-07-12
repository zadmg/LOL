// ============================================================
// Decompiled source of PE#1 (fake dbgcore.dll)
// File: D:\SRC\SRC\embedded_pe\embedded_1_at_0xC7F0.exe_unpacked.exe
// Image base: 0x180000000
// Total functions: 39
// ============================================================


// ------------------------------------------------------------
// Function 1/39: MiniDumpReadDumpStream
// Address: 0x180001000 - 0x180001007 (size 0x7)
// ------------------------------------------------------------
// attributes: thunk
BOOL __stdcall MiniDumpReadDumpStream(
        PVOID BaseOfDump,
        ULONG StreamNumber,
        PMINIDUMP_DIRECTORY *Dir,
        PVOID *StreamPointer,
        ULONG *StreamSize)
{
  return qword_180003158(BaseOfDump, StreamNumber, Dir, StreamPointer, StreamSize);
}


// ------------------------------------------------------------
// Function 2/39: MiniDumpWriteDump
// Address: 0x180001010 - 0x180001017 (size 0x7)
// ------------------------------------------------------------
// attributes: thunk
BOOL __stdcall MiniDumpWriteDump(
        HANDLE hProcess,
        DWORD ProcessId,
        HANDLE hFile,
        MINIDUMP_TYPE DumpType,
        PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
        PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
        PMINIDUMP_CALLBACK_INFORMATION CallbackParam)
{
  return qword_180003160(hProcess, ProcessId, hFile, DumpType, ExceptionParam, UserStreamParam, CallbackParam);
}


// ------------------------------------------------------------
// Function 3/39: sub_180001020
// Address: 0x180001020 - 0x18000112D (size 0x10D)
// ------------------------------------------------------------
__int64 __fastcall sub_180001020(HMODULE a1, int a2)
{
  HMODULE LibraryA; // rax
  BOOL (__stdcall *MiniDumpReadDumpStream)(PVOID, ULONG, PMINIDUMP_DIRECTORY *, PVOID *, ULONG *); // rax
  BOOL (__stdcall *MiniDumpWriteDump)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION); // rax
  const CHAR *v6; // rdx
  CHAR Buffer[280]; // [rsp+20h] [rbp-118h] BYREF

  if ( a2 )
  {
    if ( a2 == 1 )
    {
      DisableThreadLibraryCalls(a1);
      GetSystemDirectoryA(Buffer, 0x104u);
      lstrcatA(Buffer, "\\dbgcore.dll");
      LibraryA = LoadLibraryA(Buffer);
      hLibModule = LibraryA;
      if ( LibraryA )
      {
        MiniDumpReadDumpStream = (BOOL (__stdcall *)(PVOID, ULONG, PMINIDUMP_DIRECTORY *, PVOID *, ULONG *))GetProcAddress(LibraryA, "MiniDumpReadDumpStream");
        if ( MiniDumpReadDumpStream )
        {
          qword_180003158 = MiniDumpReadDumpStream;
          MiniDumpWriteDump = (BOOL (__stdcall *)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION))GetProcAddress(hLibModule, "MiniDumpWriteDump");
          if ( MiniDumpWriteDump )
          {
            qword_180003160 = MiniDumpWriteDump;
            qword_180003170 = LoadLibraryA("C:\\Users\\Public\\FlyPY\\flyinput.dll");
            return 1;
          }
        }
        v6 = "Get address failed";
      }
      else
      {
        v6 = "Load original dll failed";
      }
      MessageBoxA(0, v6, "dbgcore", 0);
      ExitProcess(1u);
    }
  }
  else
  {
    if ( hLibModule )
      FreeLibrary(hLibModule);
    if ( qword_180003170 )
      FreeLibrary(qword_180003170);
  }
  return 1;
}


// ------------------------------------------------------------
// Function 4/39: sub_18000113C
// Address: 0x18000113C - 0x180001153 (size 0x17)
// ------------------------------------------------------------
__int64 __fastcall sub_18000113C(__int64 a1)
{
  return (unsigned int)(sub_180001154(a1) != 0) - 1;
}


// ------------------------------------------------------------
// Function 5/39: sub_180001154
// Address: 0x180001154 - 0x18000118E (size 0x3A)
// ------------------------------------------------------------
void (__cdecl *__fastcall sub_180001154(void (__cdecl *a1)()))()
{
  int v2; // eax
  __int64 v3; // rdx

  if ( Table._first == (_PVFV *)-1LL )
    v2 = crt_atexit(a1);
  else
    v2 = register_onexit_function(&Table, (_onexit_t)a1);
  v3 = 0;
  if ( !v2 )
    return a1;
  return (void (__cdecl *)())v3;
}


// ------------------------------------------------------------
// Function 6/39: sub_180001190
// Address: 0x180001190 - 0x180001228 (size 0x98)
// ------------------------------------------------------------
bool __fastcall sub_180001190(__int64 a1)
{
  _DWORD *v2; // rcx
  unsigned __int64 v3; // r8
  _DWORD *v4; // rdx
  _DWORD *v5; // r9
  unsigned __int64 v6; // rcx

  if ( MEMORY[0x180000000] != 23117 )
    return 0;
  v2 = (_DWORD *)(0x180000000LL + MEMORY[0x18000003C]);
  if ( *v2 != 17744 || *(_WORD *)(0x180000018LL + MEMORY[0x18000003C]) != 523 )
    return 0;
  v3 = a1 - 0x180000000LL;
  v4 = (_DWORD *)((char *)v2 + *(unsigned __int16 *)(0x180000014LL + MEMORY[0x18000003C]) + 24);
  v5 = &v4[10 * *(unsigned __int16 *)(0x180000006LL + MEMORY[0x18000003C])];
  while ( v4 != v5 )
  {
    v6 = (unsigned int)v4[3];
    if ( v3 >= v6 && v3 < (unsigned int)(v6 + v4[2]) )
      return v4 && v4[9] >= 0;
    v4 += 10;
  }
  v4 = 0;
  return v4 && v4[9] >= 0;
}


// ------------------------------------------------------------
// Function 7/39: sub_180001228
// Address: 0x180001228 - 0x180001261 (size 0x39)
// ------------------------------------------------------------
char sub_180001228()
{
  PVOID StackBase; // rcx
  signed __int64 v1; // rax

  if ( (unsigned int)sub_180001784() )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    while ( 1 )
    {
      v1 = _InterlockedCompareExchange64(&qword_1800030D0, (signed __int64)StackBase, 0);
      if ( !v1 )
        break;
      if ( StackBase == (PVOID)v1 )
        return 1;
    }
  }
  return 0;
}


// ------------------------------------------------------------
// Function 8/39: sub_180001264
// Address: 0x180001264 - 0x180001288 (size 0x24)
// ------------------------------------------------------------
__int64 __fastcall sub_180001264(char a1)
{
  __int64 result; // rax

  result = sub_180001784();
  if ( (_DWORD)result )
  {
    if ( !a1 )
      _InterlockedExchange64(&qword_1800030D0, 0);
  }
  return result;
}


// ------------------------------------------------------------
// Function 9/39: sub_180001288
// Address: 0x180001288 - 0x1800012C2 (size 0x3A)
// ------------------------------------------------------------
char __fastcall sub_180001288(int a1)
{
  if ( !a1 )
    byte_1800030D8 = 1;
  sub_1800014E0();
  if ( !(unsigned __int8)((__int64 (*)(void))sub_180001C74)() )
    return 0;
  if ( !(unsigned __int8)((__int64 (*)(void))sub_180001C74)() )
  {
    sub_180001C74(0);
    return 0;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 10/39: sub_1800012C4
// Address: 0x1800012C4 - 0x1800012ED (size 0x29)
// ------------------------------------------------------------
char __fastcall sub_1800012C4(__int64 a1, char a2)
{
  char v2; // bl
  __int64 v3; // rcx

  v2 = a1;
  if ( !byte_1800030D8 || !a2 )
  {
    sub_180001C74(a1);
    LOBYTE(v3) = v2;
    sub_180001C74(v3);
  }
  return 1;
}


// ------------------------------------------------------------
// Function 11/39: sub_1800012F0
// Address: 0x1800012F0 - 0x18000137B (size 0x8B)
// ------------------------------------------------------------
char __fastcall sub_1800012F0(unsigned int a1)
{
  if ( !byte_1800030D9 )
  {
    if ( a1 > 1 )
      RtlFailFast(5);
    if ( !(unsigned int)sub_180001784() || a1 )
    {
      *(__m128i *)&Table._first = _mm_load_si128((const __m128i *)&xmmword_180002100);
      Table._end = (_PVFV *)-1LL;
      *(_OWORD *)&stru_1800030F8._first = *(_OWORD *)&Table._first;
      stru_1800030F8._end = (_PVFV *)-1LL;
    }
    else if ( (unsigned int)((__int64 (__fastcall *)(_onexit_table_t *))initialize_onexit_table)(&Table)
           || (unsigned int)((__int64 (__fastcall *)(_onexit_table_t *))initialize_onexit_table)(&stru_1800030F8) )
    {
      return 0;
    }
    byte_1800030D9 = 1;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 12/39: sub_18000137C
// Address: 0x18000137C - 0x1800013DC (size 0x60)
// ------------------------------------------------------------
void __fastcall sub_18000137C(__int64 a1, int a2, __int64 a3, void (__fastcall *a4)(__int64, _QWORD, __int64))
{
  if ( !(unsigned int)sub_180001784() && a2 == 1 )
    a4(a1, 0, a3);
  JUMPOUT(0x180001E50LL);
}


// ------------------------------------------------------------
// Function 13/39: sub_1800013DC
// Address: 0x1800013DC - 0x1800013F1 (size 0x15)
// ------------------------------------------------------------
bool sub_1800013DC()
{
  return sub_1800012F0(0) != 0;
}


// ------------------------------------------------------------
// Function 14/39: sub_1800013F4
// Address: 0x1800013F4 - 0x180001428 (size 0x34)
// ------------------------------------------------------------
char sub_1800013F4()
{
  unsigned int v0; // eax

  if ( (unsigned int)sub_180001784() )
  {
    sub_1800014E0();
  }
  else
  {
    v0 = sub_18000177C();
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))configure_narrow_argv)(v0) )
      return 0;
    initialize_narrow_environment();
  }
  return 1;
}


// ------------------------------------------------------------
// Function 15/39: sub_180001428
// Address: 0x180001428 - 0x180001458 (size 0x30)
// ------------------------------------------------------------
__int64 sub_180001428()
{
  __int64 result; // rax

  if ( (unsigned int)sub_180001784() )
    JUMPOUT(0x180001DF0LL);
  result = sub_180001C78();
  if ( !(_DWORD)result )
    return ((__int64 (*)(void))cexit)();
  return result;
}


// ------------------------------------------------------------
// Function 16/39: sub_180001458
// Address: 0x180001458 - 0x18000146C (size 0x14)
// ------------------------------------------------------------
__int64 sub_180001458()
{
  __int64 v0; // rcx

  sub_180001C74(0);
  return sub_180001C74(v0);
}


// ------------------------------------------------------------
// Function 17/39: sub_18000146C
// Address: 0x18000146C - 0x180001494 (size 0x28)
// ------------------------------------------------------------
char __fastcall sub_18000146C(__int64 a1)
{
  __int64 v1; // rcx
  __int64 v3; // rcx

  if ( !(unsigned __int8)sub_180001C74(a1) )
    return 0;
  if ( !(unsigned __int8)sub_180001C74(v1) )
  {
    sub_180001C74(v3);
    return 0;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 18/39: sub_180001494
// Address: 0x180001494 - 0x1800014A9 (size 0x15)
// ------------------------------------------------------------
char __fastcall sub_180001494(__int64 a1)
{
  __int64 v1; // rcx

  sub_180001C74(a1);
  sub_180001C74(v1);
  return 1;
}


// ------------------------------------------------------------
// Function 19/39: __security_check_cookie
// Address: 0x1800014C0 - 0x1800014DE (size 0x1E)
// ------------------------------------------------------------
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != _security_cookie )
loc_1800014D9:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto LABEL_4;
  }
}


// ------------------------------------------------------------
// Function 20/39: sub_1800014E0
// Address: 0x1800014E0 - 0x18000177B (size 0x29B)
// ------------------------------------------------------------
__int64 sub_1800014E0()
{
  int v5; // ebp
  bool v7; // zf
  int v12; // edi
  int v13; // eax
  unsigned __int64 v14; // rax
  __int64 v15; // rcx
  int v16; // r8d
  int v17; // r9d
  unsigned int v18; // r11d
  int v24; // esi
  int v25; // r10d
  unsigned __int64 v36; // rax
  int v37; // eax
  unsigned __int64 v38; // rax
  __int64 v39; // rdx
  int v41; // [rsp+20h] [rbp+8h]

  _RAX = 0;
  __asm { cpuid }
  v5 = _RAX;
  _RAX = 1;
  v7 = ((unsigned int)_RBX ^ 0x756E6547 | (unsigned int)_RCX ^ 0x6C65746E | (unsigned int)_RDX ^ 0x49656E69) == 0;
  __asm { cpuid }
  v12 = _RCX;
  if ( v7
    && ((v13 = _RAX & 0xFFF3FF0, qword_180003090 = 0x8000, qword_180003098 = -1, v13 == 67264)
     || v13 == 132704
     || v13 == 132720
     || (v14 = (unsigned int)(v13 - 198224), (unsigned int)v14 <= 0x20) && (v15 = 0x100010001LL, _bittest64(&v15, v14))) )
  {
    v16 = dword_180003110 | 1;
    dword_180003110 |= 1u;
  }
  else
  {
    v16 = dword_180003110;
  }
  v17 = 0;
  v18 = 0;
  if ( v5 < 7 )
  {
    v25 = 0;
    v24 = 0;
  }
  else
  {
    _RAX = 7;
    __asm { cpuid }
    v24 = _RDX;
    v25 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      dword_180003110 = v16 | 2;
    if ( (int)_RAX >= 1 )
    {
      _RAX = 7;
      __asm { cpuid }
      v17 = _RDX;
    }
    _RAX = 36;
    if ( v5 >= 36 )
    {
      __asm { cpuid }
      v18 = _RBX;
    }
  }
  v36 = qword_1800030A0 & 0xFFFFFFFFFFFFFFFEuLL;
  dword_180003088 = 1;
  dword_18000308C = 2;
  qword_1800030A0 &= ~1uLL;
  if ( (v12 & 0x100000) != 0 )
  {
    v36 &= ~0x10uLL;
    dword_180003088 = 2;
    qword_1800030A0 = v36;
    dword_18000308C = 6;
  }
  if ( (v12 & 0x8000000) != 0 )
  {
    __asm { xgetbv }
    v41 = v36;
    if ( (v12 & 0x10000000) == 0 || (v36 & 6) != 6 )
    {
LABEL_33:
      if ( (v17 & 0x200000) != 0 && (*(_QWORD *)&v41 & 0x80000LL) != 0 )
        qword_1800030A0 &= ~0x80uLL;
      return 0;
    }
    v37 = dword_18000308C | 8;
    dword_180003088 = 3;
    dword_18000308C |= 8u;
    if ( (v25 & 0x20) != 0 )
    {
      dword_180003088 = 5;
      dword_18000308C = v37 | 0x20;
      v38 = qword_1800030A0 & 0xFFFFFFFFFFFFFFFDuLL;
      qword_1800030A0 &= ~2uLL;
      if ( (v25 & 0xD0030000) != 0xD0030000 )
      {
LABEL_27:
        if ( (v24 & 0x800000) != 0 )
          qword_1800030A0 = v38 & 0xFFFFFFFFFEFFFFFFuLL;
        if ( (v17 & 0x80000) != 0 && (v41 & 0xE0) == 0xE0 )
        {
          dword_180003114 = v18 & 0x400FF;
          v39 = ~(HIWORD(v18) & 6 | 0x1000029LL) & qword_1800030A0;
          qword_1800030A0 = v39;
          if ( (unsigned __int8)v18 > 1u )
            qword_1800030A0 = v39 & 0xFFFFFFFFFFFFFFBFuLL;
        }
        goto LABEL_33;
      }
      if ( (v41 & 0xE0) == 0xE0 )
      {
        dword_18000308C |= 0x40u;
        v38 = qword_1800030A0 & 0xFFFFFFFFFFFFFFDBuLL;
        dword_180003088 = 6;
        qword_1800030A0 &= 0xFFFFFFFFFFFFFFDBuLL;
        goto LABEL_27;
      }
    }
    v38 = qword_1800030A0;
    goto LABEL_27;
  }
  return 0;
}


// ------------------------------------------------------------
// Function 21/39: RtlFailFast
// Address: 0x180001790 - 0x180001794 (size 0x4)
// ------------------------------------------------------------
void __fastcall __noreturn RtlFailFast(unsigned int a1)
{
  __fastfail(a1);
}


// ------------------------------------------------------------
// Function 22/39: __report_gsfailure
// Address: 0x1800017A0 - 0x1800017A7 (size 0x7)
// ------------------------------------------------------------
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  __fastfail(2u);
}


// ------------------------------------------------------------
// Function 23/39: sub_1800017A8
// Address: 0x1800017A8 - 0x1800018BE (size 0x116)
// ------------------------------------------------------------
__int64 __fastcall sub_1800017A8(__int64 a1, __int64 a2)
{
  char v4; // bl
  char v5; // di
  _QWORD *v6; // rax

  if ( !sub_180001288(0) )
    return 0;
  v4 = sub_180001228();
  v5 = 1;
  if ( dword_1800030C8 )
    RtlFailFast(7u);
  dword_1800030C8 = 1;
  if ( sub_1800013DC() )
  {
    sub_180001BFC();
    sub_180001BAC();
    sub_180001BC8();
    if ( !(unsigned int)((__int64 (__fastcall *)(const _PIFV *, __int64 *))initterm_e)(&First, &qword_180002348) )
    {
      if ( sub_1800013F4() )
      {
        ((void (__fastcall *)(__int64 *, __int64 *))initterm)(&qword_180002328, &qword_180002338);
        dword_1800030C8 = 2;
        v5 = 0;
      }
    }
  }
  sub_180001264(v4);
  if ( v5 )
    return 0;
  v6 = (_QWORD *)sub_180001BF4();
  if ( *v6 )
  {
    if ( sub_180001190((__int64)v6) )
      _guard_dispatch_icall_fptr(a1, 2, a2);
  }
  ++dword_180003120;
  return 1;
}


// ------------------------------------------------------------
// Function 24/39: sub_1800018C0
// Address: 0x1800018C0 - 0x180001943 (size 0x83)
// ------------------------------------------------------------
__int64 __fastcall sub_1800018C0(char a1)
{
  char v3; // bl
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  unsigned int v7; // ebx

  if ( dword_180003120 <= 0 )
    return 0;
  --dword_180003120;
  v3 = sub_180001228();
  if ( dword_1800030C8 != 2 )
    RtlFailFast(7u);
  sub_180001428();
  sub_180001BBC(v4);
  sub_180001C38(v5);
  dword_1800030C8 = 0;
  sub_180001264(v3);
  LOBYTE(v6) = a1;
  v7 = (unsigned __int8)sub_1800012C4(v6, 0);
  sub_180001458();
  return v7;
}


// ------------------------------------------------------------
// Function 25/39: sub_180001944
// Address: 0x180001944 - 0x180001994 (size 0x50)
// ------------------------------------------------------------
__int64 __fastcall sub_180001944(__int64 a1, int a2, __int64 a3)
{
  int v3; // edx
  int v4; // edx
  __int64 result; // rax

  if ( !a2 )
    return sub_1800018C0(a3 != 0);
  v3 = a2 - 1;
  if ( !v3 )
    return sub_1800017A8(a1, a3);
  v4 = v3 - 1;
  if ( v4 )
  {
    if ( v4 != 1 )
      return 1;
    LOBYTE(result) = sub_180001494(a1);
  }
  else
  {
    LOBYTE(result) = sub_18000146C(a1);
  }
  return (unsigned __int8)result;
}


// ------------------------------------------------------------
// Function 26/39: sub_180001994
// Address: 0x180001994 - 0x180001ABC (size 0x128)
// ------------------------------------------------------------
__int64 __fastcall sub_180001994(HMODULE a1, int a2, __int64 a3)
{
  unsigned int v7; // ebx
  unsigned int v8; // eax

  if ( !a2 && dword_180003120 <= 0 )
    return 0;
  if ( (unsigned int)(a2 - 1) > 1 || (v7 = sub_180001944((__int64)a1, a2, a3)) != 0 )
  {
    v8 = sub_180001020(a1, a2);
    v7 = v8;
    if ( a2 == 1 && !v8 )
    {
      sub_180001020(a1, 0);
      sub_1800018C0(a3 != 0);
    }
    if ( !a2 || a2 == 3 )
      return (unsigned int)sub_180001944((__int64)a1, a2, a3) != 0;
  }
  return v7;
}


// ------------------------------------------------------------
// Function 27/39: DllEntryPoint
// Address: 0x180001ABC - 0x180001AF9 (size 0x3D)
// ------------------------------------------------------------
BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    sub_180001AFC();
  return sub_180001994(hinstDLL, fdwReason, (__int64)lpReserved);
}


// ------------------------------------------------------------
// Function 28/39: sub_180001AFC
// Address: 0x180001AFC - 0x180001BAB (size 0xAF)
// ------------------------------------------------------------
__int64 sub_180001AFC()
{
  uintptr_t v0; // rax
  __int64 result; // rax
  struct _FILETIME v2; // [rsp+20h] [rbp-10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+40h] [rbp+10h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+48h] [rbp+18h] BYREF

  v0 = _security_cookie;
  if ( _security_cookie == 0x2B992DDFA232LL )
  {
    SystemTimeAsFileTime = 0;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v2 = SystemTimeAsFileTime;
    v2 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v2);
    v2 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v2);
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v2
        ^ *(_QWORD *)&v2
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
    if ( v0 == 0x2B992DDFA232LL )
      v0 = 0x2B992DDFA233LL;
    _security_cookie = v0;
  }
  result = ~v0;
  qword_180003080 = result;
  return result;
}


// ------------------------------------------------------------
// Function 29/39: sub_180001BC8
// Address: 0x180001BC8 - 0x180001BE3 (size 0x1B)
// ------------------------------------------------------------
_QWORD *sub_180001BC8()
{
  _QWORD *v0; // rax
  _QWORD *result; // rax

  v0 = (_QWORD *)sub_180001BE4();
  *v0 |= 0x24uLL;
  result = (_QWORD *)sub_180001BEC();
  *result |= 2uLL;
  return result;
}


// ------------------------------------------------------------
// Function 30/39: sub_180001BFC
// Address: 0x180001BFC - 0x180001C38 (size 0x3C)
// ------------------------------------------------------------
void sub_180001BFC()
{
  void (**i)(void); // rbx

  for ( i = qword_180002908; i < qword_180002908; ++i )
  {
    if ( *i )
      (*i)();
  }
}


// ------------------------------------------------------------
// Function 31/39: sub_180001C38
// Address: 0x180001C38 - 0x180001C74 (size 0x3C)
// ------------------------------------------------------------
void sub_180001C38()
{
  void (**i)(void); // rbx

  for ( i = &qword_180002918; i < &qword_180002918; ++i )
  {
    if ( *i )
      (*i)();
  }
}


// ------------------------------------------------------------
// Function 32/39: sub_180001CB6
// Address: 0x180001CB6 - 0x180001CCE (size 0x18)
// ------------------------------------------------------------
_BOOL8 __fastcall sub_180001CB6(_DWORD **a1)
{
  return **a1 == -1073741819;
}


// ------------------------------------------------------------
// Function 33/39: sub_180001CCE
// Address: 0x180001CCE - 0x180001CE5 (size 0x17)
// ------------------------------------------------------------
__int64 __fastcall sub_180001CCE(__int64 a1, __int64 a2)
{
  return sub_180001264(*(_BYTE *)(a2 + 64));
}


// ------------------------------------------------------------
// Function 34/39: sub_180001CE5
// Address: 0x180001CE5 - 0x180001CFE (size 0x19)
// ------------------------------------------------------------
__int64 __fastcall sub_180001CE5(__int64 a1, __int64 a2)
{
  return sub_180001264(*(_BYTE *)(a2 + 32));
}


// ------------------------------------------------------------
// Function 35/39: sub_180001CFE
// Address: 0x180001CFE - 0x180001D12 (size 0x14)
// ------------------------------------------------------------
__int64 sub_180001CFE()
{
  return sub_180001458();
}


// ------------------------------------------------------------
// Function 36/39: sub_180001D12
// Address: 0x180001D12 - 0x180001D48 (size 0x36)
// ------------------------------------------------------------
void __fastcall sub_180001D12(__int64 a1, __int64 a2)
{
  sub_18000137C(
    *(_QWORD *)(a2 + 96),
    *(_DWORD *)(a2 + 104),
    *(_QWORD *)(a2 + 112),
    (void (__fastcall *)(__int64, _QWORD, __int64))sub_180001944);
}


// ------------------------------------------------------------
// Function 37/39: sub_180001D48
// Address: 0x180001D48 - 0x180001D9F (size 0x57)
// ------------------------------------------------------------
void sub_180001D48()
{
  __int64 v0; // rcx
  void (__fastcall ***v1)(_QWORD, __int64); // rax
  void *v2; // rbx

  while ( 1 )
  {
    v2 = Block;
    if ( !Block )
      break;
    v0 = *((_QWORD *)Block + 1);
    Block = *(void **)Block;
    v1 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v0 + 16LL))(v0);
    if ( v1 )
      (**v1)(v1, 1);
    free(v2);
  }
}


// ------------------------------------------------------------
// Function 38/39: _crt_atexit
// Address: 0x180001DE0 - 0x180001DE6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl crt_atexit(_PVFV Function)
{
  return _crt_atexit(Function);
}


// ------------------------------------------------------------
// Function 39/39: _register_onexit_function
// Address: 0x180001E40 - 0x180001E46 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl register_onexit_function(_onexit_table_t *Table, _onexit_t Function)
{
  return _register_onexit_function(Table, Function);
}

