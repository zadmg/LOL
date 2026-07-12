// ============================================================
// Decompiled source of PE#2 (flyinput.dll)
// File: D:\SRC\SRC\embedded_pe\embedded_2_at_0xFFD0.exe_unpacked.exe
// Image base: 0x180000000
// Total functions: 121
// ============================================================


// ------------------------------------------------------------
// Function 1/121: sub_180001000
// Address: 0x180001000 - 0x180001079 (size 0x79)
// ------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
UINT __fastcall sub_180001000(double _XMM0_8)
{
  UINT result; // eax

  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vmovups ymmword ptr cs:stru_180019240.type, ymm0
    vmovups ymmword ptr cs:unk_180019270, ymm0
    vmovups ymmword ptr cs:stru_180019240.8+18h, ymm0
  }
  stru_180019240.type = 1;
  __asm { vzeroupper }
  stru_180019240.ki.wScan = MapVirtualKeyA(0x51u, 0);
  stru_180019240.mi.dy = 8;
  unk_180019268 = 1;
  result = MapVirtualKeyA(0x51u, 0);
  unk_180019272 = result;
  unk_180019274 = 10;
  return result;
}


// ------------------------------------------------------------
// Function 2/121: sub_180001080
// Address: 0x180001080 - 0x1800010F9 (size 0x79)
// ------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
UINT __fastcall sub_180001080(double _XMM0_8)
{
  UINT result; // eax

  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vmovups ymmword ptr cs:stru_180019290.type, ymm0
    vmovups ymmword ptr cs:unk_1800192C0, ymm0
    vmovups ymmword ptr cs:stru_180019290.8+18h, ymm0
  }
  stru_180019290.type = 1;
  __asm { vzeroupper }
  stru_180019290.ki.wScan = MapVirtualKeyA(0x57u, 0);
  stru_180019290.mi.dy = 8;
  unk_1800192B8 = 1;
  result = MapVirtualKeyA(0x57u, 0);
  unk_1800192C2 = result;
  unk_1800192C4 = 10;
  return result;
}


// ------------------------------------------------------------
// Function 3/121: sub_180001100
// Address: 0x180001100 - 0x180001179 (size 0x79)
// ------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
UINT __fastcall sub_180001100(double _XMM0_8)
{
  UINT result; // eax

  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vmovups ymmword ptr cs:stru_1800192E0.type, ymm0
    vmovups ymmword ptr cs:unk_180019310, ymm0
    vmovups ymmword ptr cs:stru_1800192E0.8+18h, ymm0
  }
  stru_1800192E0.type = 1;
  __asm { vzeroupper }
  stru_1800192E0.ki.wScan = MapVirtualKeyA(0x45u, 0);
  stru_1800192E0.mi.dy = 8;
  unk_180019308 = 1;
  result = MapVirtualKeyA(0x45u, 0);
  unk_180019312 = result;
  unk_180019314 = 10;
  return result;
}


// ------------------------------------------------------------
// Function 4/121: sub_180001180
// Address: 0x180001180 - 0x1800049E9 (size 0x3869)
// ------------------------------------------------------------
__int64 __fastcall sub_180001180()
{
  HMODULE ModuleHandleA; // rax
  FARPROC NtSetInformationThread; // rsi
  HANDLE CurrentThread; // rax
  __int64 result; // rax
  __int64 v25; // rcx
  char v27; // cf
  __int64 perf_frequency; // rsi
  __int64 perf_counter; // rax
  __int64 v31; // r12
  __int64 v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rax
  bool v36; // of
  __int64 v37; // r12
  __int64 v38; // rsi
  __int64 v39; // rax
  __int64 v40; // rcx
  __int64 v41; // rdx
  __int64 v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rax
  __int64 v45; // r8
  DWORD v46; // ecx
  HWND v52; // rcx
  unsigned __int8 *v54; // rdx
  __int64 v55; // rax
  unsigned __int8 *v56; // rax
  __int64 v57; // rsi
  __int64 v58; // rbx
  char *v60; // rcx
  __int64 v61; // rbp
  __int64 v62; // rdi
  unsigned __int64 v63; // rbx
  char *v64; // rcx
  char *v65; // rdx
  __int64 v66; // r12
  unsigned __int64 v67; // rax
  unsigned __int64 v68; // rsi
  unsigned __int64 v69; // r15
  size_t v70; // rcx
  __int64 v71; // rax
  _QWORD *v72; // r14
  void *v73; // rcx
  char *v74; // rbx
  char *v75; // rsi
  char *v76; // rax
  unsigned __int64 v77; // rbx
  char v78; // cl
  char *v79; // rax
  void *v80; // rsi
  unsigned __int64 v81; // rcx
  BOOL v82; // ebp
  unsigned __int64 v83; // r15
  unsigned __int64 v85; // rax
  int v86; // edi
  char *v87; // r12
  __int64 v88; // rbp
  unsigned __int64 v89; // rcx
  unsigned __int64 v90; // rsi
  unsigned __int64 v91; // rax
  unsigned __int64 v92; // rdx
  unsigned __int64 v93; // rax
  __int64 v94; // r15
  __int64 v95; // rax
  char *v96; // r13
  size_t v97; // r8
  char *v98; // rcx
  char *v99; // rdx
  void *v100; // rsi
  BOOL v101; // ebp
  __int64 v102; // r15
  void *v104; // rsi
  BOOL v105; // ebp
  __int64 v106; // r15
  unsigned __int64 v108; // rax
  char *v109; // r12
  __int64 v110; // rbp
  unsigned __int64 v111; // rcx
  unsigned __int64 v112; // rax
  unsigned __int64 v113; // rdx
  unsigned __int64 v114; // rax
  __int64 v115; // r15
  __int64 v116; // rax
  char *v117; // r13
  unsigned __int64 v118; // rax
  char *v119; // r12
  __int64 v120; // rbp
  unsigned __int64 v121; // rcx
  unsigned __int64 v122; // rax
  unsigned __int64 v123; // rdx
  unsigned __int64 v124; // rax
  __int64 v125; // r15
  __int64 v126; // rax
  char *v127; // r13
  size_t v128; // r8
  char *v129; // rcx
  char *v130; // rdx
  void *v131; // rsi
  BOOL v132; // ebp
  __int64 v133; // r15
  unsigned __int64 v135; // rax
  char *v136; // r12
  __int64 v137; // rbp
  unsigned __int64 v138; // rcx
  unsigned __int64 v139; // rax
  unsigned __int64 v140; // rdx
  unsigned __int64 v141; // rax
  __int64 v142; // r15
  __int64 v143; // rax
  char *v144; // r13
  size_t v145; // r8
  char *v146; // rcx
  char *v147; // rdx
  void *v148; // rsi
  BOOL v149; // ebp
  __int64 v150; // r15
  unsigned __int64 v152; // rax
  char *v153; // r12
  __int64 v154; // rbp
  unsigned __int64 v155; // rcx
  unsigned __int64 v156; // rax
  unsigned __int64 v157; // rdx
  unsigned __int64 v158; // rax
  __int64 v159; // r15
  __int64 v160; // rax
  char *v161; // r13
  size_t v162; // r8
  char *v163; // rcx
  char *v164; // rdx
  void *v165; // rsi
  BOOL v166; // ebp
  __int64 v167; // r15
  unsigned __int64 v169; // rax
  char *v170; // r12
  __int64 v171; // rbp
  unsigned __int64 v172; // rcx
  unsigned __int64 v173; // rax
  unsigned __int64 v174; // rdx
  unsigned __int64 v175; // rax
  __int64 v176; // r15
  __int64 v177; // rax
  char *v178; // r13
  size_t v179; // r8
  char *v180; // rcx
  char *v181; // rdx
  void *v182; // rsi
  BOOL v183; // ebp
  __int64 v184; // r15
  unsigned __int64 v186; // rax
  char *v187; // r12
  __int64 v188; // rbp
  unsigned __int64 v189; // rcx
  unsigned __int64 v190; // rax
  unsigned __int64 v191; // rdx
  unsigned __int64 v192; // rax
  __int64 v193; // r15
  __int64 v194; // rax
  char *v195; // r13
  size_t v196; // r8
  char *v197; // rcx
  char *v198; // rdx
  void *v199; // rsi
  BOOL v200; // ebp
  __int64 v201; // r15
  unsigned __int64 v203; // rax
  char *v204; // r12
  __int64 v205; // rbp
  unsigned __int64 v206; // rcx
  unsigned __int64 v207; // rax
  unsigned __int64 v208; // rdx
  unsigned __int64 v209; // rax
  __int64 v210; // r15
  __int64 v211; // rax
  char *v212; // r13
  size_t v213; // r8
  char *v214; // rcx
  char *v215; // rdx
  void *v216; // rsi
  BOOL v217; // ebp
  __int64 v218; // r15
  unsigned __int64 v220; // rax
  char *v221; // r12
  __int64 v222; // rbp
  unsigned __int64 v223; // rcx
  unsigned __int64 v224; // rax
  unsigned __int64 v225; // rdx
  unsigned __int64 v226; // rax
  __int64 v227; // r15
  __int64 v228; // rax
  char *v229; // r13
  size_t v230; // r8
  char *v231; // rcx
  char *v232; // rdx
  void *v233; // rsi
  BOOL v234; // ebp
  __int64 v235; // r15
  unsigned __int64 v237; // rax
  char *v238; // r12
  __int64 v239; // rbp
  unsigned __int64 v240; // rcx
  unsigned __int64 v241; // rax
  unsigned __int64 v242; // rdx
  unsigned __int64 v243; // rax
  __int64 v244; // r15
  __int64 v245; // rax
  char *v246; // r13
  size_t v247; // r8
  char *v248; // rcx
  char *v249; // rdx
  void *v250; // rsi
  BOOL v251; // ebp
  __int64 v252; // r15
  unsigned __int64 v254; // rax
  char *v255; // r12
  __int64 v256; // rbp
  unsigned __int64 v257; // rcx
  unsigned __int64 v258; // rsi
  unsigned __int64 v259; // rax
  unsigned __int64 v260; // rdx
  unsigned __int64 v261; // rax
  __int64 v262; // r15
  __int64 v263; // rax
  char *v264; // r13
  size_t v265; // r8
  char *v266; // rcx
  char *v267; // rdx
  size_t v268; // r8
  char *v269; // rcx
  char *v270; // rdx
  void *v271; // rsi
  BOOL v272; // ebp
  __int64 v273; // r15
  unsigned __int64 v274; // rax
  unsigned __int64 v275; // rcx
  unsigned __int64 v276; // rax
  unsigned __int64 v277; // rdx
  unsigned __int64 v278; // rax
  __int64 v279; // rax
  _QWORD *v280; // rcx
  __int16 v300; // si
  SHORT AsyncKeyState; // ax
  char v302; // cl
  int v328; // edi
  int v329; // eax
  unsigned __int16 v347; // ax
  unsigned int v354; // edi
  __int64 v361; // rax
  __int64 v363; // rax
  __int64 v365; // rax
  __int64 v367; // rax
  __int64 v368; // rax
  char *v369; // rcx
  __int64 v370; // rsi
  __int64 v374; // rsi
  char *v375; // rsi
  __int64 v376; // r11
  char v377; // bl
  char *v378; // rsi
  unsigned __int64 v379; // rdi
  __int64 v380; // rdi
  _QWORD *v381; // rbx
  __int64 v382; // [rsp+38h] [rbp-120h]
  int v383; // [rsp+38h] [rbp-120h]
  _BYTE *Src; // [rsp+40h] [rbp-118h]
  char *Srca; // [rsp+40h] [rbp-118h]
  size_t Size; // [rsp+48h] [rbp-110h]
  size_t Sizea; // [rsp+48h] [rbp-110h]
  int *v388; // [rsp+50h] [rbp-108h]
  __int16 v389; // [rsp+50h] [rbp-108h]
  char *v390; // [rsp+58h] [rbp-100h]
  __int64 v391; // [rsp+60h] [rbp-F8h]
  __int64 v392; // [rsp+68h] [rbp-F0h]

  __asm
  {
    vmovdqa [rsp+158h+var_58], xmm15
    vmovaps [rsp+158h+var_68], xmm14
    vmovaps [rsp+158h+var_78], xmm13
    vmovaps [rsp+158h+var_88], xmm12
    vmovdqa [rsp+158h+var_98], xmm11
    vmovdqa [rsp+158h+var_A8], xmm10
    vmovaps [rsp+158h+var_B8], xmm9
    vmovapd [rsp+158h+var_C8], xmm8
    vmovaps [rsp+158h+var_D8], xmm7
    vmovaps [rsp+158h+var_E8], xmm6
  }
  ModuleHandleA = GetModuleHandleA("ntdll.dll");
  NtSetInformationThread = GetProcAddress(ModuleHandleA, "NtSetInformationThread");
  CurrentThread = GetCurrentThread();
  result = ((__int64 (__fastcall *)(HANDLE, __int64, _QWORD, _QWORD))NtSetInformationThread)(CurrentThread, 17, 0, 0);
  if ( (_DWORD)result )
    goto LABEL_2;
  _RAX = GetModuleHandleA(0);
  qword_180019350 = (__int64)_RAX;
  v25 = (__int64)(_RAX + 8041488);
  qword_180019368 = (__int64)(_RAX + 8041488);
  __asm
  {
    vxorps  xmm6, xmm6, xmm6
    vucomiss xmm6, dword ptr [rax+1EAD040h]
  }
  if ( !v27 )
  {
    do
    {
      perf_frequency = Query_perf_frequency();
      perf_counter = Query_perf_counter();
      if ( perf_frequency == 24000000 )
      {
        v31 = perf_counter / 2 + 41 * perf_counter;
      }
      else if ( perf_frequency == 10000000 )
      {
        v31 = 100 * perf_counter;
      }
      else
      {
        if ( (perf_frequency | (unsigned __int64)perf_counter) >> 32 )
        {
          v32 = perf_counter % perf_frequency;
          v33 = perf_counter / perf_frequency;
        }
        else
        {
          v32 = (unsigned int)perf_counter % (unsigned int)perf_frequency;
          v33 = (unsigned int)perf_counter / (unsigned int)perf_frequency;
        }
        v34 = 1000000000 * v32;
        if ( (perf_frequency | (unsigned __int64)(1000000000 * v32)) >> 32 )
          v35 = v34 / perf_frequency;
        else
          v35 = (unsigned int)v34 / (unsigned int)perf_frequency;
        v31 = v35 + 1000000000 * v33;
      }
      v36 = __OFADD__(1000000000, v31);
      v37 = v31 + 1000000000;
      if ( v36 )
        v37 = 0x7FFFFFFFFFFFFFFFLL;
      while ( 1 )
      {
        v38 = Query_perf_frequency();
        v39 = Query_perf_counter();
        if ( v38 == 24000000 )
        {
          v40 = v39 / 2 + 41 * v39;
        }
        else if ( v38 == 10000000 )
        {
          v40 = 100 * v39;
        }
        else
        {
          if ( (v38 | (unsigned __int64)v39) >> 32 )
          {
            v41 = v39 % v38;
            v42 = v39 / v38;
          }
          else
          {
            v41 = (unsigned int)v39 % (unsigned int)v38;
            v42 = (unsigned int)v39 / (unsigned int)v38;
          }
          v43 = 1000000000 * v41;
          v44 = (v38 | (unsigned __int64)(1000000000 * v41)) >> 32 ? v43 / v38 : (unsigned int)v43 / (unsigned int)v38;
          v40 = v44 + 1000000000 * v42;
        }
        v45 = v37 - v40;
        if ( v37 <= v40 )
          break;
        v46 = 86400000;
        if ( v45 <= 86400000000000LL )
          v46 = v45 / 1000000 + (1000000 * (v45 / 1000000) < v45);
        Sleep(v46);
      }
      _RAX = qword_180019368;
      __asm { vucomiss xmm6, dword ptr [rax] }
    }
    while ( v37 >= (unsigned __int64)v40 );
    _RAX = (HMODULE)qword_180019350;
    v25 = qword_180019350 + 32165952;
  }
  __asm
  {
    vmovq   xmm0, rax
    vpbroadcastq ymm0, xmm0
    vpaddq  ymm0, ymm0, cs:ymmword_180017180
    vmovdqu cs:ymmword_1800193C8, ymm0
  }
  _R9 = 0x100000001B3LL;
  xmmword_1800193E8 = (double (*)(void))(_RAX + 1429948);
  *(&xmmword_1800193E8 + 1) = (double (*)(void))(_RAX + 3097360);
  qword_180019380 = *((_QWORD *)_RAX + 4010496);
  qword_180019378 = *((_QWORD *)_RAX + 4013091);
  qword_180019370 = *((_QWORD *)_RAX + 4013105) + 72LL;
  qword_180019388 = *((_QWORD *)_RAX + 4014672);
  qword_180019390 = *((_QWORD *)_RAX + 4016994);
  qword_1800193A0 = *((_QWORD *)_RAX + 4014739) + 24LL;
  qword_180019348 = *((_QWORD *)_RAX + 4019208) + 40LL;
  qword_180019340 = *(_QWORD *)(*((_QWORD *)_RAX + 4013105) + 24LL) + 804LL;
  qword_1800193C0 = *(_QWORD *)(*((_QWORD *)_RAX + 4013105) + 40LL) + 52LL;
  qword_180019330 = *(_QWORD *)(*((_QWORD *)_RAX + 4013105) + 96LL) + 60LL;
  _R8 = *(_QWORD *)(*((_QWORD *)_RAX + 4013105) + 104LL) + 148LL;
  qword_180019338 = _R8;
  qword_180019368 = v25;
  qword_180019398 = (__int64)(_RAX + 8088618);
  v52 = (HWND)*((_QWORD *)_RAX + 4044917);
  hWnd = v52;
  *(_QWORD *)&xmmword_180019358 = (char *)_RAX + 32861865;
  *((_QWORD *)&xmmword_180019358 + 1) = _RAX + 8215644;
  qword_1800193B0 = (__int64)(_RAX + 8230176);
  qword_1800193B8 = *((_QWORD *)_RAX + 4126531) + 576LL;
  _RDX = (__int64)(v52 + 4316);
  if ( v52 == (HWND)-17264LL )
    goto LABEL_57;
  _R8 = *(unsigned __int8 *)_RDX;
  if ( !(_BYTE)_R8 )
    goto LABEL_57;
  v54 = (unsigned __int8 *)v52 + 17265;
  v55 = 0xCBF29CE484222325uLL;
  do
  {
    v55 = 0x100000001B3LL * ((char)_R8 ^ (unsigned __int64)v55);
    _R8 = *v54++;
  }
  while ( (_BYTE)_R8 );
  if ( v55 > 0x112D788B5B855BEDLL )
  {
    if ( v55 <= 0x1A47746099CAAD96LL )
    {
      if ( v55 == 0x112D788B5B855BEELL )
      {
        v56 = (unsigned __int8 *)&unk_180017210;
        goto LABEL_541;
      }
      _RDX = 0x19BF8DB558FEDB42LL;
      if ( v55 == 0x19BF8DB558FEDB42LL )
      {
        v56 = (unsigned __int8 *)&unk_180017250;
        goto LABEL_541;
      }
    }
    else
    {
      if ( v55 == 0x1A47746099CAAD97LL )
      {
        v56 = (unsigned __int8 *)&unk_180017240;
        goto LABEL_541;
      }
      if ( v55 == 0x77EE2DDFA384BEA0LL )
      {
        v56 = (unsigned __int8 *)&unk_180017220;
        goto LABEL_541;
      }
      _RDX = 0x7A22BC4C07AC1888LL;
      if ( v55 == 0x7A22BC4C07AC1888LL )
      {
        v56 = (unsigned __int8 *)&unk_180017290;
        goto LABEL_541;
      }
    }
LABEL_57:
    word_1800193FA = 255;
    goto LABEL_58;
  }
  if ( v55 <= (__int64)0xB173594E60E46B48uLL )
  {
    if ( v55 == 0x98DD22A3CCBC7773uLL )
    {
      v56 = (unsigned __int8 *)&unk_1800172A0;
      goto LABEL_541;
    }
    _RDX = 0xAD1C144669DB1514uLL;
    if ( v55 == 0xAD1C144669DB1514uLL )
    {
      v56 = (unsigned __int8 *)&unk_180017230;
      goto LABEL_541;
    }
    goto LABEL_57;
  }
  if ( v55 == 0xB173594E60E46B49uLL )
  {
    v56 = (unsigned __int8 *)&unk_180017260;
    goto LABEL_541;
  }
  if ( v55 == 0xDE3BC2BFB3A73E2AuLL )
  {
    v56 = (unsigned __int8 *)&unk_180017280;
    goto LABEL_541;
  }
  _RDX = 0xD1C29E7AD935C17LL;
  if ( v55 != 0xD1C29E7AD935C17LL )
    goto LABEL_57;
  v56 = (unsigned __int8 *)&unk_180017270;
LABEL_541:
  _RDX = v56[8];
  word_1800193FA = v56[8];
  v361 = v56[9];
  if ( v361 != 255 )
  {
    _RDX = 696 * v361;
    _R8 = (__int64)byte_1800193F8;
    _R9 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v52 + v361 + 1921) + 304LL) + 96LL);
    __asm { vmovups xmm0, xmmword ptr [r9+7A8h] }
    v363 = *(_QWORD *)(_R9 + 1976);
    *(_DWORD *)&byte_1800193F8[_RDX + 84] = *(_DWORD *)(_R9 + 1984);
    *(_QWORD *)&byte_1800193F8[_RDX + 76] = v363;
    __asm
    {
      vmovups xmmword ptr [rdx+r8+3Ch], xmm0
      vmovups xmm0, xmmword ptr [r9+7C4h]
    }
    v365 = *(_QWORD *)(_R9 + 2004);
    *(_DWORD *)&byte_1800193F8[_RDX + 112] = *(_DWORD *)(_R9 + 2012);
    *(_QWORD *)&byte_1800193F8[_RDX + 104] = v365;
    __asm
    {
      vmovups xmmword ptr [rdx+r8+58h], xmm0
      vmovdqu xmm0, xmmword ptr [r9+6B4h]
    }
    v367 = *(_QWORD *)(_R9 + 1732);
    *(_DWORD *)&byte_1800193F8[_RDX + 56] = *(_DWORD *)(_R9 + 1740);
    *(_QWORD *)&byte_1800193F8[_RDX + 48] = v367;
    __asm { vmovdqu xmmword ptr [rdx+r8+20h], xmm0 }
    v368 = *(unsigned int *)(_R9 + 480);
    if ( *(_DWORD *)(_R9 + 480) )
    {
      v369 = &byte_1800193F8[_RDX + 32];
      _RDX = *(_QWORD *)(_R9 + 472);
      _R8 = (__int64)(v369 + 88);
      _R9 = 0;
      do
      {
        v375 = *(char **)(_RDX + 88 * _R9 + 8);
        v376 = 0xCBF29CE484222325uLL;
        if ( v375 )
        {
          v377 = *v375;
          if ( *v375 )
          {
            v378 = v375 + 1;
            v379 = 0xCBF29CE484222325uLL;
            do
            {
              v376 = 0x100000001B3LL * (v379 ^ v377);
              v377 = *v378++;
              v379 = v376;
            }
            while ( v377 );
          }
        }
        v380 = *((_QWORD *)v369 + 86);
        if ( v380 <= 0 )
        {
LABEL_544:
          *(_QWORD *)(_R8 + 40 * v380) = v376;
          v370 = *((_QWORD *)v369 + 86);
          *((_QWORD *)v369 + 86) = v370 + 1;
        }
        else
        {
          v381 = v369 + 88;
          v370 = 0;
          while ( *v381 != v376 )
          {
            ++v370;
            v381 += 5;
            if ( v380 == v370 )
              goto LABEL_544;
          }
        }
        _R10 = _RDX + 88 * _R9;
        _R11 = 5 * v370;
        __asm { vmovdqu xmm0, xmmword ptr [r10+18h] }
        v374 = *(_QWORD *)(_R10 + 40);
        *(_DWORD *)(_R8 + 8 * _R11 + 32) = *(_DWORD *)(_R10 + 48);
        *(_QWORD *)(_R8 + 8 * _R11 + 24) = v374;
        __asm { vmovdqu xmmword ptr [r8+r11*8+8], xmm0 }
        ++_R9;
      }
      while ( _R9 != v368 );
    }
  }
