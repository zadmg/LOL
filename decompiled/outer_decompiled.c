// ============================================================
// Decompiled source of Outer PE (MJTVPFeD_dumped.exe)
// File: D:\SRC\SRC\MJTVPFeD_dumped.exe
// Image base: 0x7FF71BC60000
// Total functions: 17
// ============================================================


// ------------------------------------------------------------
// Function 1/17: sub_7FF71BC61F60
// Address: 0x7FF71BC61F60 - 0x7FF71BC61F70 (size 0x10)
// ------------------------------------------------------------
void __noreturn sub_7FF71BC61F60()
{
  sub_7FF71BC6A6F0(&unk_7FF71BC7A702);
  JUMPOUT(0x7FF71BC61F70LL);
}


// ------------------------------------------------------------
// Function 2/17: sub_7FF71BC61F80
// Address: 0x7FF71BC61F80 - 0x7FF71BC61FB6 (size 0x36)
// ------------------------------------------------------------
void __noreturn sub_7FF71BC61F80()
{
  _QWORD v0[3]; // [rsp+20h] [rbp-18h] BYREF

  v0[2] = 0;
  v0[1] = &unk_7FF71BC7A6E1;
  v0[0] = (char *)&byte_7FF71BC7A219 + 391;
  sub_7FF71BC6A730(v0, &unk_7FF71BC7C320);
  JUMPOUT(0x7FF71BC61FB6LL);
}


// ------------------------------------------------------------
// Function 3/17: sub_7FF71BC655E0
// Address: 0x7FF71BC655E0 - 0x7FF71BC6575A (size 0x17A)
// ------------------------------------------------------------
unsigned __int64 *__fastcall sub_7FF71BC655E0(unsigned __int64 *a1, unsigned __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v5; // r12
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // r13
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rdx
  __int64 v13; // rcx
  __int64 v14; // rax
  unsigned __int64 v15; // r14
  unsigned __int64 v16; // r15
  unsigned __int64 v17; // r12
  unsigned __int64 v18; // rdx

  v5 = a1[2];
  if ( 0x7FFFFFFFFFFFFFFELL - v5 < a2 )
    sub_7FF71BC61F60();
  v6 = v5 + a2;
  v7 = (v5 + a2) | 7;
  if ( v7 > 0x7FFFFFFFFFFFFFFELL )
    goto LABEL_20;
  v8 = a1[3];
  if ( v8 > 0x7FFFFFFFFFFFFFFELL - (v8 >> 1) )
    goto LABEL_20;
  v9 = v8 + (v8 >> 1);
  if ( v7 > v9 )
    v9 = (v5 + a2) | 7;
  v10 = v9 + 1;
  if ( (__int64)(v9 + 1) < 0 )
    goto LABEL_20;
  if ( v9 == -1 )
  {
    v15 = 0;
  }
  else
  {
    v13 = 2 * v10;
    if ( v10 >= 0x800 )
    {
      if ( v10 < 0x7FFFFFFFFFFFFFEDLL )
      {
        v14 = sub_7FF71BC689E0(v13 + 39);
        v15 = (v14 + 39) & 0xFFFFFFFFFFFFFFE0uLL;
        *(_QWORD *)(v15 - 8) = v14;
        goto LABEL_13;
      }
LABEL_20:
      sub_7FF71BC61F80();
    }
    v15 = sub_7FF71BC689E0(v13);
  }
LABEL_13:
  a1[2] = v6;
  a1[3] = v9;
  if ( v8 < 8 )
  {
    sub_7FF71BC6A790(v15, a1, 2 * v5);
    sub_7FF71BC6A790(v15 + 2 * v5, a3, 2 * a4);
    *(_WORD *)(v15 + 2 * v5 + 2 * a4) = 0;
  }
  else
  {
    v16 = *a1;
    sub_7FF71BC6A790(v15, *a1, 2 * v5);
    v17 = v15 + 2 * v5;
    sub_7FF71BC6A790(v17, a3, 2 * a4);
    *(_WORD *)(v17 + 2 * a4) = 0;
    v18 = 2 * v8 + 2;
    if ( v18 >= 0x1000 )
    {
      if ( v16 - 8 - *(_QWORD *)(v16 - 8) >= 0x20 )
        BUG();
      v18 = 2 * v8 + 41;
      v16 = *(_QWORD *)(v16 - 8);
    }
    sub_7FF71BC68A30(v16, v18);
  }
  *a1 = v15;
  return a1;
}


