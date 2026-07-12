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
├── references/        # 其他博主脚本参考 (40 个文件)
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

## references/ - 其他博主脚本参考

### Lua 英雄脚本 (28 个)

| 脚本 | 作者 | 英雄 | 说明 |
|------|------|------|------|
| [Aphelios_zg.lua](./references/Aphelios_zg.lua) | Zgjfjfl AIO | Aphelios | 武器切换+连招 |
| [Ashe_CX.lua](./references/Ashe_CX.lua) | CX | Ashe | Q/W/R技能 |
| [Ashe_Vasilyi.lua](./references/Ashe_Vasilyi.lua) | Vasilyi | Ashe | 全功能 |
| [Caitlyn_zg.lua](./references/Caitlyn_zg.lua) | Zgjfjfl AIO | Caitlyn | 爆头被动+EQ连招 |
| [Ezreal_zg.lua](./references/Ezreal_zg.lua) | Zgjfjfl AIO | Ezreal | Q/W/R预测+碰撞检测 |
| [Jhin_zg.lua](./references/Jhin_zg.lua) | Zgjfjfl AIO | Jhin | 4发机制 |
| [Jinx_zg.lua](./references/Jinx_zg.lua) | Zgjfjfl AIO | Jinx | 火箭筒/轻机枪切换 |
| [Kaisa_Impulsx.lua](./references/Kaisa_Impulsx.lua) | Impulsx | Kaisa | 全技能 |
| [Kaisa_zg.lua](./references/Kaisa_zg.lua) | Zgjfjfl AIO | Kaisa | 全技能 |
| [Kalista_combo.lua](./references/Kalista_combo.lua) | - | Kalista | 长矛叠加+E |
| [KogMaw_Dienofail.lua](./references/KogMaw_Dienofail.lua) | Dienofail | KogMaw | W射程 |
| [KogMaw_cconn.lua](./references/KogMaw_cconn.lua) | cconn | KogMaw | W射程 |
| [Lucian_zg.lua](./references/Lucian_zg.lua) | Zgjfjfl AIO | Lucian | 双射+E重置 |
| [Lux_BioLogic.lua](./references/Lux_BioLogic.lua) | BioLogic | Lux | 全技能 |
| [Lux_GOS.lua](./references/Lux_GOS.lua) | GOS | Lux | 全技能 |
| [Lux_YTS.lua](./references/Lux_YTS.lua) | YTS | Lux | 全技能 |
| [Lux_zg.lua](./references/Lux_zg.lua) | Zgjfjfl AIO | Lux | 全技能 |
| [MissFortune_zg.lua](./references/MissFortune_zg.lua) | Zgjfjfl AIO | MissFortune | 双枪 |
| [Nilah_zg.lua](./references/Nilah_zg.lua) | Zgjfjfl AIO | Nilah | 鞭刃 |
| [Samira_zg.lua](./references/Samira_zg.lua) | Zgjfjfl AIO | Samira | 评分系统 |
| [Sivir_Dienofail.lua](./references/Sivir_Dienofail.lua) | Dienofail | Sivir | W弹射 |
| [Sivir_zg.lua](./references/Sivir_zg.lua) | Zgjfjfl AIO | Sivir | W弹射 |
| [Tristana_Impulsx.lua](./references/Tristana_Impulsx.lua) | Impulsx | Tristana | E+Q爆发 |
| [Tristana_imitat0r.lua](./references/Tristana_imitat0r.lua) | imitat0r | Tristana | E+Q爆发 |
| [TwistedFate_Hellsing.lua](./references/TwistedFate_Hellsing.lua) | Hellsing | TwistedFate | 选牌 |
| [Twitch_Bilbao.lua](./references/Twitch_Bilbao.lua) | Bilbao | Twitch | 隐形+毒 |
| [Twitch_GoS.lua](./references/Twitch_GoS.lua) | GoS | Twitch | 隐形+毒 |
| [Twitch_Vasilyi.lua](./references/Twitch_Vasilyi.lua) | Vasilyi | Twitch | 隐形+毒 |
| [Varus_zg.lua](./references/Varus_zg.lua) | Zgjfjfl AIO | Varus | 穿透箭 |
| [Vayne_zg.lua](./references/Vayne_zg.lua) | Zgjfjfl AIO | Vayne | 银弩+翻滚 |
| [Xayah_Unruly.lua](./references/Xayah_Unruly.lua) | Unruly | Xayah | 羽毛回收 |
| [Xayah_Vasilyi.lua](./references/Xayah_Vasilyi.lua) | Vasilyi | Xayah | 羽毛回收 |
| [Yunara_zg.lua](./references/Yunara_zg.lua) | Zgjfjfl AIO | Yunara | 狂热 |
| [Zeri_zg.lua](./references/Zeri_zg.lua) | Zgjfjfl AIO | Zeri | 闪电链 |