LABEL_58:
  v57 = *(_QWORD *)(qword_180019350 + 32117424);
  if ( *(_DWORD *)(v57 + 32) )
  {
    v58 = 0;
    __asm { vxorps  xmm6, xmm6, xmm6 }
    v391 = *(_QWORD *)(qword_180019350 + 32117424);
    while ( 1 )
    {
      v392 = v58;
      v61 = *(_QWORD *)(*(_QWORD *)(v57 + 24) + 8 * v58);
      if ( *(_DWORD *)(v61 + 208) )
      {
        v62 = 0;
        v63 = 0;
        Src = 0;
        v64 = 0;
        v65 = 0;
        do
        {
          v66 = *(_QWORD *)(v61 + 200);
          if ( v64 == v65 )
          {
            Size = v64 - Src;
            v67 = (v64 - Src) >> 2;
            v68 = v67 + 1;
            v69 = v67 + (v67 >> 1);
            if ( v69 <= v67 + 1 )
              v69 = v67 + 1;
            if ( v67 > 0x3FFFFFFFFFFFFFFFLL - (v67 >> 1) )
              v69 = 0x3FFFFFFFFFFFFFFFLL;
            if ( v69 > 0x3FFFFFFFFFFFFFFFLL )
            {
LABEL_556:
              __asm { vzeroupper }
              sub_180015000();
            }
            if ( v69 )
            {
              v70 = 4 * v69;
              if ( v69 < 0x400 )
              {
                __asm { vzeroupper }
                v72 = (_QWORD *)sub_180015230(v70);
              }
              else
              {
                if ( v69 >= 0x3FFFFFFFFFFFFFF7LL )
                  goto LABEL_556;
                __asm { vzeroupper }
                v71 = sub_180015230(v70 + 39);
                v72 = (_QWORD *)((v71 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
                *(v72 - 1) = v71;
              }
            }
            else
            {
              v72 = 0;
            }
            *(_DWORD *)((char *)v72 + Size) = *(_DWORD *)(v66 + v62);
            __asm { vzeroupper }
            memcpy(v72, Src, Size);
            if ( Src )
            {
              if ( Size < 0x1000 )
              {
                v73 = Src;
              }
              else
              {
                if ( (unsigned __int64)&Src[-*((_QWORD *)Src - 1) - 8] >= 0x20 )
                  goto LABEL_557;
                v73 = (void *)*((_QWORD *)Src - 1);
              }
              j_j_free(v73);
            }
            v64 = (char *)v72 + 4 * v68;
            v65 = (char *)v72 + 4 * v69;
            Src = v72;
          }
          else
          {
            *(_DWORD *)v64 = *(_DWORD *)(v66 + v62);
            v64 += 4;
          }
          ++v63;
          v62 += 24;
        }
        while ( v63 < *(unsigned int *)(v61 + 208) );
        v390 = v65;
        v74 = v64;
        v75 = Src;
      }
      else
      {
        v390 = 0;
        v74 = 0;
        v75 = 0;
      }
      __asm { vzeroupper }
      sub_1800149F0(v75, v74, (v74 - v75) >> 2, _R9);
      v388 = (int *)v75;
      Srca = v75;
      v382 = v61;
      Sizea = (size_t)v74;
      if ( v74 != v75 )
        break;
LABEL_89:
      v60 = Srca;
      v57 = v391;
      if ( Srca )
      {
        if ( (unsigned __int64)(v390 - Srca) >= 0x1000 )
        {
          if ( (unsigned __int64)&Srca[-*((_QWORD *)Srca - 1) - 8] >= 0x20 )
LABEL_557:
            BUG();
          v60 = (char *)*((_QWORD *)Srca - 1);
        }
        j_j_free(v60);
      }
      v58 = v392 + 1;
      if ( v392 + 1 >= (unsigned __int64)*(unsigned int *)(v391 + 32) )
        goto LABEL_491;
    }
    while ( 1 )
    {
      v76 = *(char **)(v61 + 8);
      v77 = 0xCBF29CE484222325uLL;
      if ( v76 )
      {
        v78 = *v76;
        if ( *v76 )
        {
          v79 = v76 + 1;
          _RDX = 0xCBF29CE484222325uLL;
          do
          {
            v77 = 0x100000001B3LL * (_RDX ^ v78);
            v78 = *v79++;
            _RDX = v77;
          }
          while ( v78 );
        }
      }
      v80 = Block;
      v81 = *((_QWORD *)Block + 1);
      v82 = 0;
      if ( *(_BYTE *)(v81 + 25) )
      {
        v83 = *((_QWORD *)Block + 1);
        _R14 = Block;
      }
      else
      {
        _R14 = Block;
        do
        {
          v83 = v81;
          v85 = *(_QWORD *)(v81 + 32);
          if ( v85 >= v77 )
            _R14 = (void *)v81;
          v81 = *(_QWORD *)(v81 + 16 * (unsigned int)(v85 < v77));
        }
        while ( !*(_BYTE *)(v81 + 25) );
        v82 = v85 >= v77;
      }
      v86 = *v388;
      if ( *((_BYTE *)_R14 + 25) || v77 < *((_QWORD *)_R14 + 4) )
      {
        if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
          goto LABEL_555;
        _R14 = (void *)sub_180015230(0x40u);
        *((_QWORD *)_R14 + 4) = v77;
        __asm { vmovups xmmword ptr [rax+28h], xmm6 }
        *((_QWORD *)_R14 + 7) = 0;
        *(_QWORD *)_R14 = v80;
        *((_QWORD *)_R14 + 1) = v80;
        *((_QWORD *)_R14 + 2) = v80;
        *((_WORD *)_R14 + 12) = 0;
        sub_1800147A0(v83, v82, _R14);
      }
      v87 = (char *)*((_QWORD *)_R14 + 6);
      if ( v87 == *((char **)_R14 + 7) )
      {
        v88 = (__int64)&v87[-*((_QWORD *)_R14 + 5)];
        v89 = v88 >> 4;
        v90 = (v88 >> 4) + 1;
        v91 = (unsigned __int64)(v88 >> 4) >> 1;
        v92 = 0xFFFFFFFFFFFFFFFLL - v91;
        v93 = (v88 >> 4) + v91;
        if ( v93 <= v90 )
          v93 = v89 + 1;
        if ( v89 > v92 )
          v93 = 0xFFFFFFFFFFFFFFFLL;
        if ( v93 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v94 = 16 * v93;
        if ( v93 )
        {
          if ( v93 < 0x100 )
          {
            v96 = (char *)sub_180015230(16 * v93);
          }
          else
          {
            if ( v93 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v95 = sub_180015230(v94 + 39);
            v96 = (char *)((v95 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v96 - 1) = v95;
          }
        }
        else
        {
          v96 = 0;
        }
        *(_QWORD *)&v96[v88] = *(_QWORD *)(v382 + 8);
        *(_DWORD *)&v96[v88 + 8] = v86;
        if ( v87 == *((char **)_R14 + 6) )
        {
          v99 = (char *)*((_QWORD *)_R14 + 5);
          v98 = v96;
          v97 = v87 - v99;
        }
        else
        {
          memcpy(v96, *((const void **)_R14 + 5), (size_t)&v87[-*((_QWORD *)_R14 + 5)]);
          v97 = *((_QWORD *)_R14 + 6) - (_QWORD)v87;
          v98 = &v96[v88 + 16];
          v99 = v87;
        }
        memcpy(v98, v99, v97);
        v81 = *((_QWORD *)_R14 + 5);
        v61 = v382;
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v96;
        *((_QWORD *)_R14 + 6) = &v96[16 * v90];
        *((_QWORD *)_R14 + 7) = &v96[v94];
        if ( v86 != 7 )
        {
LABEL_138:
          if ( v86 != 6 || v77 != 0x8ABFF924F2288F6EuLL )
            goto LABEL_95;
          v104 = Block;
          _RDX = *((_QWORD *)Block + 1);
          v105 = 0;
          if ( *(_BYTE *)(_RDX + 25) )
          {
            v106 = *((_QWORD *)Block + 1);
            _R14 = Block;
            if ( !*((_BYTE *)Block + 25) )
              goto LABEL_167;
LABEL_168:
            if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
              goto LABEL_555;
            _R14 = (void *)sub_180015230(0x40u);
            *((_QWORD *)_R14 + 4) = 0x8ABFF924F2288F6EuLL;
            __asm { vmovups xmmword ptr [rax+28h], xmm6 }
            *((_QWORD *)_R14 + 7) = 0;
            *(_QWORD *)_R14 = v104;
            *((_QWORD *)_R14 + 1) = v104;
            *((_QWORD *)_R14 + 2) = v104;
            *((_WORD *)_R14 + 12) = 0;
            sub_1800147A0(v106, v105, _R14);
          }
          else
          {
            _R14 = Block;
            do
            {
              v106 = _RDX;
              v118 = *(_QWORD *)(_RDX + 32);
              v81 = 0x8ABFF924F2288F6DuLL;
              if ( v118 > 0x8ABFF924F2288F6DuLL )
                _R14 = (void *)_RDX;
              _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v118 <= 0x8ABFF924F2288F6DuLL));
            }
            while ( !*(_BYTE *)(_RDX + 25) );
            v105 = v118 > 0x8ABFF924F2288F6DuLL;
            if ( *((_BYTE *)_R14 + 25) )
              goto LABEL_168;
LABEL_167:
            if ( *((_QWORD *)_R14 + 4) > 0x8ABFF924F2288F6EuLL )
              goto LABEL_168;
          }
          v119 = (char *)*((_QWORD *)_R14 + 6);
          if ( v119 == *((char **)_R14 + 7) )
          {
            v120 = (__int64)&v119[-*((_QWORD *)_R14 + 5)];
            v121 = v120 >> 4;
            v122 = (unsigned __int64)(v120 >> 4) >> 1;
            v123 = 0xFFFFFFFFFFFFFFFLL - v122;
            v124 = (v120 >> 4) + v122;
            if ( v124 <= (v120 >> 4) + 1 )
              v124 = v121 + 1;
            if ( v121 > v123 )
              v124 = 0xFFFFFFFFFFFFFFFLL;
            if ( v124 > 0xFFFFFFFFFFFFFFFLL )
              goto LABEL_556;
            v125 = 16 * v124;
            if ( v124 )
            {
              if ( v124 < 0x100 )
              {
                v127 = (char *)sub_180015230(16 * v124);
              }
              else
              {
                if ( v124 >= 0xFFFFFFFFFFFFFFELL )
                  goto LABEL_556;
                v126 = sub_180015230(v125 + 39);
                v127 = (char *)((v126 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
                *((_QWORD *)v127 - 1) = v126;
              }
            }
            else
            {
              v127 = 0;
            }
            *(_QWORD *)&v127[v120] = "SonaDJGenre02";
            *(_DWORD *)&v127[v120 + 8] = 6;
            if ( v119 == *((char **)_R14 + 6) )
            {
              v270 = (char *)*((_QWORD *)_R14 + 5);
              v269 = v127;
              v268 = v119 - v270;
            }
            else
            {
              memcpy(v127, *((const void **)_R14 + 5), (size_t)&v119[-*((_QWORD *)_R14 + 5)]);
              v268 = *((_QWORD *)_R14 + 6) - (_QWORD)v119;
              v269 = &v127[v120 + 16];
              v270 = v119;
            }
            memcpy(v269, v270, v268);
            v81 = *((_QWORD *)_R14 + 5);
            if ( v81 )
            {
              if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
              {
                if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
                  goto LABEL_557;
                v81 = *(_QWORD *)(v81 - 8);
              }
              j_j_free((void *)v81);
            }
            *((_QWORD *)_R14 + 5) = v127;
            *((_QWORD *)_R14 + 6) = &v127[16 * (v120 >> 4) + 16];
            *((_QWORD *)_R14 + 7) = &v127[v125];
          }
          else
          {
            *(_QWORD *)v119 = "SonaDJGenre02";
            *((_DWORD *)v119 + 2) = 6;
            *((_QWORD *)_R14 + 6) += 16LL;
          }
          v271 = Block;
          _RDX = *((_QWORD *)Block + 1);
          v272 = 0;
          if ( *(_BYTE *)(_RDX + 25) )
          {
            v273 = *((_QWORD *)Block + 1);
            _R14 = Block;
            if ( !*((_BYTE *)Block + 25) )
              goto LABEL_467;
LABEL_468:
            if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
LABEL_555:
              std::vector<void *>::_Xlen(v81, _RDX);
            _R14 = (void *)sub_180015230(0x40u);
            *((_QWORD *)_R14 + 4) = 0x8ABFF924F2288F6EuLL;
            __asm { vmovups xmmword ptr [rax+28h], xmm6 }
            *((_QWORD *)_R14 + 7) = 0;
            *(_QWORD *)_R14 = v271;
            *((_QWORD *)_R14 + 1) = v271;
            *((_QWORD *)_R14 + 2) = v271;
            *((_WORD *)_R14 + 12) = 0;
            sub_1800147A0(v273, v272, _R14);
          }
          else
          {
            _R14 = Block;
            do
            {
              v273 = _RDX;
              v274 = *(_QWORD *)(_RDX + 32);
              v81 = 0x8ABFF924F2288F6DuLL;
              if ( v274 > 0x8ABFF924F2288F6DuLL )
                _R14 = (void *)_RDX;
              _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v274 <= 0x8ABFF924F2288F6DuLL));
            }
            while ( !*(_BYTE *)(_RDX + 25) );
            v272 = v274 > 0x8ABFF924F2288F6DuLL;
            if ( *((_BYTE *)_R14 + 25) )
              goto LABEL_468;
LABEL_467:
            if ( *((_QWORD *)_R14 + 4) > 0x8ABFF924F2288F6EuLL )
              goto LABEL_468;
          }
          v255 = (char *)*((_QWORD *)_R14 + 6);
          if ( v255 != *((char **)_R14 + 7) )
          {
            *(_QWORD *)v255 = "SonaDJGenre03";
            *((_DWORD *)v255 + 2) = 6;
            goto LABEL_94;
          }
          v256 = (__int64)&v255[-*((_QWORD *)_R14 + 5)];
          v275 = v256 >> 4;
          v258 = (v256 >> 4) + 1;
          v276 = (unsigned __int64)(v256 >> 4) >> 1;
          v277 = 0xFFFFFFFFFFFFFFFLL - v276;
          v278 = (v256 >> 4) + v276;
          if ( v278 <= v258 )
            v278 = v275 + 1;
          if ( v275 > v277 )
            v278 = 0xFFFFFFFFFFFFFFFLL;
          if ( v278 > 0xFFFFFFFFFFFFFFFLL )
            goto LABEL_556;
          v262 = 16 * v278;
          if ( v278 )
          {
            if ( v278 < 0x100 )
            {
              v264 = (char *)sub_180015230(16 * v278);
            }
            else
            {
              if ( v278 >= 0xFFFFFFFFFFFFFFELL )
                goto LABEL_556;
              v279 = sub_180015230(v262 + 39);
              v264 = (char *)((v279 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
              *((_QWORD *)v264 - 1) = v279;
            }
          }
          else
          {
            v264 = 0;
          }
          *(_QWORD *)&v264[v256] = "SonaDJGenre03";
          *(_DWORD *)&v264[v256 + 8] = 6;
          if ( v255 == *((char **)_R14 + 6) )
            goto LABEL_484;
          goto LABEL_447;
        }
      }
      else
      {
        v61 = v382;
        *(_QWORD *)v87 = *(_QWORD *)(v382 + 8);
        *((_DWORD *)v87 + 2) = v86;
        *((_QWORD *)_R14 + 6) += 16LL;
        if ( v86 != 7 )
          goto LABEL_138;
      }
      if ( v77 != 0x254B9819B8CFB5E6LL )
        goto LABEL_138;
      v100 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v101 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v102 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_148;
      }
      else
      {
        _R14 = Block;
        do
        {
          v102 = _RDX;
          v108 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v108 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v108 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v101 = v108 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_148:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_151;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v100;
      *((_QWORD *)_R14 + 1) = v100;
      *((_QWORD *)_R14 + 2) = v100;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v102, v101, _R14);
LABEL_151:
      v109 = (char *)*((_QWORD *)_R14 + 6);
      if ( v109 == *((char **)_R14 + 7) )
      {
        v110 = (__int64)&v109[-*((_QWORD *)_R14 + 5)];
        v111 = v110 >> 4;
        v112 = (unsigned __int64)(v110 >> 4) >> 1;
        v113 = 0xFFFFFFFFFFFFFFFLL - v112;
        v114 = (v110 >> 4) + v112;
        if ( v114 <= (v110 >> 4) + 1 )
          v114 = v111 + 1;
        if ( v111 > v113 )
          v114 = 0xFFFFFFFFFFFFFFFLL;
        if ( v114 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v115 = 16 * v114;
        if ( v114 )
        {
          if ( v114 < 0x100 )
          {
            v117 = (char *)sub_180015230(16 * v114);
          }
          else
          {
            if ( v114 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v116 = sub_180015230(v115 + 39);
            v117 = (char *)((v116 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v117 - 1) = v116;
          }
        }
        else
        {
          v117 = 0;
        }
        *(_QWORD *)&v117[v110] = "LuxAir";
        *(_DWORD *)&v117[v110 + 8] = 7;
        if ( v109 == *((char **)_R14 + 6) )
        {
          v130 = (char *)*((_QWORD *)_R14 + 5);
          v129 = v117;
          v128 = v109 - v130;
        }
        else
        {
          memcpy(v117, *((const void **)_R14 + 5), (size_t)&v109[-*((_QWORD *)_R14 + 5)]);
          v128 = *((_QWORD *)_R14 + 6) - (_QWORD)v109;
          v129 = &v117[v110 + 16];
          v130 = v109;
        }
        memcpy(v129, v130, v128);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v117;
        *((_QWORD *)_R14 + 6) = &v117[16 * (v110 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v117[v115];
      }
      else
      {
        *(_QWORD *)v109 = "LuxAir";
        *((_DWORD *)v109 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v131 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v132 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v133 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_200;
      }
      else
      {
        _R14 = Block;
        do
        {
          v133 = _RDX;
          v135 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v135 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v135 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v132 = v135 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_200:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_203;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v131;
      *((_QWORD *)_R14 + 1) = v131;
      *((_QWORD *)_R14 + 2) = v131;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v133, v132, _R14);
LABEL_203:
      v136 = (char *)*((_QWORD *)_R14 + 6);
      if ( v136 == *((char **)_R14 + 7) )
      {
        v137 = (__int64)&v136[-*((_QWORD *)_R14 + 5)];
        v138 = v137 >> 4;
        v139 = (unsigned __int64)(v137 >> 4) >> 1;
        v140 = 0xFFFFFFFFFFFFFFFLL - v139;
        v141 = (v137 >> 4) + v139;
        if ( v141 <= (v137 >> 4) + 1 )
          v141 = v138 + 1;
        if ( v138 > v140 )
          v141 = 0xFFFFFFFFFFFFFFFLL;
        if ( v141 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v142 = 16 * v141;
        if ( v141 )
        {
          if ( v141 < 0x100 )
          {
            v144 = (char *)sub_180015230(16 * v141);
          }
          else
          {
            if ( v141 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v143 = sub_180015230(v142 + 39);
            v144 = (char *)((v143 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v144 - 1) = v143;
          }
        }
        else
        {
          v144 = 0;
        }
        *(_QWORD *)&v144[v137] = "LuxDark";
        *(_DWORD *)&v144[v137 + 8] = 7;
        if ( v136 == *((char **)_R14 + 6) )
        {
          v147 = (char *)*((_QWORD *)_R14 + 5);
          v146 = v144;
          v145 = v136 - v147;
        }
        else
        {
          memcpy(v144, *((const void **)_R14 + 5), (size_t)&v136[-*((_QWORD *)_R14 + 5)]);
          v145 = *((_QWORD *)_R14 + 6) - (_QWORD)v136;
          v146 = &v144[v137 + 16];
          v147 = v136;
        }
        memcpy(v146, v147, v145);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v144;
        *((_QWORD *)_R14 + 6) = &v144[16 * (v137 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v144[v142];
      }
      else
      {
        *(_QWORD *)v136 = "LuxDark";
        *((_DWORD *)v136 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v148 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v149 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v150 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_233;
      }
      else
      {
        _R14 = Block;
        do
        {
          v150 = _RDX;
          v152 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v152 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v152 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v149 = v152 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_233:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_236;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v148;
      *((_QWORD *)_R14 + 1) = v148;
      *((_QWORD *)_R14 + 2) = v148;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v150, v149, _R14);
LABEL_236:
      v153 = (char *)*((_QWORD *)_R14 + 6);
      if ( v153 == *((char **)_R14 + 7) )
      {
        v154 = (__int64)&v153[-*((_QWORD *)_R14 + 5)];
        v155 = v154 >> 4;
        v156 = (unsigned __int64)(v154 >> 4) >> 1;
        v157 = 0xFFFFFFFFFFFFFFFLL - v156;
        v158 = (v154 >> 4) + v156;
        if ( v158 <= (v154 >> 4) + 1 )
          v158 = v155 + 1;
        if ( v155 > v157 )
          v158 = 0xFFFFFFFFFFFFFFFLL;
        if ( v158 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v159 = 16 * v158;
        if ( v158 )
        {
          if ( v158 < 0x100 )
          {
            v161 = (char *)sub_180015230(16 * v158);
          }
          else
          {
            if ( v158 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v160 = sub_180015230(v159 + 39);
            v161 = (char *)((v160 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v161 - 1) = v160;
          }
        }
        else
        {
          v161 = 0;
        }
        *(_QWORD *)&v161[v154] = "LuxFire";
        *(_DWORD *)&v161[v154 + 8] = 7;
        if ( v153 == *((char **)_R14 + 6) )
        {
          v164 = (char *)*((_QWORD *)_R14 + 5);
          v163 = v161;
          v162 = v153 - v164;
        }
        else
        {
          memcpy(v161, *((const void **)_R14 + 5), (size_t)&v153[-*((_QWORD *)_R14 + 5)]);
          v162 = *((_QWORD *)_R14 + 6) - (_QWORD)v153;
          v163 = &v161[v154 + 16];
          v164 = v153;
        }
        memcpy(v163, v164, v162);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v161;
        *((_QWORD *)_R14 + 6) = &v161[16 * (v154 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v161[v159];
      }
      else
      {
        *(_QWORD *)v153 = "LuxFire";
        *((_DWORD *)v153 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v165 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v166 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v167 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_266;
      }
      else
      {
        _R14 = Block;
        do
        {
          v167 = _RDX;
          v169 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v169 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v169 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v166 = v169 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_266:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_269;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v165;
      *((_QWORD *)_R14 + 1) = v165;
      *((_QWORD *)_R14 + 2) = v165;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v167, v166, _R14);
LABEL_269:
      v170 = (char *)*((_QWORD *)_R14 + 6);
      if ( v170 == *((char **)_R14 + 7) )
      {
        v171 = (__int64)&v170[-*((_QWORD *)_R14 + 5)];
        v172 = v171 >> 4;
        v173 = (unsigned __int64)(v171 >> 4) >> 1;
        v174 = 0xFFFFFFFFFFFFFFFLL - v173;
        v175 = (v171 >> 4) + v173;
        if ( v175 <= (v171 >> 4) + 1 )
          v175 = v172 + 1;
        if ( v172 > v174 )
          v175 = 0xFFFFFFFFFFFFFFFLL;
        if ( v175 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v176 = 16 * v175;
        if ( v175 )
        {
          if ( v175 < 0x100 )
          {
            v178 = (char *)sub_180015230(16 * v175);
          }
          else
          {
            if ( v175 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v177 = sub_180015230(v176 + 39);
            v178 = (char *)((v177 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v178 - 1) = v177;
          }
        }
        else
        {
          v178 = 0;
        }
        *(_QWORD *)&v178[v171] = "LuxIce";
        *(_DWORD *)&v178[v171 + 8] = 7;
        if ( v170 == *((char **)_R14 + 6) )
        {
          v181 = (char *)*((_QWORD *)_R14 + 5);
          v180 = v178;
          v179 = v170 - v181;
        }
        else
        {
          memcpy(v178, *((const void **)_R14 + 5), (size_t)&v170[-*((_QWORD *)_R14 + 5)]);
          v179 = *((_QWORD *)_R14 + 6) - (_QWORD)v170;
          v180 = &v178[v171 + 16];
          v181 = v170;
        }
        memcpy(v180, v181, v179);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v178;
        *((_QWORD *)_R14 + 6) = &v178[16 * (v171 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v178[v176];
      }
      else
      {
        *(_QWORD *)v170 = "LuxIce";
        *((_DWORD *)v170 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v182 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v183 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v184 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_299;
      }
      else
      {
        _R14 = Block;
        do
        {
          v184 = _RDX;
          v186 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v186 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v186 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v183 = v186 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_299:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_302;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v182;
      *((_QWORD *)_R14 + 1) = v182;
      *((_QWORD *)_R14 + 2) = v182;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v184, v183, _R14);
LABEL_302:
      v187 = (char *)*((_QWORD *)_R14 + 6);
      if ( v187 == *((char **)_R14 + 7) )
      {
        v188 = (__int64)&v187[-*((_QWORD *)_R14 + 5)];
        v189 = v188 >> 4;
        v190 = (unsigned __int64)(v188 >> 4) >> 1;
        v191 = 0xFFFFFFFFFFFFFFFLL - v190;
        v192 = (v188 >> 4) + v190;
        if ( v192 <= (v188 >> 4) + 1 )
          v192 = v189 + 1;
        if ( v189 > v191 )
          v192 = 0xFFFFFFFFFFFFFFFLL;
        if ( v192 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v193 = 16 * v192;
        if ( v192 )
        {
          if ( v192 < 0x100 )
          {
            v195 = (char *)sub_180015230(16 * v192);
          }
          else
          {
            if ( v192 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v194 = sub_180015230(v193 + 39);
            v195 = (char *)((v194 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v195 - 1) = v194;
          }
        }
        else
        {
          v195 = 0;
        }
        *(_QWORD *)&v195[v188] = "LuxMagma";
        *(_DWORD *)&v195[v188 + 8] = 7;
        if ( v187 == *((char **)_R14 + 6) )
        {
          v198 = (char *)*((_QWORD *)_R14 + 5);
          v197 = v195;
          v196 = v187 - v198;
        }
        else
        {
          memcpy(v195, *((const void **)_R14 + 5), (size_t)&v187[-*((_QWORD *)_R14 + 5)]);
          v196 = *((_QWORD *)_R14 + 6) - (_QWORD)v187;
          v197 = &v195[v188 + 16];
          v198 = v187;
        }
        memcpy(v197, v198, v196);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v195;
        *((_QWORD *)_R14 + 6) = &v195[16 * (v188 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v195[v193];
      }
      else
      {
        *(_QWORD *)v187 = "LuxMagma";
        *((_DWORD *)v187 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v199 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v200 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v201 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_332;
      }
      else
      {
        _R14 = Block;
        do
        {
          v201 = _RDX;
          v203 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v203 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v203 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v200 = v203 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_332:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_335;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v199;
      *((_QWORD *)_R14 + 1) = v199;
      *((_QWORD *)_R14 + 2) = v199;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v201, v200, _R14);
LABEL_335:
      v204 = (char *)*((_QWORD *)_R14 + 6);
      if ( v204 == *((char **)_R14 + 7) )
      {
        v205 = (__int64)&v204[-*((_QWORD *)_R14 + 5)];
        v206 = v205 >> 4;
        v207 = (unsigned __int64)(v205 >> 4) >> 1;
        v208 = 0xFFFFFFFFFFFFFFFLL - v207;
        v209 = (v205 >> 4) + v207;
        if ( v209 <= (v205 >> 4) + 1 )
          v209 = v206 + 1;
        if ( v206 > v208 )
          v209 = 0xFFFFFFFFFFFFFFFLL;
        if ( v209 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v210 = 16 * v209;
        if ( v209 )
        {
          if ( v209 < 0x100 )
          {
            v212 = (char *)sub_180015230(16 * v209);
          }
          else
          {
            if ( v209 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v211 = sub_180015230(v210 + 39);
            v212 = (char *)((v211 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v212 - 1) = v211;
          }
        }
        else
        {
          v212 = 0;
        }
        *(_QWORD *)&v212[v205] = "LuxMystic";
        *(_DWORD *)&v212[v205 + 8] = 7;
        if ( v204 == *((char **)_R14 + 6) )
        {
          v215 = (char *)*((_QWORD *)_R14 + 5);
          v214 = v212;
          v213 = v204 - v215;
        }
        else
        {
          memcpy(v212, *((const void **)_R14 + 5), (size_t)&v204[-*((_QWORD *)_R14 + 5)]);
          v213 = *((_QWORD *)_R14 + 6) - (_QWORD)v204;
          v214 = &v212[v205 + 16];
          v215 = v204;
        }
        memcpy(v214, v215, v213);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v212;
        *((_QWORD *)_R14 + 6) = &v212[16 * (v205 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v212[v210];
      }
      else
      {
        *(_QWORD *)v204 = "LuxMystic";
        *((_DWORD *)v204 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v216 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v217 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v218 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_365;
      }
      else
      {
        _R14 = Block;
        do
        {
          v218 = _RDX;
          v220 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v220 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v220 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v217 = v220 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_365:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_368;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v216;
      *((_QWORD *)_R14 + 1) = v216;
      *((_QWORD *)_R14 + 2) = v216;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v218, v217, _R14);
LABEL_368:
      v221 = (char *)*((_QWORD *)_R14 + 6);
      if ( v221 == *((char **)_R14 + 7) )
      {
        v222 = (__int64)&v221[-*((_QWORD *)_R14 + 5)];
        v223 = v222 >> 4;
        v224 = (unsigned __int64)(v222 >> 4) >> 1;
        v225 = 0xFFFFFFFFFFFFFFFLL - v224;
        v226 = (v222 >> 4) + v224;
        if ( v226 <= (v222 >> 4) + 1 )
          v226 = v223 + 1;
        if ( v223 > v225 )
          v226 = 0xFFFFFFFFFFFFFFFLL;
        if ( v226 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v227 = 16 * v226;
        if ( v226 )
        {
          if ( v226 < 0x100 )
          {
            v229 = (char *)sub_180015230(16 * v226);
          }
          else
          {
            if ( v226 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v228 = sub_180015230(v227 + 39);
            v229 = (char *)((v228 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v229 - 1) = v228;
          }
        }
        else
        {
          v229 = 0;
        }
        *(_QWORD *)&v229[v222] = "LuxNature";
        *(_DWORD *)&v229[v222 + 8] = 7;
        if ( v221 == *((char **)_R14 + 6) )
        {
          v232 = (char *)*((_QWORD *)_R14 + 5);
          v231 = v229;
          v230 = v221 - v232;
        }
        else
        {
          memcpy(v229, *((const void **)_R14 + 5), (size_t)&v221[-*((_QWORD *)_R14 + 5)]);
          v230 = *((_QWORD *)_R14 + 6) - (_QWORD)v221;
          v231 = &v229[v222 + 16];
          v232 = v221;
        }
        memcpy(v231, v232, v230);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v229;
        *((_QWORD *)_R14 + 6) = &v229[16 * (v222 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v229[v227];
      }
      else
      {
        *(_QWORD *)v221 = "LuxNature";
        *((_DWORD *)v221 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v233 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v234 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v235 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_398;
      }
      else
      {
        _R14 = Block;
        do
        {
          v235 = _RDX;
          v237 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v237 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v237 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v234 = v237 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_398:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_401;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v233;
      *((_QWORD *)_R14 + 1) = v233;
      *((_QWORD *)_R14 + 2) = v233;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v235, v234, _R14);
LABEL_401:
      v238 = (char *)*((_QWORD *)_R14 + 6);
      if ( v238 == *((char **)_R14 + 7) )
      {
        v239 = (__int64)&v238[-*((_QWORD *)_R14 + 5)];
        v240 = v239 >> 4;
        v241 = (unsigned __int64)(v239 >> 4) >> 1;
        v242 = 0xFFFFFFFFFFFFFFFLL - v241;
        v243 = (v239 >> 4) + v241;
        if ( v243 <= (v239 >> 4) + 1 )
          v243 = v240 + 1;
        if ( v240 > v242 )
          v243 = 0xFFFFFFFFFFFFFFFLL;
        if ( v243 > 0xFFFFFFFFFFFFFFFLL )
          goto LABEL_556;
        v244 = 16 * v243;
        if ( v243 )
        {
          if ( v243 < 0x100 )
          {
            v246 = (char *)sub_180015230(16 * v243);
          }
          else
          {
            if ( v243 >= 0xFFFFFFFFFFFFFFELL )
              goto LABEL_556;
            v245 = sub_180015230(v244 + 39);
            v246 = (char *)((v245 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *((_QWORD *)v246 - 1) = v245;
          }
        }
        else
        {
          v246 = 0;
        }
        *(_QWORD *)&v246[v239] = "LuxStorm";
        *(_DWORD *)&v246[v239 + 8] = 7;
        if ( v238 == *((char **)_R14 + 6) )
        {
          v249 = (char *)*((_QWORD *)_R14 + 5);
          v248 = v246;
          v247 = v238 - v249;
        }
        else
        {
          memcpy(v246, *((const void **)_R14 + 5), (size_t)&v238[-*((_QWORD *)_R14 + 5)]);
          v247 = *((_QWORD *)_R14 + 6) - (_QWORD)v238;
          v248 = &v246[v239 + 16];
          v249 = v238;
        }
        memcpy(v248, v249, v247);
        v81 = *((_QWORD *)_R14 + 5);
        if ( v81 )
        {
          if ( *((_QWORD *)_R14 + 7) - v81 >= 0x1000 )
          {
            if ( v81 - 8 - *(_QWORD *)(v81 - 8) >= 0x20 )
              goto LABEL_557;
            v81 = *(_QWORD *)(v81 - 8);
          }
          j_j_free((void *)v81);
        }
        *((_QWORD *)_R14 + 5) = v246;
        *((_QWORD *)_R14 + 6) = &v246[16 * (v239 >> 4) + 16];
        *((_QWORD *)_R14 + 7) = &v246[v244];
      }
      else
      {
        *(_QWORD *)v238 = "LuxStorm";
        *((_DWORD *)v238 + 2) = 7;
        *((_QWORD *)_R14 + 6) += 16LL;
      }
      v250 = Block;
      _RDX = *((_QWORD *)Block + 1);
      v251 = 0;
      if ( *(_BYTE *)(_RDX + 25) )
      {
        v252 = *((_QWORD *)Block + 1);
        _R14 = Block;
        if ( !*((_BYTE *)Block + 25) )
          goto LABEL_431;
      }
      else
      {
        _R14 = Block;
        do
        {
          v252 = _RDX;
          v254 = *(_QWORD *)(_RDX + 32);
          v81 = 0x254B9819B8CFB5E5LL;
          if ( v254 > 0x254B9819B8CFB5E5LL )
            _R14 = (void *)_RDX;
          _RDX = *(_QWORD *)(_RDX + 16 * (unsigned int)(v254 <= 0x254B9819B8CFB5E5LL));
        }
        while ( !*(_BYTE *)(_RDX + 25) );
        v251 = v254 > 0x254B9819B8CFB5E5LL;
        if ( !*((_BYTE *)_R14 + 25) )
        {
LABEL_431:
          if ( *((_QWORD *)_R14 + 4) <= 0x254B9819B8CFB5E6uLL )
            goto LABEL_434;
        }
      }
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        goto LABEL_555;
      _R14 = (void *)sub_180015230(0x40u);
      *((_QWORD *)_R14 + 4) = 0x254B9819B8CFB5E6LL;
      __asm { vmovups xmmword ptr [rax+28h], xmm6 }
      *((_QWORD *)_R14 + 7) = 0;
      *(_QWORD *)_R14 = v250;
      *((_QWORD *)_R14 + 1) = v250;
      *((_QWORD *)_R14 + 2) = v250;
      *((_WORD *)_R14 + 12) = 0;
      sub_1800147A0(v252, v251, _R14);
LABEL_434:
      v255 = (char *)*((_QWORD *)_R14 + 6);
      if ( v255 != *((char **)_R14 + 7) )
      {
        *(_QWORD *)v255 = "LuxWater";
        *((_DWORD *)v255 + 2) = 7;
LABEL_94:
        *((_QWORD *)_R14 + 6) += 16LL;
        v61 = v382;
        goto LABEL_95;
      }
      v256 = (__int64)&v255[-*((_QWORD *)_R14 + 5)];
      v257 = v256 >> 4;
      v258 = (v256 >> 4) + 1;
      v259 = (unsigned __int64)(v256 >> 4) >> 1;
      v260 = 0xFFFFFFFFFFFFFFFLL - v259;
      v261 = (v256 >> 4) + v259;
      if ( v261 <= v258 )
        v261 = v257 + 1;
      if ( v257 > v260 )
        v261 = 0xFFFFFFFFFFFFFFFLL;
      if ( v261 > 0xFFFFFFFFFFFFFFFLL )
        goto LABEL_556;
      v262 = 16 * v261;
      if ( v261 )
      {
        if ( v261 < 0x100 )
        {
          v264 = (char *)sub_180015230(16 * v261);
        }
        else
        {
          if ( v261 >= 0xFFFFFFFFFFFFFFELL )
            goto LABEL_556;
          v263 = sub_180015230(v262 + 39);
          v264 = (char *)((v263 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
          *((_QWORD *)v264 - 1) = v263;
        }
      }
      else
      {
        v264 = 0;
      }
      *(_QWORD *)&v264[v256] = "LuxWater";
      *(_DWORD *)&v264[v256 + 8] = 7;
      if ( v255 == *((char **)_R14 + 6) )
      {
LABEL_484:
        v267 = (char *)*((_QWORD *)_R14 + 5);
        v266 = v264;
        v265 = v255 - v267;
        goto LABEL_485;
      }
LABEL_447:
      memcpy(v264, *((const void **)_R14 + 5), (size_t)&v255[-*((_QWORD *)_R14 + 5)]);
      v265 = *((_QWORD *)_R14 + 6) - (_QWORD)v255;
      v266 = &v264[v256 + 16];
      v267 = v255;
LABEL_485:
      memcpy(v266, v267, v265);
      v61 = v382;
      v280 = (_QWORD *)*((_QWORD *)_R14 + 5);
      if ( v280 )
      {
        if ( *((_QWORD *)_R14 + 7) - (_QWORD)v280 >= 0x1000u )
        {
          if ( (unsigned __int64)v280 - *(v280 - 1) - 8 >= 0x20 )
            goto LABEL_557;
          v280 = (_QWORD *)*(v280 - 1);
        }
        j_j_free(v280);
      }
      *((_QWORD *)_R14 + 5) = v264;
      *((_QWORD *)_R14 + 6) = &v264[16 * v258];
      *((_QWORD *)_R14 + 7) = &v264[v262];
LABEL_95:
      if ( ++v388 == (int *)Sizea )
        goto LABEL_89;
    }
  }
LABEL_491:
  if ( (unsigned __int16)word_1800193FA > 9uLL )
  {
    result = (unsigned __int8)byte_18001908C;
    if ( (byte_18001908C & 1) == 0 )
    {
LABEL_2:
      __asm
      {
        vmovaps xmm6, [rsp+158h+var_E8]
        vmovaps xmm7, [rsp+158h+var_D8]
        vmovaps xmm8, [rsp+158h+var_C8]
        vmovaps xmm9, [rsp+158h+var_B8]
        vmovaps xmm10, [rsp+158h+var_A8]
        vmovaps xmm11, [rsp+158h+var_98]
        vmovaps xmm12, [rsp+158h+var_88]
        vmovaps xmm13, [rsp+158h+var_78]
        vmovaps xmm14, [rsp+158h+var_68]
        vmovaps xmm15, [rsp+158h+var_58]
      }
      __asm { vzeroupper }
      return result;
    }
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A0
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm7, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovaps xmm9, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v300 = 0;
    while ( 1 )
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_495;
      v389 = v300;
      __asm { vzeroupper }
      AsyncKeyState = GetAsyncKeyState(32);
      v302 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v302 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v302 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v328 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v329) = GetAsyncKeyState(35);
      v383 = v329;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, dword ptr [rsp+158h+var_120]
        vpinsrw xmm0, xmm0, ebp, 1
        vpinsrw xmm0, xmm0, r14d, 2
        vpinsrw xmm0, xmm0, r15d, 3
        vpinsrw xmm0, xmm0, r12d, 4
        vpinsrw xmm0, xmm0, ebx, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v300 = v328 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v347 = v300 & ~v389;
      if ( ((unsigned __int8)v300 & (unsigned __int8)~(_BYTE)v389 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm9, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v354 = v347;
      if ( (v347 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v347 & 4) == 0 )
        {
LABEL_520:
          if ( (v347 & 8) == 0 )
            goto LABEL_521;
          goto LABEL_529;
        }
      }
      else if ( (v347 & 4) == 0 )
      {
        goto LABEL_520;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm13, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v354 & 8) == 0 )
      {
LABEL_521:
        if ( (v354 & 0x10) == 0 )
          goto LABEL_522;
        goto LABEL_530;
      }
LABEL_529:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v354 & 0x10) == 0 )
      {
LABEL_522:
        if ( (v354 & 0x20) == 0 )
          goto LABEL_523;
        goto LABEL_531;
      }
LABEL_530:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v354 & 0x20) == 0 )
      {
LABEL_523:
        if ( (v354 & 0x40) == 0 )
          goto LABEL_524;
        goto LABEL_532;
      }
LABEL_531:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v354 & 0x40) == 0 )
      {
LABEL_524:
        if ( (v354 & 0x80u) == 0 )
          goto LABEL_525;
        goto LABEL_533;
      }
LABEL_532:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v354 & 0x80u) == 0 )
      {
LABEL_525:
        if ( v354 >= 0x100 )
          goto LABEL_534;
        goto LABEL_495;
      }
LABEL_533:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v354 >= 0x100 )
LABEL_534:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_495:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
      if ( (byte_18001908C & 1) == 0 )
        goto LABEL_2;
    }
  }
  __asm
  {
    vmovaps xmm6, [rsp+158h+var_E8]
    vmovaps xmm7, [rsp+158h+var_D8]
    vmovaps xmm8, [rsp+158h+var_C8]
    vmovaps xmm9, [rsp+158h+var_B8]
    vmovaps xmm10, [rsp+158h+var_A8]
    vmovaps xmm11, [rsp+158h+var_98]
    vmovaps xmm12, [rsp+158h+var_88]
    vmovaps xmm13, [rsp+158h+var_78]
    vmovaps xmm14, [rsp+158h+var_68]
    vmovaps xmm15, [rsp+158h+var_58]
  }
  __asm { vzeroupper }
  return ((__int64 (__fastcall *)(__int64 (__fastcall **)(), __int64, __int64, __int64))funcs_18000348F[(unsigned __int16)word_1800193FA])(
           funcs_18000348F,
           _RDX,
           _R8,
           _R9);
}


// ------------------------------------------------------------
// Function 5/121: sub_1800049F0
// Address: 0x1800049F0 - 0x180004BB0 (size 0x1C0)
// ------------------------------------------------------------
__int64 __fastcall sub_1800049F0(__int64 a1)
{
  __int64 perf_frequency; // rdi
  __int64 perf_counter; // rax
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rdx
  __int64 v7; // rt2
  __int64 v8; // r8
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rdi
  __int64 v12; // rsi
  __int128 v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // r8
  DWORD v18; // ecx

  perf_frequency = Query_perf_frequency();
  perf_counter = Query_perf_counter();
  if ( perf_frequency == 24000000 )
  {
    v4 = perf_counter / 2 + 41 * perf_counter;
  }
  else if ( perf_frequency == 10000000 )
  {
    v4 = 100 * perf_counter;
  }
  else
  {
    if ( (perf_frequency | (unsigned __int64)perf_counter) >> 32 )
    {
      v7 = perf_counter % perf_frequency;
      v5 = perf_counter / perf_frequency;
      v6 = v7;
    }
    else
    {
      v6 = (unsigned int)perf_counter % (unsigned int)perf_frequency;
      v5 = (unsigned int)perf_counter / (unsigned int)perf_frequency;
    }
    v8 = 1000000000 * v5;
    v9 = 1000000000 * v6;
    if ( (perf_frequency | (unsigned __int64)(1000000000 * v6)) >> 32 )
      v10 = v9 / perf_frequency;
    else
      v10 = (unsigned int)v9 / (unsigned int)perf_frequency;
    v4 = v8 + v10;
  }
  v11 = v4 + 1000000 * a1;
  if ( v4 >= -1000000 * a1 + 0x7FFFFFFFFFFFFFFFLL )
    v11 = 0x7FFFFFFFFFFFFFFFLL;
  while ( 1 )
  {
    v12 = Query_perf_frequency();
    *(_QWORD *)&v13 = Query_perf_counter();
    if ( v12 == 24000000 )
    {
      v15 = 41 * v13;
      v13 = 0x5555555555555556LL * (__int128)(2 * (__int64)v13);
      v14 = (*((_QWORD *)&v13 + 1) >> 63) + *((_QWORD *)&v13 + 1) + v15;
    }
    else if ( v12 == 10000000 )
    {
      v14 = 100 * v13;
    }
    else
    {
      if ( (v12 | (unsigned __int64)v13) >> 32 )
      {
        *((_QWORD *)&v13 + 1) = (__int64)v13 % v12;
        v16 = (__int64)v13 / v12;
      }
      else
      {
        *((_QWORD *)&v13 + 1) = (unsigned int)v13 % (unsigned int)v12;
        v16 = (unsigned int)v13 / (unsigned int)v12;
      }
      *(_QWORD *)&v13 = 1000000000LL * *((_QWORD *)&v13 + 1);
      *(_QWORD *)&v13 = (v12 | (unsigned __int64)(1000000000LL * *((_QWORD *)&v13 + 1))) >> 32
                      ? (__int64)v13 / v12
                      : (unsigned int)v13 / (unsigned int)v12;
      v14 = v13 + 1000000000 * v16;
    }
    v17 = v11 - v14;
    if ( v11 <= v14 )
      break;
    v18 = 86400000;
    if ( v17 <= 86400000000000LL )
      v18 = v17 / 1000000 + (1000000 * (v17 / 1000000) < v17);
    Sleep(v18);
  }
  return v13;
}


// ------------------------------------------------------------
// Function 6/121: sub_180004BB0
// Address: 0x180004BB0 - 0x18000612C (size 0x157C)
// ------------------------------------------------------------
__int64 __fastcall sub_180004BB0()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  int v48; // ebp
  int v49; // eax
  unsigned __int16 v67; // ax
  unsigned int v74; // edi
  int v91; // [rsp+38h] [rbp-F0h]
  __int16 v92; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovaps [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A0
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm7, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovdqa xmm14, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v92 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v48 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v49) = GetAsyncKeyState(35);
      v91 = v49;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, r14d, 1
        vpinsrw xmm0, xmm0, r15d, 2
        vpinsrw xmm0, xmm0, r12d, 3
        vpinsrw xmm0, xmm0, r13d, 4
        vpinsrw xmm0, xmm0, esi, 5
        vpinsrw xmm0, xmm0, edi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v48 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v67 = v20 & ~v92;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v92 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm14, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v74 = v67;
      if ( (v67 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v67 & 4) == 0 )
        {
LABEL_28:
          if ( (v67 & 8) == 0 )
            goto LABEL_29;
          goto LABEL_37;
        }
      }
      else if ( (v67 & 4) == 0 )
      {
        goto LABEL_28;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm13, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 8) == 0 )
      {
LABEL_29:
        if ( (v74 & 0x10) == 0 )
          goto LABEL_30;
        goto LABEL_38;
      }
LABEL_37:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 0x10) == 0 )
      {
LABEL_30:
        if ( (v74 & 0x20) == 0 )
          goto LABEL_31;
        goto LABEL_39;
      }
LABEL_38:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v74 & 0x20) == 0 )
      {
LABEL_31:
        if ( (v74 & 0x40) == 0 )
          goto LABEL_32;
        goto LABEL_40;
      }
LABEL_39:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v74 & 0x40) == 0 )
      {
LABEL_32:
        if ( (v74 & 0x80u) == 0 )
          goto LABEL_33;
        goto LABEL_41;
      }
LABEL_40:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v74 & 0x80u) == 0 )
      {
LABEL_33:
        if ( v74 >= 0x100 )
          goto LABEL_42;
        goto LABEL_3;
      }
LABEL_41:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v74 >= 0x100 )
LABEL_42:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 7/121: sub_180006130
// Address: 0x180006130 - 0x1800076AA (size 0x157A)
// ------------------------------------------------------------
__int64 __fastcall sub_180006130()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  int v48; // edi
  int v49; // eax
  unsigned __int16 v67; // ax
  unsigned int v74; // edi
  int v91; // [rsp+38h] [rbp-F0h]
  __int16 v92; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovapd [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovapd [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A0
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm7, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm9, cs:dword_180017200
      vmovapd xmm13, cs:xmmword_1800171E0
      vmovdqa xmm14, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v92 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v48 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v49) = GetAsyncKeyState(35);
      v91 = v49;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, ebp, 1
        vpinsrw xmm0, xmm0, r14d, 2
        vpinsrw xmm0, xmm0, r15d, 3
        vpinsrw xmm0, xmm0, r12d, 4
        vpinsrw xmm0, xmm0, ebx, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v48 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v67 = v20 & ~v92;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v92 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm13, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm14, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v74 = v67;
      if ( (v67 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v67 & 4) == 0 )
        {
LABEL_28:
          if ( (v67 & 8) == 0 )
            goto LABEL_29;
          goto LABEL_37;
        }
      }
      else if ( (v67 & 4) == 0 )
      {
        goto LABEL_28;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm9, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 8) == 0 )
      {
LABEL_29:
        if ( (v74 & 0x10) == 0 )
          goto LABEL_30;
        goto LABEL_38;
      }
LABEL_37:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 0x10) == 0 )
      {
LABEL_30:
        if ( (v74 & 0x20) == 0 )
          goto LABEL_31;
        goto LABEL_39;
      }
LABEL_38:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v74 & 0x20) == 0 )
      {
LABEL_31:
        if ( (v74 & 0x40) == 0 )
          goto LABEL_32;
        goto LABEL_40;
      }
LABEL_39:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v74 & 0x40) == 0 )
      {
LABEL_32:
        if ( (v74 & 0x80u) == 0 )
          goto LABEL_33;
        goto LABEL_41;
      }
LABEL_40:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v74 & 0x80u) == 0 )
      {
LABEL_33:
        if ( v74 >= 0x100 )
          goto LABEL_42;
        goto LABEL_3;
      }
LABEL_41:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v74 >= 0x100 )
LABEL_42:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 8/121: sub_1800076B0
// Address: 0x1800076B0 - 0x180008CC3 (size 0x1613)
// ------------------------------------------------------------
__int64 __fastcall sub_1800076B0()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  __int64 v31; // rsi
  unsigned __int64 v32; // rdi
  char v34; // al
  __int64 *v35; // rax
  bool v36; // cf
  __int64 v49; // rcx
  bool v50; // cf
  bool v51; // cc
  __int64 v70; // rdi
  unsigned __int64 v71; // rbx
  char v73; // al
  bool v84; // cf
  bool v85; // cc
  bool v99; // cf
  bool v100; // cc
  int v111; // ebp
  int v112; // eax
  unsigned __int16 v130; // ax
  unsigned int v137; // edi
  int v154; // [rsp+48h] [rbp-F0h]
  __int16 v155; // [rsp+4Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+138h+var_58], xmm15
    vmovdqa [rsp+138h+var_68], xmm14
    vmovaps [rsp+138h+var_78], xmm13
    vmovaps [rsp+138h+var_88], xmm12
    vmovdqa [rsp+138h+var_98], xmm11
    vmovdqa [rsp+138h+var_A8], xmm10
    vmovaps [rsp+138h+var_B8], xmm9
    vmovapd [rsp+138h+var_C8], xmm8
    vmovaps [rsp+138h+var_D8], xmm7
    vmovaps [rsp+138h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm { vmovss  xmm7, cs:dword_1800171A4 }
    _RBP = byte_1800193F8;
    __asm
    {
      vmovsd  xmm8, cs:qword_1800171A8
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovdqa xmm14, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v155 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        _R15 = hWnd;
        _RAX = *((_QWORD *)hWnd + 1923);
        _R12 = *(unsigned __int8 *)(_RAX + 40);
        if ( *(_BYTE *)(_RAX + 40) )
        {
          __asm { vucomiss xmm0, dword ptr [rax+30h] }
          __asm
          {
            vmovss  xmm0, dword ptr [r15+360h]
            vucomiss xmm0, dword ptr [rbp+r12*4+590h]
          }
          v31 = qword_180019378;
          if ( *(_DWORD *)(qword_180019378 + 16) )
          {
            v32 = 0;
            do
            {
              _R13 = *(_QWORD *)(*(_QWORD *)(v31 + 8) + 8 * v32);
              if ( *(_BYTE *)(_R13 + 601) != *((_BYTE *)_R15 + 601)
                && *(_BYTE *)(_R13 + 776) == 1
                && *(_BYTE *)(_R13 + 3792) == 1 )
              {
                v34 = (*(__int64 (__fastcall **)(_QWORD))&ymmword_1800193C8.m256_f32[4])(*(_QWORD *)(*(_QWORD *)(v31 + 8) + 8 * v32));
                _R15 = hWnd;
                if ( v34 )
                {
                  v35 = *(__int64 **)(_R13 + 11920);
                  v36 = 0;
                  if ( v35 )
                  {
                    while ( 1 )
                    {
                      v49 = *v35;
                      if ( *(_BYTE *)(*v35 + 12) == 18 && *(_QWORD *)(v49 + 16) && *(_BYTE *)(v49 + 56) )
                        break;
                      v35 += 2;
                      v36 = (unsigned __int64)v35 < *(_QWORD *)(_R13 + 11928);
                      if ( (unsigned __int64)v35 >= *(_QWORD *)(_R13 + 11928) )
                        goto LABEL_20;
                    }
                  }
                  else
                  {
LABEL_20:
                    __asm
                    {
                      vmovsd  xmm0, qword ptr [r13+200h]
                      vinsertps xmm0, xmm0, dword ptr [r13+208h], 20h ; ' '
                      vmovsd  xmm1, qword ptr [r15+200h]
                      vinsertps xmm1, xmm1, dword ptr [r15+208h], 20h ; ' '
                      vsubps  xmm0, xmm1, xmm0
                      vdpps   xmm0, xmm0, xmm0, 7Fh
                      vmovss  xmm1, dword ptr [rbp+r12*4+5C8h]
                      vaddss  xmm1, xmm1, dword ptr [r13+6F8h]
                      vaddss  xmm1, xmm1, dword ptr [r15+6F8h]
                      vmulss  xmm1, xmm1, xmm1
                      vucomiss xmm0, xmm1
                    }
                    if ( v36 )
                    {
                      __asm
                      {
                        vmovss  xmm0, dword ptr [r13+1120h]
                        vaddss  xmm6, xmm0, dword ptr [r13+1080h]
                      }
                      *(double *)&_XMM0 = sub_180013070(_R13);
                      __asm { vucomiss xmm6, xmm0 }
                      if ( v36 )
                        byte_1800193F8[0] = 1;
                    }
                  }
                }
              }
              ++v32;
            }
            while ( v32 < *(unsigned int *)(v31 + 16) );
          }
        }
        v50 = byte_1800193F8[0] == 0;
        v51 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v50 = 0, v51 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_1800192E0, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v50 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v51 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        _RSI = hWnd;
        _RAX = *((_QWORD *)hWnd + 1923);
        _R15 = *(unsigned __int8 *)(_RAX + 40);
        if ( *(_BYTE *)(_RAX + 40) )
        {
          __asm { vucomiss xmm0, dword ptr [rax+30h] }
          __asm
          {
            vmovss  xmm0, dword ptr [rsi+360h]
            vucomiss xmm0, dword ptr [rbp+r15*4+590h]
          }
          v70 = qword_180019388;
          if ( *(_DWORD *)(qword_180019388 + 16) )
          {
            v71 = 0;
            do
            {
              _R12 = *(_BYTE **)(*(_QWORD *)(v70 + 8) + 8 * v71);
              if ( _R12[601] != *((_BYTE *)_RSI + 601) && _R12[776] == 1 && _R12[3792] == 1 )
              {
                v73 = (*(__int64 (__fastcall **)(_QWORD))&ymmword_1800193C8.m256_f32[4])(*(_QWORD *)(*(_QWORD *)(v70 + 8) + 8 * v71));
                _RSI = hWnd;
                if ( v73 )
                {
                  __asm
                  {
                    vmovsd  xmm0, qword ptr [r12+200h]
                    vinsertps xmm0, xmm0, dword ptr [r12+208h], 20h ; ' '
                    vmovsd  xmm1, qword ptr [rsi+200h]
                    vinsertps xmm1, xmm1, dword ptr [rsi+208h], 20h ; ' '
                    vsubps  xmm0, xmm1, xmm0
                    vdpps   xmm0, xmm0, xmm0, 7Fh
                    vmovss  xmm1, dword ptr [rbp+r15*4+5C8h]
                    vaddss  xmm1, xmm1, dword ptr [r12+6F8h]
                    vaddss  xmm1, xmm1, dword ptr [rsi+6F8h]
                    vmulss  xmm1, xmm1, xmm1
                    vucomiss xmm0, xmm1
                  }
                }
              }
              ++v71;
            }
            while ( v71 < *(unsigned int *)(v70 + 16) );
          }
        }
        v84 = byte_1800193F8[0] == 0;
        v85 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v84 = 0, v85 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_1800192E0, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v84 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v85 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v99 = byte_1800193F8[0] == 0;
        v100 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v99 = 0, v100 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_1800192E0, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v99 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v100 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v111 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v112) = GetAsyncKeyState(35);
      v154 = v112;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+138h+var_F0]
        vpinsrw xmm0, xmm0, r15d, 1
        vpinsrw xmm0, xmm0, r12d, 2
        vpinsrw xmm0, xmm0, r13d, 3
        vpinsrw xmm0, xmm0, ebx, 4
        vpinsrw xmm0, xmm0, edi, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v111 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v130 = v20 & ~v155;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v155 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm14, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v137 = v130;
      if ( (v130 & 2) != 0 )
        *(_BYTE *)qword_180019338 ^= 1u;
      _RBP = byte_1800193F8;
      if ( (v130 & 4) != 0 )
      {
        _RAX = qword_180019340;
        __asm
        {
          vaddss  xmm0, xmm13, dword ptr [rax]
          vmovss  dword ptr [rax], xmm0
        }
        _RAX = qword_180019348;
        __asm { vmovss  dword ptr [rax], xmm0 }
        if ( (v137 & 8) == 0 )
        {
LABEL_74:
          if ( (v137 & 0x10) == 0 )
            goto LABEL_75;
          goto LABEL_82;
        }
      }
      else if ( (v130 & 8) == 0 )
      {
        goto LABEL_74;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v137 & 0x10) == 0 )
      {
LABEL_75:
        if ( (v137 & 0x20) == 0 )
          goto LABEL_76;
        goto LABEL_83;
      }
LABEL_82:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v137 & 0x20) == 0 )
      {
LABEL_76:
        if ( (v137 & 0x40) == 0 )
          goto LABEL_77;
        goto LABEL_84;
      }
LABEL_83:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v137 & 0x40) == 0 )
      {
LABEL_77:
        if ( (v137 & 0x80u) == 0 )
          goto LABEL_78;
        goto LABEL_85;
      }
LABEL_84:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v137 & 0x80u) == 0 )
      {
LABEL_78:
        if ( v137 >= 0x100 )
          goto LABEL_86;
        goto LABEL_3;
      }
LABEL_85:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v137 >= 0x100 )
LABEL_86:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+138h+var_E8]
    vmovaps xmm7, [rsp+138h+var_D8]
    vmovaps xmm8, [rsp+138h+var_C8]
    vmovaps xmm9, [rsp+138h+var_B8]
    vmovaps xmm10, [rsp+138h+var_A8]
    vmovaps xmm11, [rsp+138h+var_98]
    vmovaps xmm12, [rsp+138h+var_88]
    vmovaps xmm13, [rsp+138h+var_78]
    vmovaps xmm14, [rsp+138h+var_68]
    vmovaps xmm15, [rsp+138h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 9/121: sub_180008CD0
// Address: 0x180008CD0 - 0x18000A394 (size 0x16C4)
// ------------------------------------------------------------
__int64 __fastcall sub_180008CD0()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  bool v26; // cf
  bool v27; // cc
  bool v41; // cf
  bool v42; // cc
  bool v56; // cf
  bool v57; // cc
  int v68; // ebp
  int v69; // eax
  unsigned __int16 v87; // ax
  unsigned int v94; // edi
  int v111; // [rsp+38h] [rbp-F0h]
  __int16 v112; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovaps [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm { vmovss  xmm6, cs:dword_1800171A4 }
    __asm
    {
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm9, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm7, cs:dword_180017204
      vmovss  xmm12, cs:dword_180017200
      vmovdqa xmm15, cs:xmmword_1800171E0
      vmovdqa xmm14, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v112 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v26 = byte_1800193F8[0] == 0;
        v27 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v26 = 0, v27 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019290, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v26 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v27 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v41 = byte_1800193F8[0] == 0;
        v42 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v41 = 0, v42 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019290, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v41 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v42 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v56 = byte_1800193F8[0] == 0;
        v57 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v56 = 0, v57 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019290, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v56 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v57 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v68 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v69) = GetAsyncKeyState(35);
      v111 = v69;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, r14d, 1
        vpinsrw xmm0, xmm0, r15d, 2
        vpinsrw xmm0, xmm0, r12d, 3
        vpinsrw xmm0, xmm0, r13d, 4
        vpinsrw xmm0, xmm0, edi, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v68 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v87 = v20 & ~v112;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v112 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm15, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm14, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v94 = v87;
      if ( (v87 & 2) != 0 )
        *(_BYTE *)qword_180019338 ^= 1u;
      if ( (v87 & 4) != 0 )
      {
        _RAX = qword_180019340;
        __asm
        {
          vaddss  xmm0, xmm12, dword ptr [rax]
          vmovss  dword ptr [rax], xmm0
        }
        _RAX = qword_180019348;
        __asm { vmovss  dword ptr [rax], xmm0 }
        if ( (v94 & 8) == 0 )
        {
LABEL_48:
          if ( (v94 & 0x10) == 0 )
            goto LABEL_49;
          goto LABEL_56;
        }
      }
      else if ( (v87 & 8) == 0 )
      {
        goto LABEL_48;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm7, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v94 & 0x10) == 0 )
      {
LABEL_49:
        if ( (v94 & 0x20) == 0 )
          goto LABEL_50;
        goto LABEL_57;
      }
LABEL_56:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v94 & 0x20) == 0 )
      {
LABEL_50:
        if ( (v94 & 0x40) == 0 )
          goto LABEL_51;
        goto LABEL_58;
      }
LABEL_57:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v94 & 0x40) == 0 )
      {
LABEL_51:
        if ( (v94 & 0x80u) == 0 )
          goto LABEL_52;
        goto LABEL_59;
      }
LABEL_58:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v94 & 0x80u) == 0 )
      {
LABEL_52:
        if ( v94 >= 0x100 )
          goto LABEL_60;
        goto LABEL_3;
      }
LABEL_59:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v94 >= 0x100 )
LABEL_60:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 10/121: sub_18000A3A0
// Address: 0x18000A3A0 - 0x18000B8CC (size 0x152C)
// ------------------------------------------------------------
__int64 __fastcall sub_18000A3A0()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  int v48; // ebp
  int v49; // eax
  unsigned __int16 v67; // ax
  unsigned int v74; // edi
  int v91; // [rsp+38h] [rbp-F0h]
  __int16 v92; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovaps [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A0
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm7, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovdqa xmm14, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v92 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v48 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v49) = GetAsyncKeyState(35);
      v91 = v49;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, r14d, 1
        vpinsrw xmm0, xmm0, r15d, 2
        vpinsrw xmm0, xmm0, r12d, 3
        vpinsrw xmm0, xmm0, r13d, 4
        vpinsrw xmm0, xmm0, esi, 5
        vpinsrw xmm0, xmm0, edi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v48 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v67 = v20 & ~v92;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v92 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm14, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v74 = v67;
      if ( (v67 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v67 & 4) == 0 )
        {
LABEL_28:
          if ( (v67 & 8) == 0 )
            goto LABEL_29;
          goto LABEL_37;
        }
      }
      else if ( (v67 & 4) == 0 )
      {
        goto LABEL_28;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm13, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 8) == 0 )
      {
LABEL_29:
        if ( (v74 & 0x10) == 0 )
          goto LABEL_30;
        goto LABEL_38;
      }
LABEL_37:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 0x10) == 0 )
      {
LABEL_30:
        if ( (v74 & 0x20) == 0 )
          goto LABEL_31;
        goto LABEL_39;
      }
LABEL_38:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v74 & 0x20) == 0 )
      {
LABEL_31:
        if ( (v74 & 0x40) == 0 )
          goto LABEL_32;
        goto LABEL_40;
      }
LABEL_39:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v74 & 0x40) == 0 )
      {
LABEL_32:
        if ( (v74 & 0x80u) == 0 )
          goto LABEL_33;
        goto LABEL_41;
      }
LABEL_40:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v74 & 0x80u) == 0 )
      {
LABEL_33:
        if ( v74 >= 0x100 )
          goto LABEL_42;
        goto LABEL_3;
      }
