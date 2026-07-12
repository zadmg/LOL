# 英雄联盟辅助逆向工程

> 基于 16.13.exe 的完整逆向分析与重写准备资料库
> 目标版本: 16.13.exe (1,297,416 bytes, MD5: 02a6cd700069594d8cab92377667ad97)
> 保护方式: VMProtect (轻度保护，函数级标记壳，未虚拟化)

---

## 目录结构

```
LOL/
├── analysis/          # 破解笔记与分析报告 (5 个文件)
├── scripts/           # 核心 Python 脚本 (20 个文件)
├── decompiled/        # 反编译源码与分析数据 (17 个文件)
└── README.md          # 本文件
```

---

## analysis/ - 破解笔记与分析报告

| 文件 | 内容 |
|------|------|
| [破解笔记.md](./analysis/破解笔记.md) | 完整逆向记录：网络验证绕过 + DLL劫持 + 英雄移植 + 假点击 + 偏移速查表 |
| [深度分析报告.md](./analysis/深度分析报告.md) | 10轮深度挖掘：文件结构/开发者信息/反检测/功能清单/API协议/加密技术/17英雄哈希 |
| [封禁绕过报告.md](./analysis/封禁绕过报告.md) | VMProtect壳分析 + 登录流程逆向 + 2个补丁点 + pywinauto测试验证 |
| [MJTVPFeD分析报告.md](./analysis/MJTVPFeD分析报告.md) | 三层嵌套PE结构 + DLL劫持链 + flyinput.dll反调试/按键连发/内存读取 |
| [连招方案指南.md](./analysis/连招方案指南.md) | 10个英雄完整连招方案 + 伤害公式 + 技能参数 + DLL移植指南 |

---

## scripts/ - 核心 Python 脚本

### 补丁与部署
| 脚本 | 用途 |
|------|------|
| [patch_beifen.py](./scripts/patch_beifen.py) | 网络验证绕过补丁 (2个补丁点) |
| [add_jinx.py](./scripts/add_jinx.py) | Jinx 英雄移植到 flyinput.dll |
| [add_fakeclicks_v3.py](./scripts/add_fakeclicks_v3.py) | 假点击功能 v3 (修复版) |
| [add_fakeclicks_v2.py](./scripts/add_fakeclicks_v2.py) | 假点击功能 v2 (有bug参考) |
| [add_fakeclick_only.py](./scripts/add_fakeclick_only.py) | 仅假点击功能补丁 |
| [pack_and_deploy.py](./scripts/pack_and_deploy.py) | UPX加壳 + RC4加密 + 部署 |
| [apply_patches_v2.py](./scripts/apply_patches_v2.py) | 批量应用补丁 |

### 验证与分析
| 脚本 | 用途 |
|------|------|
| [verify_final.py](./scripts/verify_final.py) | 最终二进制完整性验证 |
| [verify_fakeclick_v3.py](./scripts/verify_fakeclick_v3.py) | 假点击v3机器码验证 |
| [check_pe2_space.py](./scripts/check_pe2_space.py) | PE2槽位空间检查 |
| [compare_versions.py](./scripts/compare_versions.py) | 版本对比 |
| [diff_patched.py](./scripts/diff_patched.py) | 补丁差异分析 |
| [extract_embedded_pe.py](./scripts/extract_embedded_pe.py) | 嵌入PE提取 |
| [analyze_flyinput_v3.py](./scripts/analyze_flyinput_v3.py) | flyinput.dll深度分析 |
| [fnv_hash_reverse.py](./scripts/fnv_hash_reverse.py) | FNV-1a哈希反查(17英雄名) |
| [deep_10_rounds.py](./scripts/deep_10_rounds.py) | 10轮深度分析 |
| [dump_mjtvped_v4.py](./scripts/dump_mjtvped_v4.py) | MJTVPFeD.dat内存dump |
| [rc4_keystream_analysis.py](./scripts/rc4_keystream_analysis.py) | RC4密钥流分析 |
| [cert_full_analysis.py](./scripts/cert_full_analysis.py) | Pikachu证书链完整分析 |

---

## decompiled/ - 反编译源码

### 反编译 C 代码
| 文件 | 内容 | 大小 |
|------|------|------|
| [flyinput_analysis_report.c](./decompiled/flyinput_analysis_report.c) | flyinput.dll分析报告 | 23KB |
| [outer_decompiled.c](./decompiled/outer_decompiled.c) | 外层EXE反编译 | 26KB |
| [pe1_dbgcore_decompiled.c](./decompiled/pe1_dbgcore_decompiled.c) | dbgcore.dll反编译 | 24KB |
| [pe2_flyinput_decompiled.c](./decompiled/pe2_flyinput_decompiled.c) | flyinput.dll反编译 | 294KB |

> 注: flyinput_full_decompiled.c (5.89MB) 超出GitHub API限制，保留在本地

### 分析数据
| 文件 | 内容 |
|------|------|
| outer/pe1/pe2 的 strings/exports/imports/functions/xrefs/segments | PE结构完整分析数据 |

---

## 成品清单 (本地保存)

### 可执行文件

