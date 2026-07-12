/*
 * =====================================================================
 * flyinput.dll 完整逆向分析报告
 * 英雄联盟 (League of Legends) 辅助程序
 * =====================================================================
 * 文件: enhr_pe2_unpacked.exe (实际为 flyinput.dll)
 * 大小: 96,256 字节
 * 格式: PE32+ x64 DLL
 * 基址: 0x180000000
 * 编译: MSVC 2015+ (使用 VCRUNTIME140.dll, MSVCP140.dll)
 * =====================================================================
 */

=====================================================================
一、程序架构概览
=====================================================================

1. 入口点: DllMain (0x180015A20)
   - 标准 CRT 初始化
   - 调用 _initterm 初始化全局对象
   - 注册 DisableThreadLibraryCalls

2. 工作线程: StartAddress (0x180012C10)
   - 功能: 主工作线程入口
   - 反调试: 调用 NtSetInformationThread(ThreadHideFromDebugger, 0x11)
   - 等待事件触发，循环处理游戏逻辑
   - 通过 [r14+0xe8/e9] 标志位控制运行状态

3. 定时器: TimerFunc (0x180014020)
   - 功能: 配置热加载/菜单交互 (4路switch)
   - Case 0: KillTimer(1), 启动主逻辑
   - Case 1: KillTimer(3), 处理配置变更(哈希比对)
   - Case 2: KillTimer(2), 停止主逻辑
   - Case 3: KillTimer(4), 处理另一种配置变更

4. 主循环初始化: sub_1800134E0
   - 分配多个内部数据结构
   - 设置函数指针表
   - 使用魔数哈希管理配置项

=====================================================================
二、虚拟键码 (VK_*) 绑定表
=====================================================================

从 GetAsyncKeyState 调用中提取的键码:

| 地址       | 虚拟键码         | 值    | 功能上下文                          |
|-----------|-----------------|-------|------------------------------------|
| 0x4CBD    | VK_SPACE        | 0x20  | 走砍/攻击键 (Ashe/Kaia逻辑)         |
| 0x623D    | VK_SPACE        | 0x20  | 走砍/攻击键 (Kaisa E逻辑)           |
| 0x6C70    | VK_C            | 0x43  | Kaia E 自动施放开关                 |
| 0x12C49   | VK_CONTROL      | 0x11  | NtSetInformationThread参数(非按键)   |

注意: 大部分键码绑定通过全局配置结构体动态读取，而非硬编码。
      结构体中的键码字段位于 +0x20, +0x28, +0x30, +0x38 等位置，
      这些在运行时从配置文件或菜单中加载。

=====================================================================
三、游戏内存偏移量完全列表
=====================================================================

3.1 全局/基址偏移 (从游戏模块基址):

| 偏移量        | 用途描述                              |
|--------------|--------------------------------------|
| 0x1EAD040    | 游戏主状态指针 (首个访问的偏移)        |
| 0x1E99000    | 游戏数据区域1                         |
| 0x1E9E118    | 游戏数据区域2                         |
| 0x1E9E188    | 游戏数据区域3 (频繁使用)              |
| 0x1EA1280    | 游戏数据区域4                         |
| 0x1EA12B0    | 对象列表指针 (包含所有游戏对象)        |
| 0x1EA1498    | 游戏数据区域5                         |
| 0x1EA5B10    | 游戏数据区域6                         |
| 0x1EAA040    | 游戏数据区域7                         |
| 0x1EDC3A8    | 游戏数据区域8                         |
| 0x1F7BA18    | 游戏数据区域9                         |

3.2 游戏对象结构体 (Object):

| 偏移量   | 类型    | 描述                              |
|---------|--------|-----------------------------------|
| +0x200  | double | 位置 X 坐标                        |
| +0x208  | float  | 位置 Z 坐标 (高度)                  |
| +0x259  | byte   | 队伍ID (判断敌我)                   |
| +0x308  | byte   | 可见性标志 (1=可见)                 |
| +0x360  | float  | 攻击范围/某属性                     |
| +0x6F8  | float  | 碰撞半径 (BoundingRadius)           |
| +0x1080 | float  | 当前生命值 (HP)                     |
| +0x1120 | float  | 生命值相关 (可能是护盾/额外HP)       |
| +0xED0  | byte   | 可选中/可攻击标志 (1=可攻击)         |
| +0x4370 | string | 对象名称 (SSO, <16字节直接存)        |
| +0x4380 | size_t | 对象名称长度                        |

3.3 本地玩家/英雄结构体 (LocalPlayer):