LABEL_41:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v74 >= 0x100 )
LABEL_42:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 11/121: sub_18000B8D0
// Address: 0x18000B8D0 - 0x18000CE80 (size 0x15B0)
// ------------------------------------------------------------
__int64 __fastcall sub_18000B8D0()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  bool v26; // cf
  bool v27; // cc
  bool v41; // cf
  bool v42; // cc
  bool v56; // cf
  bool v57; // cc
  int v68; // ebp
  int v69; // eax
  unsigned __int16 v87; // ax
  unsigned int v94; // edi
  int v111; // [rsp+38h] [rbp-F0h]
  __int16 v112; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovaps [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A4
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm9, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm7, cs:dword_180017204
      vmovss  xmm12, cs:dword_180017200
      vmovdqa xmm15, cs:xmmword_1800171E0
      vmovdqa xmm14, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v112 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v26 = byte_1800193F8[0] == 0;
        v27 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v26 = 0, v27 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019240, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v26 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v27 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v41 = byte_1800193F8[0] == 0;
        v42 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v41 = 0, v42 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019240, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v41 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v42 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v56 = byte_1800193F8[0] == 0;
        v57 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v56 = 0, v57 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019240, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v56 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v57 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v68 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v69) = GetAsyncKeyState(35);
      v111 = v69;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, r14d, 1
        vpinsrw xmm0, xmm0, r15d, 2
        vpinsrw xmm0, xmm0, r12d, 3
        vpinsrw xmm0, xmm0, r13d, 4
        vpinsrw xmm0, xmm0, edi, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v68 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v87 = v20 & ~v112;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v112 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm15, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm14, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v94 = v87;
      if ( (v87 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v87 & 4) == 0 )
        {
LABEL_46:
          if ( (v87 & 8) == 0 )
            goto LABEL_47;
          goto LABEL_55;
        }
      }
      else if ( (v87 & 4) == 0 )
      {
        goto LABEL_46;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v94 & 8) == 0 )
      {
LABEL_47:
        if ( (v94 & 0x10) == 0 )
          goto LABEL_48;
        goto LABEL_56;
      }
