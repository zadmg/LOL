# MJTVPFeD.dat 辅助程序分析报告

## 1. 概述

`MJTVPFeD.dat` 是由 `16.13.exe`(走砍) 在登录绕过后释放并执行的辅助主体程序。
该文件是一个 **64 位 PE 文件**(自删除型启动器),其内部**嵌入两个 UPX 加壳的 DLL 负载**,
专门针对 **League of Legends(英雄联盟)** 的 `LeagueClient.exe` 进行 DLL 劫持注入,
实现按键连发、技能快捷键、视角控制、游戏内存读取等辅助功能。

### 文件信息
| 项目 | 值 |
|------|----|
| 文件名 | `MJTVPFeD.dat` |
| 类型 | PE32+ (x64) EXE |
| 大小 | 131,072 字节(内存 dump 后) |
| 镜像基址 | `0x7FF71BC60000` |
| 来源 | 16.13.exe 登录成功后释放并启动 |
| 行为 | 启动后自删除文件,弹出 cmd 窗口提示"注册表获取Game目录失败,将通过游戏进程获取目录" |
| 目标 | League of Legends (`LeagueClient.exe`) |
| 释放目录 | `C:\Users\Public\FlyPY\` |
| 释放 DLL | `flyinput.dll`(主辅助) + `dbgcore.dll`(劫持器) |

---

## 2. 整体架构

MJTVPFeD.dat 内部结构为 **三层嵌套**:

```
┌─────────────────────────────────────────────────┐
│  外层 EXE (MJTVPFeD.dat, 131KB)                  │
│  - std::filesystem 路径操作                      │
│  - 注册表读取 Software\Tencent\LOL              │
│  - 进程枚举查找 LeagueClient.exe                │
│  - 释放 flyinput.dll + dbgcore.dll 到 FlyPY 目录 │
│  - ShellExecuteA 启动注入                        │
│  - 启动后自删除                                   │
├─────────────────────────────────────────────────┤
│  嵌入 PE #1 (offset 0xC7F0, UPX→10KB)          │
│  - DLL 类型,导出 MiniDumpWriteDump /            │
│    MiniDumpReadDumpStream                        │
│  - DLL 劫持核心:加载真 dbgcore.dll 转发调用     │
│  - 同时加载 C:\Users\Public\FlyPY\flyinput.dll   │
├─────────────────────────────────────────────────┤
│  嵌入 PE #2 (offset 0xFFD0, UPX→96KB)          │
│  - DLL 类型(flyinput.dll)                       │
│  - 主辅助逻辑                                    │
│  - 反调试:NtSetInformationThread(17)            │
│  - 按键监听:GetAsyncKeyState (空格/V/C/方向键等) │
│  - 按键连发:SetTimer + SendInput                │
│  - 游戏内存读取:基于偏移访问英雄/技能数据       │
│  - FNV-1a 哈希查找游戏对象                       │
└─────────────────────────────────────────────────┘
```

### 嵌入 PE 提取结果

在 MJTVPFeD_dumped.exe 中搜索 MZ 头,找到 3 个有效 PE:

| # | 偏移 | 原始大小 | 解壳后 | 类型 | 说明 |
|---|------|---------|--------|------|------|
| 0 | 0x0 | 51184 B | - | 外层 EXE | 6 段(.text/.rdata/.data/.pdata/.rsrc/.reloc),非 UPX |
| 1 | 0xC7F0 | 6656 B | 10240 B | UPX DLL | 假 dbgcore.dll,导出 MiniDump* |
| 2 | 0xFFD0 | 31232 B | 96256 B | UPX DLL | flyinput.dll,辅助主体 |

UPX 解壳使用 `D:\SRC\Tools\upx-4.2.4-win64\upx.exe -d`,两个嵌入 PE 均成功解壳。

---

## 3. 外层 EXE 分析(MJTVPFeD.dat 主体)

### 3.1 段结构
| 段名 | 起始地址 | 大小 | 说明 |
|------|---------|------|------|
| .text | 0x7FF71BC61000 | 0x9000 | 代码段 |
| .rdata | 0x7FF71BC6A000 | 0x10218 | 只读数据(含嵌入 PE) |
| .idata | 0x7FF71BC7A218 | 0x458 | 导入表 |
| .rdata | 0x7FF71BC7A670 | 0x1990 | 只读数据(证书) |
| .data | 0x7FF71BC7C000 | 0x1000 | 可读写数据 |
| .pdata | 0x7FF71BC7D000 | 0x1000 | 异常处理表 |

### 3.2 导入 API(来自 .idata 字符串扫描)
**进程操作**:
- `CreateToolhelp32Snapshot` - 创建进程快照
- `Process32First` / `Process32Next` - 遍历进程
- `OpenProcess` - 打开进程
- `QueryFullProcessImageNameA` - 获取进程完整路径

**注册表操作**:
- `RegOpenKeyExA` - 打开注册表键
- `RegQueryValueExA` - 查询注册表值

**文件/执行**:
- `CreateFileA` - 创建/打开文件
- `WriteFile` - 写文件
- `ShellExecuteA` - 执行程序
- `CreateProcessA` - 创建进程

**动态加载**:
- `LoadLibraryA` - 加载 DLL
- `GetProcAddress` - 获取函数地址
- `VirtualProtect` - 修改内存保护

**其他**:
- `MessageBoxA` - 消息框(错误提示)
- `MiniDumpWriteDump` / `MiniDumpReadDumpStream` - 与 dbgcore 相关

### 3.3 关键字符串
| 地址 | 字符串 | 用途 |
|------|--------|------|
| 0x7FF71BC6D5E0 | `LeagueClient.exe` | 目标游戏进程名 |
| 0x7FF71BC6E13E | `C:\Users\Public\FlyPY\f` | 释放路径(拼接 flyinput.dll) |
| 0x7FF71BC6EF8C | `dbgcore.dll` | 劫持目标 DLL |
| 0x7FF71BC7A8BD | `flyinput.dll` | 主辅助 DLL |
| 0x7FF71BC7A91E | `C:/Users/Public/FlyPY` | 释放目录(Unix 风格) |
| 0x7FF71BC7A934 | `Software\Tencent\LOL` | 注册表游戏路径键 |
| 0x7FF71BC7A7B7 | `LeagueClient` | 进程名匹配关键字 |
| 0x7FF71BC7A7E8 | ` dbgcore ` | DLL 劫持标识 |
| 0x7FF71BC7A7FC | ` FlyPY ` | 释放目录标识 |

### 3.4 证书信息(自签名)
文件内嵌 Pikachu 自签名证书链(用于绕过数字签名验证):
```
CN = Pikachu Trust Network CA
CN = Pikachu Certification Authority
CN = Pikachu Test CA RSA1
E = testca@certs.us.kg
有效期: 2015-04-01 ~ 2099-12-31
```
同时还包含 **Thawte** 根证书和代码签名证书(`thawte SHA256 Code Signing CA`),
可能是为了伪装合法签名链。

### 3.5 主工作流程(推断)
1. **启动**: 由 16.13.exe 通过 CreateProcessA 或 ShellExecuteA 启动
2. **自删除**: 启动后立即删除自身文件 MJTVPFeD.dat
3. **获取游戏目录**:
   - 方案 A: 读注册表 `HKLM\Software\Tencent\LOL`(可能含 InstallPath 值)
   - 方案 B(回退): 用 `CreateToolhelp32Snapshot` 遍历进程,匹配 `LeagueClient.exe`,
     通过 `OpenProcess` + `QueryFullProcessImageNameA` 获取其完整路径
   - 若两者都失败,弹出 cmd 窗口提示:"注册表获取Game目录失败,将通过游戏进程获取目录。
     进入游戏大厅后按任意键继续..."
4. **释放 DLL**: 在 `C:\Users\Public\FlyPY\` 创建目录并释放:
   - `flyinput.dll`(嵌入 PE #2 解壳后写入)
   - `dbgcore.dll`(嵌入 PE #1 解壳后写入)
5. **注入触发**: 等待游戏启动,利用 LeagueClient.exe 加载 dbgcore.dll 的时机,
   让假的 dbgcore.dll 被加载,再由假 dbgcore.dll 加载 flyinput.dll
6. **辅助运行**: flyinput.dll 在游戏进程中执行辅助逻辑

---

## 4. 嵌入 PE #1 分析(假 dbgcore.dll - DLL 劫持器)

### 4.1 基本信息
| 项目 | 值 |
|------|----|
| 文件 | `embedded_1_at_0xC7F0.exe_unpacked.exe` |
| 类型 | PE32+ DLL |
| 大小 | 10240 字节(UPX 解壳后) |
| 镜像基址 | 0x180000000 |
| 入口点 | 0xFFFFFFFFFFFFFFFF(DLL 无标准入口) |
| 函数数 | 37 |
| 导出 | `MiniDumpWriteDump`, `MiniDumpReadDumpStream` |

### 4.2 导入表
| 模块 | 导入函数 |
|------|---------|
| KERNEL32 | `DisableThreadLibraryCalls`, `ExitProcess`, `FreeLibrary`, `GetCurrentProcessId`, `GetCurrentThreadId`, `GetProcAddress`, `GetSystemDirectoryA`, `GetSystemTimeAsFileTime`, `InitializeSListHead`, `LoadLibraryA`, `QueryPerformanceCounter`, `lstrcatA` |
| USER32 | `MessageBoxA` |
| VCRUNTIME140 | `__C_specific_handler`, `__std_type_info_destroy_list`, `memcpy` |
| api-ms-win-crt-heap | `calloc`, `free` |
| api-ms-win-crt-runtime | `_cexit`, `_configure_narrow_argv`, `_crt_atexit`, `_execute_onexit_table`, `_initialize_narrow_environment`, `_initialize_onexit_table`, `_initterm`, `_initterm_e`, `_register_onexit_function`, `_seh_filter_dll` |

### 4.3 DllMain 反编译(sub_180001020)
```c
__int64 __fastcall sub_180001020(HMODULE a1, int a2)
{
  // a2 == 1: DLL_PROCESS_ATTACH
  if ( a2 == 1 )
  {
    DisableThreadLibraryCalls(a1);                    // 禁用线程通知
    GetSystemDirectoryA(Buffer, 0x104u);              // 获取 System32 目录
    lstrcatA(Buffer, "\\dbgcore.dll");                // 拼接真 dbgcore.dll 路径
    LibraryA = LoadLibraryA(Buffer);                  // 加载真 dbgcore.dll
    hLibModule = LibraryA;
    if ( LibraryA )
    {
      // 获取真 MiniDumpReadDumpStream 地址
      MiniDumpReadDumpStream = GetProcAddress(LibraryA, "MiniDumpReadDumpStream");
      if ( MiniDumpReadDumpStream )
      {
        qword_180003158 = MiniDumpReadDumpStream;     // 保存真函数指针
        // 获取真 MiniDumpWriteDump 地址
        MiniDumpWriteDump = GetProcAddress(hLibModule, "MiniDumpWriteDump");
        if ( MiniDumpWriteDump )
        {
          qword_180003160 = MiniDumpWriteDump;         // 保存真函数指针
          // 加载真正的辅助 DLL
          qword_180003170 = LoadLibraryA("C:\\Users\\Public\\FlyPY\\flyinput.dll");
          return 1;                                    // 加载成功
        }
      }
      v6 = "Get address failed";                      // 获取地址失败
    }
    else
    {
      v6 = "Load original dll failed";                // 加载原始 DLL 失败
    }
    MessageBoxA(0, v6, "dbgcore", 0);                 // 弹错误框
    ExitProcess(1u);                                  // 退出进程
  }
  else if ( a2 == 0 )  // DLL_PROCESS_DETACH
  {
    if ( hLibModule ) FreeLibrary(hLibModule);
    if ( qword_180003170 ) FreeLibrary(qword_180003170);
  }
  return 1;
}
```

### 4.4 工作原理(DLL 代理劫持)
1. **导出同名函数**: 导出 `MiniDumpWriteDump` 和 `MiniDumpReadDumpStream`(与系统 dbgcore.dll 相同)
2. **加载真 DLL**: 在 DllMain 中 `LoadLibraryA("System32\dbgcore.dll")` 加载真 dbgcore
3. **转发调用**: 导出函数内部通过保存的真函数指针转发调用(jmp qword_180003158)
4. **加载辅助**: 同时 `LoadLibraryA("C:\Users\Public\FlyPY\flyinput.dll")` 加载主辅助 DLL
5. **静默运行**: 由于所有 dbgcore API 调用都被正确转发,游戏无感知

### 4.5 字符串
| 地址 | 字符串 |
|------|--------|
| 0x180002260 | `MiniDumpWriteDump` |
| 0x180002272 | `MiniDumpReadDumpStream` |
| 0x180002289 | `C:\Users\Public\FlyPY\flyinput.dll` |
| 0x1800022AC | `\dbgcore.dll` |
| 0x1800022B9 | `dbgcore`(MessageBox 标题) |
| 0x1800022C1 | `Get address failed` |
| 0x1800022D4 | `Load original dll failed` |

---

## 5. 嵌入 PE #2 分析(flyinput.dll - 主辅助逻辑)

### 5.1 基本信息
| 项目 | 值 |
|------|----|
| 文件 | `embedded_2_at_0xFFD0.exe_unpacked.exe` |
| 类型 | PE32+ DLL |
| 大小 | 96256 字节(UPX 解壳后) |
| 镜像基址 | 0x180000000 |
| 函数数 | 121 |
| 关键函数 | `sub_180001180`(主逻辑,0x3869 字节)、`TimerFunc`、`StartAddress` |

### 5.2 导入表
| 模块 | 导入函数 | 用途 |
|------|---------|------|
| KERNEL32 | `DisableThreadLibraryCalls`, `GetCurrentProcessId`, `GetCurrentThread`, `GetCurrentThreadId`, `GetModuleHandleA`, `GetProcAddress`, `GetSystemTimeAsFileTime`, `InitializeSListHead`, `QueryPerformanceCounter`, `Sleep` | 基础 API + 动态获取 NtSetInformationThread |
| USER32 | **`GetAsyncKeyState`**, **`KillTimer`**, **`MapVirtualKeyA`**, **`SendInput`**, **`SetTimer`** | 按键监听 + 按键模拟 + 定时器 |
| MSVCP140 | `_Cnd_broadcast`, `_Cnd_wait`, `_Mtx_lock`, `_Mtx_unlock`, `_Thrd_join` 等 | C++ 标准库线程同步 |
| VCRUNTIME140 | `_CxxThrowException`, `__C_specific_handler`, `memcpy` | C++ 异常处理 |
| api-ms-win-crt-runtime | `_beginthreadex`, `terminate` | 线程创建 |

### 5.3 反调试技术(sub_180001180 开头)
```c
__int64 __fastcall sub_180001180()
{
  // 1. 隐藏线程(反调试)
  ModuleHandleA = GetModuleHandleA("ntdll.dll");
  NtSetInformationThread = GetProcAddress(ModuleHandleA, "NtSetInformationThread");
  CurrentThread = GetCurrentThread();
  // InformationClass = 17 (ThreadHideFromDebugger)
  result = NtSetInformationThread(CurrentThread, 17, 0, 0);
  
  // 2. 获取自身模块基址(游戏进程内的 flyinput.dll)
  _RAX = GetModuleHandleA(0);
  qword_180019350 = (__int64)_RAX;
  
  // 3. 基于偏移读取游戏内存(关键数据结构)
  v25 = (__int64)(_RAX + 8041488);      // 游戏数据基址偏移
  qword_180019368 = (__int64)(_RAX + 8041488);
  // ...大量基于偏移的内存读取...
  qword_180019380 = *((_QWORD *)_RAX + 4010496);
  qword_180019378 = *((_QWORD *)_RAX + 4013091);
  // ...
  
  // 4. 等待游戏加载(基于 QueryPerformanceCounter 的循环)
  do {
    perf_frequency = Query_perf_frequency();
    perf_counter = Query_perf_counter();
    // ...计算纳秒级延迟...
    Sleep(v46);
  } while (v37 >= v40);
}
```

**ThreadHideFromDebugger** (0x11) 是经典反调试技术:
- 调用 `NtSetInformationThread(GetCurrentThread(), ThreadHideFromDebugger, 0, 0)`
- 通过 `GetProcAddress` 动态获取,绕过静态导入表分析
- 隐藏辅助线程,使调试器无法检测

### 5.4 游戏内存读取
辅助通过**直接内存偏移**读取游戏状态(不使用 ReadProcessMemory,因为已在游戏进程内):
```c
qword_180019350 = (__int64)GetModuleHandleA(0);     // flyinput.dll 自身基址
v25 = (__int64)(_RAX + 8041488);                   // 偏移到游戏数据区
qword_180019380 = *((_QWORD *)_RAX + 4010496);     // 游戏对象指针
qword_180019378 = *((_QWORD *)_RAX + 4013091);     // 英雄列表
qword_180019370 = *((_QWORD *)_RAX + 4013105) + 72; // 英雄属性
qword_180019388 = *((_QWORD *)_RAX + 4014672);      // 技能数据
qword_180019390 = *((_QWORD *)_RAX + 4016994);     // 物品数据
```

### 5.5 FNV-1a 哈希字符串查找
使用 FNV-1a 算法(初始值 `0xCBF29CE484222325`,素数 `0x100000001B3`)进行字符串匹配:
```c
v55 = 0xCBF29CE484222325uLL;
do {
  v55 = 0x100000001B3LL * ((char)_R8 ^ (unsigned __int64)v55);
  _R8 = *v54++;
} while ( (_BYTE)_R8 );
// 比较 v55 与预计算的哈希值
if ( v55 == 0x112D788B5B855BEELL ) { ... }
if ( v55 == 0x19BF8DB558FEDB42LL ) { ... }
// ... 等
```
这是一种**反字符串分析**技术,避免明文出现英雄/技能名,但实际游戏数据字符串仍以明文存在。

### 5.6 按键监听与连发
通过 `GetAsyncKeyState` 监听以下按键:

| VK 代码 | 按键 | 功能(推断) |
|---------|------|------------|
| 0x20 (32) | Space | 视角锁定/平移 |
| 0x56 (86) | V | 撤退信号 |
| 0x43 (67) | C | 角色信息 |
| 0x24 (36) | Home | 视角上移 |
| 0x23 (35) | End | 视角下移 |
| 0x21 (33) | PageUp | 视角放大 |
| 0x22 (34) | PageDown | 视角缩小 |
| 0x26 (38) | Up | 视角上 |
| 0x28 (40) | Down | 视角下 |
| 0x25 (37) | Left | 视角左 |
| 0x27 (39) | Right | 视角右 |
| 0x01 (1) | LButton | 鼠标左键(选择) |
| 0x45 (69) | E | 技能 E |
| 0x33 (51) | 3 | 物品栏 3 |
| 0x46 (71) | F | 召唤师技能(闪现) |

### 5.7 按键连发实现(SetTimer + SendInput)
```c
// 按下按键时设置定时器(1ms 间隔)
if ( (v347 & 2) != 0 )  // V 键被按下
{
    *(_BYTE *)qword_180019338 ^= 1u;  // 切换状态
    // 设置 4 个定时器,每个 1ms 间隔,回调 TimerFunc
    SetTimer(*(HWND *)qword_180019398, 1u, 1u, TimerFunc);
    SetTimer(*(HWND *)qword_180019398, 2u, 1u, TimerFunc);
    SetTimer(*(HWND *)qword_180019398, 3u, 1u, TimerFunc);
    SetTimer(*(HWND *)qword_180019398, 4u, 1u, TimerFunc);
}