// ------------------------------------------------------------
// Function 4/17: sub_7FF71BC65CE0
// Address: 0x7FF71BC65CE0 - 0x7FF71BC662B5 (size 0x5D5)
// ------------------------------------------------------------
unsigned __int16 **__fastcall sub_7FF71BC65CE0(unsigned __int16 **a1, unsigned __int16 ***a2)
{
  signed __int64 v3; // rdi
  unsigned __int16 **v4; // rax
  unsigned int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // rcx
  unsigned int v8; // ecx
  int v9; // r8d
  int v10; // r8d
  int v11; // r8d
  int v12; // ecx
  unsigned __int16 **v13; // rbx
  __int64 v14; // rbx
  unsigned __int16 **v15; // rcx
  __int64 v16; // r11
  unsigned __int16 *v17; // r15
  char *v18; // rbp
  unsigned int v19; // r8d
  unsigned int v20; // r8d
  int v21; // r9d
  int v22; // r9d
  unsigned __int16 **v23; // r9
  int v24; // r10d
  int v25; // r8d
  __int64 v26; // r9
  int v27; // r8d
  unsigned __int16 *v28; // r12
  unsigned __int16 **v29; // r14
  int v30; // eax
  __int64 v31; // rbp
  unsigned __int16 **v32; // rax
  unsigned int v33; // r8d
  unsigned __int64 v34; // r15
  unsigned __int64 v35; // rdi
  __int64 v36; // r13
  unsigned __int16 **v37; // r14
  char *v38; // rsi
  unsigned __int16 **v39; // rbp
  unsigned __int16 *v40; // rbx
  __int64 v41; // r12
  __int64 v42; // rax
  bool v43; // zf
  unsigned __int16 **v44; // rdx
  unsigned __int16 *v45; // rax
  int v46; // eax
  unsigned int v47; // r8d
  int v48; // edx
  int v49; // edx
  int v50; // edx
  unsigned __int16 *v51; // rax
  unsigned __int16 *v52; // rcx
  unsigned __int16 **v53; // rdx
  __int64 v54; // r12
  unsigned __int16 *v55; // rax
  unsigned __int16 *v56; // rcx
  int v58; // edx
  __int64 v59; // rdi
  int v60; // edx
  unsigned __int16 **v61; // [rsp+20h] [rbp-58h]
  unsigned __int16 *v62; // [rsp+28h] [rbp-50h]

  v3 = (signed __int64)a2[2];
  v4 = (unsigned __int16 **)a2;
  if ( (unsigned __int64)a2[3] >= 8 )
    v4 = *a2;
  if ( (unsigned __int64)v3 < 2 )
    goto LABEL_37;
  v5 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 0xFFFFFFDF) - 3801153 <= 0x19 )
  {
    if ( v3 >= 3 )
    {
      v6 = *((unsigned __int16 *)v4 + 2);
      if ( v6 == 47 || v6 == 92 )
        goto LABEL_8;
    }
    goto LABEL_37;
  }
  if ( v3 < 2 || (_WORD)v5 != 92 && (unsigned __int16)v5 != 47 )
    goto LABEL_37;
  v8 = HIWORD(v5);
  if ( (unsigned __int64)v3 < 4 )
  {
    if ( v3 == 2 )
      goto LABEL_37;
    goto LABEL_25;
  }
  v9 = *((unsigned __int16 *)v4 + 3);
  if ( v9 != 92 && v9 != 47 || v3 != 4 && ((v10 = *((unsigned __int16 *)v4 + 4), v10 == 47) || v10 == 92) )
  {
LABEL_25:
    if ( (_WORD)v8 != 92 && (unsigned __int16)v8 != 47 )
      goto LABEL_37;
    v12 = *((unsigned __int16 *)v4 + 2);
    if ( v12 == 47 || v12 == 92 )
      goto LABEL_37;
    goto LABEL_8;
  }
  if ( (_WORD)v8 != 47 && (unsigned __int16)v8 != 92 )
  {
    if ( (unsigned __int16)v8 == 63 )
    {
      LOWORD(v11) = *((_WORD *)v4 + 2);
      goto LABEL_36;
    }
LABEL_37:
    v14 = (__int64)a1[2];
    v15 = a1;
    if ( (unsigned __int64)a1[3] >= 8 )
      v15 = (unsigned __int16 **)*a1;
    v16 = 2 * v14;
    v17 = (unsigned __int16 *)v15 + v14;
    v18 = (char *)v15;
    if ( v14 >= 2 )
    {
      v19 = *(_DWORD *)v15;
      if ( (*(_DWORD *)v15 & 0xFFFFFFDF) - 3801153 <= 0x19 )
      {
        v18 = (char *)v15 + 4;
        goto LABEL_71;
      }
      if ( (_WORD)v19 == 92 || (v18 = (char *)v15, (unsigned __int16)v19 == 47) )
      {
        v20 = HIWORD(v19);
        if ( (unsigned __int64)v14 < 4 )
        {
          v18 = (char *)v15;
          if ( v14 == 2 )
            goto LABEL_71;
        }
        else
        {
          v21 = *((unsigned __int16 *)v15 + 3);
          if ( v21 == 92 || v21 == 47 )
          {
            if ( v14 == 4 || (v22 = *((unsigned __int16 *)v15 + 4), v22 != 47) && v22 != 92 )
            {
              v23 = (unsigned __int16 **)((char *)v15 + 6);
              if ( (_WORD)v20 != 47 && (unsigned __int16)v20 != 92 )
              {
                v18 = (char *)v15;
                if ( (unsigned __int16)v20 != 63 )
                  goto LABEL_71;
                LOWORD(v24) = *((_WORD *)v15 + 2);
                goto LABEL_68;
              }
              v24 = *((unsigned __int16 *)v15 + 2);
              if ( v24 == 46 || v24 == 63 )
              {
LABEL_70:
                v18 = (char *)v23;
                goto LABEL_71;
              }
              if ( v20 == 63 )
              {
LABEL_68:
                if ( (_WORD)v24 != 63 )
                  v23 = v15;
                goto LABEL_70;
              }
            }
          }
        }
        if ( (_WORD)v20 == 92 || (v18 = (char *)v15, (unsigned __int16)v20 == 47) )
        {
          v25 = *((unsigned __int16 *)v15 + 2);
          v18 = (char *)v15;
          if ( v25 != 47 )
          {
            v18 = (char *)v15;
            if ( v25 != 92 )
            {
              v18 = (char *)v15 + 6;
              if ( v14 != 3 )
              {
                v26 = v16 - 6;
                while ( 1 )
                {
                  v27 = *(unsigned __int16 *)v18;
                  if ( v27 == 47 || v27 == 92 )
                    break;
                  v18 += 2;
                  v26 -= 2;
                  if ( !v26 )
                  {
                    v18 = (char *)v15 + 2 * v14;
                    break;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_71:
    v28 = (unsigned __int16 *)v4 + v3;
    if ( v3 < 2 )
    {
LABEL_72:
      v29 = v4;
      goto LABEL_73;
    }
    v33 = *(_DWORD *)v4;
    if ( (*(_DWORD *)v4 & 0xFFFFFFDF) - 3801153 <= 0x19 )
    {
      v29 = (unsigned __int16 **)((char *)v4 + 4);
      goto LABEL_82;
    }
    if ( (_WORD)v33 != 92 && (unsigned __int16)v33 != 47 )
      goto LABEL_72;
    v47 = HIWORD(v33);
    if ( (unsigned __int64)v3 < 4 )
    {
      if ( v3 == 2 )
        goto LABEL_72;
    }
    else
    {
      v48 = *((unsigned __int16 *)v4 + 3);
      if ( v48 == 92 || v48 == 47 )
      {
        if ( v3 == 4 || (v49 = *((unsigned __int16 *)v4 + 4), v49 != 47) && v49 != 92 )
        {
          v29 = (unsigned __int16 **)((char *)v4 + 6);
          if ( (_WORD)v47 != 47 && (unsigned __int16)v47 != 92 )
          {
            if ( (unsigned __int16)v47 != 63 )
              goto LABEL_72;
            LOWORD(v50) = *((_WORD *)v4 + 2);
            goto LABEL_136;
          }
          v50 = *((unsigned __int16 *)v4 + 2);
          if ( v50 == 46 || v50 == 63 )
          {
LABEL_82:
            v61 = v29;
            v62 = (unsigned __int16 *)v15 + v14;
            v34 = ((char *)v29 - (char *)v4) >> 1;
            v35 = (v18 - (char *)v15) >> 1;
            v36 = v35;
            if ( v34 < v35 )
              v36 = ((char *)v29 - (char *)v4) >> 1;
            v37 = a1;
            v38 = v18;
            v39 = v15;
            v40 = v28;
            v41 = v16;
            sub_7FF71BC69820();
            v15 = v39;
            v18 = v38;
            a1 = v37;
            v29 = v61;
            v43 = v35 == v34;
            v17 = v62;
            if ( !v43 || (v16 = v41, v28 = v40, v42 != v36) )
            {
              v44 = (unsigned __int16 **)a2;
              if ( a1 == (unsigned __int16 **)a2 )
                return a1;
              v3 = (signed __int64)a2[2];
              if ( (unsigned __int64)a2[3] >= 8 )
                v44 = *a2;
              v45 = a1[3];
              if ( v3 > (unsigned __int64)v45 )
              {
                sub_7FF71BC662C0((unsigned __int64 *)a1, v3, (__int64)v44);
                return a1;
              }
              v13 = a1;
              if ( (unsigned __int64)v45 >= 8 )
                v13 = (unsigned __int16 **)*a1;
              a1[2] = (unsigned __int16 *)v3;
              goto LABEL_117;
            }
LABEL_73:
            if ( v29 != (unsigned __int16 **)v28 )
            {
              v30 = *(unsigned __int16 *)v29;
              if ( v30 == 92 || v30 == 47 )
              {
                v31 = v18 - (char *)v15;
                if ( (unsigned __int64)a1[2] < v31 >> 1 )
                  sub_7FF71BC663E0();
                a1[2] = (unsigned __int16 *)(v31 >> 1);
                v32 = a1;
                if ( (unsigned __int64)a1[3] >= 8 )
                  v32 = (unsigned __int16 **)*a1;
                *(_WORD *)((char *)v32 + v31) = 0;
                goto LABEL_113;
              }
            }
            if ( v18 == (char *)v17 )
            {
              if ( v16 >= 5 )
                goto LABEL_108;
            }
            else
            {
              v46 = *(v17 - 1);
              if ( v46 != 47 && v46 != 92 )
              {
LABEL_108:
                v51 = a1[2];
                v52 = a1[3];
                if ( v51 >= v52 )
                {
                  sub_7FF71BC66400((unsigned __int64 *)a1);
                }
                else
                {
                  a1[2] = (unsigned __int16 *)((char *)v51 + 1);
                  v53 = a1;
                  if ( (unsigned __int64)v52 >= 8 )
                    v53 = (unsigned __int16 **)*a1;
                  *((_WORD *)v53 + (_QWORD)v51) = 92;
                  *((_WORD *)v53 + (_QWORD)v51 + 1) = 0;
                }
              }
            }
LABEL_113:
            v54 = (char *)v28 - (char *)v29;
            v55 = a1[2];
            v56 = a1[3];
            if ( v54 >> 1 > (unsigned __int64)((char *)v56 - (char *)v55) )
            {
              sub_7FF71BC655E0((unsigned __int64 *)a1, v54 >> 1, (__int64)v29, v54 >> 1);
              return a1;
            }
            v3 = (signed __int64)v55 + (v54 >> 1);
            a1[2] = (unsigned __int16 *)v3;
            v13 = a1;
            if ( (unsigned __int64)v56 >= 8 )
              v13 = (unsigned __int16 **)*a1;
            goto LABEL_117;
          }
          if ( v47 == 63 )
          {
LABEL_136:
            if ( (_WORD)v50 != 63 )
              v29 = v4;
            if ( v4 == v29 )
              goto LABEL_73;
            goto LABEL_82;
          }
        }
      }
    }
    if ( (_WORD)v47 != 92 && (unsigned __int16)v47 != 47 )
      goto LABEL_72;
    v58 = *((unsigned __int16 *)v4 + 2);
    if ( v58 == 47 || v58 == 92 )
      goto LABEL_72;
    v29 = (unsigned __int16 **)((char *)v4 + 6);
    if ( v3 != 3 )
    {
      v59 = 2 * v3 - 6;
      while ( 1 )
      {
        v60 = *(unsigned __int16 *)v29;
        if ( v60 == 47 || v60 == 92 )
          break;
        v29 = (unsigned __int16 **)((char *)v29 + 2);
        v59 -= 2;
        if ( !v59 )
        {
          v29 = (unsigned __int16 **)v28;
          goto LABEL_82;
        }
      }
    }
    goto LABEL_82;
  }
  v11 = *((unsigned __int16 *)v4 + 2);
  if ( v11 != 46 && v11 != 63 )
  {
    if ( v8 == 63 )
    {
LABEL_36:
      if ( (_WORD)v11 == 63 )
        goto LABEL_8;
      goto LABEL_37;
    }
    goto LABEL_25;
  }
LABEL_8:
  if ( a1 != (unsigned __int16 **)a2 )
  {
    v7 = a1[3];
    if ( v3 > (unsigned __int64)v7 )
    {
      sub_7FF71BC662C0((unsigned __int64 *)a1, (unsigned __int64)a2[2], (__int64)v4);
      return a1;
    }
    v13 = a1;
    if ( (unsigned __int64)v7 >= 8 )
      v13 = (unsigned __int16 **)*a1;
    a1[2] = (unsigned __int16 *)v3;
LABEL_117:
    sub_7FF71BC6A7A0();
    *((_WORD *)v13 + v3) = 0;
  }
  return a1;
}


// ------------------------------------------------------------
// Function 5/17: sub_7FF71BC662C0
// Address: 0x7FF71BC662C0 - 0x7FF71BC663DC (size 0x11C)
// ------------------------------------------------------------
unsigned __int64 *__fastcall sub_7FF71BC662C0(unsigned __int64 *a1, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v5; // r15
  unsigned __int64 v6; // r12
  unsigned __int64 v7; // rdx
  __int64 v9; // rcx
  __int64 v10; // rax
  unsigned __int64 v11; // r14
  __int64 v12; // rcx
  unsigned __int64 v13; // rdx

  if ( a2 > 0x7FFFFFFFFFFFFFFELL )
    sub_7FF71BC61F60();
  if ( (a2 | 7) > 0x7FFFFFFFFFFFFFFELL )
    goto LABEL_17;
  v5 = a1[3];
  if ( v5 > 0x7FFFFFFFFFFFFFFELL - (v5 >> 1) )
    goto LABEL_17;
  v6 = v5 + (v5 >> 1);
  if ( (a2 | 7) > v6 )
    v6 = a2 | 7;
  v7 = v6 + 1;
  if ( (__int64)(v6 + 1) < 0 )
    goto LABEL_17;
  v9 = 2 * v7;
  if ( v7 >= 0x800 )
  {
    if ( v7 < 0x7FFFFFFFFFFFFFEDLL )
    {
      v10 = sub_7FF71BC689E0(v9 + 39);
      v11 = (v10 + 39) & 0xFFFFFFFFFFFFFFE0uLL;
      *(_QWORD *)(v11 - 8) = v10;
      goto LABEL_11;
    }
LABEL_17:
    sub_7FF71BC61F80();
  }
  v11 = sub_7FF71BC689E0(v9);
LABEL_11:
  a1[2] = a2;
  a1[3] = v6;
  sub_7FF71BC6A790(v11, a3, 2 * a2);
  *(_WORD *)(v11 + 2 * a2) = 0;
  if ( v5 >= 8 )
  {
    v12 = *a1;
    v13 = 2 * v5 + 2;
    if ( v13 >= 0x1000 )
    {
      if ( (unsigned __int64)(v12 - 8 - *(_QWORD *)(v12 - 8)) >= 0x20 )
        BUG();
      v13 = 2 * v5 + 41;
      v12 = *(_QWORD *)(v12 - 8);
    }
    sub_7FF71BC68A30(v12, v13);
  }
  *a1 = v11;
  return a1;
}


// ------------------------------------------------------------
// Function 6/17: sub_7FF71BC663E0
// Address: 0x7FF71BC663E0 - 0x7FF71BC663F0 (size 0x10)
// ------------------------------------------------------------
void __noreturn sub_7FF71BC663E0()
{
  ((void (__fastcall *)(void *))((char *)&loc_7FF71BC6A6FA + 6))(&unk_7FF71BC7A6A0);
  JUMPOUT(0x7FF71BC663F0LL);
}


// ------------------------------------------------------------
// Function 7/17: sub_7FF71BC66400
// Address: 0x7FF71BC66400 - 0x7FF71BC66541 (size 0x141)
// ------------------------------------------------------------
unsigned __int64 *__fastcall sub_7FF71BC66400(unsigned __int64 *a1)
{
  unsigned __int64 v1; // r14
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  unsigned __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v8; // rax
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rdx

  v1 = a1[2];
  if ( v1 == 0x7FFFFFFFFFFFFFFELL )
    sub_7FF71BC61F60();
  v3 = (v1 + 1) | 7;
  if ( v3 > 0x7FFFFFFFFFFFFFFELL )
    goto LABEL_20;
  v4 = a1[3];
  if ( v4 > 0x7FFFFFFFFFFFFFFELL - (v4 >> 1) )
    goto LABEL_20;
  v5 = v4 + (v4 >> 1);
  if ( v3 > v5 )
    v5 = (v1 + 1) | 7;
  v6 = v5 + 1;
  if ( (__int64)(v5 + 1) < 0 )
    goto LABEL_20;
  if ( v5 == -1 )
  {
    v9 = 0;
  }
  else
  {
    v7 = 2 * v6;
    if ( v6 >= 0x800 )
    {
      if ( v6 < 0x7FFFFFFFFFFFFFEDLL )
      {
        v8 = sub_7FF71BC689E0(v7 + 39);
        v9 = (v8 + 39) & 0xFFFFFFFFFFFFFFE0uLL;
        *(_QWORD *)(v9 - 8) = v8;
        goto LABEL_13;
      }
LABEL_20:
      sub_7FF71BC61F80();
    }
    v9 = sub_7FF71BC689E0(v7);
  }
LABEL_13:
  a1[2] = v1 + 1;
  a1[3] = v5;
  if ( v4 < 8 )
  {
    sub_7FF71BC6A790(v9, a1, 2 * v1);
    *(_DWORD *)(v9 + 2 * v1) = 92;
  }
  else
  {
    v10 = *a1;
    sub_7FF71BC6A790(v9, *a1, 2 * v1);
    *(_DWORD *)(v9 + 2 * v1) = 92;
    v11 = 2 * v4 + 2;
    if ( v11 >= 0x1000 )
    {
      if ( v10 - 8 - *(_QWORD *)(v10 - 8) >= 0x20 )
        BUG();
      v11 = 2 * v4 + 41;
      v10 = *(_QWORD *)(v10 - 8);
    }
    sub_7FF71BC68A30(v10, v11);
  }
  *a1 = v9;
  return a1;
}


// ------------------------------------------------------------
// Function 8/17: sub_7FF71BC689E0
// Address: 0x7FF71BC689E0 - 0x7FF71BC68A23 (size 0x43)
// ------------------------------------------------------------
__int64 __fastcall sub_7FF71BC689E0(__int64 a1)
{
  __int64 result; // rax

  for ( result = ((__int64 (*)(void))sub_7FF71BC6A7D0)(); !result; result = sub_7FF71BC6A7D0(a1) )
  {
    if ( !(unsigned int)sub_7FF71BC6A830(a1) )
    {
      if ( a1 != -1 )
      {
        sub_7FF71BC69AA0();
        __debugbreak();
      }
      sub_7FF71BC69AC0();
      JUMPOUT(0x7FF71BC68A23LL);
    }
  }
  return result;
}


// ------------------------------------------------------------
// Function 9/17: sub_7FF71BC68A30
// Address: 0x7FF71BC68A30 - 0x7FF71BC68A35 (size 0x5)
// ------------------------------------------------------------
// attributes: thunk
void __fastcall sub_7FF71BC68A30()
{
  JUMPOUT(0x7FF71BC69AE0LL);
}


// ------------------------------------------------------------
// Function 10/17: start
// Address: 0x7FF71BC69770 - 0x7FF71BC69793 (size 0x23)
// ------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned __int64 __fastcall start(__int64 a1, __int64 a2, int *a3)
{
  __int64 v4; // [rsp-18h] [rbp-18h] BYREF

  *((_BYTE *)a3 - 117) = __ROR1__(*((_BYTE *)a3 - 117), 77);
  return sub_7FF71BC6A0E0((unsigned __int64)&v4 ^ a1, a2, a3);
}


// ------------------------------------------------------------
// Function 11/17: sub_7FF71BC69820
// Address: 0x7FF71BC69820 - 0x7FF71BC69825 (size 0x5)
// ------------------------------------------------------------
// attributes: thunk
void __fastcall sub_7FF71BC69820()
{
  JUMPOUT(0x7FF71BC69830LL);
}


// ------------------------------------------------------------
// Function 12/17: sub_7FF71BC699A0
// Address: 0x7FF71BC699A0 - 0x7FF71BC69A04 (size 0x64)
// ------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_7FF71BC699A0()
{
  int v0; // ebx
  unsigned int v1; // ebp
  _QWORD *v2; // rsi
  int v3; // r14d
  unsigned int v4; // edi
  __int64 result; // rax
  int v6; // [rsp+18h] [rbp+18h] BYREF

  v4 = MEMORY[0x1B0FE](4864, 0, v1);
  while ( ++v0 < 3 && !v4 )
  {
    if ( !v0 )
    {
      v6 = 1033;
      goto LABEL_14;
    }
    if ( v0 != 1 )
    {
      v6 = v3;
LABEL_14:
      JUMPOUT(0x7FF71BC6999FLL);
    }
    if ( (unsigned int)MEMORY[0x1B166](&unk_7FF71BC7A7D8, 536870913, &v6, 2) )
      goto LABEL_14;
  }
  result = v4;
  if ( v4 )
  {
    do
    {
      if ( byte_7FF71BC6D150[*(unsigned __int8 *)(*v2 + result - 1)] == (_BYTE)v3 )
        break;
      --result;
    }
    while ( result );
  }
  return result;
}


// ------------------------------------------------------------
// Function 13/17: sub_7FF71BC6A0D0
// Address: 0x7FF71BC6A0D0 - 0x7FF71BC6A0D7 (size 0x7)
// ------------------------------------------------------------
void __noreturn sub_7FF71BC6A0D0()
{
  __fastfail(2u);
}


// ------------------------------------------------------------
// Function 14/17: sub_7FF71BC6A0E0
// Address: 0x7FF71BC6A0E0 - 0x7FF71BC6A2FE (size 0x21E)
// ------------------------------------------------------------
unsigned __int64 __fastcall sub_7FF71BC6A0E0(unsigned __int64 a1, __int64 a2, int *a3)
{
  __int64 v3; // rsi
  unsigned __int64 v5; // r10
  _BYTE *v6; // r8
  unsigned int v7; // ecx
  unsigned __int8 v8; // r9
  unsigned int v9; // r11d
  __int64 v10; // r9
  unsigned int v11; // edx
  unsigned __int8 *v12; // r8
  unsigned int i; // ecx
  unsigned int v14; // eax
  __int64 v15; // rax
  int v16; // ebx
  unsigned __int8 v17; // al
  char v18; // dl
  unsigned __int8 v19; // dl
  __int64 v20; // rax
  unsigned __int64 result; // rax
  __int64 v22; // rcx

  v3 = *a3;
  if ( (v3 & 4) != 0 )
    v5 = -a3[2] & (a1 + a3[1]);
  else
    v5 = a1;
  v6 = (_BYTE *)(*(_QWORD *)(a2 + 8) + *(unsigned int *)(*(_QWORD *)(a2 + 16) + 8LL));
  v7 = (unsigned __int8)v6[3];
  if ( (*v6 & 7u) < 3 )
  {
    if ( (v7 & 0xF) != 0 )
    {
      v8 = v6[3];
      goto LABEL_32;
    }
    goto LABEL_8;
  }
  v9 = v7 & 0x1F;
  if ( (v7 & 0x1F) == 0 )
  {
LABEL_8:
    v10 = 0;
    goto LABEL_33;
  }
  v10 = 0;
  v11 = v7 >> 5;
  v12 = &v6[(v7 & 0x1F) + 4];
  for ( i = 0; i < v11; ++i )
  {
    v14 = *v12;
    v12 += 3;
    v15 = v14 >> 3;
    if ( (_DWORD)v15 )
      v12 += v15 + 3;
  }
  v16 = 0;
  if ( !v9 )
    goto LABEL_33;
  while ( 1 )
  {
    v17 = *v12;
    v18 = *v12;
    if ( *v12 > 3u )
    {
      v18 = v17 & 0xF;
      if ( (unsigned __int8)((v17 & 0xF) - 8) > 2u )
      {
        v18 = v17 & 7;
        if ( (unsigned __int8)((v17 & 7) - 4) > 3u )
        {
LABEL_21:
          v17 &= 0x3Fu;
          if ( v17 != 32 )
            sub_7FF71BC6A0D0();
          goto LABEL_24;
        }
      }
    }
    if ( !v18 )
      break;
    if ( v17 > 3u )
    {
      v19 = v17 & 0xF;
      if ( (unsigned __int8)((v17 & 0xF) - 8) > 2u )
      {
        v19 = v17 & 7;
        if ( (unsigned __int8)((v17 & 7) - 4) > 3u )
          goto LABEL_21;
      }
      v17 = v19;
    }
LABEL_24:
    switch ( v17 )
    {
      case 0u:
      case 3u:
      case 0x20u:
        v20 = 2;
        break;
      case 1u:
      case 5u:
      case 9u:
        v20 = 5;
        break;
      case 2u:
      case 6u:
      case 0xAu:
        v20 = 3;
        break;
      case 4u:
      case 7u:
      case 8u:
        v20 = 1;
        break;
    }
    v12 += v20;
    if ( ++v16 >= v9 )
      goto LABEL_33;
  }
  v8 = v12[1];
LABEL_32:
  v10 = v8 & 0xF0;
LABEL_33:
  result = v3 & 0xFFFFFFFFFFFFFFF8uLL;
  v22 = *(_QWORD *)((v3 & 0xFFFFFFFFFFFFFFF8uLL) + v5) ^ (v10 + a1);
  if ( v22 != qword_7FF71BC7CE40 || (unsigned __int16)__ROL8__(v22, 16) )
    sub_7FF71BC6A0D0();
  return result;
}


// ------------------------------------------------------------
// Function 15/17: sub_7FF71BC6A710
// Address: 0x7FF71BC6A710 - 0x7FF71BC6A730 (size 0x20)
// ------------------------------------------------------------
void __fastcall sub_7FF71BC6A710(__int64 a1, __int64 a2)
{
  _QWORD *v2; // rbx
  unsigned __int64 v3; // rdi

  do
  {
    if ( *v2 )
      sub_7FF71BC699A0();
    ++v2;
  }
  while ( (unsigned __int64)v2 < v3 );
  sub_7FF71BC6A730(a1, a2);
}


// ------------------------------------------------------------
// Function 16/17: sub_7FF71BC6A790
// Address: 0x7FF71BC6A790 - 0x7FF71BC6A7A0 (size 0x10)
// ------------------------------------------------------------
__int64 sub_7FF71BC6A790()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  return sub_7FF71BC6A7A0();
}


// ------------------------------------------------------------
// Function 17/17: sub_7FF71BC6A7A0
// Address: 0x7FF71BC6A7A0 - 0x7FF71BC6A7A2 (size 0x2)
// ------------------------------------------------------------
__int64 __fastcall sub_7FF71BC6A7A0()
{
  __int64 (*v0)(void); // rax

  return v0();
}