LABEL_55:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm7, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v94 & 0x10) == 0 )
      {
LABEL_48:
        if ( (v94 & 0x20) == 0 )
          goto LABEL_49;
        goto LABEL_57;
      }
LABEL_56:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v94 & 0x20) == 0 )
      {
LABEL_49:
        if ( (v94 & 0x40) == 0 )
          goto LABEL_50;
        goto LABEL_58;
      }
LABEL_57:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v94 & 0x40) == 0 )
      {
LABEL_50:
        if ( (v94 & 0x80u) == 0 )
          goto LABEL_51;
        goto LABEL_59;
      }
LABEL_58:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v94 & 0x80u) == 0 )
      {
LABEL_51:
        if ( v94 >= 0x100 )
          goto LABEL_60;
        goto LABEL_3;
      }
LABEL_59:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v94 >= 0x100 )
LABEL_60:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 12/121: sub_18000CE80
// Address: 0x18000CE80 - 0x18000E65D (size 0x17DD)
// ------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_18000CE80(double _XMM0_8)
{
  _QWORD *v14; // rax
  struct _Mtx_internal_imp_t *v16; // r14
  _DWORD *v17; // r15
  unsigned __int16 v27; // di
  SHORT AsyncKeyState; // ax
  char v29; // cl
  int v55; // esi
  int v56; // eax
  unsigned int v67; // eax
  int v68; // edi
  unsigned int v69; // eax
  int v70; // ebx
  unsigned int v71; // eax
  int v72; // eax
  char v86; // si
  int v93; // esi
  char *v96; // rcx
  struct _Cnd_internal_imp_t *v107; // [rsp+40h] [rbp-168h]
  int v108; // [rsp+48h] [rbp-160h]
  unsigned __int16 v109; // [rsp+4Ch] [rbp-15Ch]
  char *v110; // [rsp+50h] [rbp-158h]
  _DWORD *v111; // [rsp+58h] [rbp-150h]
  struct _Mtx_internal_imp_t *v112; // [rsp+60h] [rbp-148h]
  char *v113; // [rsp+68h] [rbp-140h]
  unsigned int ThrdAddr[4]; // [rsp+70h] [rbp-138h] BYREF
  _Thrd_t v115; // [rsp+80h] [rbp-128h] BYREF
  void *Block; // [rsp+B8h] [rbp-F0h]

  __asm
  {
    vmovdqa [rsp+1A8h+var_58], xmm15
    vmovaps [rsp+1A8h+var_68], xmm14
    vmovaps [rsp+1A8h+var_78], xmm13
    vmovaps [rsp+1A8h+var_88], xmm12
    vmovdqa [rsp+1A8h+var_98], xmm11
    vmovdqa [rsp+1A8h+var_A8], xmm10
    vmovaps [rsp+1A8h+var_B8], xmm9
    vmovapd [rsp+1A8h+var_C8], xmm8
    vmovaps [rsp+1A8h+var_D8], xmm7
    vmovaps [rsp+1A8h+var_E8], xmm6
  }
  _RBX = (char *)sub_180015230(0xF0u);
  v115._Hnd = &off_180017300;
  *(_QWORD *)&v115._Id = sub_1800150E0;
  Block = &v115;
  *(_QWORD *)_RBX = &off_180017300;
  *((_QWORD *)_RBX + 1) = sub_1800150E0;
  *((_QWORD *)_RBX + 7) = _RBX;
  *((_QWORD *)_RBX + 8) = 0;
  *((_DWORD *)_RBX + 18) = 0;
  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vmovups ymmword ptr [rbx+78h], ymm0
    vmovups ymmword ptr [rbx+58h], ymm0
  }
  *((_DWORD *)_RBX + 38) = -1;
  *((_DWORD *)_RBX + 20) = 2;
  __asm
  {
    vmovups ymmword ptr [rbx+0CAh], ymm0
    vmovups ymmword ptr [rbx+0BCh], ymm0
    vmovups ymmword ptr [rbx+9Ch], ymm0
  }
  __asm { vzeroupper }
  v14 = (_QWORD *)sub_180015230(8u);
  *v14 = _RBX;
  *(_QWORD *)ThrdAddr = beginthreadex(0, 0, StartAddress, v14, 0, &ThrdAddr[2]);
  if ( !*(_QWORD *)ThrdAddr )
    goto LABEL_78;
  if ( *((_DWORD *)_RBX + 18) )
    goto LABEL_79;
  __asm { vmovups xmm0, xmmword ptr [rsp+1A8h+var_138] }
  v110 = _RBX + 64;
  __asm { vmovups xmmword ptr [rax], xmm0 }
  if ( Block && Block != &v115 )
    j_j_free(Block);
  v16 = (struct _Mtx_internal_imp_t *)(_RBX + 80);
  v17 = _RBX + 156;
  if ( (byte_18001908C & 1) != 0 )
  {
    v107 = (struct _Cnd_internal_imp_t *)(_RBX + 160);
    __asm
    {
      vmovss  xmm7, cs:dword_1800171A0
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm9, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovd   xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovdqa xmm14, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v27 = 0;
    v113 = _RBX;
    v112 = (struct _Mtx_internal_imp_t *)(_RBX + 80);
    v111 = _RBX + 156;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_8;
      v109 = v27;
      AsyncKeyState = GetAsyncKeyState(32);
      v29 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v29 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v29 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v55 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v56) = GetAsyncKeyState(35);
      v108 = v56;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+1A8h+var_160]
        vpinsrw xmm0, xmm0, r12d, 1
        vpinsrw xmm0, xmm0, r13d, 2
        vpinsrw xmm0, xmm0, r14d, 3
        vpinsrw xmm0, xmm0, ebx, 4
        vpinsrw xmm0, xmm0, r15d, 5
        vpinsrw xmm0, xmm0, edi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm6, xmm11, xmm0
      }
      LOWORD(v67) = GetAsyncKeyState(69);
      v68 = (v67 >> 6) & 0x200;
      LOWORD(v69) = GetAsyncKeyState(51);
      v70 = (v69 >> 5) & 0x400;
      LOWORD(v71) = GetAsyncKeyState(71);
      v72 = v55 | v68 | v70 | (v71 >> 4) & 0x800;
      __asm
      {
        vpshufd xmm0, xmm6, 0EEh
        vpor    xmm0, xmm6, xmm0
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   edi, xmm0
      }
      v27 = v72 | _EDI;
      if ( ((unsigned __int8)v27 & (unsigned __int8)~(_BYTE)v109 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm14, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v86 = v27 & ~(_BYTE)v109;
      if ( (v86 & 2) != 0 )
        *(_BYTE *)qword_180019338 ^= 1u;
      _RBX = v113;
      v16 = v112;
      v17 = v111;
      if ( (v86 & 4) != 0 )
      {
        _RAX = qword_180019340;
        __asm
        {
          vaddss  xmm0, xmm13, dword ptr [rax]
          vmovss  dword ptr [rax], xmm0
        }
        _RAX = qword_180019348;
        __asm { vmovss  dword ptr [rax], xmm0 }
        if ( (v86 & 8) == 0 )
        {
LABEL_35:
          if ( (v86 & 0x10) == 0 )
            goto LABEL_36;
          goto LABEL_46;
        }
      }
      else if ( (v86 & 8) == 0 )
      {
        goto LABEL_35;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v86 & 0x10) == 0 )
      {
LABEL_36:
        if ( (v86 & 0x20) == 0 )
          goto LABEL_37;
        goto LABEL_47;
      }
LABEL_46:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v86 & 0x20) == 0 )
      {
LABEL_37:
        if ( (v86 & 0x40) == 0 )
          goto LABEL_38;
        goto LABEL_48;
      }
LABEL_47:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v86 & 0x40) == 0 )
      {
LABEL_38:
        if ( v86 >= 0 )
          goto LABEL_39;
        goto LABEL_49;
      }
LABEL_48:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( v86 >= 0 )
      {
LABEL_39:
        if ( (v27 & (unsigned __int16)~v109 & 0x100) == 0 )
          goto LABEL_40;
        goto LABEL_50;
      }
LABEL_49:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( (v27 & (unsigned __int16)~v109 & 0x100) == 0 )
      {
LABEL_40:
        if ( (v27 & (unsigned __int16)~v109 & 0x200) == 0 )
          goto LABEL_41;
        goto LABEL_51;
      }
LABEL_50:
      qword_180019410 = *(_QWORD *)qword_1800193A0;
      if ( (v27 & (unsigned __int16)~v109 & 0x200) == 0 )
      {
LABEL_41:
        if ( (v27 & (unsigned __int16)~v109 & 0x400) != 0 )
          goto LABEL_56;
        goto LABEL_42;
      }
LABEL_51:
      __asm { vzeroupper }
      if ( Mtx_lock(v112) )
        goto LABEL_76;
      if ( *v111 == 0x7FFFFFFF )
        goto LABEL_77;
      if ( !v113[233] )
      {
        *(_WORD *)(v113 + 233) = 513;
        Cnd_broadcast(v107);
      }
      Mtx_unlock(v112);
      if ( (v27 & (unsigned __int16)~v109 & 0x400) != 0 )
      {
LABEL_56:
        __asm { vzeroupper }
        if ( Mtx_lock(v112) )
          goto LABEL_76;
        if ( *v111 == 0x7FFFFFFF )
          goto LABEL_77;
        if ( !v113[233] )
        {
          *(_WORD *)(v113 + 233) = 257;
          Cnd_broadcast(v107);
        }
        Mtx_unlock(v112);
        if ( (v27 & (unsigned __int16)~v109 & 0x800) == 0 )
          goto LABEL_8;
        goto LABEL_61;
      }
LABEL_42:
      if ( (v27 & (unsigned __int16)~v109 & 0x800) == 0 )
        goto LABEL_8;
LABEL_61:
      __asm { vzeroupper }
      if ( Mtx_lock(v112) )
        goto LABEL_76;
      if ( *v111 == 0x7FFFFFFF )
        goto LABEL_77;
      if ( !v113[233] )
      {
        *(_WORD *)(v113 + 233) = 769;
        Cnd_broadcast(v107);
      }
      Mtx_unlock(v112);
LABEL_8:
      __asm { vzeroupper }
      sub_1800049F0(10);
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  if ( Mtx_lock(v16) )
    goto LABEL_76;
  if ( *v17 == 0x7FFFFFFF )
  {
LABEL_77:
    *v17 = 2147483646;
    std::_Throw_Cpp_error(6);
LABEL_78:
    ThrdAddr[2] = 0;
    std::_Throw_Cpp_error(6);
LABEL_79:
    terminate();
  }
  _RBX[232] = 1;
  Cnd_broadcast((_Cnd_t)(_RBX + 160));
  Mtx_unlock(v16);
  v93 = *((_DWORD *)_RBX + 18);
  if ( !v93 )
    goto LABEL_72;
  if ( v93 == Thrd_id() )
  {
LABEL_76:
    std::_Throw_Cpp_error(5);
    goto LABEL_77;
  }
  _RAX = v110;
  __asm
  {
    vmovups xmm0, xmmword ptr [rax]
    vmovaps xmmword ptr [rsp+1A8h+var_128._Hnd], xmm0
  }
  if ( Thrd_join(&v115, 0) )
  {
    std::_Throw_Cpp_error(2);
    JUMPOUT(0x18000E65CLL);
  }
  *((_QWORD *)_RBX + 8) = 0;
  *((_DWORD *)_RBX + 18) = 0;
LABEL_72:
  v96 = (char *)*((_QWORD *)_RBX + 7);
  if ( v96 && v96 != _RBX )
    j_j_free(v96);
  j_j_free(_RBX);
  __asm
  {
    vmovaps xmm6, [rsp+1A8h+var_E8]
    vmovaps xmm7, [rsp+1A8h+var_D8]
    vmovaps xmm8, [rsp+1A8h+var_C8]
    vmovaps xmm9, [rsp+1A8h+var_B8]
    vmovaps xmm10, [rsp+1A8h+var_A8]
    vmovaps xmm11, [rsp+1A8h+var_98]
    vmovaps xmm12, [rsp+1A8h+var_88]
    vmovaps xmm13, [rsp+1A8h+var_78]
    vmovaps xmm14, [rsp+1A8h+var_68]
    vmovaps xmm15, [rsp+1A8h+var_58]
  }
}


// ------------------------------------------------------------
// Function 13/121: sub_18000E660
// Address: 0x18000E660 - 0x18000FC13 (size 0x15B3)
// ------------------------------------------------------------
__int64 __fastcall sub_18000E660()
{
  __int64 result; // rax
  __int16 v19; // si
  SHORT AsyncKeyState; // ax
  char v21; // cl
  __int64 v31; // rsi
  unsigned __int64 v32; // rdi
  char v34; // al
  __int64 *v35; // rax
  bool v36; // cf
  __int64 v50; // rcx
  bool v51; // cf
  bool v52; // cc
  __int64 v72; // rdi
  unsigned __int64 v73; // rbx
  char v75; // al
  bool v87; // cf
  bool v88; // cc
  bool v102; // cf
  bool v103; // cc
  int v114; // ebp
  int v115; // eax
  unsigned __int16 v133; // ax
  unsigned int v140; // edi
  int v157; // [rsp+48h] [rbp-F0h]
  __int16 v158; // [rsp+4Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+138h+var_58], xmm15
    vmovdqa [rsp+138h+var_68], xmm14
    vmovaps [rsp+138h+var_78], xmm13
    vmovaps [rsp+138h+var_88], xmm12
    vmovdqa [rsp+138h+var_98], xmm11
    vmovdqa [rsp+138h+var_A8], xmm10
    vmovaps [rsp+138h+var_B8], xmm9
    vmovapd [rsp+138h+var_C8], xmm8
    vmovaps [rsp+138h+var_D8], xmm7
    vmovaps [rsp+138h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm7, cs:dword_1800171A4
      vmovsd  xmm8, cs:qword_1800171A8
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovdqa xmm14, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v19 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v158 = v19;
      AsyncKeyState = GetAsyncKeyState(32);
      v21 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v21 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        _R15 = hWnd;
        _RAX = *((_QWORD *)hWnd + 1923);
        _R12 = *(unsigned __int8 *)(_RAX + 40);
        if ( *(_BYTE *)(_RAX + 40) )
        {
          __asm { vucomiss xmm0, dword ptr [rax+30h] }
          __asm { vmovss  xmm0, dword ptr [r15+360h] }
          _RAX = byte_1800193F8;
          __asm { vucomiss xmm0, dword ptr [rax+r12*4+590h] }
          v31 = qword_180019378;
          if ( *(_DWORD *)(qword_180019378 + 16) )
          {
            v32 = 0;
            do
            {
              _R13 = *(_QWORD *)(*(_QWORD *)(v31 + 8) + 8 * v32);
              if ( *(_BYTE *)(_R13 + 601) != *((_BYTE *)_R15 + 601)
                && *(_BYTE *)(_R13 + 776) == 1
                && *(_BYTE *)(_R13 + 3792) == 1 )
              {
                v34 = (*(__int64 (__fastcall **)(_QWORD))&ymmword_1800193C8.m256_f32[4])(*(_QWORD *)(*(_QWORD *)(v31 + 8) + 8 * v32));
                _R15 = hWnd;
                if ( v34 )
                {
                  v35 = *(__int64 **)(_R13 + 11920);
                  v36 = 0;
                  if ( v35 )
                  {
                    while ( 1 )
                    {
                      v50 = *v35;
                      if ( *(_BYTE *)(*v35 + 12) == 18 && *(_QWORD *)(v50 + 16) && *(_BYTE *)(v50 + 56) )
                        break;
                      v35 += 2;
                      v36 = (unsigned __int64)v35 < *(_QWORD *)(_R13 + 11928);
                      if ( (unsigned __int64)v35 >= *(_QWORD *)(_R13 + 11928) )
                        goto LABEL_20;
                    }
                  }
                  else
                  {
LABEL_20:
                    __asm
                    {
                      vmovsd  xmm0, qword ptr [r13+200h]
                      vinsertps xmm0, xmm0, dword ptr [r13+208h], 20h ; ' '
                      vmovsd  xmm1, qword ptr [r15+200h]
                      vinsertps xmm1, xmm1, dword ptr [r15+208h], 20h ; ' '
                      vsubps  xmm0, xmm1, xmm0
                      vdpps   xmm0, xmm0, xmm0, 7Fh
                    }
                    _RAX = byte_1800193F8;
                    __asm
                    {
                      vmovss  xmm1, dword ptr [rax+r12*4+5C8h]
                      vaddss  xmm1, xmm1, dword ptr [r13+6F8h]
                      vaddss  xmm1, xmm1, dword ptr [r15+6F8h]
                      vmulss  xmm1, xmm1, xmm1
                      vucomiss xmm0, xmm1
                    }
                    if ( v36 )
                    {
                      __asm
                      {
                        vmovss  xmm0, dword ptr [r13+1120h]
                        vaddss  xmm6, xmm0, dword ptr [r13+1080h]
                      }
                      *(double *)&_XMM0 = sub_180012960(_R13);
                      __asm { vucomiss xmm6, xmm0 }
                      if ( v36 )
                        byte_1800193F8[0] = 1;
                    }
                  }
                }
              }
              ++v32;
            }
            while ( v32 < *(unsigned int *)(v31 + 16) );
          }
        }
        v51 = byte_1800193F8[0] == 0;
        v52 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v51 = 0, v52 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_1800192E0, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v51 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v52 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v21 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        _RSI = hWnd;
        _RAX = *((_QWORD *)hWnd + 1923);
        _R15 = *(unsigned __int8 *)(_RAX + 40);
        if ( *(_BYTE *)(_RAX + 40) )
        {
          __asm { vucomiss xmm0, dword ptr [rax+30h] }
          __asm { vmovss  xmm0, dword ptr [rsi+360h] }
          _RAX = byte_1800193F8;
          __asm { vucomiss xmm0, dword ptr [rax+r15*4+590h] }
          v72 = qword_180019388;
          if ( *(_DWORD *)(qword_180019388 + 16) )
          {
            v73 = 0;
            do
            {
              _R12 = *(_BYTE **)(*(_QWORD *)(v72 + 8) + 8 * v73);
              if ( _R12[601] != *((_BYTE *)_RSI + 601) && _R12[776] == 1 && _R12[3792] == 1 )
              {
                v75 = (*(__int64 (__fastcall **)(_QWORD))&ymmword_1800193C8.m256_f32[4])(*(_QWORD *)(*(_QWORD *)(v72 + 8) + 8 * v73));
                _RSI = hWnd;
                if ( v75 )
                {
                  __asm
                  {
                    vmovsd  xmm0, qword ptr [r12+200h]
                    vinsertps xmm0, xmm0, dword ptr [r12+208h], 20h ; ' '
                    vmovsd  xmm1, qword ptr [rsi+200h]
                    vinsertps xmm1, xmm1, dword ptr [rsi+208h], 20h ; ' '
                    vsubps  xmm0, xmm1, xmm0
                    vdpps   xmm0, xmm0, xmm0, 7Fh
                  }
                  _RAX = byte_1800193F8;
                  __asm
                  {
                    vmovss  xmm1, dword ptr [rax+r15*4+5C8h]
                    vaddss  xmm1, xmm1, dword ptr [r12+6F8h]
                    vaddss  xmm1, xmm1, dword ptr [rsi+6F8h]
                    vmulss  xmm1, xmm1, xmm1
                    vucomiss xmm0, xmm1
                  }
                }
              }
              ++v73;
            }
            while ( v73 < *(unsigned int *)(v72 + 16) );
          }
        }
        v87 = byte_1800193F8[0] == 0;
        v88 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v87 = 0, v88 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_1800192E0, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v87 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v88 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v102 = byte_1800193F8[0] == 0;
        v103 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v102 = 0, v103 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_1800192E0, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v102 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v103 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v114 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v115) = GetAsyncKeyState(35);
      v157 = v115;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+138h+var_F0]
        vpinsrw xmm0, xmm0, r15d, 1
        vpinsrw xmm0, xmm0, r12d, 2
        vpinsrw xmm0, xmm0, r13d, 3
        vpinsrw xmm0, xmm0, ebx, 4
        vpinsrw xmm0, xmm0, edi, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v19 = v114 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v133 = v19 & ~v158;
      if ( ((unsigned __int8)v19 & (unsigned __int8)~(_BYTE)v158 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm14, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v140 = v133;
      if ( (v133 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v133 & 4) == 0 )
        {
LABEL_72:
          if ( (v133 & 8) == 0 )
            goto LABEL_73;
          goto LABEL_81;
        }
      }
      else if ( (v133 & 4) == 0 )
      {
        goto LABEL_72;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm13, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v140 & 8) == 0 )
      {
LABEL_73:
        if ( (v140 & 0x10) == 0 )
          goto LABEL_74;
        goto LABEL_82;
      }
LABEL_81:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v140 & 0x10) == 0 )
      {
LABEL_74:
        if ( (v140 & 0x20) == 0 )
          goto LABEL_75;
        goto LABEL_83;
      }
LABEL_82:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v140 & 0x20) == 0 )
      {
LABEL_75:
        if ( (v140 & 0x40) == 0 )
          goto LABEL_76;
        goto LABEL_84;
      }
LABEL_83:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v140 & 0x40) == 0 )
      {
LABEL_76:
        if ( (v140 & 0x80u) == 0 )
          goto LABEL_77;
        goto LABEL_85;
      }
LABEL_84:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v140 & 0x80u) == 0 )
      {
LABEL_77:
        if ( v140 >= 0x100 )
          goto LABEL_86;
        goto LABEL_3;
      }
LABEL_85:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v140 >= 0x100 )
LABEL_86:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+138h+var_E8]
    vmovaps xmm7, [rsp+138h+var_D8]
    vmovaps xmm8, [rsp+138h+var_C8]
    vmovaps xmm9, [rsp+138h+var_B8]
    vmovaps xmm10, [rsp+138h+var_A8]
    vmovaps xmm11, [rsp+138h+var_98]
    vmovaps xmm12, [rsp+138h+var_88]
    vmovaps xmm13, [rsp+138h+var_78]
    vmovaps xmm14, [rsp+138h+var_68]
    vmovaps xmm15, [rsp+138h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 14/121: sub_18000FC20
// Address: 0x18000FC20 - 0x1800111D0 (size 0x15B0)
// ------------------------------------------------------------
__int64 __fastcall sub_18000FC20()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  bool v26; // cf
  bool v27; // cc
  bool v41; // cf
  bool v42; // cc
  bool v56; // cf
  bool v57; // cc
  int v68; // ebp
  int v69; // eax
  unsigned __int16 v87; // ax
  unsigned int v94; // edi
  int v111; // [rsp+38h] [rbp-F0h]
  __int16 v112; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovaps [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A4
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm9, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm7, cs:dword_180017204
      vmovss  xmm12, cs:dword_180017200
      vmovdqa xmm15, cs:xmmword_1800171E0
      vmovdqa xmm14, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v112 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v26 = byte_1800193F8[0] == 0;
        v27 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v26 = 0, v27 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019290, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v26 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v27 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v41 = byte_1800193F8[0] == 0;
        v42 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v41 = 0, v42 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019290, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v41 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v42 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        v56 = byte_1800193F8[0] == 0;
        v57 = byte_1800193F8[0] <= 1u;
        if ( byte_1800193F8[0] == 1 && (v56 = 0, v57 = ((_BYTE)hWnd[1320] & 4) == 0, ((_BYTE)hWnd[1320] & 4) != 0) )
        {
          byte_1800193F8[0] = 0;
          SendInput(2u, &stru_180019290, 40);
          sub_1800049F0(10);
        }
        else
        {
          _RAX = qword_180019368;
          __asm
          {
            vmovss  xmm0, dword ptr [rax]
            vcvtss2sd xmm1, xmm0, xmm0
            vmovss  xmm2, cs:dword_180019400
            vcvtss2sd xmm2, xmm2, xmm2
            vaddsd  xmm2, xmm8, xmm2
            vucomisd xmm2, xmm1
          }
          if ( v56 )
          {
            __asm
            {
              vmovss  xmm1, cs:dword_180019408
              vaddss  xmm1, xmm1, cs:dword_1800193FC
              vucomiss xmm0, xmm1
            }
            if ( !v57 && ((_BYTE)hWnd[1320] & 8) != 0 )
            {
              SendInput(2u, &pInputs, 40);
              sub_1800049F0(10);
              _RAX = qword_180019368;
              __asm
              {
                vmovss  xmm0, dword ptr [rax]
                vmovss  cs:dword_180019400, xmm0
              }
            }
          }
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v68 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v69) = GetAsyncKeyState(35);
      v111 = v69;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, r14d, 1
        vpinsrw xmm0, xmm0, r15d, 2
        vpinsrw xmm0, xmm0, r12d, 3
        vpinsrw xmm0, xmm0, r13d, 4
        vpinsrw xmm0, xmm0, edi, 5
        vpinsrw xmm0, xmm0, esi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v68 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v87 = v20 & ~v112;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v112 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm15, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm14, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v94 = v87;
      if ( (v87 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v87 & 4) == 0 )
        {
LABEL_46:
          if ( (v87 & 8) == 0 )
            goto LABEL_47;
          goto LABEL_55;
        }
      }
      else if ( (v87 & 4) == 0 )
      {
        goto LABEL_46;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v94 & 8) == 0 )
      {
LABEL_47:
        if ( (v94 & 0x10) == 0 )
          goto LABEL_48;
        goto LABEL_56;
      }
LABEL_55:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm7, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v94 & 0x10) == 0 )
      {
LABEL_48:
        if ( (v94 & 0x20) == 0 )
          goto LABEL_49;
        goto LABEL_57;
      }
LABEL_56:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v94 & 0x20) == 0 )
      {
LABEL_49:
        if ( (v94 & 0x40) == 0 )
          goto LABEL_50;
        goto LABEL_58;
      }
LABEL_57:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v94 & 0x40) == 0 )
      {
LABEL_50:
        if ( (v94 & 0x80u) == 0 )
          goto LABEL_51;
        goto LABEL_59;
      }
LABEL_58:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v94 & 0x80u) == 0 )
      {
LABEL_51:
        if ( v94 >= 0x100 )
          goto LABEL_60;
        goto LABEL_3;
      }
