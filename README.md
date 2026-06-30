# LOL相关
> 英雄联盟辅助开发相关开源项目导航，按功能分类整理
> 适用场景：flyinput.dll 防检测体系（DLL劫持 + 只读内存 + SendInput 模拟）

## 分支导航

| 分支名称 | 说明 | 包含项目 |
|---------|------|---------|
| [外部辅助](../../tree/外部辅助) | 纯外部 RPM 读取，与 flyinput.dll "只看不做"理念兼容 | VakScript, Lmeme, ExSharp-Base, KBot, MagicOrbwalker, league-of-legends |
| [Overlay渲染](../../tree/Overlay渲染) | 外部 Overlay 进程，不破坏 DLL 防检测 | aero-overlay, StealthOverlay, imgui-external-overlay |
| [人类化输入](../../tree/人类化输入) | 鼠标/键盘人类化模拟算法参考 | FakeClicks, Wind Mouse, Bezier Mouse |
| [LeagueSharp](../../tree/LeagueSharp) | 内部 Hook 框架（参考架构，不可直接用） | LeagueSharp.Common |
| [反检测研究](../../tree/反检测研究) | Riot 反作弊检测手段研究 | External-Mitigations |
| [内存偏移与特征码](../../tree/内存偏移与特征码) | LOL 内存偏移、特征码扫描表 | Lmeme-offsets, Ovortex |
| [脚本参考](../../tree/脚本参考) | Lua/Python 英雄脚本，可参考连招逻辑 | Ezreal_zg, Caitlyn_zg |

## 项目列表

### 外部辅助