### C# 框架代码 (7 个)

| 文件 | 来源 | 说明 |
|------|------|------|
| [AntiGapcloser.cs](./references/AntiGapcloser.cs) | LeagueSharp.Common | 防突进 |
| [Interrupter.cs](./references/Interrupter.cs) | LeagueSharp.Common | 打断技能 |
| [MinionManager.cs](./references/MinionManager.cs) | LeagueSharp.Common | 小兵管理 |
| [Orbwalking.cs](./references/Orbwalking.cs) | LeagueSharp.Common | 走砍核心 |
| [Prediction.cs](./references/Prediction.cs) | LeagueSharp.Common | 技能预测 |
| [Spell.cs](./references/Spell.cs) | LeagueSharp.Common | 技能封装 |
| [Ashe_CX.lua](./references/Ashe_CX.lua) | CX | Ashe (Lua版) |

> 注: Lua 脚本基于内部 API（GGPrediction 等），flyinput.dll 不能直接使用，但可参考连招逻辑和技能时序

---

## 外部项目导航

### 外部辅助

| 项目名称 | 作者 | Stars | 说明 |
|---------|------|-------|------|
| [VakScript](https://github.com/vakdev/VakScript) | [vakdev](https://github.com/vakdev) | 188 | Python 纯外部 RPM 辅助，Target 优先级、Lasthit、Auto Smite、插件系统 |
| [Lmeme](https://github.com/hrt/Lmeme) | [hrt](https://github.com/hrt) | 57 | Python 外部辅助，特征码扫描表（oLocalPlayer/oObjectManager/oGameTime 等） |
| [ExSharp-Base](https://github.com/ZeroLP/ExSharp-Base) | [ZeroLP](https://github.com/ZeroLP) | 155 | C# RPM + PixelSearch，CD 跟踪、敌方检测、攻击范围圆绘制 |
| [KBot](https://github.com/KebsCS/KBot) | [KebsCS](https://github.com/KebsCS) | 151 | C++ 内核驱动读取，Evade、Orbwalker |
| [MagicOrbwalker](https://github.com/sajmonekk191/MagicOrbwalker) | [sajmonekk191](https://github.com/sajmonekk191) | 20 | C# 外部走砍，2025-06 更新支持 14.x |
| [league-of-legends](https://github.com/campiohe/league-of-legends) | [campiohe](https://github.com/campiohe) | 37 | Python GDI Overlay 外部辅助，移动预测、Aim-Lock |

### Overlay 渲染

| 项目名称 | 作者 | Stars | 说明 |
|---------|------|-------|------|
| [aero-overlay](https://github.com/ReactiioN1337/aero-overlay) | [ReactiioN1337](https://github.com/ReactiioN1337) | - | C++ D2D + DWrite 透明窗口框架，MIT 许可 |
| [StealthOverlay](https://github.com/nertigel/StealthOverlay) | [nertigel](https://github.com/nertigel) | - | C++ D3D11 + ImGui，Streamproof + uiaccess + xorstr |
| [imgui-external-overlay](https://github.com/3r4y/imgui-external-overlay) | [3r4y](https://github.com/3r4y) | 90 | C++ D3D9 + ImGui 通用外部 Overlay 模板 |

### 人类化输入

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [FakeClicks.cs](https://github.com/LeagueSharp/LeagueSharp.Common/blob/master/FakeClicks.cs) | LeagueSharp | C# 假点击实现，OnIssueOrder/OnNewPath 事件 0.15-0.35s 随机间隔 |
| [Wind Mouse 算法](https://github.com/BenLand100/SMART/blob/master/src/main/java/smart/WindMouse.java) | BenLand100 | Java 鼠标风算法，模拟带"风"的鼠标轨迹 |
| [Bezier Mouse](https://github.com/BenLand100/SMART) | BenLand100 | 贝塞尔曲线鼠标轨迹，3-4 控制点 + 随机扰动 |
| [Perlin Noise Mouse](https://github.com/BenLand100/SMART) | BenLand100 | 柏林噪声生成平滑随机轨迹 |

### LeagueSharp 架构

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [LeagueSharp.Common](https://github.com/LeagueSharp/LeagueSharp.Common) | LeagueSharp | C# 内部 Hook 框架，基于 Hook + 事件驱动 + 托管 API + 渲染注入 + 封包操作 |

**可用部分**（11 个）：Geometry.cs, MEC.cs, MapPositions.cs, ItemData.cs, WeightedRandom.cs, KeyboardEvents.cs, MouseEvents.cs, Keys.cs, WindowsMessages.cs, NativeMethods.cs, VirtualMouse.cs

**部分可用**（18 个）：Damage.cs, Prediction.cs, Spell.cs, TargetSelector.cs, HealthPrediction.cs, MinionManager.cs, Orbwalking.cs, Items.cs, AntiGapcloser.cs, Interrupter.cs, Dash.cs, AutoLevel.cs, FakeClicks.cs, LastCastedSpell.cs, Utility.cs, Cursor.cs, Utils.cs 等

**完全不可用**（11 个）：ObjectHandler.cs, CustomEvents.cs, Hacks.cs, Packet.cs, GamePacket.cs, Shared.cs, Notifications.cs, Render.cs, PermaShow.cs, MenuWrapper.cs, Alerter.cs

### 反检测研究

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [External-Mitigations](https://github.com/ZeroLP/External-Mitigations) | [ZeroLP](https://github.com/ZeroLP) | C# 反向参考：Riot 检测外部脚本的手段 |

### 内存偏移与特征码

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [Lmeme 偏移表](https://github.com/hrt/Lmeme/blob/master/constants.py) | hrt | LOL 14.x 完整偏移表 + 特征码扫描表 |

**Lmeme 特征码扫描表**（版本无关稳定）：
```
oLocalPlayer:      \x8B\x3D????\x3B\xF7\x75    (aBlueHero 字符串)
oObjectManager:    \x8B\x0D????\x89\x7C\x24\x14
oViewProjMatrices: \xB9????\x0F\x10\x80
oRenderer:         \xA1????\x53\x8B\x1D????\x56\x57\x8B\xF9
oGameTime:         \xF3\x0F\x5C\x0D????\x0F\x2F\xC1\xF3
oObjectHealth:     \x8D\x8B????\xE8????\x83\xEC
```

**英雄对象内存布局**：
```
oObjectHealth = 0xDB4          # 血量
oObjectMana = 0x2B4             # 蓝量
oObjectPos = 0x1F4              # 坐标 X/Z/Y
oObjectTeam = 0x4C              # 队伍
oObjectLevel = 0x3394            # 等级
oObjectAtkRange = 0x1304        # 攻击范围
oObjectAtkSpeedMulti = 0x12B8   # 攻速
oObjectBaseAtk = 0x12BC         # 基础攻击
oObjectBonusAtk = 0x1234        # 额外攻击
oObjectArmor = 0x12E4           # 护甲
oObjectMagicRes = 0x12EC        # 魔抗
oObjectAbilityPower = 0x1788    # 法强
oObjectName = 0x2BDC            # 名称
oObjectSpellBook = 0x27e4       # 技能书
oObjectBuffManager = 0x21B8     # Buff 管理器
oObjectVisibility = 0x28C       # 可见性
oObjectTargetable = 0xD1C       # 可选中
```

---

## 兼容性矩阵

### flyinput.dll 防检测体系兼容性

| 项目 | 注入方式 | 内存访问 | 输入模拟 | Hook | 兼容性 |
|------|---------|---------|---------|------|--------|
| **VakScript** | 独立进程 | 外部 RPM | pyautogui | 无 | 完美兼容 |
| **Lmeme** | 独立进程 | 外部 RPM | SendInput | 无 | 完美兼容 |
| **ExSharp-Base** | 独立进程 | 外部 RPM | SendInput | 无 | 兼容 |
| **KBot** | 内核驱动 | 驱动读 | SendInput | 无 | 升级路径 |
| **MagicOrbwalker** | 独立进程 | 外部 RPM | SendInput | 无 | 走砍参考 |
| **LeagueSharp** | 内部注入 | 直接访问 | Control.CastSpell | 大量 Hook | 不可用 |
| **aero-overlay** | 独立进程 | 无 | 无 | 无 | 完美兼容 |
| **StealthOverlay** | 独立进程 | 无 | 无 | 无 | 完美兼容 |

### flyinput.dll 当前架构限制

```
LeagueClient.exe（flyinput.dll 在这里）
    │
    │  可读：LeagueClient.exe 自身进程内存
    │  不可读：League of Legends.exe 对局进程
    │
    ▼
League of Legends.exe（游戏对局进程）
    └─ 血量、技能 CD、物品状态都在这里
```

**IAT 可用 API**：SendInput, GetAsyncKeyState, SetTimer, KillTimer, MapVirtualKeyA, GetModuleHandleA, GetProcAddress, Sleep, QueryPerformanceCounter

**IAT 缺失**：OpenProcess, ReadProcessMemory

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

## 推荐架构 (flyinput.dll + 外部辅助)

```
LeagueClient.exe
  └─ flyinput.dll（只读内存 + SendInput + 假点击）
      └─ 命名管道 IPC ←──┐
                          │
Overlay.exe（独立进程）   │
  ├─ aero-overlay 框架   │
  ├─ 读取 IPC ───────────┘
  ├─ 绘制攻击范围圆（借鉴 ExSharp-Base）
  └─ uiaccess + xorstr（借鉴 StealthOverlay）
```

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