LABEL_59:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v94 >= 0x100 )
LABEL_60:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 15/121: sub_1800111D0
// Address: 0x1800111D0 - 0x1800126FC (size 0x152C)
// ------------------------------------------------------------
__int64 __fastcall sub_1800111D0()
{
  __int64 result; // rax
  __int16 v20; // si
  SHORT AsyncKeyState; // ax
  char v22; // cl
  int v48; // ebp
  int v49; // eax
  unsigned __int16 v67; // ax
  unsigned int v74; // edi
  int v91; // [rsp+38h] [rbp-F0h]
  __int16 v92; // [rsp+3Ch] [rbp-ECh]

  __asm
  {
    vmovdqa [rsp+128h+var_58], xmm15
    vmovdqa [rsp+128h+var_68], xmm14
    vmovaps [rsp+128h+var_78], xmm13
    vmovaps [rsp+128h+var_88], xmm12
    vmovdqa [rsp+128h+var_98], xmm11
    vmovdqa [rsp+128h+var_A8], xmm10
    vmovaps [rsp+128h+var_B8], xmm9
    vmovapd [rsp+128h+var_C8], xmm8
    vmovaps [rsp+128h+var_D8], xmm7
    vmovaps [rsp+128h+var_E8], xmm6
  }
  result = (unsigned __int8)byte_18001908C;
  if ( (byte_18001908C & 1) != 0 )
  {
    __asm
    {
      vmovss  xmm6, cs:dword_1800171A0
      vmovsd  xmm8, cs:qword_1800171A8
      vmovss  xmm7, cs:dword_1800171B0
      vmovdqa xmm10, cs:xmmword_1800171C0
      vmovdqa xmm11, cs:xmmword_1800171D0
      vmovss  xmm12, cs:dword_180017204
      vmovss  xmm13, cs:dword_180017200
      vmovdqa xmm14, cs:xmmword_1800171E0
      vmovdqa xmm15, cs:xmmword_1800171F0
    }
    v20 = 0;
    do
    {
      if ( *(_BYTE *)xmmword_180019358 != 1 || **((_BYTE **)&xmmword_180019358 + 1) )
        goto LABEL_3;
      v92 = v20;
      AsyncKeyState = GetAsyncKeyState(32);
      v22 = byte_1800193F9;
      if ( AsyncKeyState < 0 )
      {
        if ( (byte_1800193F9 & 1) == 0 )
        {
          *(_BYTE *)qword_180019330 = 1;
          byte_1800193F9 = v22 | 1;
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 1) != 0 )
      {
        *(_BYTE *)qword_180019330 = 0;
        byte_1800193F9 = v22 & 0xFE;
      }
      if ( GetAsyncKeyState(86) < 0 )
      {
        if ( (byte_1800193F9 & 2) == 0 )
          byte_1800193F9 |= 2u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vmovss  xmm1, cs:dword_180019404
          vaddss  xmm1, xmm1, cs:dword_1800193FC
          vucomiss xmm1, xmm0
        }
        __asm
        {
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 2) != 0 )
      {
        byte_1800193F9 &= ~2u;
      }
      if ( GetAsyncKeyState(67) < 0 )
      {
        if ( (byte_1800193F9 & 4) == 0 )
          byte_1800193F9 |= 4u;
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, cs:dword_180019404
          vaddss  xmm0, xmm0, cs:dword_1800193FC
          vucomiss xmm0, dword ptr [rax]
        }
        _RAX = qword_180019368;
        __asm
        {
          vmovss  xmm0, dword ptr [rax]
          vcvtss2sd xmm1, xmm0, xmm0
          vmovss  xmm2, cs:dword_180019400
          vcvtss2sd xmm2, xmm2, xmm2
          vaddsd  xmm2, xmm8, xmm2
          vucomisd xmm2, xmm1
        }
      }
      else if ( (byte_1800193F9 & 4) != 0 )
      {
        byte_1800193F9 &= ~4u;
      }
      v48 = (unsigned __int16)GetAsyncKeyState(36) >> 15;
      LOWORD(v49) = GetAsyncKeyState(35);
      v91 = v49;
      GetAsyncKeyState(33);
      GetAsyncKeyState(34);
      GetAsyncKeyState(38);
      GetAsyncKeyState(40);
      GetAsyncKeyState(37);
      GetAsyncKeyState(39);
      GetAsyncKeyState(1);
      __asm
      {
        vmovd   xmm0, [rsp+128h+var_F0]
        vpinsrw xmm0, xmm0, r14d, 1
        vpinsrw xmm0, xmm0, r15d, 2
        vpinsrw xmm0, xmm0, r12d, 3
        vpinsrw xmm0, xmm0, r13d, 4
        vpinsrw xmm0, xmm0, esi, 5
        vpinsrw xmm0, xmm0, edi, 6
        vpinsrw xmm0, xmm0, eax, 7
        vpmulhuw xmm0, xmm10, xmm0
        vpand   xmm0, xmm11, xmm0
        vpshufd xmm1, xmm0, 0EEh
        vpor    xmm0, xmm0, xmm1
        vpshufd xmm1, xmm0, 55h ; 'U'
        vpor    xmm0, xmm0, xmm1
        vpsrld  xmm1, xmm0, 10h
        vpor    xmm0, xmm1, xmm0
        vmovd   esi, xmm0
      }
      v20 = v48 | _ESI;
      GetAsyncKeyState(69);
      GetAsyncKeyState(51);
      GetAsyncKeyState(71);
      v67 = v20 & ~v92;
      if ( ((unsigned __int8)v20 & (unsigned __int8)~(_BYTE)v92 & 1) != 0 )
      {
        _RCX = qword_180019350;
        __asm
        {
          vmovq   xmm0, rcx
          vpbroadcastq ymm0, xmm0
          vpaddq  ymm1, ymm0, cs:ymmword_180017180
          vmovdqu cs:ymmword_1800193C8, ymm1
          vpaddq  xmm1, xmm14, xmm0
          vmovdqu cs:xmmword_1800193E8, xmm1
        }
        qword_180019380 = *(_QWORD *)(qword_180019350 + 32083968);
        qword_180019378 = *(_QWORD *)(qword_180019350 + 32104728);
        qword_180019370 = *(_QWORD *)(qword_180019350 + 32104840) + 72LL;
        qword_180019388 = *(_QWORD *)(qword_180019350 + 32117376);
        qword_180019390 = *(_QWORD *)(qword_180019350 + 32135952);
        qword_1800193A0 = *(_QWORD *)(qword_180019350 + 32117912) + 24LL;
        qword_180019348 = *(_QWORD *)(qword_180019350 + 32153664) + 40LL;
        qword_180019340 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 24LL) + 804LL;
        qword_1800193C0 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 40LL) + 52LL;
        qword_180019330 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 96LL) + 60LL;
        qword_180019338 = *(_QWORD *)(*(_QWORD *)(qword_180019350 + 32104840) + 104LL) + 148LL;
        qword_180019368 = qword_180019350 + 32165952;
        qword_180019398 = qword_180019350 + 32354472;
        hWnd = *(HWND *)(qword_180019350 + 32359336);
        __asm
        {
          vpaddq  xmm0, xmm15, xmm0
          vmovdqu cs:xmmword_180019358, xmm0
        }
        qword_1800193B0 = qword_180019350 + 32920704;
        qword_1800193B8 = *(_QWORD *)(qword_180019350 + 33012248) + 576LL;
      }
      v74 = v67;
      if ( (v67 & 2) != 0 )
      {
        *(_BYTE *)qword_180019338 ^= 1u;
        if ( (v67 & 4) == 0 )
        {
LABEL_28:
          if ( (v67 & 8) == 0 )
            goto LABEL_29;
          goto LABEL_37;
        }
      }
      else if ( (v67 & 4) == 0 )
      {
        goto LABEL_28;
      }
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm13, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 8) == 0 )
      {
LABEL_29:
        if ( (v74 & 0x10) == 0 )
          goto LABEL_30;
        goto LABEL_38;
      }
LABEL_37:
      _RAX = qword_180019340;
      __asm
      {
        vaddss  xmm0, xmm12, dword ptr [rax]
        vmovss  dword ptr [rax], xmm0
      }
      _RAX = qword_180019348;
      __asm { vmovss  dword ptr [rax], xmm0 }
      if ( (v74 & 0x10) == 0 )
      {
LABEL_30:
        if ( (v74 & 0x20) == 0 )
          goto LABEL_31;
        goto LABEL_39;
      }
LABEL_38:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
      if ( (v74 & 0x20) == 0 )
      {
LABEL_31:
        if ( (v74 & 0x40) == 0 )
          goto LABEL_32;
        goto LABEL_40;
      }
LABEL_39:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
      if ( (v74 & 0x40) == 0 )
      {
LABEL_32:
        if ( (v74 & 0x80u) == 0 )
          goto LABEL_33;
        goto LABEL_41;
      }
LABEL_40:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
      if ( (v74 & 0x80u) == 0 )
      {
LABEL_33:
        if ( v74 >= 0x100 )
          goto LABEL_42;
        goto LABEL_3;
      }
LABEL_41:
      __asm { vzeroupper }
      SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
      if ( v74 >= 0x100 )
LABEL_42:
        qword_180019410 = *(_QWORD *)qword_1800193A0;
LABEL_3:
      __asm { vzeroupper }
      sub_1800049F0(10);
      result = (unsigned __int8)byte_18001908C;
    }
    while ( (byte_18001908C & 1) != 0 );
  }
  __asm
  {
    vmovaps xmm6, [rsp+128h+var_E8]
    vmovaps xmm7, [rsp+128h+var_D8]
    vmovaps xmm8, [rsp+128h+var_C8]
    vmovaps xmm9, [rsp+128h+var_B8]
    vmovaps xmm10, [rsp+128h+var_A8]
    vmovaps xmm11, [rsp+128h+var_98]
    vmovaps xmm12, [rsp+128h+var_88]
    vmovaps xmm13, [rsp+128h+var_78]
    vmovaps xmm14, [rsp+128h+var_68]
    vmovaps xmm15, [rsp+128h+var_58]
  }
  return result;
}


// ------------------------------------------------------------
// Function 16/121: sub_180012700
// Address: 0x180012700 - 0x18001295A (size 0x25A)
// ------------------------------------------------------------
__int64 __fastcall sub_180012700(__int64 a1, __int64 a2)
{
  unsigned __int64 v5; // rbp
  char v7; // al

  if ( *(_DWORD *)(a2 + 16) )
  {
    _R13 = hWnd;
    __asm { vmovss  xmm6, cs:dword_1800171B0 }
    v5 = 0;
    do
    {
      _RBX = *(_BYTE **)(*(_QWORD *)(a2 + 8) + 8 * v5);
      if ( _RBX[601] != *((_BYTE *)_R13 + 601) && _RBX[776] == 1 && _RBX[3792] == 1 )
      {
        v7 = (*(__int64 (__fastcall **)(_QWORD))&ymmword_1800193C8.m256_f32[4])(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 8 * v5));
        _R13 = hWnd;
        if ( v7 )
        {
          _RAX = *((_QWORD *)hWnd + 1923);
          if ( *(_BYTE *)(_RAX + 40) )
          {
            __asm { vmovss  xmm0, dword ptr [rax+30h] }
            _RAX = qword_180019368;
            __asm { vucomiss xmm0, dword ptr [rax] }
          }
          __asm
          {
            vmovsd  xmm0, qword ptr [rbx+200h]
            vinsertps xmm0, xmm0, dword ptr [rbx+208h], 20h ; ' '
            vmovsd  xmm1, qword ptr [r13+200h]
            vinsertps xmm1, xmm1, dword ptr [r13+208h], 20h ; ' '
            vsubps  xmm0, xmm1, xmm0
            vdpps   xmm0, xmm0, xmm0, 7Fh
            vmovss  xmm1, dword ptr [r13+17FCh]
            vaddss  xmm1, xmm1, dword ptr [rbx+6F8h]
            vaddss  xmm1, xmm1, dword ptr [r13+6F8h]
            vmulss  xmm1, xmm1, xmm1
            vucomiss xmm0, xmm1
          }
        }
      }
      ++v5;
    }
    while ( v5 < *(unsigned int *)(a2 + 16) );
  }
  __asm
  {
    vmovaps xmm6, [rsp+88h+var_68]
    vmovaps xmm7, [rsp+88h+var_58]
  }
  return 0;
}


// ------------------------------------------------------------
// Function 17/121: sub_180012960
// Address: 0x180012960 - 0x180012C01 (size 0x2A1)
// ------------------------------------------------------------
__m128 __fastcall sub_180012960(__int64 _RCX, __int64 _RDX)
{
  __int64 *v4; // rax
  __m128 result; // xmm0
  __int64 v6; // r9
  __int64 v7; // r10
  __int64 v13; // rax
  _QWORD *v14; // r11
  __int64 v15; // rsi
  _QWORD *v18; // rdi
  __int64 v19; // rsi
  _QWORD *v22; // rsi
  __int64 v23; // r10
  _QWORD *v36; // r8
  __int64 v37; // rcx

  v4 = *(__int64 **)(_RCX + 11920);
  __asm { vxorps  xmm0, xmm0, xmm0 }
  if ( v4 )
  {
    while ( 1 )
    {
      v6 = *v4;
      if ( *(_BYTE *)(*v4 + 12) == 24 )
      {
        v7 = *(_QWORD *)(v6 + 16);
        if ( v7 )
        {
          if ( *(_BYTE *)(v6 + 56) && **(_QWORD **)(v7 + 8) == 0x6544686374697754LL )
            break;
        }
      }
      v4 += 2;
      if ( (unsigned __int64)v4 >= *(_QWORD *)(_RCX + 11928) )
        return result;
    }
    if ( *(_BYTE *)(v6 + 140) )
    {
      _R8 = hWnd;
      __asm
      {
        vmovss  xmm0, dword ptr [r8+16B8h]
        vmovss  xmm2, dword ptr [r8+16D0h]
        vmovss  xmm1, dword ptr [rcx+17DCh]
        vmovss  xmm4, dword ptr [r8+1710h]
      }
      v13 = qword_180019C38;
      if ( qword_180019C38 <= 0 )
      {
LABEL_13:
        *(_QWORD *)&byte_1800193F8[40 * qword_180019C38 + 1512] = 0xF38433EC8F69355AuLL;
        v15 = qword_180019C38;
        v13 = ++qword_180019C38;
      }
      else
      {
        v14 = &unk_1800199E0;
        v15 = 0;
        while ( *v14 != 0xF38433EC8F69355AuLL )
        {
          ++v15;
          v14 += 5;
          if ( qword_180019C38 == v15 )
            goto LABEL_13;
        }
      }
      _RSI = &byte_1800193F8[40 * v15];
      _RDX = (unsigned __int8)_RDX;
      __asm { vmovss  xmm3, dword ptr [rsi+rdx*4+5F0h] }
      if ( v13 <= 0 )
      {
LABEL_18:
        *(_QWORD *)&byte_1800193F8[40 * v13 + 1512] = 0xED5A926F3C152571uLL;
        v13 = ++qword_180019C38;
      }
      else
      {
        v18 = &unk_1800199E0;
        v19 = 0;
        while ( *v18 != 0xED5A926F3C152571uLL )
        {
          ++v19;
          v18 += 5;
          if ( v13 == v19 )
            goto LABEL_18;
        }
      }
      __asm { vcvtsi2ss xmm5, xmm5, r10d }
      __asm { vfmadd213ss xmm3, xmm4, dword ptr [r10+rdx*4+5F0h] }
      if ( v13 <= 0 )
      {
LABEL_23:
        *(_QWORD *)&byte_1800193F8[40 * v13 + 1512] = 0xE617C1FE6EFC9C79uLL;
        v13 = ++qword_180019C38;
      }
      else
      {
        v22 = &unk_1800199E0;
        v23 = 0;
        while ( *v22 != 0xE617C1FE6EFC9C79uLL )
        {
          ++v23;
          v22 += 5;
          if ( v13 == v23 )
            goto LABEL_23;
        }
      }
      __asm { vfmadd213ss xmm3, xmm5, dword ptr [r10+rdx*4+5F0h] }
      __asm
      {
        vfmsub213ss xmm1, xmm0, xmm2
        vxorps  xmm0, xmm0, xmm0
        vmaxss  xmm1, xmm1, xmm0
        vmovss  xmm0, cs:dword_180017208
        vfmadd213ss xmm1, xmm0, cs:dword_18001720C
        vdivss  xmm1, xmm3, xmm1
        vmovss  xmm2, dword ptr [r8+16B4h]
        vmovss  xmm3, dword ptr [r8+16BCh]
        vmulss  xmm5, xmm5, dword ptr [r8+1720h]
        vmovss  xmm4, dword ptr [rcx+17E4h]
        vfmadd132ss xmm5, xmm5, dword ptr [r8+1724h]
      }
      if ( v13 <= 0 )
      {
LABEL_28:
        *(_QWORD *)&byte_1800193F8[40 * v13 + 1512] = 0xB11E31F649A5A7ELL;
        ++qword_180019C38;
      }
      else
      {
        v36 = &unk_1800199E0;
        v37 = 0;
        while ( *v36 != 0xB11E31F649A5A7ELL )
        {
          ++v37;
          v36 += 5;
          if ( v13 == v37 )
            goto LABEL_28;
        }
      }
      __asm
      {
        vmulss  xmm5, xmm5, dword ptr [rax+rdx*4+5F0h]
        vfmsub213ss xmm4, xmm3, xmm2
        vxorps  xmm2, xmm2, xmm2
        vmaxss  xmm2, xmm4, xmm2
        vfmadd213ss xmm0, xmm2, cs:dword_18001720C
        vdivss  xmm0, xmm5, xmm0
        vaddss  xmm0, xmm0, xmm1
      }
    }
  }
  return result;
}


// ------------------------------------------------------------
// Function 18/121: StartAddress
// Address: 0x180012C10 - 0x180012D54 (size 0x144)
// ------------------------------------------------------------
__int64 __fastcall StartAddress(__int64 *a1)
{
  __int64 v2; // r14
  HMODULE ModuleHandleA; // rax
  FARPROC NtSetInformationThread; // rdi
  HANDLE CurrentThread; // rax
  unsigned __int8 i; // cl
  unsigned __int8 v7; // al
  unsigned int v8; // ebp
  __int64 v9; // rax

  v2 = *a1;
  ModuleHandleA = GetModuleHandleA("ntdll.dll");
  NtSetInformationThread = GetProcAddress(ModuleHandleA, "NtSetInformationThread");
  CurrentThread = GetCurrentThread();
  ((void (__fastcall *)(HANDLE, __int64, _QWORD, _QWORD))NtSetInformationThread)(CurrentThread, 17, 0, 0);
  if ( Mtx_lock((_Mtx_t)(v2 + 80)) )
    goto LABEL_14;
  if ( *(_DWORD *)(v2 + 156) == 0x7FFFFFFF )
  {
LABEL_13:
    *(_DWORD *)(v2 + 156) = 2147483646;
    std::_Throw_Cpp_error(6);
LABEL_14:
    std::_Throw_Cpp_error(5);
LABEL_15:
    std::_Xbad_function_call();
    JUMPOUT(0x180012D53LL);
  }
  for ( i = *(_BYTE *)(v2 + 233); ; i = 0 )
  {
    v7 = *(_BYTE *)(v2 + 232);
    if ( ((v7 | i) & 1) == 0 )
    {
      do
      {
        Cnd_wait((_Cnd_t)(v2 + 160), (_Mtx_t)(v2 + 80));
        v7 = *(_BYTE *)(v2 + 232);
      }
      while ( !*(_BYTE *)(v2 + 233) && !v7 );
    }
    if ( (v7 & 1) != 0 )
      break;
    v8 = *(unsigned __int8 *)(v2 + 234);
    Mtx_unlock((_Mtx_t)(v2 + 80));
    v9 = *(_QWORD *)(v2 + 56);
    if ( !v9 )
      goto LABEL_15;
    (*(void (__fastcall **)(_QWORD))(v9 + 8))(v8);
    if ( Mtx_lock((_Mtx_t)(v2 + 80)) )
      goto LABEL_14;
    if ( *(_DWORD *)(v2 + 156) == 0x7FFFFFFF )
      goto LABEL_13;
    *(_BYTE *)(v2 + 233) = 0;
  }
  Mtx_unlock((_Mtx_t)(v2 + 80));
  Cnd_do_broadcast_at_thread_exit();
  j_j_free(a1);
  return 0;
}


// ------------------------------------------------------------
// Function 19/121: sub_180012D60
// Address: 0x180012D60 - 0x180012D76 (size 0x16)
// ------------------------------------------------------------
_QWORD *__fastcall sub_180012D60(__int64 a1, _QWORD *a2)
{
  *a2 = &off_180017300;
  a2[1] = *(_QWORD *)(a1 + 8);
  return a2;
}


// ------------------------------------------------------------
// Function 20/121: sub_180012D80
// Address: 0x180012D80 - 0x180012D8A (size 0xA)
// ------------------------------------------------------------
__int64 __fastcall sub_180012D80(__int64 a1, unsigned __int8 *a2)
{
  return (*(__int64 (__fastcall **)(_QWORD))(a1 + 8))(*a2);
}


// ------------------------------------------------------------
// Function 21/121: sub_180012D90
// Address: 0x180012D90 - 0x180012D9F (size 0xF)
// ------------------------------------------------------------
void __fastcall sub_180012D90(void *a1, char a2)
{
  if ( a2 )
    j_j_free(a1);
}


// ------------------------------------------------------------
// Function 22/121: sub_180012DA0
// Address: 0x180012DA0 - 0x18001306E (size 0x2CE)
// ------------------------------------------------------------
__int64 __fastcall sub_180012DA0(__int64 a1, __int64 a2)
{
  unsigned __int64 v5; // r12
  char v7; // al

  if ( *(_DWORD *)(a2 + 16) )
  {
    _RBP = hWnd;
    __asm { vmovss  xmm6, cs:dword_1800171B0 }
    v5 = 0;
    do
    {
      _RBX = *(_BYTE **)(*(_QWORD *)(a2 + 8) + 8 * v5);
      if ( _RBX[601] != *((_BYTE *)_RBP + 601) && _RBX[776] == 1 && _RBX[3792] == 1 )
      {
        v7 = (*(__int64 (__fastcall **)(_QWORD))&ymmword_1800193C8.m256_f32[4])(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 8 * v5));
        _RBP = hWnd;
        if ( v7 )
        {
          _RAX = *((_QWORD *)hWnd + 1923);
          if ( *(_BYTE *)(_RAX + 40) )
          {
            __asm { vmovss  xmm0, dword ptr [rax+30h] }
            _RAX = qword_180019368;
            __asm { vucomiss xmm0, dword ptr [rax] }
          }
          __asm
          {
            vmovsd  xmm0, qword ptr [rbx+200h]
            vinsertps xmm0, xmm0, dword ptr [rbx+208h], 20h ; ' '
            vmovsd  xmm1, qword ptr [rbp+200h]
            vinsertps xmm1, xmm1, dword ptr [rbp+208h], 20h ; ' '
            vsubps  xmm0, xmm1, xmm0
            vdpps   xmm0, xmm0, xmm0, 7Fh
            vmovss  xmm1, dword ptr [rbp+17FCh]
            vaddss  xmm1, xmm1, dword ptr [rbx+6F8h]
            vaddss  xmm1, xmm1, dword ptr [rbp+6F8h]
            vmulss  xmm1, xmm1, xmm1
            vucomiss xmm0, xmm1
          }
        }
      }
      ++v5;
    }
    while ( v5 < *(unsigned int *)(a2 + 16) );
  }
  __asm
  {
    vmovaps xmm6, [rsp+88h+var_68]
    vmovaps xmm7, [rsp+88h+var_58]
  }
  return 0;
}


// ------------------------------------------------------------
// Function 23/121: sub_180013070
// Address: 0x180013070 - 0x1800133D3 (size 0x363)
// ------------------------------------------------------------
char *__fastcall sub_180013070(__int64 _RCX, unsigned __int8 a2)
{
  char *result; // rax
  __int64 v6; // r9
  __int64 v7; // r10
  __int64 v16; // rax
  _QWORD *v17; // r10
  __int64 v18; // rcx
  _QWORD *v22; // r11
  __int64 v23; // rdx
  _QWORD *v26; // rdx
  __int64 v27; // r10
  _QWORD *v29; // r11
  __int64 v30; // r10
  _QWORD *v33; // r10
  __int64 v34; // r9
  _QWORD *v39; // r10
  __int64 v40; // r9

  result = *(char **)(_RCX + 11920);
  __asm { vxorps  xmm0, xmm0, xmm0 }
  if ( result )
  {
    while ( 1 )
    {
      v6 = *(_QWORD *)result;
      if ( *(_BYTE *)(*(_QWORD *)result + 12LL) == 13 )
      {
        v7 = *(_QWORD *)(v6 + 16);
        if ( v7 )
        {
          if ( *(_BYTE *)(v6 + 56) && **(_QWORD **)(v7 + 8) == 0x65617473696C616BLL )
            break;
        }
      }
      result += 16;
      if ( (unsigned __int64)result >= *(_QWORD *)(_RCX + 11928) )
        goto LABEL_39;
    }
    _RAX = hWnd;
    __asm
    {
      vmovss  xmm0, dword ptr [rax+1710h]
      vaddss  xmm0, xmm0, dword ptr [rax+17B4h]
      vmovss  xmm4, dword ptr [rax+1720h]
      vfmadd132ss xmm4, xmm4, dword ptr [rax+1724h]
      vmovss  xmm1, dword ptr [rax+16B8h]
      vmovss  xmm3, dword ptr [rax+16D0h]
      vmovss  xmm2, dword ptr [rcx+17DCh]
    }
    v16 = qword_180019C38;
    if ( qword_180019C38 <= 0 )
    {
LABEL_12:
      *(_QWORD *)&byte_1800193F8[40 * qword_180019C38 + 1512] = 0xC97AAA6A55555790uLL;
      v18 = qword_180019C38;
      v16 = ++qword_180019C38;
    }
    else
    {
      v17 = &unk_1800199E0;
      v18 = 0;
      while ( *v17 != 0xC97AAA6A55555790uLL )
      {
        ++v18;
        v17 += 5;
        if ( qword_180019C38 == v18 )
          goto LABEL_12;
      }
    }
    _R11 = &byte_1800193F8[40 * v18];
    _RCX = a2;
    __asm { vmovss  xmm5, dword ptr [r11+rcx*4+5F0h] }
    if ( v16 <= 0 )
    {
LABEL_17:
      *(_QWORD *)&byte_1800193F8[40 * v16 + 1512] = 0x3001A3B81D29C94LL;
      v23 = qword_180019C38;
      v16 = ++qword_180019C38;
    }
    else
    {
      v22 = &unk_1800199E0;
      v23 = 0;
      while ( *v22 != 0x3001A3B81D29C94LL )
      {
        ++v23;
        v22 += 5;
        if ( v16 == v23 )
          goto LABEL_17;
      }
    }
    _RDX = &byte_1800193F8[40 * v23];
    __asm { vmovss  xmm6, dword ptr [rdx+rcx*4+5F0h] }
    if ( v16 <= 0 )
    {
LABEL_22:
      *(_QWORD *)&byte_1800193F8[40 * v16 + 1512] = 0xBD6594AB87DBE1A4uLL;
      v16 = ++qword_180019C38;
    }
    else
    {
      v26 = &unk_1800199E0;
      v27 = 0;
      while ( *v26 != 0xBD6594AB87DBE1A4uLL )
      {
        ++v27;
        v26 += 5;
        if ( v16 == v27 )
          goto LABEL_22;
      }
    }
    __asm { vfmadd213ss xmm6, xmm4, dword ptr [r10+rcx*4+5F0h] }
    if ( v16 <= 0 )
    {
LABEL_27:
      *(_QWORD *)&byte_1800193F8[40 * v16 + 1512] = 0xC37C6468B57ADDBCuLL;
      v30 = qword_180019C38;
      v16 = ++qword_180019C38;
    }
    else
    {
      v29 = &unk_1800199E0;
      v30 = 0;
      while ( *v29 != 0xC37C6468B57ADDBCuLL )
      {
        ++v30;
        v29 += 5;
        if ( v16 == v30 )
          goto LABEL_27;
      }
    }
    _R9 = &byte_1800193F8[40 * v30];
    __asm { vmovss  xmm7, dword ptr [r9+rcx*4+5F0h] }
    if ( v16 <= 0 )
    {
LABEL_32:
      *(_QWORD *)&byte_1800193F8[40 * v16 + 1512] = 0xD8B150C7435590BFuLL;
      v34 = qword_180019C38;
      v16 = ++qword_180019C38;
    }
    else
    {
      v33 = &unk_1800199E0;
      v34 = 0;
      while ( *v33 != 0xD8B150C7435590BFuLL )
      {
        ++v34;
        v33 += 5;
        if ( v16 == v34 )
          goto LABEL_32;
      }
    }
    __asm
    {
      vfmadd213ss xmm5, xmm0, xmm6
      vcvtsi2ss xmm6, xmm15, edx
    }
    _R9 = &byte_1800193F8[40 * v34];
    __asm { vmovss  xmm8, dword ptr [r9+rcx*4+5F0h] }
    if ( v16 <= 0 )
    {
LABEL_37:
      *(_QWORD *)&byte_1800193F8[40 * v16 + 1512] = 0xE617C1FE6EFC9C79uLL;
      v40 = qword_180019C38++;
    }
    else
    {
      v39 = &unk_1800199E0;
      v40 = 0;
      while ( *v39 != 0xE617C1FE6EFC9C79uLL )
      {
        ++v40;
        v39 += 5;
        if ( v16 == v40 )
          goto LABEL_37;
      }
    }
    result = &byte_1800193F8[40 * v40];
    __asm
    {
      vfmadd213ss xmm8, xmm4, dword ptr [rax+rcx*4+5F0h]
      vfmadd213ss xmm7, xmm0, xmm8
      vfmadd213ss xmm6, xmm5, xmm7
      vfmsub213ss xmm2, xmm1, xmm3
      vxorps  xmm0, xmm0, xmm0
      vmaxss  xmm0, xmm2, xmm0
      vmovss  xmm1, cs:dword_180017208
      vfmadd213ss xmm1, xmm0, cs:dword_18001720C
      vdivss  xmm0, xmm6, xmm1
    }
  }
LABEL_39:
  __asm
  {
    vmovaps xmm6, [rsp+38h+var_38]
    vmovaps xmm7, [rsp+38h+var_28]
    vmovaps xmm8, [rsp+38h+var_18]
  }
  return result;
}


// ------------------------------------------------------------
// Function 24/121: sub_1800133E0
// Address: 0x1800133E0 - 0x180013486 (size 0xA6)
// ------------------------------------------------------------
__int64 __fastcall sub_1800133E0(HMODULE a1, int a2)
{
  _QWORD *v2; // rax
  unsigned int ThrdAddr[4]; // [rsp+30h] [rbp-28h] BYREF
  _Thrd_t v6; // [rsp+40h] [rbp-18h] BYREF

  if ( !a2 )
    goto LABEL_7;
  if ( a2 == 1 )
  {
    DisableThreadLibraryCalls(a1);
    v2 = (_QWORD *)sub_180015230(8u);
    *v2 = sub_180001180;
    *(_QWORD *)ThrdAddr = beginthreadex(0, 0, sub_180013490, v2, 0, &ThrdAddr[2]);
    if ( !*(_QWORD *)ThrdAddr )
    {
      ThrdAddr[2] = 0;
      std::_Throw_Cpp_error(6);
      JUMPOUT(0x180013485LL);
    }
    if ( !ThrdAddr[2] )
      goto LABEL_6;
    __asm
    {
      vmovups xmm0, xmmword ptr [rsp+58h+var_28]
      vmovaps xmmword ptr [rsp+58h+var_18._Hnd], xmm0
    }
    if ( Thrd_detach(&v6) )
    {
LABEL_6:
      std::_Throw_Cpp_error(1);
LABEL_7:
      byte_18001908C = 0;
    }
  }
  return 1;
}


// ------------------------------------------------------------
// Function 25/121: sub_180013490
// Address: 0x180013490 - 0x1800134B4 (size 0x24)
// ------------------------------------------------------------
__int64 __fastcall sub_180013490(void (**a1)(void))
{
  (*a1)();
  Cnd_do_broadcast_at_thread_exit();
  j_j_free(a1);
  return 0;
}