| 偏移量    | 类型     | 描述                              |
|----------|---------|-----------------------------------|
| +0x28    | byte    | 等级/索引                          |
| +0x30    | float   | 冷却/计时器                        |
| +0x130   | ptr     | 技能书指针 (SpellBook)              |
| +0x360   | float   | 攻击范围 (AttackRange)              |
| +0x14A0  | dword   | 功能标志位 (bitfield)               |
| +0x16B8  | float   | 技能数据 (与Twitch相关)             |
| +0x16D0  | float   | 技能数据 (与Twitch相关)             |
| +0x1710  | float   | 基础攻击力 (BaseAD)                 |
| +0x17B4  | float   | 额外攻击力 (BonusAD)                |
| +0x17DC  | float   | Twitch E 相关伤害                  |
| +0x17FC  | float   | 攻击范围 (备用)                     |
| +0x2E90  | ptr     | 技能列表指针                        |
| +0x2E98  | ptr     | 技能列表结束指针                    |
| +0x3C10  | ptr     | 本地玩家对象指针偏移                |
| +0x4120  | ptr     | 配置数据指针                        |
| +0x4140  | dword   | 配置值 (与TimerFunc配合)            |

3.4 技能结构体 (Spell):

| 偏移量   | 类型    | 描述                              |
|---------|--------|-----------------------------------|
| +0x0C   | byte   | 技能槽位 (0=Q, 1=W, 2=E, 3=R, 0x18=被动, 0x1A=?) |
| +0x10   | ptr    | 技能数据指针                       |
| +0x38   | byte   | 技能等级 (0=未学习)                |
| +0x8C   | byte   | 某些标志                           |

3.5 技能数据结构体 (SpellData):

| 偏移量   | 类型    | 描述                              |
|---------|--------|-----------------------------------|
| +0x08   | ptr    | 技能名称指针                       |
| +0x28   | string | 技能名称 (如 "PickACard")         |

3.6 配置哈希表结构体 (Config):

| 偏移量    | 类型    | 描述                              |
|----------|--------|-----------------------------------|
| +0x00    | qword  | 哈希键 (128位)                     |
| +0x08    | dword  | 范围下限                           |
| +0x0C    | dword  | 范围上限                           |
| +0x10    | ptr    | 数据起始                           |
| +0x18    | ptr    | 数据结束                           |
| +0x28    |        | 条目大小 (0x28)                    |

3.7 常量/魔法数字:

| 值                  | 用途                              |
|--------------------|-----------------------------------|
| 0x16E3600          | 游戏版本/时间检测 (23,976,960)      |
| 0x989680           | 游戏版本/时间检测 (10,000,000)      |
| 0x3B9ACA00         | 1,000,000,000 (纳秒/100ns转换)     |
| 0x5265C00          | 86,400,000 (毫秒/天)               |
| 0x4E94914F0000     | 阈值常量                           |
| 0x431BDE82D7B634DB | 时间除法魔数                        |
| 0x5555555555555556 | 除法魔数 (用于 /3)                  |
| 0x7FFFFFFFFFFFFFFF | INT64_MAX                         |
| 0xF4240            | 1,000,000 (微秒转换)               |
| 0xCBF29CE484222325 | FNV-1a hash 初始值 (offset basis)  |
| 0x100000001B3      | FNV-1a hash 素数                   |

=====================================================================
四、英雄专属逻辑
=====================================================================

4.1 卡牌大师 - 崔斯特 (Twisted Fate) - Pick A Card
   函数: sub_1800150E0 (RVA: 0x150E0)
   
   逻辑:
   1. 读取本地玩家: [base + 0x3C10]
   2. 检查功能开关: [base + 0x14A0] bit 2 (值 0x04)
   3. 读取技能书: [localPlayer + 0x130]
   4. 读取技能名称: [spellBook + 0x28]
   5. 比较技能名是否为 "PickACard" (0x726143416B636950)
   6. 对比阈值: [base + 0x360] vs [base + rdx*4 + 0x2D8]
   7. 循环等待: 每次 sleep(10ms)，最多循环 0xB (11) 次
   8. 当卡牌变成目标颜色时退出循环
   
   字符串引用:
   - "PickACar"    (0x17490) - 蓝牌
   - "BlueCard"    (0x17499) - 蓝牌
   - "GoldCard"    (0x174A2) - 黄牌
   - "RedCard"     (0x174AB) - 红牌
   - "PickACarI98" (0x15134) - 变体引用