| 文件 | 说明 | 位置 |
|------|------|------|
| 16.13.exe (原始) | 未修改版本 | D:\SRC\SRC\ |
| 16.13.exe.jinx_fc | 当前部署版(绕过+Jinx+假点击v3) | D:\SRC\SRC\ |
| 16.13.exe.bak2 | 同jinx_fc(备份) | D:\SRC\SRC\ |
| BeiFen/16.13_patched.exe | 仅绕过网络验证 | D:\SRC\SRC\BeiFen\ |

### DLL 文件

| 文件 | 说明 | 位置 |
|------|------|------|
| enhr_pe2_jinx_fc3_ub.dll | UPX加壳版(30,720bytes) | D:\SRC\SRC\enhr_embedded\ |
| enhr_pe2_jinx_fakeclick3.exe | 解壳版(含Jinx+假点击v3) | D:\SRC\SRC\enhr_embedded\ |

### 关键数据文件

| 文件 | 说明 | 位置 |
|------|------|------|
| rc4_keystream.bin | RC4密钥流(113,664bytes) | D:\SRC\SRC\ |

---

## 关键偏移速查表

### 16.13.exe 补丁点

| 偏移 | 原始 | 修改 | 说明 |
|------|------|------|------|
| 0x0142CB | `0F840A000000` | `E90B00000090` | jz->jmp 跳过API验证 |
| 0x016B43 | `0F8484000000` | `909090909090` | jz->nop 跳过授权验证 |

### MJTVPFeD.dat 结构 (解密后)

| 偏移 | 内容 | 大小 |
|------|------|------|
| 0x00000 | 外层EXE (MZ) | 47,856 |
| 0x0B9F0 | PE1: dbgcore.dll (MZ) | 14,272 |
| 0x0F1D0 | PE2: flyinput.dll (MZ) | 31,232 |
| 0x16BD0 | 证书+配置 | 20,528 |

### flyinput.dll 关键 RVA

| RVA | 内容 |
|-----|------|
| 0x14020 | TimerFunc 入口 |
| 0x14025 | TimerFunc+5 (返回点) |
| 0x17B08 | SendInput IAT |
| 0x17AF0 | GetAsyncKeyState IAT |
| 0x17B10 | SetTimer IAT |
| 0x1D000 | .newtext 节区开始 |
| 0x1E800 | 假点击函数 v3 |
| 0x1F000 | 状态变量 (fc_step/dx/dy) |

### 10 英雄函数映射

| 模式 | 英雄 | 函数地址 | 行数 |
|------|------|---------|------|
| 0x00 | Ashe | 0x180004BB0 | 1070 |
| 0x01 | Kaisa | 0x180006130 | 1102 |
| 0x02 | Kalista | 0x1800076B0 | 1090 |
| 0x03 | KogMaw | 0x180008CD0 | 1135 |
| 0x04 | Sivir | 0x18000A3A0 | 1053 |
| 0x05 | Tristana | 0x18000B8D0 | 1083 |
| 0x06 | TwistedFate | 0x18000CE80 | 1181 |
| 0x07 | Twitch | 0x18000E660 | 1074 |
| 0x08 | Xayah | 0x18000FC20 | 1083 |
| 0x09 | Yunara | 0x1800111D0 | 5038 |

---

## 游戏更新后重写流程

1. 获取新版本 LOL 内存偏移 (Lmeme/IDA/CE)
2. 在解壳 flyinput.dll 中定位所有偏移 (51个)
3. 批量修改偏移 (Python脚本)
4. UPX --ultra-brute 加壳 (确保 <= 31,232 bytes)
5. 替换 PE2 @ 0xF1D0，尾部补0填充
6. RC4 重新加密 (rc4_keystream.bin XOR)
7. 拼接回 16.13.exe (前0x121000 + 8字节header + 加密数据)

---

## 参考资源 (本地保存)

| 资源 | 位置 | 说明 |
|------|------|------|
| LeagueSharp.Common | D:\SRC\SRC\LeagueSharp.Common-master\ | 40+ C# 源文件 |
| Lmeme | D:\SRC\SRC\Lmeme-master\ | LOL 偏移表 |
| VakScript | D:\SRC\SRC\VakScript-main\ | 外部辅助参考 |
| aero-overlay | D:\SRC\SRC\aero-overlay-master\ | Overlay 渲染 |
| league_ref | D:\SRC\SRC\league_ref\ | 英雄脚本参考 |
| ComboAssistant | D:\SRC\SRC\ComboAssistant\ | LOL连招助手 (.NET 8) |
| buried_data | D:\SRC\SRC\buried_data\ | 27个分析数据文件 |
| deep_rounds | D:\SRC\SRC\deep_rounds\ | 10轮深度分析数据 |
| embedded_pe | D:\SRC\SRC\embedded_pe\ | 提取的嵌入PE |
| enhr_embedded | D:\SRC\SRC\enhr_embedded\ | 增强嵌入PE |
| rsrc_extracted | D:\SRC\SRC\rsrc_extracted\ | 资源段提取 |

---

*文档更新: 2026-07-12*
*基于 16.13.exe 逆向工程完整记录*