// ------------------------------------------------------------
// Function 26/121: sub_1800134C0
// Address: 0x1800134C0 - 0x1800134D3 (size 0x13)
// ------------------------------------------------------------
const char *__fastcall sub_1800134C0(__int64 a1)
{
  __int64 v1; // rcx
  const char *result; // rax

  v1 = *(_QWORD *)(a1 + 8);
  result = "Unknown exception";
  if ( v1 )
    return (const char *)v1;
  return result;
}


// ------------------------------------------------------------
// Function 27/121: sub_1800134E0
// Address: 0x1800134E0 - 0x180013E3A (size 0x95A)
// ------------------------------------------------------------
__int64 __fastcall sub_1800134E0()
{
  _QWORD *v2; // rax
  _QWORD *v30; // r14
  size_t v31; // r15
  __int64 v32; // r13
  _BYTE *v34; // rbx
  __int64 v35; // rdi
  __int64 v36; // rax
  size_t v37; // rdi
  unsigned __int64 v38; // rax
  __int64 v39; // rax
  void *v40; // rcx
  void *v41; // rcx
  void *v42; // rcx
  void *v43; // rcx
  void *v44; // rcx
  void *v45; // rcx
  void *v46; // rcx
  void *v47; // rcx
  void *v48; // rcx
  void *v49; // rcx
  void *v51; // rcx
  __int64 v55; // [rsp+28h] [rbp-210h]
  __int64 v56; // [rsp+30h] [rbp-208h]
  void *Src; // [rsp+38h] [rbp-200h]
  char *v58; // [rsp+40h] [rbp-1F8h] BYREF
  char *v59; // [rsp+48h] [rbp-1F0h]
  __int64 v60; // [rsp+50h] [rbp-1E8h]
  __int64 v61; // [rsp+58h] [rbp-1E0h]
  void *v62; // [rsp+60h] [rbp-1D8h]
  __int64 v63; // [rsp+68h] [rbp-1D0h]
  __int64 v64; // [rsp+70h] [rbp-1C8h]
  unsigned __int64 v65; // [rsp+78h] [rbp-1C0h]
  __int64 v66; // [rsp+80h] [rbp-1B8h]
  void *v67; // [rsp+88h] [rbp-1B0h]
  __int64 v68; // [rsp+90h] [rbp-1A8h]
  __int64 v69; // [rsp+98h] [rbp-1A0h]
  __int64 v70; // [rsp+A0h] [rbp-198h]
  __int64 v71; // [rsp+A8h] [rbp-190h]
  void *v72; // [rsp+B0h] [rbp-188h]
  __int64 v73; // [rsp+B8h] [rbp-180h]
  __int64 v74; // [rsp+C0h] [rbp-178h]
  __int64 v75; // [rsp+C8h] [rbp-170h]
  __int64 v76; // [rsp+D0h] [rbp-168h]
  void *v77; // [rsp+D8h] [rbp-160h]
  __int64 v78; // [rsp+E0h] [rbp-158h]
  __int64 v79; // [rsp+E8h] [rbp-150h]
  __int64 v80; // [rsp+F0h] [rbp-148h]
  __int64 v81; // [rsp+F8h] [rbp-140h]
  void *v82; // [rsp+100h] [rbp-138h]
  __int64 v83; // [rsp+108h] [rbp-130h]
  __int64 v84; // [rsp+110h] [rbp-128h]
  __int64 v85; // [rsp+118h] [rbp-120h]
  __int64 v86; // [rsp+120h] [rbp-118h]
  void *v87; // [rsp+128h] [rbp-110h]
  __int64 v88; // [rsp+130h] [rbp-108h]
  __int64 v89; // [rsp+138h] [rbp-100h]
  __int64 v90; // [rsp+140h] [rbp-F8h]
  __int64 v91; // [rsp+148h] [rbp-F0h]
  void *v92; // [rsp+150h] [rbp-E8h]
  __int64 v93; // [rsp+158h] [rbp-E0h]
  __int64 v94; // [rsp+160h] [rbp-D8h]
  __int64 v95; // [rsp+168h] [rbp-D0h]
  __int64 v96; // [rsp+170h] [rbp-C8h]
  void *v97; // [rsp+178h] [rbp-C0h]
  __int64 v98; // [rsp+180h] [rbp-B8h]
  __int64 v99; // [rsp+188h] [rbp-B0h]
  unsigned __int64 v100; // [rsp+190h] [rbp-A8h]
  __int64 v101; // [rsp+198h] [rbp-A0h]
  void *v102; // [rsp+1A0h] [rbp-98h]
  __int64 v103; // [rsp+1A8h] [rbp-90h]
  __int64 v104; // [rsp+1B0h] [rbp-88h]
  unsigned __int64 v105; // [rsp+1B8h] [rbp-80h]
  __int64 v106; // [rsp+1C0h] [rbp-78h]
  void *v107; // [rsp+1C8h] [rbp-70h]
  __int64 v108; // [rsp+1D0h] [rbp-68h]
  __int64 v109; // [rsp+1D8h] [rbp-60h]

  __asm
  {
    vxorps  xmm6, xmm6, xmm6
    vmovups cs:Block, xmm6
  }
  v2 = (_QWORD *)sub_180015230(0x40u);
  *v2 = v2;
  v2[1] = v2;
  v2[2] = v2;
  *((_WORD *)v2 + 12) = 257;
  Block = v2;
  sub_1800152C0(Function);
  v55 = 0x7734BE05A394D5E2LL;
  v56 = 0x240000001DLL;
  _RAX = (char *)sub_180015230(0x30u);
  _R12 = &v58;
  Src = _RAX;
  v59 = _RAX + 48;
  __asm
  {
    vmovups ymm0, ymmword ptr cs:off_180017330; "Dagger 1"
    vmovups ymmword ptr [rax], ymm0
    vmovups ymm0, ymmword ptr cs:off_180017340; "Dagger 3"
    vmovups ymmword ptr [rax+10h], ymm0
  }
  v58 = _RAX + 48;
  v60 = 0x33055511E147AE6BLL;
  v61 = 0x200000001ALL;
  __asm { vzeroupper }
  _RAX = sub_180015230(0x20u);
  v62 = (void *)_RAX;
  v64 = _RAX + 32;
  __asm
  {
    vmovups ymm0, ymmword ptr cs:off_180017360; "Head off"
    vmovups ymmword ptr [rax], ymm0
  }
  v63 = _RAX + 32;
  v65 = 0xBEE5A1E555549E3AuLL;
  v66 = 0x1000000010LL;
  __asm { vzeroupper }
  _RAX = sub_180015230(0x20u);
  v67 = (void *)_RAX;
  v69 = _RAX + 32;
  __asm
  {
    vmovups ymm0, ymmword ptr cs:off_180017380; "Scarlet fair"
    vmovups ymmword ptr [rax], ymm0
  }
  v68 = _RAX + 32;
  v70 = 0x76B75EAD90784E9ELL;
  v71 = 0x500000005LL;
  __asm { vzeroupper }
  _RAX = sub_180015230(0x18u);
  v72 = (void *)_RAX;
  __asm
  {
    vmovups xmm0, xmmword ptr cs:off_1800173A0; "Level 1"
    vmovups xmmword ptr [rax], xmm0
  }
  v74 = _RAX + 24;
  *(_QWORD *)(_RAX + 16) = "Level 3";
  v73 = _RAX + 24;
  v75 = 0x26CC198AD69F57A9LL;
  v76 = 0x5600000056LL;
  _RAX = sub_180015230(0x18u);
  v77 = (void *)_RAX;
  __asm
  {
    vmovups xmm7, xmmword ptr cs:off_180017400; "Hall of Legends"
    vmovups xmmword ptr [rax], xmm7
  }
  v79 = _RAX + 24;
  *(_QWORD *)(_RAX + 16) = "Immortalized Legend";
  v78 = _RAX + 24;
  v80 = 0x7E5859EA35269A8ALL;
  v81 = 0x3C0000003CLL;
  _RAX = sub_180015230(0x18u);
  v82 = (void *)_RAX;
  __asm
  {
    vmovups xmm0, xmmword ptr cs:off_1800173B8; "With hood"
    vmovups xmmword ptr [rax], xmm0
  }
  v84 = _RAX + 24;
  *(_QWORD *)(_RAX + 16) = "Without hood";
  v83 = _RAX + 24;
  v85 = 0x57C2E824D58ED1B5LL;
  v86 = 0x4200000042LL;
  _RAX = sub_180015230(0x18u);
  v87 = (void *)_RAX;
  __asm
  {
    vmovups xmm0, xmmword ptr cs:off_1800173D0; "Blue"
    vmovups xmmword ptr [rax], xmm0
  }
  v89 = _RAX + 24;
  *(_QWORD *)(_RAX + 16) = "Red";
  v88 = _RAX + 24;
  v90 = 0x4D36A3AC1E71D9E5LL;
  v91 = 0x3600000036LL;
  _RAX = sub_180015230(0x18u);
  v92 = (void *)_RAX;
  __asm
  {
    vmovups xmm0, xmmword ptr cs:off_1800173E8; "Sahn-Uzal"
    vmovups xmmword ptr [rax], xmm0
  }
  v94 = _RAX + 24;
  *(_QWORD *)(_RAX + 16) = "Iron Revenant";
  v93 = _RAX + 24;
  v95 = 0x77EE2DDFA384BEA0LL;
  v96 = 0x4700000047LL;
  _RAX = sub_180015230(0x18u);
  v97 = (void *)_RAX;
  v99 = _RAX + 24;
  __asm { vmovups xmmword ptr [rax], xmm7 }
  *(_QWORD *)(_RAX + 16) = "Immortalized Legend";
  v98 = _RAX + 24;
  v100 = 0x9EC758AC0B3E6DD0uLL;
  v101 = 0x5000000050LL;
  _RAX = sub_180015230(0x30u);
  v102 = (void *)_RAX;
  v104 = _RAX + 48;
  __asm
  {
    vmovups ymm0, ymmword ptr cs:off_180017418; "Mask1"
    vmovups ymmword ptr [rax], ymm0
    vmovups ymm0, ymmword ptr cs:off_180017428; "Mask3"
    vmovups ymmword ptr [rax+10h], ymm0
  }
  v103 = _RAX + 48;
  v105 = 0x90409361E7DBC9E5uLL;
  v106 = 0x2B0000002BLL;
  __asm { vzeroupper }
  _RAX = sub_180015230(0x38u);
  v107 = (void *)_RAX;
  __asm
  {
    vmovups ymm0, ymmword ptr cs:off_180017448; "Sword1"
    vmovups ymmword ptr [rax], ymm0
  }
  v109 = _RAX + 56;
  __asm
  {
    vmovups ymm0, ymmword ptr cs:off_180017460; "Sword4"
    vmovups ymmword ptr [rax+18h], ymm0
  }
  v108 = _RAX + 56;
  __asm { vmovups cs:xmmword_180019228, xmm6 }
  qword_180019238 = 0;
  __asm { vzeroupper }
  _RSI = sub_180015230(0x1B8u);
  xmmword_180019228 = (void *)_RSI;
  *(&xmmword_180019228 + 1) = (void *)_RSI;
  qword_180019238 = _RSI + 440;
  _RAX = 0;
  do
  {
    v32 = _RAX;
    __asm
    {
      vmovups xmm0, xmmword ptr [r12+rax-18h]
      vmovups xmmword ptr [rsi+rax], xmm0
      vmovups xmmword ptr [rsi+rax+10h], xmm6
    }
    *(_QWORD *)(_RSI + _RAX + 32) = 0;
    v34 = *(void **)((char *)&Src + _RAX);
    v35 = *(__int64 *)((char *)&v58 + _RAX);
    v36 = v35 - (_QWORD)v34;
    v37 = v35 - (_QWORD)v34;
    if ( v37 )
    {
      v38 = v36 >> 3;
      if ( v38 >> 61 )
        std::vector<void *>::_Xlen(v38 >> 61);
      if ( v38 < 0x200 )
      {
        v30 = (_QWORD *)sub_180015230(v37);
        v31 = v37;
      }
      else
      {
        v39 = sub_180015230(v37 + 39);
        v30 = (_QWORD *)((v39 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
        *(v30 - 1) = v39;
        v34 = *(void **)((char *)&Src + v32);
        v31 = *(char **)((char *)&v58 + v32) - v34;
      }
      *(_QWORD *)(_RSI + v32 + 16) = v30;
      *(_QWORD *)(_RSI + v32 + 24) = v30;
      *(_QWORD *)(_RSI + v32 + 32) = (char *)v30 + v37;
      memcpy(v30, v34, v31);
      *(_QWORD *)(_RSI + v32 + 24) = (char *)v30 + v31;
    }
    _RAX = v32 + 40;
  }
  while ( v32 != 400 );
  *(&xmmword_180019228 + 1) = (void *)(_RSI + 440);
  v40 = v107;
  if ( v107 )
  {
    if ( (unsigned __int64)(v109 - (_QWORD)v107) >= 0x1000 )
    {
      if ( (unsigned __int64)v107 - *((_QWORD *)v107 - 1) - 8 >= 0x20 )
        goto LABEL_66;
      v40 = (void *)*((_QWORD *)v107 - 1);
    }
    j_j_free(v40);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+188h], xmm0
    }
    v109 = 0;
  }
  v41 = v102;
  if ( v102 )
  {
    if ( (unsigned __int64)(v104 - (_QWORD)v102) >= 0x1000 )
    {
      if ( (unsigned __int64)v102 - *((_QWORD *)v102 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v41 = (void *)*((_QWORD *)v102 - 1);
    }
    j_j_free(v41);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+160h], xmm0
    }
    v104 = 0;
  }
  v42 = v97;
  if ( v97 )
  {
    if ( (unsigned __int64)(v99 - (_QWORD)v97) >= 0x1000 )
    {
      if ( (unsigned __int64)v97 - *((_QWORD *)v97 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v42 = (void *)*((_QWORD *)v97 - 1);
    }
    j_j_free(v42);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+138h], xmm0
    }
    v99 = 0;
  }
  v43 = v92;
  if ( v92 )
  {
    if ( (unsigned __int64)(v94 - (_QWORD)v92) >= 0x1000 )
    {
      if ( (unsigned __int64)v92 - *((_QWORD *)v92 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v43 = (void *)*((_QWORD *)v92 - 1);
    }
    j_j_free(v43);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+110h], xmm0
    }
    v94 = 0;
  }
  v44 = v87;
  if ( v87 )
  {
    if ( (unsigned __int64)(v89 - (_QWORD)v87) >= 0x1000 )
    {
      if ( (unsigned __int64)v87 - *((_QWORD *)v87 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v44 = (void *)*((_QWORD *)v87 - 1);
    }
    j_j_free(v44);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+0E8h], xmm0
    }
    v89 = 0;
  }
  v45 = v82;
  if ( v82 )
  {
    if ( (unsigned __int64)(v84 - (_QWORD)v82) >= 0x1000 )
    {
      if ( (unsigned __int64)v82 - *((_QWORD *)v82 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v45 = (void *)*((_QWORD *)v82 - 1);
    }
    j_j_free(v45);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+0C0h], xmm0
    }
    v84 = 0;
  }
  v46 = v77;
  if ( v77 )
  {
    if ( (unsigned __int64)(v79 - (_QWORD)v77) >= 0x1000 )
    {
      if ( (unsigned __int64)v77 - *((_QWORD *)v77 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v46 = (void *)*((_QWORD *)v77 - 1);
    }
    j_j_free(v46);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+98h], xmm0
    }
    v79 = 0;
  }
  v47 = v72;
  if ( v72 )
  {
    if ( (unsigned __int64)(v74 - (_QWORD)v72) >= 0x1000 )
    {
      if ( (unsigned __int64)v72 - *((_QWORD *)v72 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v47 = (void *)*((_QWORD *)v72 - 1);
    }
    j_j_free(v47);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+70h], xmm0
    }
    v74 = 0;
  }
  v48 = v67;
  if ( v67 )
  {
    if ( (unsigned __int64)(v69 - (_QWORD)v67) >= 0x1000 )
    {
      if ( (unsigned __int64)v67 - *((_QWORD *)v67 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v48 = (void *)*((_QWORD *)v67 - 1);
    }
    j_j_free(v48);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+48h], xmm0
    }
    v69 = 0;
  }
  v49 = v62;
  if ( v62 )
  {
    if ( (unsigned __int64)(v64 - (_QWORD)v62) >= 0x1000 )
    {
      if ( (unsigned __int64)v62 - *((_QWORD *)v62 - 1) - 8 > 0x1F )
        goto LABEL_66;
      v49 = (void *)*((_QWORD *)v62 - 1);
    }
    j_j_free(v49);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups xmmword ptr [r12+20h], xmm0
    }
    v64 = 0;
  }
  v51 = Src;
  if ( Src )
  {
    if ( (unsigned __int64)(v59 - (_BYTE *)Src) < 0x1000 )
    {
LABEL_63:
      j_j_free(v51);
      goto LABEL_64;
    }
    if ( (unsigned __int64)Src - *((_QWORD *)Src - 1) - 8 <= 0x1F )
    {
      v51 = (void *)*((_QWORD *)Src - 1);
      goto LABEL_63;
    }
LABEL_66:
    BUG();
  }
LABEL_64:
  __asm
  {
    vmovaps xmm6, [rsp+238h+var_58]
    vmovaps xmm7, [rsp+238h+var_48]
  }
  return sub_1800152C0(sub_180013E90);
}


// ------------------------------------------------------------
// Function 28/121: Function
// Address: 0x180013E40 - 0x180013E69 (size 0x29)
// ------------------------------------------------------------
void __fastcall Function()
{
  sub_180013F80(*((void **)Block + 1));
  j_j_free(Block);
}


// ------------------------------------------------------------
// Function 29/121: ?_Xlen@?$vector@PEAXV?$allocator@PEAX@std@@@std@@IEBAXXZ
// Address: 0x180013E70 - 0x180013E81 (size 0x11)
// ------------------------------------------------------------
void __noreturn std::vector<void *>::_Xlen()
{
  std::_Xlength_error("vector too long");
}


// ------------------------------------------------------------
// Function 30/121: sub_180013E90
// Address: 0x180013E90 - 0x180013F72 (size 0xE2)
// ------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_180013E90(double _XMM0_8)
{
  _QWORD *v2; // rsi
  _QWORD *v3; // rdi
  _QWORD *v6; // rcx

  v2 = xmmword_180019228;
  if ( xmmword_180019228 )
  {
    v3 = *(&xmmword_180019228 + 1);
    if ( xmmword_180019228 != *(&xmmword_180019228 + 1) )
    {
      __asm { vxorps  xmm6, xmm6, xmm6 }
      do
      {
        v6 = (_QWORD *)v2[2];
        if ( v6 )
        {
          if ( v2[4] - (_QWORD)v6 >= 0x1000u )
          {
            if ( (unsigned __int64)v6 - *(v6 - 1) - 8 >= 0x20 )
              goto LABEL_16;
            v6 = (_QWORD *)*(v6 - 1);
          }
          _RBX = v2 + 2;
          j_j_free(v6);
          __asm { vmovups xmmword ptr [rbx], xmm6 }
          v2[4] = 0;
        }
        v2 += 5;
      }
      while ( v2 != v3 );
      v2 = xmmword_180019228;
    }
    if ( (unsigned __int64)(qword_180019238 - (_QWORD)v2) >= 0x1000 )
    {
      if ( (unsigned __int64)v2 - *(v2 - 1) - 8 >= 0x20 )
LABEL_16:
        BUG();
      v2 = (_QWORD *)*(v2 - 1);
    }
    j_j_free(v2);
    __asm
    {
      vxorps  xmm0, xmm0, xmm0
      vmovups cs:xmmword_180019228, xmm0
    }
    qword_180019238 = 0;
  }
  __asm { vmovaps xmm6, [rsp+48h+var_28] }
}


// ------------------------------------------------------------
// Function 31/121: sub_180013F80
// Address: 0x180013F80 - 0x18001401C (size 0x9C)
// ------------------------------------------------------------
void __fastcall sub_180013F80(void **Block)
{
  void **v3; // rsi
  void **v6; // rdi
  _QWORD *v7; // rcx

  if ( !*((_BYTE *)Block + 25) )
  {
    v3 = Block;
    __asm { vxorps  xmm6, xmm6, xmm6 }
    do
    {
      sub_180013F80(v3[2]);
      v6 = (void **)*v3;
      v7 = v3[5];
      if ( v7 )
      {
        if ( (unsigned __int64)((_BYTE *)v3[7] - (_BYTE *)v7) >= 0x1000 )
        {
          if ( (unsigned __int64)v7 - *(v7 - 1) - 8 >= 0x20 )
            BUG();
          v7 = (_QWORD *)*(v7 - 1);
        }
        _RBX = (char *)(v3 + 5);
        j_j_free(v7);
        __asm { vmovups xmmword ptr [rbx], xmm6 }
        v3[7] = 0;
      }
      j_j_free(v3);
      v3 = v6;
    }
    while ( !*((_BYTE *)v6 + 25) );
  }
  __asm { vmovaps xmm6, [rsp+48h+var_28] }
}


// ------------------------------------------------------------
// Function 32/121: TimerFunc
// Address: 0x180014020 - 0x180014239 (size 0x219)
// ------------------------------------------------------------
void __fastcall TimerFunc(HWND a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rcx
  unsigned __int64 v4; // rsi
  char *v5; // rdx
  char v6; // r9
  char *v7; // rdx
  __int64 v8; // rax
  unsigned __int64 v9; // rsi
  char *v10; // rdx
  char v11; // r9
  char *v12; // rdx
  __int64 v13; // rax
  _DWORD *v14; // rdx
  unsigned int v15; // r9d
  HWND v16; // rcx
  unsigned __int64 v17; // rax
  unsigned int v18; // r9d
  char v19; // al

  switch ( a3 )
  {
    case 1LL:
      KillTimer(a1, 1u);
      LOBYTE(v3) = 1;
      goto LABEL_14;
    case 2LL:
      KillTimer(a1, 2u);
      v3 = 0;
LABEL_14:
      sub_180014240(v3);
      return;
    case 3LL:
      v4 = 0xCBF29CE484222325uLL;
      KillTimer(a1, 3u);
      v5 = (char *)*((_QWORD *)hWnd + 2084);
      if ( v5 && (v6 = *v5) != 0 )
      {
        v7 = v5 + 1;
        do
        {
          v8 = 0x100000001B3LL * (v4 ^ v6);
          v6 = *v7++;
          v4 = v8;
        }
        while ( v6 );
      }
      else
      {
        v8 = 0xCBF29CE484222325uLL;
      }
      v14 = xmmword_180019228;
      if ( xmmword_180019228 != *(&xmmword_180019228 + 1) )
      {
        v15 = *((_DWORD *)hWnd + 4176);
        do
        {
          if ( *(_QWORD *)v14 == v8 && v14[2] <= v15 && v14[3] >= v15 )
            break;
          v14 += 10;
        }
        while ( v14 != *(&xmmword_180019228 + 1) );
      }
      if ( v14 == *(&xmmword_180019228 + 1) )
        return;
      v16 = hWnd + 4162;
      v17 = *((unsigned __int8 *)hWnd + 16804);
      if ( (__int64)(*((_QWORD *)v14 + 3) - *((_QWORD *)v14 + 2)) >> 3 <= v17 )
        return;
      *((_BYTE *)hWnd + 16804) = v17 + 1;
      goto LABEL_35;
    case 4LL:
      v9 = 0xCBF29CE484222325uLL;
      KillTimer(a1, 4u);
      v10 = (char *)*((_QWORD *)hWnd + 2084);
      if ( v10 && (v11 = *v10) != 0 )
      {
        v12 = v10 + 1;
        do
        {
          v13 = 0x100000001B3LL * (v9 ^ v11);
          v11 = *v12++;
          v9 = v13;
        }
        while ( v11 );
      }
      else
      {
        v13 = 0xCBF29CE484222325uLL;
      }
      v14 = xmmword_180019228;
      if ( xmmword_180019228 == *(&xmmword_180019228 + 1) )
        return;
      v18 = *((_DWORD *)hWnd + 4176);
      v16 = hWnd + 4162;
      break;
    default:
      return;
  }
  while ( *(_QWORD *)v14 != v13 || v14[2] > v18 || v14[3] < v18 )
  {
    v14 += 10;
    if ( v14 == *(&xmmword_180019228 + 1) )
      return;
  }
  if ( v14 != *(&xmmword_180019228 + 1) )
  {
    v19 = *((_BYTE *)hWnd + 16804);
    if ( v19 )
    {
      *((_BYTE *)hWnd + 16804) = v19 - 1;
LABEL_35:
      LOBYTE(v14) = 1;
      ymmword_1800193C8(v16, v14);
    }
  }
}


// ------------------------------------------------------------
// Function 33/121: sub_180014240
// Address: 0x180014240 - 0x180014775 (size 0x535)
// ------------------------------------------------------------
__int64 __fastcall sub_180014240(char a1, __int64 a2)
{
  __int64 v4; // r14
  HWND v5; // r15
  char *v6; // rax
  unsigned __int64 v7; // r12
  char v8; // cl
  char *v9; // rax
  unsigned __int64 v10; // r8
  void *v11; // r13
  __int64 v12; // rcx
  BOOL v13; // ebp
  __int64 v14; // rsi
  unsigned __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 result; // rax
  __int64 v21; // r9
  HWND v22; // rcx
  unsigned __int64 v23; // rax
  int v24; // r10d
  unsigned int v26; // r11d
  unsigned int v28; // edx
  int v35; // r10d
  __int64 v36; // r10
  __int64 v37; // rax
  __int64 v39; // rsi
  __int64 v45; // rax
  char *v46; // rax
  HWND v47; // rcx
  char v48; // r10
  char *v49; // rax
  __int64 v50; // rax
  __int64 v51; // r10
  unsigned int v52; // [rsp+90h] [rbp-48h] BYREF
  _DWORD v53[17]; // [rsp+94h] [rbp-44h] BYREF

  v4 = 0xCBF29CE484222325uLL;
  v5 = hWnd;
  v6 = (char *)*((_QWORD *)hWnd + 2084);
  v7 = 0xCBF29CE484222325uLL;
  if ( v6 )
  {
    v8 = *v6;
    v7 = 0xCBF29CE484222325uLL;
    if ( *v6 )
    {
      a2 = 0x100000001B3LL;
      v9 = v6 + 1;
      v10 = 0xCBF29CE484222325uLL;
      do
      {
        v7 = 0x100000001B3LL * (v10 ^ v8);
        v8 = *v9++;
        v10 = v7;
      }
      while ( v8 );
    }
  }
  v11 = Block;
  v12 = *((_QWORD *)Block + 1);
  v13 = 0;
  if ( *(_BYTE *)(v12 + 25) )
  {
    v14 = *((_QWORD *)Block + 1);
    _RDI = Block;
    if ( *((_BYTE *)Block + 25) )
    {
LABEL_14:
      if ( *(&Block + 1) == (void *)0x3FFFFFFFFFFFFFFLL )
        std::vector<void *>::_Xlen(v12, a2);
      _RDI = (_QWORD *)sub_180015230(0x40u);
      _RDI[4] = v7;
      __asm
      {
        vpxor   xmm0, xmm0, xmm0
        vmovdqu xmmword ptr [rax+28h], xmm0
      }
      _RDI[7] = 0;
      *_RDI = v11;
      _RDI[1] = v11;
      _RDI[2] = v11;
      *((_WORD *)_RDI + 12) = 0;
      sub_1800147A0(v14, v13, _RDI);
      goto LABEL_16;
    }
  }
  else
  {
    _RDI = Block;
    do
    {
      v14 = v12;
      v16 = *(_QWORD *)(v12 + 32);
      if ( v16 >= v7 )
        _RDI = (_QWORD *)v12;
      v12 = *(_QWORD *)(v12 + 16 * (unsigned int)(v16 < v7));
    }
    while ( !*(_BYTE *)(v12 + 25) );
    v13 = v16 >= v7;
    if ( *((_BYTE *)_RDI + 25) )
      goto LABEL_14;
  }
  if ( v7 < _RDI[4] )
    goto LABEL_14;
LABEL_16:
  v17 = _RDI[5];
  v18 = _RDI[6];
  result = v17;
  if ( v17 != v18 )
  {
    result = _RDI[5];
    while ( *(_DWORD *)(result + 8) != *((_DWORD *)v5 + 4176) )
    {
      result += 16;
      if ( result == v18 )
        return result;
    }
  }
  if ( result == v18 )
    return result;
  if ( a1 )
  {
    result += 16;
    if ( v18 == result )
      return result;
  }
  else
  {
    if ( result == v17 )
      return result;
    result -= 16;
  }
  _R8 = *(unsigned int *)(result + 8);
  v21 = *(_QWORD *)result;
  v22 = hWnd;
  if ( *((_BYTE *)hWnd + 4936) == 1 )
  {
    LODWORD(v23) = hWnd[1229];
  }
  else
  {
    *(_WORD *)((char *)hWnd + 4937) = 1;
    v23 = __rdtsc();
    *((_DWORD *)v22 + 1229) = v23;
    *((_BYTE *)v22 + 4939) = 0;
    *((_BYTE *)v22 + 4936) = 1;
  }
  v53[0] = v23;
  v24 = *((unsigned __int8 *)v22 + 4937);
  _RDX = (unsigned int)_R8;
  if ( *((_BYTE *)v22 + 4937) )
  {
    v26 = 0;
    _EAX = ~(_DWORD)v23;
    LODWORD(_RDX) = _R8;
    if ( (unsigned __int8)v24 <= 3u )
      goto LABEL_38;
    v26 = 0;
    if ( (unsigned __int8)v24 >= 0x20u )
    {
      v26 = v24 & 0xFFFFFFE0;
      _RDX = (unsigned int)_R8;
      if ( (v24 & 0xFFFFFFE0) == v24 )
        goto LABEL_40;
      if ( (v24 & 0x1C) == 0 )
        goto LABEL_38;
    }
    v28 = v26;
    v26 = v24 & 0xFFFFFFFC;
    __asm
    {
      vmovd   xmm0, r8d
      vmovd   xmm1, eax
      vpbroadcastd xmm1, xmm1
    }
    LODWORD(_RDX) = v28 - (v24 & 0xFFFFFFFC);
    do
    {
      __asm { vpxor   xmm0, xmm0, xmm1 }
      _RDX = (unsigned int)(_RDX + 4);
    }
    while ( (_DWORD)_RDX );
    __asm
    {
      vpshufd xmm1, xmm0, 0EEh
      vpxor   xmm0, xmm0, xmm1
      vpshufd xmm1, xmm0, 55h ; 'U'
      vpxor   xmm0, xmm0, xmm1
      vmovd   edx, xmm0
    }
    if ( v26 != v24 )
    {
LABEL_38:
      v35 = v24 - v26;
      do
      {
        _RDX = _EAX ^ (unsigned int)_RDX;
        --v35;
      }
      while ( v35 );
    }
  }
LABEL_40:
  v52 = _RDX;
  v36 = *((unsigned __int8 *)v22 + 4938);
  v37 = 4 - v36;
  if ( (unsigned __int64)(4 - v36) > 3 )
    goto LABEL_52;
  if ( (unsigned __int8)v36 <= 7u )
    goto LABEL_50;
  if ( (v36 & 0x80u) != 0LL )
  {
    if ( (_DWORD)v36 == 128 )
      goto LABEL_52;
    _R11 = 128;
    if ( (v36 & 0x78) == 0 )
    {
      v37 = 132 - v36;
      goto LABEL_50;
    }
  }
  else
  {
    _R11 = 0;
  }
  v39 = (unsigned int)v36 & 0xFFFFFFF8;
  _RDI = (char *)&v53[-1] + v37;
  __asm { vpcmpeqd xmm0, xmm0, xmm0 }
  do
  {
    _R15 = *(_QWORD *)&_RDI[_R11] ^ *(_QWORD *)((char *)v53 + v37 + _R11);
    __asm
    {
      vmovq   xmm1, r15
      vpxor   xmm1, xmm1, xmm0
      vmovq   qword ptr [rdi+r11], xmm1
    }
    _R11 += 8;
  }
  while ( v39 != _R11 );
  if ( v39 == v36 )
    goto LABEL_52;
  v37 |= v39;
  do
  {
LABEL_50:
    *((_BYTE *)&v53[-1] + v37) = ~(*((_BYTE *)&v53[-1] + v37) ^ *((_BYTE *)v53 + v37));
    ++v37;
  }
  while ( v37 != 4 );
  _RDX = v52;
LABEL_52:
  v45 = (*((_BYTE *)v22 + 4939) + 1) & 3;
  *((_DWORD *)v22 + v45 + 1230) = _RDX;
  *((_BYTE *)v22 + 4939) = v45;
  *((_DWORD *)hWnd + 4176) = _R8;
  v46 = (char *)*((_QWORD *)hWnd + 2084);
  v47 = hWnd + 4162;
  if ( !v46 )
    goto LABEL_70;
  v48 = *v46;
  if ( !*v46 )
    goto LABEL_70;
  _RDX = 0x100000001B3LL;
  v49 = v46 + 1;
  do
  {
    v4 = 0x100000001B3LL * (v48 ^ (unsigned __int64)v4);
    v48 = *v49++;
  }
  while ( v48 );
  if ( (unsigned int)(_R8 - 29) <= 7 && v4 == 0x7734BE05A394D5E2LL
    || (unsigned int)(_R8 - 26) <= 6 && v4 == 0x33055511E147AE6BLL
    || (_DWORD)_R8 == 16 && v4 == 0xBEE5A1E555549E3AuLL )
  {
    *((_BYTE *)hWnd + 16804) = 0;
LABEL_72:
    LOBYTE(_RDX) = 1;
    return ymmword_1800193C8(v47, _RDX);
  }
  _RDX = 0x8ABFF924F2288F6EuLL;
  if ( v4 != 0x254B9819B8CFB5E6LL && v4 != 0x8ABFF924F2288F6EuLL )
  {
LABEL_70:
    if ( v4 != 0xB509E7DE614B86C2uLL && *((_BYTE *)hWnd + 16804) != 0xFF )
      *((_BYTE *)hWnd + 16804) = -1;
    goto LABEL_72;
  }
  v50 = *(_QWORD *)v47;
  v51 = *((_QWORD *)hWnd + 2082);
  if ( (v4 != 0x254B9819B8CFB5E6LL || (_DWORD)_R8 != 7) && (v4 != 0x8ABFF924F2288F6EuLL || (_DWORD)_R8 != 6) )
  {
    if ( v50 != v51 )
    {
      *((_QWORD *)hWnd + 2082) = v50;
      v47 = hWnd + 4162;
    }
    goto LABEL_72;
  }
  if ( v50 != v51 )
  {
    *((_QWORD *)hWnd + 2082) = v50;
    v47 = hWnd + 4162;
  }
  return ((__int64 (__fastcall *)(HWND, __int64, __int64, _QWORD, _BYTE, _BYTE, _BYTE, _BYTE, char, _BYTE, char, char *, _DWORD, char *, _DWORD, _BYTE, int))*(&ymmword_1800193C8 + 1))(
           v47,
           v21,
           _R8,
           0,
           0,
           0,
           0,
           0,
           1,
           0,
           -1,
           "",
           0,
           "",
           0,
           0,
           1);
}