// TimerFunc 内部通过 SendInput 模拟按键
// MapVirtualKeyA 用于虚拟键码转换
```

### 5.8 游戏资源字符串(LOL 英雄/皮肤)
辅助内置大量英雄联盟字符串,用于自动选择/识别:

**英雄/皮肤名称**:
- `LuxAir`, `LuxWater`, `LuxStorm`, `LuxDark`, `LuxFire`, `LuxIce`, `LuxMystic`, `LuxMagma`, `LuxNature`(Lux 系列)
- `Iron Revenant`(Mordekaiser), `Royal arms`, `Hall of Legends`, `Zero hour`, `Scarlet fair`
- `Sahn-Uzal`(Mordekaiser 背景故事)
- `Unconquered King`, `Risen Legend`, `Immortalized Legend`, `Parallel world`, `Starswarm`
- `PickACar`, `BlueCard`, `GoldCard`, `RedCardL`(Twisted Fate 卡牌)

**装备/等级**:
- `Sword1` ~ `Sword7`(剑)
- `Mask1` ~ `Mask6`(面具)
- `Dagger 1` ~ `Dagger 6`(匕首)
- `Level 1` ~ `Level 3`
- `SonaDJGenre02`, `SonaDJGenre03`(Sona DJ 皮肤)

**游戏术语**:
- `Head on`, `Head off`, `Ultimate`, `Without hood`, `With hood`

### 5.9 性能计时(sub_1800049F0)
基于 `QueryPerformanceFrequency` / `QueryPerformanceCounter` 的高精度计时器,
用于按键连发的精确时间控制(纳秒级):
```c
// 计算 1ms 间隔
v11 = v4 + 1000000 * a1;  // a1 = 10 表示 10ms
// 循环等待
while (1) {
    v12 = Query_perf_frequency();
    v13 = Query_perf_counter();
    // 计算纳秒...
    if (v11 <= v14) break;
    Sleep(v18);  // 休眠剩余时间
}
```

---

## 6. 注入与加载流程

### 6.1 完整攻击链
```
[16.13.exe 登录绕过]
        ↓