4.2 寒冰射手 - 艾希 (Ashe) - Q技能
   函数: sub_180004BB0 (RVA: 0x4BB0)
   字符串: "AsheQCasM9" (0x4F74)
   
   逻辑:
   1. 检查全局使能标志: [rip + 0x14474] bit 0
   2. 检查游戏状态: [rip + 0x146B5] 和 [rip + 0x146B1]
   3. 调用 GetAsyncKeyState(VK_SPACE) 检测走砍键
   4. 状态机管理: 使用 [rip + 0x14733] 标志位
   5. 检查功能开关: [rcx + 0x14A0] bit 0
   6. 搜索技能列表: [rcx + 0x2E90]
   7. 遍历技能，查找技能槽 0x1A，名称匹配 "KaisaE" (实际也处理Kaisa)
   8. 自动施放逻辑

4.3 虚空之女 - 卡莎 (Kai'Sa) - E技能
   函数: sub_180006130 (RVA: 0x6130)
   字符串: "KaisaE" (0x632B, 0x669B, 0x6D4B)
   
   逻辑:
   1. 检查全局使能标志: [rip + 0x12EF4] bit 0
   2. 检查游戏状态: [rip + 0x13135] 和 [rip + 0x13131]
   3. 调用 GetAsyncKeyState(VK_SPACE) 检测走砍键
   4. 状态机管理: 使用 [rip + 0x131B2] 标志位
   5. 检查功能开关: [rcx + 0x14A0] bit 0
   6. 搜索技能列表: [rcx + 0x2E90]
   7. 查找技能槽 2 (E技能)，名称匹配 "KaisaE"
   8. 自动瞄准/走砍逻辑:
      - 遍历所有敌方对象
      - 检查队伍: [obj + 0x259] != [local + 0x259]
      - 检查可见性: [obj + 0x308] == 1
      - 检查可攻击: [obj + 0xED0] == 1
      - 计算距离: sqrt((dx)^2 + (dy)^2)
      - 检查攻击范围: distance <= attackRange + boundingRadius
      - 检查HP: [obj + 0x1080] <= [local + 0x1710] + [local + 0x17B4]
      - 世界坐标转屏幕坐标 (矩阵乘法)
      - SendInput 发送鼠标移动事件
   9. 额外: GetAsyncKeyState(VK_C) 检测另一个热键
      - 检查 [rcx + 0x14A0] bit 3 (值 0x08)
      - 自动施放逻辑

4.4 瘟疫之源 - 图奇 (Twitch) - E技能伤害计算
   函数: sub_180012960 (RVA: 0x12960)
   字符串: "TwitchDe" (0x12978) = "TwitchDe..."
   
   逻辑:
   1. 搜索技能列表 [rcx + 0x2E90]
   2. 查找技能类型 0x18 (24)，名称匹配 "TwitchDe"
   3. 读取技能数据:
      - [base + 0x16B8]: 基础伤害
      - [base + 0x16D0]: 每层伤害
      - [rcx + 0x17DC]: 目标相关
   4. 使用3级哈希表累加伤害:
      - 第1级哈希: 0xF38433EC8F69355A
      - 第2级哈希: 0xED5A926F3C152571
      - 第3级哈希: 0xE617C1FE6EFC9C79
   5. 计算总伤害用于判断是否可斩杀

4.5 复仇之矛 - 卡莉斯塔 (Kalista) - E技能
   函数: sub_180013070 (RVA: 0x13070)
   字符串: "kalistae" (0x1309B)
   
   逻辑:
   1. 读取本地玩家: [base + 0x3C10]
   2. 检查: [rsi + 0x28] 和 [rsi + 0x30]
   3. 读取技能书: [rsi + 0x130]
   4. 读取技能名称: [rsi + 0x28]
   5. 比较是否为 "kalistae"
   6. 类似伤害计算逻辑

=====================================================================
五、核心功能实现分析
=====================================================================

5.1 走砍逻辑 (Orbwalker)
   位于: sub_180006130 (Kaisa E), sub_180004BB0 (Ashe Q) 等函数中
   
   核心流程:
   1. 按键检测: GetAsyncKeyState(VK_SPACE) 检测攻击键
   2. 目标选择:
      a. 遍历对象列表 [base + 0x1EA12B0]
      b. 过滤: 敌方 ([obj+0x259] != [local+0x259])
      c. 过滤: 可见 ([obj+0x308] == 1)
      d. 过滤: 可攻击 ([obj+0xED0] == 1)
      e. 过滤: 存活 ([obj+0x1080] > 0)
   3. 距离计算:
      a. 读取双方位置: [obj+0x200], [obj+0x208]
      b. 计算欧氏距离: vdpps xmm0, delta, delta, 0x7F
      c. 攻击范围: [local+0x17FC] + bounding radii
      d. 比较: distance <= (attackRange + bound1 + bound2)^2
   4. 目标优先级:
      a. 最近目标优先
      b. 可斩杀目标优先 ([obj+0x1080] <= AD)
   5. 自动攻击:
      a. 世界坐标→屏幕坐标转换 (4x4矩阵乘法)
      b. SendInput 移动鼠标到目标位置
      c. 发送右键点击 (通过 SendInput)

5.2 视距调节 (Zoom Hack)
   - 未在代码中显式发现视距调节逻辑
   - 可能通过内存写入实现，但在反编译代码中未见直接证据
   - 相关偏移 0x1E99000 等可能用于此目的

5.3 攻击范围显示 (Attack Range Indicator)
   - 通过读取 [local+0x360] 和 [local+0x17FC] 获取攻击范围
   - 在 sub_180012DA0 和 sub_180006130 中均有使用
   - 范围 = 攻击范围 + 自身碰撞半径 + 目标碰撞半径
   - 通过世界坐标到屏幕坐标转换后绘制

5.4 清线逻辑 (Lane Clear)
   - 在 sub_180006130 中有第二个目标选择循环
   - 遍历小兵/野怪对象: [obj+0x259] 比较
   - 特别处理野怪: "sru_drag"(龙), "SRU_Baro"(男爵), "SRU_Atak"(塔)
   - 使用 [r14 + rdx*4 + 0x5C8] 作为小兵攻击范围
   - 使用 [r14 + rdx*4 + 0x590] 作为阈值

5.5 野怪/史诗怪物检测
   位于: sub_180012700, sub_180012DA0
   
   检测对象名:
   - "sru_drag" = 龙 (Dragon)
   - "SRU_Baro" = 纳什男爵 (Baron Nashor)
   - "SRU_Atak" = 塔 (Tower)
   
   检测逻辑:
   1. 读取对象名: [obj + 0x4370]
   2. 比较魔数:
      - 0x676172645F757273 = "sru_drag" (小端)
      - 0x6F7261425F555253 = "SRU_Baro" (小端)
      - 0x6B6174415F555253 = "SRU_Atak" (小端)
   3. 对野怪计算血量: [obj+0x1120] + [obj+0x1080]

=====================================================================
六、隐藏功能
=====================================================================

6.1 反调试保护
   位置: sub_180001180 (0x1180), StartAddress (0x12C10)
   方法: NtSetInformationThread(Thread, 0x11, 0, 0)
   其中 0x11 = ThreadHideFromDebugger (17)
   注意: 这是未文档化的ntdll函数，用于隐藏线程不被调试器检测

6.2 配置动态加载
   位置: TimerFunc (0x14020)
   - 使用 FNV-1a 哈希 (offset basis: 0xCBF29CE484222325, prime: 0x100000001B3)
   - 对配置数据进行哈希比较
   - 支持运行时热更新配置，无需重启

6.3 自动技能施放
   - 多个英雄有自动施放逻辑
   - 条件: 走砍键按下 + 技能可用 + 目标在范围内
   - 不同于菜单中明示的功能

6.4 伤害计算引擎
   - Twitch E 的3级哈希表累加伤害计算
   - 用于判断是否可斩杀
   - 可能也用于其他英雄的斩杀判断

6.5 世界坐标→屏幕坐标转换
   - 使用4x4视图矩阵 (view matrix)
   - 在 sub_180006130 中实现
   - 矩阵乘法: vbroadcastf128 + vfmadd213ps 系列指令
   - 用于各种绘制功能 (攻击范围、技能指示器等)

=====================================================================
七、结构体定义 (C语言)
=====================================================================

typedef struct {
    char     pad_0000[0x200];
    double   posX;           // +0x200
    float    posZ;           // +0x208
    char     pad_020C[0x4D];
    uint8_t  teamId;         // +0x259
    char     pad_025A[0xAE];
    uint8_t  isVisible;      // +0x308
    char     pad_0309[0x57];
    float    attackRange;    // +0x360
    char     pad_0364[0x394];
    float    boundingRadius; // +0x6F8
    char     pad_06FC[0x384];
    float    currentHP;      // +0x1080
    float    bonusHP;        // +0x1120
    char     pad_1124[0xDAC];
    uint8_t  isTargetable;   // +0xED0
    char     pad_0ED1[0x349F];
    char     objectName[16]; // +0x4370 (SSO)
    size_t   nameLength;     // +0x4380
} GameObject;

typedef struct {
    char     pad_0000[0x28];
    uint8_t  level;          // +0x28
    float    cooldown;       // +0x30
    char     pad_0034[0xFC];
    void*    spellBook;      // +0x130
    char     pad_0138[0x228];
    float    attackRange;    // +0x360
    char     pad_0364[0x113C];
    uint32_t featureFlags;   // +0x14A0
    char     pad_14A4[0x214];
    float    spellData1;     // +0x16B8
    float    spellData2;     // +0x16D0
    char     pad_16D4[0x3C];
    float    baseAD;         // +0x1710
    float    bonusAD;        // +0x17B4
    float    twitchEData;    // +0x17DC
    float    attackRange2;   // +0x17FC
    char     pad_1800[0x1690];
    void*    spellList;      // +0x2E90
    void*    spellListEnd;   // +0x2E98
    char     pad_2E9C[0xD74];
    void*    localPlayer;    // +0x3C10
    char     pad_3C14[0x50C];
    void*    configData;     // +0x4120
    uint32_t configValue;    // +0x4140
} LocalPlayer;

typedef struct {
    char     pad_0000[0x0C];
    uint8_t  spellSlot;      // +0x0C
    void*    spellData;      // +0x10
    char     pad_0018[0x20];
    uint8_t  spellLevel;     // +0x38
    char     pad_0039[0x53];
    uint8_t  flags;          // +0x8C
} Spell;

typedef struct {
    char     pad_0000[0x08];
    char*    spellName;      // +0x08
    char     pad_0010[0x18];
} SpellData;

=====================================================================
八、函数表
=====================================================================

| RVA      | 函数名            | 描述                              |
|----------|-------------------|-----------------------------------|
| 0x01180  | sub_180001180     | 核心初始化 (反调试+全局指针建立)     |
| 0x049F0  | sub_1800049F0     | 精确定时器/Sleep函数               |
| 0x04BB0  | sub_180004BB0     | Ashe Q + Kaisa 自动施放            |
| 0x06130  | sub_180006130     | Kaisa E 走砍+自动瞄准              |
| 0x076B0  | sub_1800076B0     | 大处理函数 (模板实例化)            |
| 0x08CD0  | sub_180008CD0     | 大处理函数 (模板实例化)            |
| 0x0A3A0  | sub_18000A3A0     | 大处理函数 (模板实例化)            |
| 0x0B8D0  | sub_18000B8D0     | 大处理函数 (模板实例化)            |
| 0x0CE80  | sub_18000CE80     | 大处理函数 (模板实例化)            |
| 0x0E660  | sub_18000E660     | 野怪处理 (sru_drag/SRU_Baro/SRU_Atak) |
| 0x0FC20  | sub_18000FC20     | 大处理函数 (模板实例化)            |
| 0x111D0  | sub_1800111D0     | 大处理函数 (模板实例化)            |
| 0x12700  | sub_180012700     | 初始化+野怪检测                    |
| 0x12960  | sub_180012960     | Twitch E 伤害计算                  |
| 0x12C10  | StartAddress      | 工作线程入口                       |
| 0x12DA0  | sub_180012DA0     | 游戏内存读取+目标选择               |
| 0x13070  | sub_180013070     | Kalista E 逻辑                     |
| 0x134E0  | sub_1800134E0     | 主循环初始化                       |
| 0x13E90  | sub_180013E90     | 辅助函数                           |
| 0x13F80  | sub_180013F80     | 辅助函数                           |
| 0x14020  | TimerFunc         | 定时器回调 (配置热加载)            |
| 0x14240  | sub_180014240     | 主逻辑入口                         |
| 0x149F0  | sub_1800149F0     | DLL 初始化相关                     |
| 0x150E0  | sub_1800150E0     | 卡牌切牌 (Pick A Card)             |
| 0x15490  | sub_180015490     | CRT 入口                           |
| 0x15A20  | DllMain           | DLL 入口点                         |
| 0x16090  | sub_180016090     | 内部函数 (异常处理)                |
| 0x160A0  | sub_1800160A0     | 内部函数 (终止)                    |
| 0x160D0  | sub_1800160D0     | 内部函数                           |
| 0x160E0  | sub_1800160E0     | 内部函数 (等待事件)                |
| 0x160F0  | sub_1800160F0     | 内部函数 (事件状态)                |
| 0x16100  | sub_180016100     | 内部函数 (获取事件)                |
| 0x16110  | sub_180016110     | 内部函数 (获取时间1)               |
| 0x16120  | sub_180016120     | 内部函数 (获取时间2)               |
| 0x16270  | sub_180016270     | 内部函数 (malloc)                  |

=====================================================================
九、关键导入函数
=====================================================================

USER32.dll:
  - GetAsyncKeyState   : 检测按键状态
  - SendInput          : 模拟鼠标/键盘输入
  - SetTimer           : 创建定时器
  - KillTimer          : 销毁定时器
  - MapVirtualKeyA     : 虚拟键码转换

KERNEL32.dll:
  - GetModuleHandleA   : 获取模块句柄 (用于反调试)
  - GetProcAddress     : 获取函数地址 (用于反调试)
  - GetSystemTimeAsFileTime : 系统时间
  - QueryPerformanceCounter : 高精度计时
  - Sleep              : 线程休眠

MSVCP140.dll:
  - _Cnd_broadcast, _Cnd_wait : 条件变量
  - _Mtx_lock, _Mtx_unlock   : 互斥锁
  - _Thrd_detach, _Thrd_join : 线程管理

=====================================================================
十、野怪字符串完整列表
=====================================================================

从 .rdata 段提取的所有游戏相关字符串:

LOL 对象相关:
  - "sru_drag"    : 元素龙 (Dragon)
  - "SRU_Baro"    : 纳什男爵 (Baron Nashor)
  - "SRU_Atak"    : 防御塔 (Tower)

英雄技能相关:
  - "PickACar"    : 卡牌 W - 选牌
  - "BlueCard"    : 卡牌 蓝牌
  - "GoldCard"    : 卡牌 黄牌
  - "RedCard"     : 卡牌 红牌
  - "PickACarI98" : 卡牌 W 变体
  - "AsheQCasM9"  : 艾希 Q - 射手的专注
  - "KaisaE"      : 卡莎 E - 超级充能
  - "kalistae"    : 卡莉斯塔 E - 撕裂
  - "TwitchDe"    : 图奇 E - 毒性爆发

皮肤/外观相关:
  - "Iron Revenant"    : 铁男皮肤
  - "Fins"             : 小鱼人皮肤
  - "Royal arms"       : 皇室武器
  - "Hall of Legends"  : 名人堂
  - "Zero hour"        : 零时
  - "Scarlet fair"     : 猩红集市
  - "LuxAir"           : 拉克丝 风
  - "LuxWater"         : 拉克丝 水
  - "LuxStorm"         : 拉克丝 风暴
  - "LuxDark"          : 拉克丝 暗
  - "LuxNature"        : 拉克丝 自然
  - "LuxFire"          : 拉克丝 火
  - "LuxIce"           : 拉克丝 冰
  - "LuxMystic"        : 拉克丝 神秘
  - "LuxMagma"         : 拉克丝 岩浆
  - "Starswarm"        : 星群
  - "Sahn-Uzal"        : 萨恩-乌祖尔
  - "Unconquered King" : 不败之王
  - "Head on" / "Head off" : 头盔开关
  - "Without hood" / "With hood" : 兜帽开关
  - "Risen Legend"     : 崛起传说
  - "Immortalized Legend" : 不朽传说
  - "Parallel world"   : 平行世界
  - "Blue" / "Gold" / "Ultimate" : 颜色/终极

音效相关:
  - "SonaDJGenre02" / "SonaDJGenre03" : 琴女DJ音效

这些皮肤/外观字符串暗示该辅助可能包含皮肤修改功能(换肤)。

=====================================================================
十一、反编译结果文件
=====================================================================

1. D:\SRC\SRC\decompiled_src\flyinput_full_decompiled.c
   - 完整反汇编输出 (所有26个关键函数)
   
2. D:\SRC\SRC\decompiled_src\strings.txt
   - 所有659个字符串及其地址

3. D:\SRC\SRC\analyze_flyinput.py
   - PE分析和字符串提取脚本

4. D:\SRC\SRC\analyze_flyinput_v2.py
   - 完整反汇编脚本

5. D:\SRC\SRC\analyze_flyinput_v3.py
   - 深度分析脚本 (GetAsyncKeyState/偏移/英雄逻辑)

=====================================================================
* 报告完成
* 分析日期: 2026-06-28
* 分析工具: Python 3.11 + pefile 2024.8.26 + capstone 5.0.7
=====================================================================
*/