// ------------------------------------------------------------
// Function 34/121: ?_Xlen@?$vector@PEAXV?$allocator@PEAX@std@@@std@@IEBAXXZ_0
// Address: 0x180014780 - 0x180014791 (size 0x11)
// ------------------------------------------------------------
void __noreturn std::vector<void *>::_Xlen()
{
  std::_Xlength_error("map/set too long");
}


// ------------------------------------------------------------
// Function 35/121: sub_1800147A0
// Address: 0x1800147A0 - 0x1800149E6 (size 0x246)
// ------------------------------------------------------------
__int64 *__fastcall sub_1800147A0(__int64 **a1, int a2, __int64 *a3)
{
  __int64 *result; // rax
  __int64 **v4; // r8
  __int64 **v5; // r9
  __int64 *v6; // rcx
  __int64 *v7; // rcx
  _BYTE *v8; // r11
  __int64 *v9; // r10
  __int64 *v10; // rdx
  __int64 *v11; // rsi
  __int64 *v12; // r9
  __int64 *v13; // r9
  __int64 v14; // r10
  __int64 v15; // r10
  __int64 **v16; // rdx
  __int64 *v17; // r9
  __int64 v18; // r10
  __int64 **v19; // r10
  __int64 v20; // r10
  __int64 **v21; // r10

  *(&Block + 1) = (char *)*(&Block + 1) + 1;
  result = a3;
  v4 = (__int64 **)Block;
  result[1] = (__int64)a1;
  if ( a1 != v4 )
  {
    v5 = (__int64 **)(result + 1);
    if ( a2 )
    {
      *a1 = result;
      if ( a1 == (__int64 **)*v4 )
        *v4 = result;
    }
    else
    {
      a1[2] = result;
      if ( a1 == (__int64 **)v4[2] )
        v4[2] = result;
    }
    v7 = *v5;
    if ( *((_BYTE *)*v5 + 24) )
    {
LABEL_9:
      v6 = v4[1];
      goto LABEL_10;
    }
    v8 = v7 + 3;
    v9 = result;
    while ( 1 )
    {
      v10 = (__int64 *)v7[1];
      v11 = (__int64 *)*v10;
      if ( v7 == (__int64 *)*v10 )
      {
        v11 = (__int64 *)v10[2];
        if ( *((_BYTE *)v11 + 24) )
        {
          v13 = (__int64 *)v7[2];
          if ( v9 == v13 )
          {
            v15 = *v13;
            v7[2] = *v13;
            if ( !*(_BYTE *)(v15 + 25) )
            {
              *(_QWORD *)(v15 + 8) = v7;
              v10 = (__int64 *)v7[1];
            }
            v13[1] = (__int64)v10;
            if ( v7 == *((__int64 **)Block + 1) )
            {
              *((_QWORD *)Block + 1) = v13;
            }
            else if ( v7 == (__int64 *)*v10 )
            {
              *v10 = (__int64)v13;
            }
            else
            {
              v10[2] = (__int64)v13;
            }
            *v13 = (__int64)v7;
            v7[1] = (__int64)v13;
          }
          else
          {
            v13 = v7;
            v7 = v9;
          }
          *((_BYTE *)v13 + 24) = 1;
          *(_BYTE *)(*(_QWORD *)(v7[1] + 8) + 24LL) = 0;
          v16 = *(__int64 ***)(v7[1] + 8);
          v17 = *v16;
          v20 = (*v16)[2];
          *v16 = (__int64 *)v20;
          if ( !*(_BYTE *)(v20 + 25) )
            *(_QWORD *)(v20 + 8) = v16;
          v21 = (__int64 **)v16[1];
          v17[1] = (__int64)v21;
          if ( v16 == *((__int64 ***)Block + 1) )
          {
            *((_QWORD *)Block + 1) = v17;
            v17[2] = (__int64)v16;
          }
          else
          {
            if ( v16 == (__int64 **)v21[2] )
              v21[2] = v17;
            else
              *v21 = v17;
            v17[2] = (__int64)v16;
          }
          goto LABEL_42;
        }
      }
      else if ( *((_BYTE *)v11 + 24) )
      {
        v12 = (__int64 *)*v7;
        if ( v9 == (__int64 *)*v7 )
        {
          v14 = v12[2];
          *v7 = v14;
          if ( !*(_BYTE *)(v14 + 25) )
          {
            *(_QWORD *)(v14 + 8) = v7;
            v10 = (__int64 *)v7[1];
          }
          v12[1] = (__int64)v10;
          if ( v7 == *((__int64 **)Block + 1) )
          {
            *((_QWORD *)Block + 1) = v12;
          }
          else if ( v7 == (__int64 *)v10[2] )
          {
            v10[2] = (__int64)v12;
          }
          else
          {
            *v10 = (__int64)v12;
          }
          v12[2] = (__int64)v7;
          v7[1] = (__int64)v12;
        }
        else
        {
          v12 = v7;
          v7 = v9;
        }
        *((_BYTE *)v12 + 24) = 1;
        *(_BYTE *)(*(_QWORD *)(v7[1] + 8) + 24LL) = 0;
        v16 = *(__int64 ***)(v7[1] + 8);
        v17 = v16[2];
        v18 = *v17;
        v16[2] = (__int64 *)*v17;
        if ( !*(_BYTE *)(v18 + 25) )
          *(_QWORD *)(v18 + 8) = v16;
        v19 = (__int64 **)v16[1];
        v17[1] = (__int64)v19;
        if ( v16 == *((__int64 ***)Block + 1) )
        {
          *((_QWORD *)Block + 1) = v17;
        }
        else if ( v16 == (__int64 **)*v19 )
        {
          *v19 = v17;
        }
        else
        {
          v19[2] = v17;
        }
        *v17 = (__int64)v16;
LABEL_42:
        v16[1] = v17;
        goto LABEL_13;
      }
      *v8 = 1;
      *((_BYTE *)v11 + 24) = 1;
      *(_BYTE *)((*v5)[1] + 24) = 0;
      v7 = (__int64 *)(*v5)[1];
LABEL_13:
      v9 = v7;
      v5 = (__int64 **)(v7 + 1);
      v7 = (__int64 *)v7[1];
      v8 = v7 + 3;
      if ( *((_BYTE *)v7 + 24) )
        goto LABEL_9;
    }
  }
  *v4 = result;
  v4[1] = result;
  v4[2] = result;
  v6 = result;
LABEL_10:
  *((_BYTE *)v6 + 24) = 1;
  return result;
}


// ------------------------------------------------------------
// Function 36/121: sub_1800149F0
// Address: 0x1800149F0 - 0x180014FF2 (size 0x602)
// ------------------------------------------------------------
void __fastcall sub_1800149F0(char *a1, char *a2, __int64 a3)
{
  char *v3; // rsi
  char *v4; // r14
  __int64 v5; // rcx
  unsigned int *v6; // rax
  __int64 v7; // rcx
  char *v8; // r8
  unsigned int v9; // edx
  __int64 v10; // r8
  unsigned int v11; // r9d
  unsigned int *v13; // rdi
  char *v14; // rax
  unsigned __int64 v15; // rcx
  unsigned int *v16; // r8
  unsigned int *v17; // rdx
  __int64 v18; // r9
  unsigned __int64 v19; // r9
  unsigned int v20; // r10d
  unsigned int v21; // ebp
  unsigned int v22; // ebp
  unsigned int v23; // r14d
  unsigned int v24; // r14d
  unsigned int v25; // ebp
  unsigned int v26; // ebp
  unsigned int v27; // r11d
  unsigned int v28; // r11d
  unsigned int v29; // ebp
  unsigned int v30; // r11d
  unsigned int v31; // ebp
  unsigned int v32; // ebp
  unsigned int v33; // edx
  unsigned int v34; // r10d
  unsigned int *v35; // rdx
  unsigned __int64 v36; // rcx
  char *v37; // rcx
  unsigned int *v38; // r8
  unsigned int v39; // r10d
  unsigned int *v40; // r15
  unsigned int v41; // r10d
  unsigned int v42; // r8d
  int v43; // edx
  unsigned int v44; // r8d
  unsigned int v45; // r10d
  unsigned int v46; // edx
  unsigned __int64 v47; // r9
  __int64 v48; // rax
  unsigned __int64 v49; // rdx
  unsigned __int64 v50; // r8
  signed __int64 v51; // rcx
  __int64 v52; // rbx
  __int64 v53; // r9
  unsigned int v54; // r10d
  __int64 v55; // r11
  __int64 v56; // r14
  unsigned int v57; // ebp
  unsigned int v58; // ebx
  bool v59; // cf
  unsigned int v60; // ebp
  __int64 v61; // r10
  __int64 v62; // rdx
  unsigned int v63; // r8d
  __int64 v64; // r9
  __int64 v65; // r11
  unsigned int v66; // ebx
  unsigned int v67; // r10d
  bool v68; // cf
  unsigned int v69; // r11d
  unsigned int v70; // eax
  __int64 v71; // rcx
  __int64 v72; // r8
  __int64 v73; // r10
  signed __int64 v74; // rdx
  __int64 v75; // rbx
  unsigned int v76; // ebp
  unsigned int v77; // r11d
  bool v78; // cf
  unsigned __int64 v79; // r8
  unsigned int v80; // r9d

  v3 = a2;
  v4 = a1;
  v5 = a2 - a1;
  if ( v5 < 129 )
  {
LABEL_2:
    if ( v4 != v3 )
    {
      v6 = (unsigned int *)(v4 + 4);
      if ( v4 + 4 != v3 )
      {
        v7 = 4;
        do
        {
          v9 = *v6;
          v10 = v7;
          do
          {
            v11 = *(_DWORD *)&v4[v10 - 4];
            if ( v9 >= v11 )
            {
              v8 = &v4[v10];
              goto LABEL_6;
            }
            *(_DWORD *)&v4[v10] = v11;
            v10 -= 4;
          }
          while ( v10 );
          v8 = v4;
LABEL_6:
          *(_DWORD *)v8 = v9;
          ++v6;
          v7 += 4;
        }
        while ( v6 != (unsigned int *)v3 );
      }
    }
    return;
  }
  v13 = (unsigned int *)v4;
  v14 = a2;
LABEL_14:
  if ( a3 > 0 )
  {
    v15 = (unsigned __int64)v5 >> 3;
    v16 = &v13[v15];
    v17 = (unsigned int *)(v3 - 4);
    v18 = (v3 - 4 - (char *)v13) >> 2;
    if ( v18 < 41 )
    {
      v19 = *v16;
      if ( (unsigned int)v19 < *v13 )
      {
        *v16 = *v13;
        *v13 = v19;
        v19 = *v16;
      }
      v34 = *v17;
      if ( *v17 < (unsigned int)v19 )
      {
        *v17 = v19;
        *v16 = v34;
        if ( v34 < *v13 )
        {
          *v16 = *v13;
          *v13 = v34;
        }
      }
    }
    else
    {
      v19 = (unsigned __int64)(v18 + 1) >> 3;
      v20 = v13[v19];
      if ( v20 < *v13 )
      {
        v13[v19] = *v13;
        *v13 = v20;
        v20 = v13[v19];
      }
      v21 = v13[2 * v19];
      if ( v21 < v20 )
      {
        v13[2 * v19] = v20;
        v13[v19] = v21;
        if ( v21 < *v13 )
        {
          v13[v19] = *v13;
          *v13 = v21;
        }
      }
      v22 = *v16;
      v23 = v16[-v19];
      if ( *v16 < v23 )
      {
        *v16 = v23;
        v16[-v19] = v22;
        v22 = *v16;
      }
      v24 = v16[v19];
      if ( v24 < v22 )
      {
        v16[v19] = v22;
        *v16 = v24;
        v25 = v16[-v19];
        if ( v24 < v25 )
        {
          *v16 = v25;
          v16[-v19] = v24;
        }
      }
      v26 = v17[-v19];
      v27 = v17[-2 * v19];
      if ( v26 < v27 )
      {
        v17[-v19] = v27;
        v17[-2 * v19] = v26;
        v26 = v17[-v19];
      }
      v28 = *v17;
      if ( *v17 < v26 )
      {
        *v17 = v26;
        v17[-v19] = v28;
        v29 = v17[-2 * v19];
        if ( v28 < v29 )
        {
          v17[-v19] = v29;
          v17[-2 * v19] = v28;
        }
      }
      v30 = *v16;
      v31 = v13[v19];
      if ( *v16 < v31 )
      {
        *v16 = v31;
        v13[v19] = v30;
        v30 = *v16;
      }
      v32 = v17[-v19];
      if ( v32 < v30 )
      {
        v17[-v19] = v30;
        *v16 = v32;
        v33 = v13[v19];
        if ( v32 < v33 )
        {
          *v16 = v33;
          v13[v19] = v32;
        }
      }
    }
    do
    {
      v35 = v16;
      if ( v13 >= v16 )
        break;
      --v16;
      v19 = *v35;
    }
    while ( (_DWORD)v19 == *(v35 - 1) );
    v36 = (unsigned __int64)&v13[v15 + 1];
    do
    {
      v4 = (char *)v36;
      if ( v36 >= (unsigned __int64)v3 )
        break;
      v36 += 4LL;
    }
    while ( *v35 == *(_DWORD *)v4 );
    v37 = v4;
    v38 = v35;
LABEL_49:
    while ( v37 < v3 )
    {
      v19 = *(unsigned int *)v37;
      if ( *v38 >= (unsigned int)v19 )
      {
        if ( *v38 > (unsigned int)v19 )
          break;
        if ( v37 != v4 )
        {
          v39 = *(_DWORD *)v4;
          *(_DWORD *)v4 = v19;
          *(_DWORD *)v37 = v39;
        }
        v4 += 4;
      }
      v37 += 4;
    }
    if ( v13 >= v35 )
      goto LABEL_63;
    while ( 1 )
    {
      v19 = (unsigned __int64)v35--;
      v41 = *(_DWORD *)(v19 - 4);
      if ( v41 < *v38 )
      {
        v40 = v38;
      }
      else
      {
        if ( v41 > *v38 )
        {
          v35 = (unsigned int *)v19;
LABEL_63:
          v40 = v38;
LABEL_64:
          if ( v37 != v3 || v35 != v13 )
          {
            if ( v35 == v13 )
            {
              v44 = *v40;
              if ( v4 != v37 )
              {
                *v40 = *(_DWORD *)v4;
                *(_DWORD *)v4 = v44;
                v44 = *v40;
              }
              v4 += 4;
              v19 = *(unsigned int *)v37;
              *v40 = v19;
              *(_DWORD *)v37 = v44;
              v37 += 4;
              v38 = v40 + 1;
            }
            else
            {
              v19 = (unsigned __int64)(v35 - 1);
              if ( v37 == v3 )
              {
                v38 = v40 - 1;
                v45 = *(v40 - 1);
                if ( v35 != v40 )
                {
                  v46 = *(_DWORD *)v19;
                  *(_DWORD *)v19 = v45;
                  *v38 = v46;
                  v45 = v46;
                }
                *v38 = *((_DWORD *)v4 - 1);
                *((_DWORD *)v4 - 1) = v45;
                v4 -= 4;
                v35 = (unsigned int *)v19;
              }
              else
              {
                v43 = *(_DWORD *)v37;
                *(_DWORD *)v37 = *(_DWORD *)v19;
                *(_DWORD *)v19 = v43;
                v37 += 4;
                v35 = (unsigned int *)v19;
                v38 = v40;
              }
            }
            goto LABEL_49;
          }
          a3 = ((unsigned __int64)a3 >> 1) + ((unsigned __int64)a3 >> 2);
          if ( (char *)v40 - (char *)v13 >= v14 - v4 )
          {
            sub_1800149F0(v4, v3, a3, v19);
            v14 = (char *)v40;
            v4 = (char *)v13;
            v3 = (char *)v40;
          }
          else
          {
            sub_1800149F0(v13, v40, a3, v19);
            v13 = (unsigned int *)v4;
            v14 = v3;
          }
          v5 = v14 - (char *)v13;
          if ( v14 - (char *)v13 < 129 )
            goto LABEL_2;
          goto LABEL_14;
        }
        v40 = v38 - 1;
        if ( (unsigned int *)v19 != v38 )
        {
          v42 = *v40;
          *v40 = v41;
          *v35 = v42;
        }
      }
      v38 = v40;
      if ( v13 >= v35 )
        goto LABEL_64;
    }
  }
  v47 = v3 - (char *)v13;
  v48 = (v3 - (char *)v13) >> 3;
  if ( v48 > 0 )
  {
    v49 = v47 >> 2;
    v50 = (v47 >> 2) - 1;
    v51 = v50 >> 1;
    if ( (v47 & 4) != 0 )
    {
      do
      {
        v62 = v48--;
        v63 = v13[v62 - 1];
        v64 = v48;
        if ( v62 <= v51 )
        {
          v64 = v48;
          do
          {
            v65 = 2 * v64 + 2;
            v66 = v13[2 * v64 + 1];
            v67 = v13[2 * v64 + 2];
            v68 = v67 < v66;
            if ( v67 > v66 )
              v66 = v13[2 * v64 + 2];
            v13[v64] = v66;
            v64 = 2 * v64 + 1;
            if ( !v68 )
              v64 = v65;
          }
          while ( v64 < v51 );
        }
        if ( v62 <= v64 )
        {
          while ( 1 )
          {
            v61 = (v64 - 1) >> 1;
            v69 = v13[v61];
            if ( v69 >= v63 )
              break;
            v13[v64] = v69;
            v64 = (v64 - 1) >> 1;
            if ( v62 > v61 )
              goto LABEL_96;
          }
        }
        v61 = v64;
LABEL_96:
        v13[v61] = v63;
      }
      while ( v62 > 1 );
    }
    else
    {
      do
      {
        v53 = v48--;
        v54 = v13[v53 - 1];
        v55 = v48;
        if ( v53 <= v51 )
        {
          v55 = v48;
          do
          {
            v56 = 2 * v55 + 2;
            v57 = v13[2 * v55 + 1];
            v58 = v13[2 * v55 + 2];
            v59 = v58 < v57;
            if ( v58 > v57 )
              v57 = v13[2 * v55 + 2];
            v13[v55] = v57;
            v55 = 2 * v55 + 1;
            if ( !v59 )
              v55 = v56;
          }
          while ( v55 < v51 );
        }
        if ( v55 == v51 )
        {
          v13[v51] = v13[v49 - 1];
          v55 = v50;
        }
        if ( v53 <= v55 )
        {
          while ( 1 )
          {
            v52 = (v55 - 1) >> 1;
            v60 = v13[v52];
            if ( v60 >= v54 )
              break;
            v13[v55] = v60;
            v55 = (v55 - 1) >> 1;
            if ( v53 > v52 )
              goto LABEL_81;
          }
        }
        v52 = v55;
LABEL_81:
        v13[v52] = v54;
      }
      while ( v53 > 1 );
    }
  }
  do
  {
    v70 = *((_DWORD *)v3 - 1);
    *((_DWORD *)v3 - 1) = *v13;
    v3 -= 4;
    v71 = v3 - (char *)v13;
    v72 = (v3 - (char *)v13) >> 2;
    v73 = (v72 - 1) >> 1;
    v74 = 0;
    while ( v74 < v73 )
    {
      v75 = 2 * v74 + 2;
      v76 = v13[2 * v74 + 1];
      v77 = v13[2 * v74 + 2];
      v78 = v77 < v76;
      if ( v77 > v76 )
        v76 = v13[2 * v74 + 2];
      v13[v74] = v76;
      v74 = 2 * v74 + 1;
      if ( !v78 )
        v74 = v75;
    }
    if ( (v71 & 4) == 0 && v74 == v73 )
    {
      v13[v73] = v13[v72 - 1];
      v74 = v72 - 1;
    }
    if ( v74 > 0 )
    {
      while ( 1 )
      {
        v79 = (unsigned __int64)(v74 - 1) >> 1;
        v80 = v13[v79];
        if ( v80 >= v70 )
          break;
        v13[v74] = v80;
        v74 = (unsigned __int64)(v74 - 1) >> 1;
        if ( !v79 )
        {
          v74 = 0;
          break;
        }
      }
    }
    v13[v74] = v70;
  }
  while ( v71 > 4 );
}


// ------------------------------------------------------------
// Function 37/121: sub_180015000
// Address: 0x180015000 - 0x180015037 (size 0x37)
// ------------------------------------------------------------
void __noreturn sub_180015000()
{
  _QWORD pExceptionObject[3]; // [rsp+20h] [rbp-18h] BYREF

  pExceptionObject[2] = 0;
  pExceptionObject[1] = "bad array new length";
  pExceptionObject[0] = &unk_180017480;
  throw (std::bad_array_new_length *)pExceptionObject;
}


// ------------------------------------------------------------
// Function 38/121: ??1agent@Concurrency@@UEAA@XZ
// Address: 0x180015040 - 0x180015053 (size 0x13)
// ------------------------------------------------------------
void __fastcall Concurrency::agent::~agent(Concurrency::agent *this)
{
  *(_QWORD *)this = &unk_180017480;
  _std_exception_destroy((char *)this + 8);
}


// ------------------------------------------------------------
// Function 39/121: sub_180015060
// Address: 0x180015060 - 0x180015094 (size 0x34)
// ------------------------------------------------------------
_QWORD *__fastcall sub_180015060(_QWORD *_RCX, __int64 a2)
{
  _QWORD *v3; // rsi

  v3 = _RCX;
  *_RCX = &unk_180017480;
  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vmovups xmmword ptr [rcx+8], xmm0
  }
  _std_exception_copy(a2 + 8, _RCX + 1);
  return v3;
}


// ------------------------------------------------------------
// Function 40/121: sub_1800150A0
// Address: 0x1800150A0 - 0x1800150DE (size 0x3E)
// ------------------------------------------------------------
_QWORD *__fastcall sub_1800150A0(_QWORD *_RCX, __int64 a2)
{
  _QWORD *v3; // rsi

  v3 = _RCX;
  *_RCX = &unk_180017480;
  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vmovups xmmword ptr [rcx+8], xmm0
  }
  _std_exception_copy(a2 + 8, _RCX + 1);
  *v3 = &unk_180017480;
  return v3;
}


// ------------------------------------------------------------
// Function 41/121: sub_1800150E0
// Address: 0x1800150E0 - 0x1800151F2 (size 0x112)
// ------------------------------------------------------------
HWND sub_1800150E0()
{
  HWND result; // rax

  result = hWnd;
  _RSI = *((_QWORD *)hWnd + 1922);
  if ( *(_BYTE *)(_RSI + 40) )
  {
    if ( ((_BYTE)hWnd[1320] & 4) != 0 )
    {
      __asm { vmovss  xmm0, dword ptr [rsi+30h] }
      _R8 = qword_180019368;
      __asm { vucomiss xmm0, dword ptr [r8] }
    }
  }
  return result;
}


// ------------------------------------------------------------
// Function 42/121: sub_180015200
// Address: 0x180015200 - 0x18001522A (size 0x2A)
// ------------------------------------------------------------
__int64 sub_180015200()
{
  SendInput(2u, &stru_180019290, 40);
  return sub_1800049F0(10);
}


// ------------------------------------------------------------
// Function 43/121: sub_180015230
// Address: 0x180015230 - 0x180015274 (size 0x44)
// ------------------------------------------------------------
void *__fastcall sub_180015230(size_t Size)
{
  void *result; // rax

  for ( result = malloc(Size); !result; result = malloc(Size) )
  {
    if ( !callnewh(Size) )
    {
      if ( Size != -1 )
        Concurrency::cancel_current_task();
      Concurrency::cancel_current_task();
    }
  }
  return result;
}


// ------------------------------------------------------------
// Function 44/121: j_j_free
// Address: 0x180015280 - 0x180015285 (size 0x5)
// ------------------------------------------------------------
// attributes: thunk
void __cdecl j_j_free(void *Block)
{
  j_free(Block);
}