| 项目名称 | 作者 | Stars | 说明 |
|---------|------|-------|------|
| [VakScript](https://github.com/vakdev/VakScript) | [vakdev](https://github.com/vakdev) | 188 | Python 纯外部 RPM 辅助，明确声明不使用内部游戏函数，Target 优先级、Lasthit、Auto Smite、插件系统 |
| [Lmeme](https://github.com/hrt/Lmeme) | [hrt](https://github.com/hrt) | 57 | Python 外部辅助，**特征码扫描表**（oLocalPlayer/oObjectManager/oGameTime 等），解决版本失效问题 |
| [ExSharp-Base](https://github.com/ZeroLP/ExSharp-Base) | [ZeroLP](https://github.com/ZeroLP) | 155 | C# RPM + PixelSearch，CD 跟踪、敌方检测、攻击范围圆绘制 |
| [KBot](https://github.com/KebsCS/KBot) | [KebsCS](https://github.com/KebsCS) | 151 | C++ 内核驱动读取（升级路径参考），Evade、Orbwalker |
| [MagicOrbwalker](https://github.com/sajmonekk191/MagicOrbwalker) | [sajmonekk191](https://github.com/sajmonekk191) | 20 | C# 外部走砍，**2025-06 更新支持 14.x**，Attack Speed/Windup 时机计算 |
| [league-of-legends](https://github.com/campiohe/league-of-legends) | [campiohe](https://github.com/campiohe) | 37 | Python GDI Overlay 外部辅助，移动预测、Aim-Lock |

### Overlay渲染

| 项目名称 | 作者 | Stars | 说明 |
|---------|------|-------|------|
| [aero-overlay](https://github.com/ReactiioN1337/aero-overlay) | [ReactiioN1337](https://github.com/ReactiioN1337) | - | C++ D2D + DWrite 透明窗口框架，MIT 许可，最干净的 Overlay 模板 |
| [StealthOverlay](https://github.com/nertigel/StealthOverlay) | [nertigel](https://github.com/nertigel) | - | C++ D3D11 + ImGui，**Streamproof**（OBS 录屏不可见）+ uiaccess + xorstr |
| [imgui-external-overlay](https://github.com/3r4y/imgui-external-overlay) | [3r4y](https://github.com/3r4y) | 90 | C++ D3D9 + ImGui 通用外部 Overlay 模板 |

### 人类化输入

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [FakeClicks.cs](https://github.com/LeagueSharp/LeagueSharp.Common/blob/master/FakeClicks.cs) | LeagueSharp | C# 假点击实现，OnIssueOrder/OnNewPath 事件 → 0.15-0.35s 随机间隔 → Hud.ShowClick |
| [Wind Mouse 算法](https://github.com/BenLand100/SMART/blob/master/src/main/java/smart/ WindMouse.java) | BenLand100 | Java 鼠标风算法，模拟带"风"的鼠标轨迹（Pascal/Simba 起源） |
| [Bezier Mouse](https://github.com/BenLand100/SMART) | BenLand100 | 贝塞尔曲线鼠标轨迹，3-4 控制点 + 随机扰动 |
| [Perlin Noise Mouse](https://github.com/BenLand100/SMART) | BenLand100 | 柏林噪声生成平滑随机轨迹 |

### LeagueSharp（架构参考）

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [LeagueSharp.Common](https://github.com/LeagueSharp/LeagueSharp.Common) | LeagueSharp | C# 内部 Hook 框架，基于 Hook + 事件驱动 + 托管 API + 渲染注入 + 封包操作五位一体 |

**可用部分**（11 个）：Geometry.cs, MEC.cs, MapPositions.cs, ItemData.cs, WeightedRandom.cs, KeyboardEvents.cs, MouseEvents.cs, Keys.cs, WindowsMessages.cs, NativeMethods.cs, VirtualMouse.cs

**部分可用**（18 个）：Damage.cs, Prediction.cs, Spell.cs, TargetSelector.cs, HealthPrediction.cs, MinionManager.cs, Orbwalking.cs, Items.cs, AntiGapcloser.cs, Interrupter.cs/2.cs, Dash.cs, AutoLevel.cs, FakeClicks.cs, LastCastedSpell.cs, Utility.cs, Cursor.cs, Utils.cs 等

**完全不可用**（11 个）：ObjectHandler.cs, CustomEvents.cs, Hacks.cs, Packet.cs, GamePacket.cs, Shared.cs, Notifications.cs, Render.cs, PermaShow.cs, MenuWrapper.cs, Alerter.cs

### 反检测研究

| 项目名称 | 作者 | 说明 |
|---------|------|------|
| [External-Mitigations](https://github.com/ZeroLP/External-Mitigations) | [ZeroLP](https://github.com/ZeroLP) | C# **反向参考**：Riot 检测外部脚本的手段，了解检测原理以规避 |

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

### 脚本参考

| 文件 | 来源 | 说明 |
|------|------|------|
| Ezreal_zg.lua | Zgjfjfl AIO | 585 行 Ezreal 脚本，Q/W/R 技能预测、碰撞检测、补刀、W 标记检测 |
| Caitlyn_zg.lua | Zgjfjfl AIO | 565 行 Caitlyn 脚本，Q/W/E/R、爆头被动、EQ 连招、防 gank E 位移 |

**注意**：Lua 脚本基于内部 API（GGPrediction 等），flyinput.dll 不能直接使用，但可参考连招逻辑和技能时序。

---

## 兼容性矩阵

### flyinput.dll 防检测体系兼容性

| 项目 | 注入方式 | 内存访问 | 输入模拟 | Hook | 兼容性 |
|------|---------|---------|---------|------|--------|
| **VakScript** | 独立进程 | 外部 RPM | pyautogui | 无 | ★★★★★ 完美兼容 |
| **Lmeme** | 独立进程 | 外部 RPM | SendInput | 无 | ★★★★★ 完美兼容 |
| **ExSharp-Base** | 独立进程 | 外部 RPM | SendInput | 无 | ★★★★☆ 兼容 |
| **KBot** | 内核驱动 | 驱动读 | SendInput | 无 | ★★★☆☆ 升级路径 |
| **MagicOrbwalker** | 独立进程 | 外部 RPM | SendInput | 无 | ★★★☆☆ 走砍参考 |
| **LeagueSharp** | 内部注入 | 直接访问 | Control.CastSpell | 大量 Hook | ❌ 不可用 |
| **aero-overlay** | 独立进程 | 无 | 无 | 无 | ★★★★★ 完美兼容 |
| **StealthOverlay** | 独立进程 | 无 | 无 | 无 | ★★★★★ 完美兼容 |

### flyinput.dll 当前架构限制

```
LeagueClient.exe（flyinput.dll 在这里）
    │
    │  ✅ 可读：LeagueClient.exe 自身进程内存（GetModuleHandleA + 指针解引用）
    │  ❌ 不可读：League of Legends.exe 对局进程（无 OpenProcess + ReadProcessMemory）
    │
    ▼
League of Legends.exe（游戏对局进程）
    └─ 血量、技能 CD、物品状态都在这里
```

**IAT 可用 API**：
- ✅ SendInput, GetAsyncKeyState, SetTimer, KillTimer, MapVirtualKeyA
- ✅ GetModuleHandleA, GetProcAddress, Sleep, QueryPerformanceCounter
- ❌ OpenProcess, ReadProcessMemory（未导入）

---

## flyinput.dll 防检测体系设计

### 核心原则："只看不做"

| 原则 | 实现 | 检测面 |
|------|------|--------|
| DLL 劫持注入 | 伪装为 dbgcore.dll | 低 |
| 只读游戏内存 | 直接指针解引用（不 Hook） | 无 |
| 输入模拟 | SendInput（全局输入事件） | 低 |
| 不 Hook 游戏函数 | 无函数 Hook | 无 |
| 不修改游戏内存 | 只读不写 | 无 |
| 不注入渲染 | 无 D3D Hook | 无 |
| 不操作封包 | 无网络栈修改 | 无 |

### 防检测对比

| 方案 | 注入 | 内存读 | Hook | 封包 | 渲染 | 检测风险 |
|------|------|-------|------|------|------|---------|
| **flyinput.dll** | DLL 劫持 | 内部直接读 | 无 | 无 | 无 | ★ 最低 |
| LeagueSharp | 内部注入 | 直接访问 | 大量 | 有 | 有 | ★★★★★ 最高 |
| VakScript | 独立进程 | 外部 RPM | 无 | 无 | 无 | ★★ 低 |
| KBot | 内核驱动 | 驱动读 | 无 | 无 | 无 | ★★ 低 |

---

## 推荐架构（flyinput.dll + 外部辅助）

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

**关键点**：Overlay 必须是独立 .exe 进程，不与 flyinput.dll 同进程，否则 DLL 卸载会一起挂掉。

---

## 使用说明

1. 点击上方分支名称查看对应分类的详细说明
2. 每个分支包含该分类下所有项目的详细介绍和链接
3. 项目标注「原创」表示本人开发，「Fork」表示收藏的优秀项目
4. **兼容性矩阵** 标注了每个项目与 flyinput.dll 防检测体系的兼容程度

## 贡献

欢迎推荐更多优质项目！

## 相关仓库

- [toolkit](https://github.com/zadmg/toolkit) - 通用工具集导航