[释放并启动 MJTVPFeD.dat]
        ↓
[MJTVPFeD.dat 自删除 + 获取游戏目录]
   ├─ 方案A: RegOpenKeyExA("Software\Tencent\LOL")
   └─ 方案B: CreateToolhelp32Snapshot + 遍历找 LeagueClient.exe
        ↓
[释放到 C:\Users\Public\FlyPY\]
   ├─ flyinput.dll (PE#2 解壳)
   └─ dbgcore.dll  (PE#1 解壳)
        ↓
[等待 LeagueClient.exe 启动]
        ↓
[游戏加载 dbgcore.dll(其实是假 DLL)]
        ↓
[假 dbgcore.dll 的 DllMain]
   ├─ LoadLibraryA("System32\dbgcore.dll")  // 加载真 DLL
   ├─ GetProcAddress 获取真 MiniDump* 函数   // 准备转发
   └─ LoadLibraryA("C:\Users\Public\FlyPY\flyinput.dll")  // 加载辅助
        ↓
[flyinput.dll 的 DllMain]
   ├─ NtSetInformationThread(17)  // 反调试
   ├─ GetModuleHandleA(0)         // 获取基址
   ├─ 读取游戏内存偏移             // 初始化数据
   └─ 进入按键监听循环             // 主逻辑
        ↓
[按键连发/技能快捷键/视角控制]
        ↓
[SetTimer + SendInput 模拟输入]
```

### 6.2 DLL 劫持原理
1. **目标 DLL 选择**: `dbgcore.dll` 是 Windows 系统的调试核心 DLL,
   被 LeagueClient.exe 动态加载(用于 crash dump)
2. **DLL 搜索顺序利用**: Windows DLL 搜索顺序为:
   应用程序目录 → System32 → 系统目录 → PATH
3. **放置假 DLL**: 将假 dbgcore.dll 放到 LeagueClient.exe 所在目录
4. **代理转发**: 假 DLL 加载真 DLL 并转发所有 API 调用,游戏无感知
5. **隐藏负载**: 在 DllMain 中静默加载 flyinput.dll,实现辅助功能

---

## 7. 反检测与隐藏技术

### 7.1 反调试
- **NtSetInformationThread(ThreadHideFromDebugger)**: 隐藏辅助线程,使调试器无法枚举
- **动态获取 API**: 通过 `GetProcAddress` 而非静态导入 `NtSetInformationThread`,
  绕过静态 IAT 分析

### 7.2 文件隐藏
- **自删除**: MJTVPFeD.dat 启动后删除自身文件
- **释放到 Public 目录**: 使用 `C:\Users\Public\FlyPY\`(权限宽松,无需管理员)
- **DLL 命名伪装**: 假 DLL 命名为 `dbgcore.dll`(系统 DLL 名)

### 7.3 字符串混淆
- **FNV-1a 哈希查找**: 部分关键字符串通过哈希值比较,而非明文
- **UPX 加壳**: 嵌入 PE 使用 UPX 加壳,增加静态分析难度

### 7.4 证书伪装
- 内嵌 **Pikachu 自签名证书链**(有效期到 2099 年)
- 内嵌 **Thawte 根证书和代码签名证书**
- 可能用于绕过签名验证或伪装合法签名

---

## 8. 关键技术指标

### 8.1 内存偏移表(基于 flyinput.dll 基址)
| 偏移 | 含义(推断) |
|------|------------|
| +8041488 (0x7ABFE0) | 游戏数据基址 |
| +32165952 (0x1EA4A0) | 主数据区 |
| +32861865 (0x1F51029) | 对象表 |
| +8215644 (0x7D6B2C) | 英雄对象 |
| +8230176 (0x7DA360) | 技能对象 |
| +32920704 (0x1F63380) | 物品对象 |
| +33012248 (0x1F79AD8) | 视角数据 |
| +32354472 (0x1EEB668) | 主窗口句柄 |

### 8.2 FNV-1a 哈希值
| 哈希值 | 用途(推断) |
|--------|------------|
| 0x112D788B5B855BEE | 英雄/模式标识 1 |
| 0x19BF8DB558FEDB42 | 英雄/模式标识 2 |
| 0x1A47746099CAAD97 | 英雄/模式标识 3 |
| 0x77EE2DDFA384BEA0 | 英雄/模式标识 4 |
| 0x7A22BC4C07AC1888 | 英雄/模式标识 5 |
| 0x98DD22A3CCBC7773 | 英雄/模式标识 6 |
| 0xAD1C144669DB1514 | 英雄/模式标识 7 |
| 0xB173594E60E46B49 | 英雄/模式标识 8 |
| 0xDE3BC2BFB3A73E2A | 英雄/模式标识 9 |
| 0x0D1C29E7AD935C17 | 英雄/模式标识 10 |

### 8.3 函数地址表(PE#2)
| 地址 | 函数名 | 大小 | 功能 |
|------|--------|------|------|
| 0x180001180 | sub_180001180 | 0x3869 | 主逻辑(反调试+初始化+主循环) |
| 0x1800049F0 | sub_1800049F0 | 0x1C0 | 高精度计时器 |
| 0x180004BB0 | sub_180004BB0 | 0x157C | 子逻辑 1 |
| 0x180006130 | sub_180006130 | 0x157A | 子逻辑 2 |
| 0x1800076B0 | sub_1800076B0 | 0x1613 | 子逻辑 3 |
| 0x180008CD0 | sub_180008CD0 | 0x16C4 | 子逻辑 4 |
| 0x18000A3A0 | sub_18000A3A0 | 0x152C | 子逻辑 5 |
| 0x18000B8D0 | sub_18000B8D0 | 0x15B0 | 子逻辑 6 |
| 0x18000CE80 | sub_18000CE80 | 0x17DD | 子逻辑 7 |
| 0x18000E660 | sub_18000E660 | 0x15B3 | 子逻辑 8 |
| 0x18000FC20 | sub_18000FC20 | 0x15B0 | 子逻辑 9 |
| 0x1800111D0 | sub_1800111D0 | 0x152C | 子逻辑 10 |
| 0x180012C10 | StartAddress | 0x144 | 线程函数 |
| 0x180014020 | TimerFunc | 0x219 | 定时器回调(SendInput) |
| 0x180015D70 | DllEntryPoint | 0x3D | DLL 入口 |

---

## 9. 检测与清除建议

### 9.1 检测特征
1. **文件存在**: `C:\Users\Public\FlyPY\` 目录及其中 `flyinput.dll`、`dbgcore.dll`
2. **进程行为**: LeagueClient.exe 进程内加载了非系统目录的 dbgcore.dll
3. **注册表访问**: 程序读取 `Software\Tencent\LOL` 注册表键
4. **API 调用**: `NtSetInformationThread(ThreadHideFromDebugger)` 调用
5. **网络特征**: 无明显网络通信(纯本地辅助)

### 9.2 清除步骤
1. 终止 LeagueClient.exe 进程
2. 删除 `C:\Users\Public\FlyPY\` 整个目录
3. 检查 LeagueClient.exe 所在目录是否有假 dbgcore.dll
4. 清理可能的注册表残留
5. 全盘扫描 16.13.exe(辅助启动器)

### 9.3 防御建议
1. **DLL 加载策略**: 启用 SafeDllSearchMode,强制从 System32 加载系统 DLL
2. **签名验证**: 对加载的 dbgcore.dll 进行数字签名验证
3. **反调试检测**: 监控 `NtSetInformationThread(ThreadHideFromDebugger)` 调用
4. **文件完整性**: 监控 `C:\Users\Public\` 目录下的异常文件创建

---

## 10. 分析文件清单

| 文件 | 说明 |
|------|------|
| `MJTVPFeD.dat` | 原始辅助程序(自删除,运行后消失) |
| `MJTVPFeD_dumped.exe` | 从内存 dump 的 PE(131KB) |
| `embedded_pe/embedded_0_at_0x0.exe` | 外层 PE 提取(非 UPX) |
| `embedded_pe/embedded_1_at_0xC7F0.exe` | PE#1 UPX 加壳(6.6KB) |
| `embedded_pe/embedded_1_at_0xC7F0.exe_unpacked.exe` | PE#1 解壳(10KB,假 dbgcore.dll) |
| `embedded_pe/embedded_2_at_0xFFD0.exe` | PE#2 UPX 加壳(31KB) |
| `embedded_pe/embedded_2_at_0xFFD0.exe_unpacked.exe` | PE#2 解壳(96KB,flyinput.dll) |
| `extract_embedded_pe.py` | 嵌入 PE 提取脚本 |
| `analyze_unpacked.py` | 解壳 PE 分析脚本 |
| `analyze_unpacked.log` | 解壳 PE 分析输出(166KB) |
| `analyze_outer.py` | 外层 PE 分析脚本 |
| `analyze_outer.log` | 外层 PE 分析输出 |

---

## 11. 总结

`MJTVPFeD.dat` 是一个**多层嵌套的英雄联盟辅助程序**,核心技术包括:

1. **三层嵌套架构**: 外层 EXE + 嵌入两个 UPX 加壳 DLL
2. **DLL 劫持**: 通过假 dbgcore.dll 代理转发 + 加载辅助 DLL
3. **反调试**: NtSetInformationThread(ThreadHideFromDebugger)
4. **游戏内存读取**: 基于偏移直接读取游戏数据(英雄/技能/物品)
5. **按键连发**: SetTimer + SendInput 实现 1ms 间隔按键模拟
6. **自隐藏**: 启动后自删除 + 释放到 Public 目录 + 证书伪装

该辅助主要功能包括:视角控制、技能快捷键、按键连发(走砍)、自动选择英雄/皮肤等,
针对 League of Legends 客户端,通过 DLL 劫持方式注入,具有较强的隐蔽性。

---

**分析完成时间**: 2026-06-28
**分析工具**: IDA Pro 9.3 (idalib) + UPX 4.2.4 + Python PE 解析
**分析师**: 自动化逆向分析