// ------------------------------------------------------------
// Function 45/121: sub_180015290
// Address: 0x180015290 - 0x1800152BB (size 0x2B)
// ------------------------------------------------------------
_QWORD *__fastcall sub_180015290(_QWORD *a1, char a2)
{
  *a1 = &type_info::`vftable';
  if ( (a2 & 1) != 0 )
    j_j_free(a1);
  return a1;
}


// ------------------------------------------------------------
// Function 46/121: sub_1800152C0
// Address: 0x1800152C0 - 0x180015300 (size 0x40)
// ------------------------------------------------------------
__int64 __fastcall sub_1800152C0(void (__cdecl *Function)())
{
  int v2; // eax
  void (__cdecl *v3)(); // rdx

  if ( Table._first == (_PVFV *)-1LL )
    v2 = crt_atexit(Function);
  else
    v2 = register_onexit_function(&Table, (_onexit_t)Function);
  v3 = 0;
  if ( !v2 )
    v3 = Function;
  return (unsigned int)(v3 != 0) - 1;
}


// ------------------------------------------------------------
// Function 47/121: sub_180015300
// Address: 0x180015300 - 0x180015391 (size 0x91)
// ------------------------------------------------------------
bool __fastcall sub_180015300(__int64 a1)
{
  _DWORD *v2; // rcx
  unsigned __int64 v3; // r8
  _DWORD *v4; // rax
  _DWORD *v5; // r9
  unsigned __int64 v6; // rdx

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
      return v4[9] >= 0;
    v4 += 10;
  }
  return 0;
}


// ------------------------------------------------------------
// Function 48/121: sub_1800153A0
// Address: 0x1800153A0 - 0x1800153E7 (size 0x47)
// ------------------------------------------------------------
char sub_1800153A0()
{
  int v0; // eax
  PVOID StackBase; // rcx
  signed __int64 v2; // rax

  LOBYTE(v0) = __uncaught_exception();
  if ( !v0 )
    return 0;
  StackBase = NtCurrentTeb()->NtTib.StackBase;
  v2 = _InterlockedCompareExchange64(&qword_180019198, (signed __int64)StackBase, 0);
  if ( !v2 )
    return 0;
  while ( StackBase != (PVOID)v2 )
  {
    v2 = _InterlockedCompareExchange64(&qword_180019198, (signed __int64)StackBase, 0);
    if ( !v2 )
      return 0;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 49/121: sub_1800153F0
// Address: 0x1800153F0 - 0x180015415 (size 0x25)
// ------------------------------------------------------------
char __fastcall sub_1800153F0(char a1)
{
  int v2; // eax

  LOBYTE(v2) = __uncaught_exception();
  if ( v2 && !a1 )
    LOBYTE(v2) = _InterlockedExchange64(&qword_180019198, 0);
  return v2;
}


// ------------------------------------------------------------
// Function 50/121: sub_180015420
// Address: 0x180015420 - 0x18001545B (size 0x3B)
// ------------------------------------------------------------
char __fastcall sub_180015420(int a1)
{
  if ( !a1 )
    byte_1800191A0 = 1;
  sub_180015730();
  if ( !(unsigned __int8)((__int64 (*)(void))sub_180015F80)() )
    return 0;
  if ( !(unsigned __int8)((__int64 (*)(void))sub_180015F80)() )
  {
    sub_180015F80(0);
    return 0;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 51/121: sub_180015460
// Address: 0x180015460 - 0x18001548B (size 0x2B)
// ------------------------------------------------------------
char __fastcall sub_180015460(__int64 a1, char a2)
{
  unsigned __int8 v2; // bl

  v2 = a1;
  if ( !byte_1800191A0 || !a2 )
  {
    sub_180015F80(a1);
    sub_180015F80(v2);
  }
  return 1;
}


// ------------------------------------------------------------
// Function 52/121: sub_180015490
// Address: 0x180015490 - 0x1800154D9 (size 0x49)
// ------------------------------------------------------------
int __fastcall sub_180015490(
        __int64 a1,
        int a2,
        __int64 a3,
        void (__fastcall *a4)(__int64, _QWORD, __int64),
        unsigned int ExceptionNum,
        struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  int v10; // eax

  LOBYTE(v10) = __uncaught_exception();
  if ( !v10 && a2 == 1 )
    a4(a1, 0, a3);
  return seh_filter_dll(ExceptionNum, ExceptionPtr);
}


// ------------------------------------------------------------
// Function 53/121: sub_1800154E0
// Address: 0x1800154E0 - 0x180015559 (size 0x79)
// ------------------------------------------------------------
char sub_1800154E0()
{
  int v0; // eax

  if ( !byte_1800191A1 )
  {
    LOBYTE(v0) = __uncaught_exception();
    if ( v0 )
    {
      if ( initialize_onexit_table(&Table) || initialize_onexit_table(&stru_1800191C0) )
        return 0;
    }
    else
    {
      *(__m128i *)&Table._first = _mm_load_si128((const __m128i *)&xmmword_180017010);
      Table._end = (_PVFV *)-1LL;
      *(_OWORD *)&stru_1800191C0._first = *(_OWORD *)&Table._first;
      stru_1800191C0._end = (_PVFV *)-1LL;
    }
    byte_1800191A1 = 1;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 54/121: sub_180015560
// Address: 0x180015560 - 0x18001559C (size 0x3C)
// ------------------------------------------------------------
char sub_180015560()
{
  int v0; // eax
  _crt_argv_mode v2; // eax

  LOBYTE(v0) = __uncaught_exception();
  if ( v0 )
  {
    sub_180015730();
    return 1;
  }
  else
  {
    v2 = (unsigned int)sub_1800159E0();
    if ( configure_narrow_argv(v2) )
    {
      return 0;
    }
    else
    {
      initialize_narrow_environment();
      return 1;
    }
  }
}


// ------------------------------------------------------------
// Function 55/121: sub_1800155A0
// Address: 0x1800155A0 - 0x1800155D4 (size 0x34)
// ------------------------------------------------------------
void sub_1800155A0()
{
  int v0; // eax

  LOBYTE(v0) = __uncaught_exception();
  if ( v0 )
  {
    execute_onexit_table(&Table);
  }
  else if ( !(unsigned int)sub_180015F90() )
  {
    cexit();
  }
}


// ------------------------------------------------------------
// Function 56/121: sub_1800155E0
// Address: 0x1800155E0 - 0x1800155F4 (size 0x14)
// ------------------------------------------------------------
__int64 sub_1800155E0()
{
  __int64 v0; // rcx

  sub_180015F80(0);
  return sub_180015F80(v0);
}


// ------------------------------------------------------------
// Function 57/121: sub_180015600
// Address: 0x180015600 - 0x180015629 (size 0x29)
// ------------------------------------------------------------
char __fastcall sub_180015600(__int64 a1)
{
  __int64 v1; // rcx
  __int64 v2; // rcx

  if ( !(unsigned __int8)sub_180015F80(a1) )
    return 0;
  if ( !(unsigned __int8)sub_180015F80(v1) )
  {
    sub_180015F80(v2);
    return 0;
  }
  return 1;
}


// ------------------------------------------------------------
// Function 58/121: sub_180015630
// Address: 0x180015630 - 0x180015645 (size 0x15)
// ------------------------------------------------------------
char __fastcall sub_180015630(__int64 a1)
{
  __int64 v1; // rcx

  sub_180015F80(a1);
  sub_180015F80(v1);
  return 1;
}


// ------------------------------------------------------------
// Function 59/121: Sleep
// Address: 0x180015650 - 0x180015657 (size 0x7)
// ------------------------------------------------------------
// attributes: thunk
void __stdcall Sleep(DWORD dwMilliseconds)
{
  __imp_Sleep(dwMilliseconds);
}


// ------------------------------------------------------------
// Function 60/121: sub_180015660
// Address: 0x180015660 - 0x180015681 (size 0x21)
// ------------------------------------------------------------
_QWORD *__fastcall sub_180015660(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad allocation";
  *a1 = &unk_180017480;
  return a1;
}


// ------------------------------------------------------------
// Function 61/121: ??1agent@Concurrency@@UEAA@XZ_0
// Address: 0x180015690 - 0x1800156A3 (size 0x13)
// ------------------------------------------------------------
void __fastcall Concurrency::agent::~agent(Concurrency::agent *this)
{
  *(_QWORD *)this = &unk_180017480;
  _std_exception_destroy((char *)this + 8);
}


// ------------------------------------------------------------
// Function 62/121: sub_1800156B0
// Address: 0x1800156B0 - 0x1800156D1 (size 0x21)
// ------------------------------------------------------------
_QWORD *__fastcall sub_1800156B0(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad array new length";
  *a1 = &unk_180017480;
  return a1;
}


// ------------------------------------------------------------
// Function 63/121: ?cancel_current_task@Concurrency@@YAXXZ
// Address: 0x1800156E0 - 0x180015700 (size 0x20)
// ------------------------------------------------------------
void __fastcall __noreturn Concurrency::cancel_current_task()
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_180015660(pExceptionObject);
  throw (std::bad_alloc *)pExceptionObject;
}


// ------------------------------------------------------------
// Function 64/121: ?cancel_current_task@Concurrency@@YAXXZ_0
// Address: 0x180015700 - 0x180015720 (size 0x20)
// ------------------------------------------------------------
void __fastcall __noreturn Concurrency::cancel_current_task()
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_1800156B0(pExceptionObject);
  throw (std::bad_array_new_length *)pExceptionObject;
}


// ------------------------------------------------------------
// Function 65/121: j_free
// Address: 0x180015720 - 0x180015725 (size 0x5)
// ------------------------------------------------------------
// attributes: thunk
void __cdecl j_free(void *Block)
{
  free(Block);
}


// ------------------------------------------------------------
// Function 66/121: sub_180015730
// Address: 0x180015730 - 0x1800159D8 (size 0x2A8)
// ------------------------------------------------------------
__int64 sub_180015730()
{
  int v5; // r11d
  bool v6; // zf
  int v12; // edi
  int v13; // eax
  unsigned __int64 v14; // rax
  __int64 v15; // rcx
  int v16; // r8d
  int v17; // r10d
  unsigned __int8 v18; // r14
  char v19; // si
  int v25; // ebp
  int v26; // r9d
  unsigned __int64 v42; // rax
  int v43; // eax
  unsigned __int64 v44; // rax
  unsigned __int64 v45; // rcx
  int v47; // [rsp+30h] [rbp+8h]

  _RAX = 0;
  __asm { cpuid }
  v5 = _RAX;
  v6 = ((unsigned int)_RBX ^ 0x756E6547 | (unsigned int)_RCX ^ 0x6C65746E | (unsigned int)_RDX ^ 0x49656E69) == 0;
  _RAX = 1;
  __asm { cpuid }
  v12 = _RCX;
  if ( v6
    && ((v13 = _RAX & 0xFFF3FF0, qword_180019010 = 0x8000, qword_180019018 = -1, v13 == 67264)
     || v13 == 132704
     || v13 == 132720
     || (v14 = (unsigned int)(v13 - 198224), (unsigned int)v14 <= 0x20) && (v15 = 0x100010001LL, _bittest64(&v15, v14))) )
  {
    v16 = dword_1800191D8 | 1;
    dword_1800191D8 |= 1u;
  }
  else
  {
    v16 = dword_1800191D8;
  }
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( v5 < 7 )
  {
    v26 = 0;
    v25 = 0;
  }
  else
  {
    _RAX = 7;
    __asm { cpuid }
    v25 = _RDX;
    v26 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      dword_1800191D8 = v16 | 2;
    if ( (int)_RAX >= 1 )
    {
      _RAX = 7;
      __asm { cpuid }
      v17 = _RDX;
    }
    if ( v5 >= 36 )
    {
      _RAX = 36;
      __asm { cpuid }
      v18 = _RBX;
    }
    if ( v5 >= 41 )
    {
      _RAX = 41;
      __asm { cpuid }
      v19 = _RBX;
    }
  }
  v42 = qword_180019020 & 0xFFFFFFFFFFFFFFFEuLL;
  dword_180019008 = 1;
  dword_18001900C = 2;
  qword_180019020 &= ~1uLL;
  if ( (v12 & 0x100000) != 0 )
  {
    v42 &= ~0x10uLL;
    dword_180019008 = 2;
    qword_180019020 = v42;
    dword_18001900C = 6;
  }
  if ( (v12 & 0x8000000) != 0 )
  {
    __asm { xgetbv }
    v47 = v42;
    if ( (v12 & 0x10000000) == 0 || (v42 & 6) != 6 )
    {
LABEL_35:
      if ( (v17 & 0x200000) != 0 && (v19 & 1) != 0 && (*(_QWORD *)&v47 & 0x80000LL) != 0 )
        qword_180019020 &= ~0x80uLL;
      return 0;
    }
    v43 = dword_18001900C | 8;
    dword_180019008 = 3;
    dword_18001900C |= 8u;
    if ( (v26 & 0x20) != 0 )
    {
      dword_180019008 = 5;
      dword_18001900C = v43 | 0x20;
      v44 = qword_180019020 & 0xFFFFFFFFFFFFFFFDuLL;
      qword_180019020 &= ~2uLL;
      if ( (v26 & 0xD0030000) != 0xD0030000 )
      {
LABEL_29:
        if ( (v25 & 0x800000) != 0 )
          qword_180019020 = v44 & 0xFFFFFFFFFEFFFFFFuLL;
        if ( (v17 & 0x80000) != 0 && (v47 & 0xE0) == 0xE0 )
        {
          v45 = qword_180019020 & 0xFFFFFFFFFEFFFFD0uLL;
          dword_1800191DC = v18;
          qword_180019020 &= 0xFFFFFFFFFEFFFFD0uLL;
          if ( v18 > 1u )
            qword_180019020 = v45 & 0xFFFFFFFFFFFFFFBFuLL;
        }
        goto LABEL_35;
      }
      if ( (v47 & 0xE0) == 0xE0 )
      {
        dword_18001900C |= 0x40u;
        v44 = qword_180019020 & 0xFFFFFFFFFFFFFFDBuLL;
        dword_180019008 = 6;
        qword_180019020 &= 0xFFFFFFFFFFFFFFDBuLL;
        goto LABEL_29;
      }
    }
    v44 = qword_180019020;
    goto LABEL_29;
  }
  return 0;
}


// ------------------------------------------------------------
// Function 67/121: sub_1800159E0
// Address: 0x1800159E0 - 0x1800159E6 (size 0x6)
// ------------------------------------------------------------
__int64 sub_1800159E0()
{
  return 1;
}


// ------------------------------------------------------------
// Function 68/121: ?__uncaught_exception@@YA_NXZ
// Address: 0x1800159F0 - 0x1800159FC (size 0xC)
// ------------------------------------------------------------
_BOOL8 __fastcall __uncaught_exception()
{
  return dword_180019088 != 0;
}


// ------------------------------------------------------------
// Function 69/121: RtlFailFast
// Address: 0x180015A00 - 0x180015A04 (size 0x4)
// ------------------------------------------------------------
void __fastcall __noreturn RtlFailFast(unsigned int a1)
{
  __fastfail(a1);
}


// ------------------------------------------------------------
// Function 70/121: nullsub_1
// Address: 0x180015A04 - 0x180015A05 (size 0x1)
// ------------------------------------------------------------
void nullsub_1()
{
  ;
}


// ------------------------------------------------------------
// Function 71/121: _guard_check_icall_nop
// Address: 0x180015A10 - 0x180015A13 (size 0x3)
// ------------------------------------------------------------
void guard_check_icall_nop()
{
  ;
}


// ------------------------------------------------------------
// Function 72/121: sub_180015A20
// Address: 0x180015A20 - 0x180015B25 (size 0x105)
// ------------------------------------------------------------
__int64 __fastcall sub_180015A20(__int64 a1, __int64 a2)
{
  char v4; // bl
  char v5; // di
  void (__fastcall **v6)(__int64, __int64, __int64); // rax
  void (__fastcall **v7)(__int64, __int64, __int64); // rbx

  if ( !sub_180015420(0) )
    return 0;
  v4 = sub_1800153A0();
  v5 = 1;
  if ( dword_180019190 )
    RtlFailFast(7u);
  dword_180019190 = 1;
  if ( sub_1800154E0() )
  {
    sub_180015EE0();
    sub_180015E70();
    sub_180015E90();
    if ( !initterm_e((_PIFV *)&First, (_PIFV *)&Last) )
    {
      if ( sub_180015560() )
      {
        initterm((_PVFV *)&qword_1800177F0, (_PVFV *)&qword_180017818);
        dword_180019190 = 2;
        v5 = 0;
      }
    }
  }
  sub_1800153F0(v4);
  if ( v5 )
    return 0;
  v6 = (void (__fastcall **)(__int64, __int64, __int64))sub_180015ED0();
  v7 = v6;
  if ( *v6 )
  {
    if ( sub_180015300((__int64)v6) )
      (*v7)(a1, 2, a2);
  }
  ++dword_1800191E8;
  return 1;
}


// ------------------------------------------------------------
// Function 73/121: sub_180015B30
// Address: 0x180015B30 - 0x180015BCA (size 0x9A)
// ------------------------------------------------------------
__int64 __fastcall sub_180015B30(unsigned __int8 a1)
{
  char v3; // bl
  __int64 v4; // rcx
  __int64 v5; // rcx
  unsigned int v6; // ebx

  if ( dword_1800191E8 <= 0 )
    return 0;
  --dword_1800191E8;
  v3 = sub_1800153A0();
  if ( dword_180019190 != 2 )
    RtlFailFast(7u);
  sub_1800155A0();
  sub_180015E80(v4);
  sub_180015F30(v5);
  dword_180019190 = 0;
  sub_1800153F0(v3);
  v6 = (unsigned __int8)sub_180015460(a1, 0);
  sub_1800155E0();
  return v6;
}


// ------------------------------------------------------------
// Function 74/121: sub_180015BD0
// Address: 0x180015BD0 - 0x180015C26 (size 0x56)
// ------------------------------------------------------------
__int64 __fastcall sub_180015BD0(__int64 a1, int a2, __int64 a3)
{
  int v3; // edx
  int v4; // edx

  if ( !a2 )
    return sub_180015B30(a3 != 0);
  v3 = a2 - 1;
  if ( !v3 )
    return sub_180015A20(a1, a3);
  v4 = v3 - 1;
  if ( !v4 )
    return (unsigned __int8)sub_180015600(a1);
  if ( v4 == 1 )
    return (unsigned __int8)sub_180015630(a1);
  return 1;
}


// ------------------------------------------------------------
// Function 75/121: sub_180015C30
// Address: 0x180015C30 - 0x180015D66 (size 0x136)
// ------------------------------------------------------------
__int64 __fastcall sub_180015C30(HMODULE a1, int a2, __int64 a3)
{
  unsigned int v7; // ebx
  unsigned int v8; // eax

  if ( !a2 && dword_1800191E8 <= 0 )
    return 0;
  if ( (unsigned int)(a2 - 1) > 1 || (v7 = sub_180015BD0((__int64)a1, a2, a3)) != 0 )
  {
    v8 = sub_1800133E0(a1, a2);
    v7 = v8;
    if ( a2 == 1 && !v8 )
    {
      sub_1800133E0(a1, 0);
      sub_180015B30(a3 != 0);
    }
    if ( !a2 || a2 == 3 )
      return (unsigned int)sub_180015BD0((__int64)a1, a2, a3) != 0;
  }
  return v7;
}


// ------------------------------------------------------------
// Function 76/121: DllEntryPoint
// Address: 0x180015D70 - 0x180015DAD (size 0x3D)
// ------------------------------------------------------------
BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    sub_180015DB0();
  return sub_180015C30(hinstDLL, fdwReason, (__int64)lpReserved);
}


// ------------------------------------------------------------
// Function 77/121: sub_180015DB0
// Address: 0x180015DB0 - 0x180015E6F (size 0xBF)
// ------------------------------------------------------------
uintptr_t sub_180015DB0()
{
  uintptr_t result; // rax
  uintptr_t v1; // rcx
  struct _FILETIME v2; // [rsp+20h] [rbp-18h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+40h] [rbp+8h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+48h] [rbp+10h] BYREF

  if ( _security_cookie == 0x2B992DDFA232LL )
  {
    SystemTimeAsFileTime = 0;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v2 = SystemTimeAsFileTime;
    v2 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v2);
    v2 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v2);
    QueryPerformanceCounter(&PerformanceCount);
    v1 = ((unsigned __int64)&v2
        ^ *(_QWORD *)&v2
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
    result = 0x2B992DDFA233LL;
    if ( v1 == 0x2B992DDFA232LL )
      v1 = 0x2B992DDFA233LL;
    _security_cookie = v1;
    qword_180019080 = ~v1;
  }
  else
  {
    qword_180019080 = ~_security_cookie;
    return ~_security_cookie;
  }
  return result;
}


// ------------------------------------------------------------
// Function 78/121: sub_180015E70
// Address: 0x180015E70 - 0x180015E7E (size 0xE)
// ------------------------------------------------------------
void sub_180015E70()
{
  InitializeSListHead(&stru_1800191F0);
}


// ------------------------------------------------------------
// Function 79/121: sub_180015E80
// Address: 0x180015E80 - 0x180015E8C (size 0xC)
// ------------------------------------------------------------
__int64 sub_180015E80()
{
  return _std_type_info_destroy_list(&stru_1800191F0);
}


// ------------------------------------------------------------
// Function 80/121: sub_180015E90
// Address: 0x180015E90 - 0x180015EAB (size 0x1B)
// ------------------------------------------------------------
_QWORD *sub_180015E90()
{
  _QWORD *v0; // rax
  _QWORD *result; // rax

  v0 = (_QWORD *)sub_180015EB0();
  *v0 |= 0x24uLL;
  result = (_QWORD *)sub_180015EC0();
  *result |= 2uLL;
  return result;
}


// ------------------------------------------------------------
// Function 81/121: sub_180015EB0
// Address: 0x180015EB0 - 0x180015EB8 (size 0x8)
// ------------------------------------------------------------
void *sub_180015EB0()
{
  return &unk_180019200;
}


// ------------------------------------------------------------
// Function 82/121: sub_180015EC0
// Address: 0x180015EC0 - 0x180015EC8 (size 0x8)
// ------------------------------------------------------------
void *sub_180015EC0()
{
  return &unk_180019208;
}


// ------------------------------------------------------------
// Function 83/121: sub_180015ED0
// Address: 0x180015ED0 - 0x180015ED8 (size 0x8)
// ------------------------------------------------------------
void *sub_180015ED0()
{
  return &unk_180019210;
}


// ------------------------------------------------------------
// Function 84/121: sub_180015EE0
// Address: 0x180015EE0 - 0x180015F22 (size 0x42)
// ------------------------------------------------------------
void __spoils<> sub_180015EE0()
{
  ;
}


// ------------------------------------------------------------
// Function 85/121: sub_180015F30
// Address: 0x180015F30 - 0x180015F72 (size 0x42)
// ------------------------------------------------------------
void __spoils<> sub_180015F30()
{
  ;
}


// ------------------------------------------------------------
// Function 86/121: sub_180015F80
// Address: 0x180015F80 - 0x180015F83 (size 0x3)
// ------------------------------------------------------------
char sub_180015F80()
{
  return 1;
}


// ------------------------------------------------------------
// Function 87/121: sub_180015F90
// Address: 0x180015F90 - 0x180015F93 (size 0x3)
// ------------------------------------------------------------
__int64 sub_180015F90()
{
  return 0;
}


// ------------------------------------------------------------
// Function 88/121: _guard_dispatch_icall_nop
// Address: 0x180015FB0 - 0x180015FB2 (size 0x2)
// ------------------------------------------------------------
__int64 __fastcall guard_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ------------------------------------------------------------
// Function 89/121: _guard_xfg_dispatch_icall_nop
// Address: 0x180015FD0 - 0x180015FD6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
__int64 __fastcall guard_xfg_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ------------------------------------------------------------
// Function 90/121: ?_Throw_Cpp_error@std@@YAXH@Z
// Address: 0x180016090 - 0x180016096 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __fastcall std::_Throw_Cpp_error(int a1)
{
  __imp_?_Throw_Cpp_error@std@@YAXH@Z(a1);
}


// ------------------------------------------------------------
// Function 91/121: ?_Xbad_function_call@std@@YAXXZ
// Address: 0x1800160A0 - 0x1800160A6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void std::_Xbad_function_call()
{
  __imp_?_Xbad_function_call@std@@YAXXZ();
}


// ------------------------------------------------------------
// Function 92/121: ?_Xlength_error@std@@YAXPEBD@Z
// Address: 0x1800160B0 - 0x1800160B6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __fastcall __noreturn std::_Xlength_error(const char *a1)
{
  __imp_?_Xlength_error@std@@YAXPEBD@Z(a1);
}


// ------------------------------------------------------------
// Function 93/121: _Cnd_broadcast
// Address: 0x1800160C0 - 0x1800160C6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl Cnd_broadcast(_Cnd_t a1)
{
  return _Cnd_broadcast(a1);
}


// ------------------------------------------------------------
// Function 94/121: _Cnd_do_broadcast_at_thread_exit
// Address: 0x1800160D0 - 0x1800160D6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __cdecl Cnd_do_broadcast_at_thread_exit()
{
  _Cnd_do_broadcast_at_thread_exit();
}


// ------------------------------------------------------------
// Function 95/121: _Cnd_wait
// Address: 0x1800160E0 - 0x1800160E6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl Cnd_wait(_Cnd_t a1, _Mtx_t a2)
{
  return _Cnd_wait(a1, a2);
}


// ------------------------------------------------------------
// Function 96/121: _Mtx_lock
// Address: 0x1800160F0 - 0x1800160F6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl Mtx_lock(_Mtx_t a1)
{
  return _Mtx_lock(a1);
}


// ------------------------------------------------------------
// Function 97/121: _Mtx_unlock
// Address: 0x180016100 - 0x180016106 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl Mtx_unlock(_Mtx_t a1)
{
  return _Mtx_unlock(a1);
}


// ------------------------------------------------------------
// Function 98/121: _Query_perf_counter
// Address: 0x180016110 - 0x180016116 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
__int64 __cdecl Query_perf_counter()
{
  return _Query_perf_counter();
}


// ------------------------------------------------------------
// Function 99/121: _Query_perf_frequency
// Address: 0x180016120 - 0x180016126 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
__int64 __cdecl Query_perf_frequency()
{
  return _Query_perf_frequency();
}


// ------------------------------------------------------------
// Function 100/121: _Thrd_detach
// Address: 0x180016130 - 0x180016136 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl Thrd_detach(_Thrd_t *a1)
{
  return _Thrd_detach(a1);
}


// ------------------------------------------------------------
// Function 101/121: _Thrd_id
// Address: 0x180016140 - 0x180016146 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
_Thrd_id_t __cdecl Thrd_id()
{
  return _Thrd_id();
}


// ------------------------------------------------------------
// Function 102/121: _Thrd_join
// Address: 0x180016150 - 0x180016156 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl Thrd_join(_Thrd_t *a1, int *a2)
{
  return _Thrd_join(a1, a2);
}


// ------------------------------------------------------------
// Function 103/121: _CxxThrowException
// Address: 0x180016160 - 0x180016166 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __stdcall __noreturn CxxThrowException(void *pExceptionObject, _ThrowInfo *pThrowInfo)
{
  _CxxThrowException(pExceptionObject, pThrowInfo);
}


// ------------------------------------------------------------
// Function 104/121: __C_specific_handler
// Address: 0x180016170 - 0x180016176 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
}


// ------------------------------------------------------------
// Function 105/121: __std_exception_copy
// Address: 0x180016180 - 0x180016186 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
__int64 __fastcall _std_exception_copy(__int64 a1, __int64 a2)
{
  return __std_exception_copy(a1, a2);
}


// ------------------------------------------------------------
// Function 106/121: __std_exception_destroy
// Address: 0x180016190 - 0x180016196 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
__int64 __fastcall _std_exception_destroy(__int64 a1)
{
  return __std_exception_destroy(a1);
}


// ------------------------------------------------------------
// Function 107/121: __std_type_info_destroy_list
// Address: 0x1800161A0 - 0x1800161A6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
__int64 __fastcall _std_type_info_destroy_list(__int64 a1)
{
  return __std_type_info_destroy_list(a1);
}


// ------------------------------------------------------------
// Function 108/121: _callnewh
// Address: 0x1800161B0 - 0x1800161B6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl callnewh(size_t Size)
{
  return _callnewh(Size);
}


// ------------------------------------------------------------
// Function 109/121: _cexit
// Address: 0x1800161C0 - 0x1800161C6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __cdecl cexit()
{
  _cexit();
}


// ------------------------------------------------------------
// Function 110/121: _configure_narrow_argv
// Address: 0x1800161D0 - 0x1800161D6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
errno_t __cdecl configure_narrow_argv(_crt_argv_mode mode)
{
  return _configure_narrow_argv(mode);
}


// ------------------------------------------------------------
// Function 111/121: _crt_atexit
// Address: 0x1800161E0 - 0x1800161E6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl crt_atexit(_PVFV Function)
{
  return _crt_atexit(Function);
}


// ------------------------------------------------------------
// Function 112/121: _execute_onexit_table
// Address: 0x1800161F0 - 0x1800161F6 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl execute_onexit_table(_onexit_table_t *Table)
{
  return _execute_onexit_table(Table);
}


// ------------------------------------------------------------
// Function 113/121: _initialize_narrow_environment
// Address: 0x180016200 - 0x180016206 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl initialize_narrow_environment()
{
  return _initialize_narrow_environment();
}


// ------------------------------------------------------------
// Function 114/121: _initialize_onexit_table
// Address: 0x180016210 - 0x180016216 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl initialize_onexit_table(_onexit_table_t *Table)
{
  return _initialize_onexit_table(Table);
}


// ------------------------------------------------------------
// Function 115/121: _initterm
// Address: 0x180016220 - 0x180016226 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _initterm(First, Last);
}


// ------------------------------------------------------------
// Function 116/121: _initterm_e
// Address: 0x180016230 - 0x180016236 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl initterm_e(_PIFV *First, _PIFV *Last)
{
  return _initterm_e(First, Last);
}


// ------------------------------------------------------------
// Function 117/121: _register_onexit_function
// Address: 0x180016240 - 0x180016246 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl register_onexit_function(_onexit_table_t *Table, _onexit_t Function)
{
  return _register_onexit_function(Table, Function);
}


// ------------------------------------------------------------
// Function 118/121: _seh_filter_dll
// Address: 0x180016250 - 0x180016256 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
int __cdecl seh_filter_dll(unsigned int ExceptionNum, struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  return _seh_filter_dll(ExceptionNum, ExceptionPtr);
}


// ------------------------------------------------------------
// Function 119/121: free
// Address: 0x180016260 - 0x180016266 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void __cdecl free(void *Block)
{
  __imp_free(Block);
}


// ------------------------------------------------------------
// Function 120/121: malloc
// Address: 0x180016270 - 0x180016276 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void *__cdecl malloc(size_t Size)
{
  return __imp_malloc(Size);
}


// ------------------------------------------------------------
// Function 121/121: memcpy
// Address: 0x180016280 - 0x180016286 (size 0x6)
// ------------------------------------------------------------
// attributes: thunk
void *__cdecl memcpy(void *a1, const void *Src, size_t Size)
{
  return __imp_memcpy(a1, Src, Size);
}

