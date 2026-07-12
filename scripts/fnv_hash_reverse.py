#!/usr/bin/env python3
"""
flyinput.dll FNV-1a 哈希值反向解析 - 完整分析 v2
目标：反向匹配代码中硬编码的 17 个 FNV-1a 哈希值
"""
import struct, os, itertools, string, sys

# ============================================================
# FNV-1a 哈希函数
# ============================================================
FNV_BASIS = 0xCBF29CE484222325
FNV_PRIME = 0x100000001B3

def fnv1a_64(data: bytes) -> int:
    h = FNV_BASIS
    for b in data:
        h = ((h ^ b) * FNV_PRIME) & 0xFFFFFFFFFFFFFFFF
    return h

def fnv1a_str(s: str) -> int:
    return fnv1a_64(s.encode('utf-8'))

# ============================================================
# 目标哈希值（从反编译代码中提取）
# ============================================================
# 10 个哈希表条目（在 sub_180001180 中，行 525-590）
hash_table = {
    0x112D788B5B855BEE: "unk_180017210 (offset 0x00)",
    0x77EE2DDFA384BEA0: "unk_180017220 (offset 0x10)",
    0xAD1C144669DB1514: "unk_180017230 (offset 0x20)",
    0x1A47746099CAAD97: "unk_180017240 (offset 0x30)",
    0x19BF8DB558FEDB42: "unk_180017250 (offset 0x40)",
    0xB173594E60E46B49: "unk_180017260 (offset 0x50)",
    0x0D1C29E7AD935C17: "unk_180017270 (offset 0x60)",
    0xDE3BC2BFB3A73E2A: "unk_180017280 (offset 0x70)",
    0x7A22BC4C07AC1888: "unk_180017290 (offset 0x80)",
    0x98DD22A3CCBC7773: "unk_1800172A0 (offset 0x90)",
}

# 额外哈希值（在 sub_180001180 和 sub_1800111D0 中）
extra_hashes = {
    0x8ABFF924F2288F6E: "sub_180001180 行 933/948/964/974 - 树查找键",
    0x254B9819B8CFB5E6: "sub_180001180 行 1146/1175/1182 - 树查找键",
    0xB509E7DE614B86C2: "sub_1800111D0 行 8270 - 条件检查",
    0x7734BE05A394D5E2: "sub_1800111D0 行 7354/8257 - 与 Dagger1/Dagger3 关联",
    0x33055511E147AE6B: "sub_1800111D0 行 7368/8258 - 与 Head off 关联",
    0xBEE5A1E555549E3A: "sub_1800111D0 行 7380/8259 - 与 Scarlet fair 关联",
    0x76B75EAD90784E9E: "sub_1800111D0 行 7392 - 与 Level 1 关联",
}

all_target_hashes = {**hash_table, **extra_hashes}

# ============================================================
# LOL 字典
# ============================================================
lol_champions = [
    "Aatrox","Ahri","Akali","Akshan","Alistar","Amumu","Anivia","Annie","Aphelios","Ashe",
    "AurelionSol","Aurora","Azir","Bard","Belveth","Blitzcrank","Brand","Braum","Briar",
    "Caitlyn","Camille","Cassiopeia","Chogath","Corki","Darius","Diana","Draven","DrMundo",
    "Ekko","Elise","Evelynn","Ezreal","Fiddlesticks","Fiora","Fizz","Galio","Gangplank",
    "Garen","Gnar","Gragas","Graves","Gwen","Hecarim","Heimerdinger","Hwei","Illaoi","Irelia",
    "Ivern","Janna","JarvanIV","Jax","Jayce","Jhin","Jinx","Kaisa","Kalista","Karma","Karthus",
    "Kassadin","Katarina","Kayle","Kayn","Kennen","KhaZix","Kindred","Kled","KogMaw","KSante",
    "Leblanc","LeeSin","Leona","Lillia","Lissandra","Lucian","Lulu","Lux","Malphite","Malzahar",
    "Maokai","MasterYi","Mel","Milio","MissFortune","Mordekaiser","Morgana","Naafiri","Nami",
    "Nasus","Nautilus","Neeko","Nidalee","Nilah","Nocturne","Nunu","NunuWillump","Olaf",
    "Orianna","Ornn","Pantheon","Poppy","Pyke","Qiyana","Quinn","Rakan","Rammus","RekSai",
    "Rell","Renata","RenataGlasc","Renekton","Rengar","Riven","Rumble","Ryze","Samira","Sejuani",
    "Senna","Seraphine","Sett","Shaco","Shen","Shyvana","Singed","Sion","Sivir","Skarner",
    "Smolder","Sona","Soraka","Swain","Sylas","Syndra","TahmKench","Taliyah","Talon","Taric",
    "Teemo","Thresh","Tristana","Trundle","Tryndamere","TwistedFate","Twitch","Udyr","Urgot",
    "Varus","Vayne","Veigar","Velkoz","Vex","Vi","Viego","Viktor","Vladimir","Volibear",
    "Warwick","Wukong","Xayah","Xerath","XinZhao","Yasuo","Yone","Yorick","Yuumi","Zac","Zed",
    "Zeri","Ziggs","Zilean","Zoe","Zyra",
]

# LOL 技能名
champion_spells = []
for champ in lol_champions:
    for suffix in ["Q","W","E","R","Passive","BasicAttack","BasicAttack2","CritAttack",
                   "Q1","Q2","W1","W2","E1","E2","R1","R2"]:
        champion_spells.append(f"{champ}{suffix}")

# LOL 野怪
jungle_monsters = [
    "SRU_Dragon","SRU_Baron","SRU_Herald","SRU_Atakhan","SRU_Blue","SRU_Red","SRU_Gromp",
    "SRU_Wolf","SRU_Raptor","SRU_Krug","SRU_Murkwolf","SRU_Razorbeak","SRU_Crab","SRU_Scuttle",
    "SRU_RiftHerald","SRU_Voidgrub","SRU_Dragon_Elder","SRU_Dragon_Fire","SRU_Dragon_Water",
    "SRU_Dragon_Air","SRU_Dragon_Earth","SRU_Dragon_Chemtech","SRU_Dragon_Hextech",
    "sru_dragon","sru_baron","sru_herald","sru_atakhan","sru_blue","sru_red","sru_gromp",
    "sru_wolf","sru_raptor","sru_krug","sru_murkwolf","sru_razorbeak","sru_crab","sru_scuttle",
    "sru_dragonElder","sru_dragonFire","sru_dragonWater","sru_dragonAir",
    "sru_dragonEarth","sru_dragonChemtech","sru_dragonHextech",
    "Dragon","Baron","Herald","Atakhan","Blue","Red","Gromp","Wolf","Raptor","Krug","Crab",
    "dragon","baron","herald","atakhan","blue","red","gromp","wolf","raptor","krug","crab",
    "SRU_Chaos","SRU_Order","sru_chaos","sru_order",
]

# LOL 地图目标
map_objects = [
    "Turret","Inhibitor","Nexus","turret","inhibitor","nexus",
    "Turret_T1","Turret_T2","Turret_T3","Turret_T4",
    "Turret_L1","Turret_L2","Turret_L3","Turret_C1","Turret_C2","Turret_C3",
    "Inhibitor_L","Inhibitor_C","Inhibitor_R",
    "Nexus_L","Nexus_R","Nexus_C",
    "HQ","HQ_T","HQ_L","HQ_C","HQ_R",
    "Order","Chaos","order","chaos",
    "SRU_Order","SRU_Chaos","sru_order","sru_chaos",
    "Minion","minion","SuperMinion","SiegeMinion","CasterMinion","MeleeMinion",
    "SRU_OrderMinion","SRU_ChaosMinion",
]

# LOL 皮肤主题
skin_themes = [
    "Air","Water","Storm","Dark","Nature","Fire","Ice","Mystic","Magma",
    "Light","Shadow","Iron","Silver","Gold","Diamond","Crystal","Ruby",
    "Sapphire","Emerald","Jade","Pearl","Amethyst","Topaz","Obsidian",
    "Classic","Default","Original","Prime","Alpha","Omega","Deluxe","Special",
    "Normal","Custom","Ultimate","Mythic","Legendary","Epic","Rare","Prestige",
    "Arcade","Battle","Boss","Project","Program","Mecha","Pulsefire","Battlecast",
    "StarGuardian","Odyssey","DarkStar","Cosmic","HighNoon","SpiritBlossom","Coven",
    "BloodMoon","SnowMoon","Lunar","Solar","Eclipse","Nightbringer","Dawnbringer",
    "GodKing","PoolParty","CrimeCity","Debonair","BattleAcademia","Arcana","Arcanist",
    "Astronaut","Bees","Bewitching","Blackfrost","CafeCuties","CrystalRose","WitheredRose",
    "CyberHalo","DarkWaters","DeathBlossom","Dragonslayer","Dragonmancer","Heartseeker",
    "Hextech","HighSociety","ImmortalJourney","Infernal","Marauder","MechaZero",
    "Nightmare","OceanSong","Papercraft","Pentakill","Praetorian","PsyOps","Ruined",
    "Sentinel","ShanHai","SpaceGroove","SteelLegion","StreetDemons","SugarRush",
    "SuperGalaxy","Superhero","ThunderLord","WarringKingdoms","Winterblessed",
    "WinterWonder","SoulFighter","Empyrean","FrightNight","BrokenCovenant",
    "LunarRevel","Heavenscale","PrimalAmbush","RainShepherd","PajamaGuardian",
    "KDA","TrueDamage","Heartsteel","Chromacrash","BattleBoss","BattleBunny",
    "BattleQueen","EventHorizon","Galaxy","Nebula","Supernova","Chronos","Eternum",
    "Molten","Volcanic","Lava","Frost","Glacial","Arctic","Thunder","Tempest",
    "Lightning","Hurricane","Ocean","Sea","Deep","Abyss","Nether","Underworld",
    "Hades","Hell","Heaven","Angel","Demon","Devil","Elf","Dwarf","Orc","Goblin",
    "Troll","Giant","Fairy","Pixie","Sprite","Nymph","Centaur","Minotaur","Satyr",
    "Mermaid","Siren","Harpy","Gorgon","Medusa","Cyclops","Chimera","Hydra","Basilisk",
    "Griffin","Pegasus","Unicorn","Cerberus","Fenrir","Kraken","Leviathan","Behemoth",
    "Sphinx","Manticore","Oni","Tengu","Kitsune","Wyrm","Wyvern","Drake","Lindworm",
    "Royal","Imperial","Regal","Noble","Majestic","Midnight","Twilight","Dawn","Dusk",
    "Spring","Summer","Autumn","Winter","Coral","Ivory","Ebony","Amber","Onyx",
    "Warrior","Knight","Paladin","Crusader","Templar","Samurai","Ronin","Ninja",
    "Monk","Priest","Cleric","Druid","Shaman","Necromancer","Sorcerer","Wizard",
    "Warlock","Enchanter","Illusionist","Archer","Ranger","Hunter","Sniper","Marksman",
    "Gunslinger","Berserker","Barbarian","Juggernaut","Brawler","Gladiator","Thief",
    "Rogue","Shadow","Spy","Infiltrator","Saboteur","Agent","Bard","Minstrel","Jester",
    "Clown","Harlequin","Puppeteer","Dancer","Pirate","Corsair","Buccaneer","Viking",
    "Raider","Marauder","Brigand",
    "Risen","Immortalized","Legend","Parallel","World","Revenant","Conquered","King",
    "Starswarm","Hour","Zero","Scarlet","Fair","Hall","Legends","Royal","Arms","Fins",
    "Unconquered","Unknown","Exception","Pick","Car","PickACar","PickACard",
    "Card","Cards","Chroma","Skin","WardSkin","Icon","Emote",
    "Sword","Dagger","Mask","Bow","Staff","Ring","Tome","Belt","Cloak","Chain",
    "Charm","Lens","Ward","Potion","Bead","Level","Tier","Rank","Grade","Score",
    "Head","hood","Hood","On","Off",
    "With","Without","with","without",
]

# LOL 物品名
items = [
    "InfinityEdge","EssenceReaver","TheCollector","PhantomDancer","RunaansHurricane",
    "RapidFirecannon","StatikkShiv","KrakenSlayer","ImmortalShieldbow","BladeoftheRuinedKing",
    "GuinsoosRageblade","WitsEnd","Terminus","NashorsTooth","LichBane","RabadonsDeathcap",
    "ZhonyasHourglass","BansheesVeil","VoidStaff","Cryptbloom","Stormsurge","LudensCompanion",
    "ArchangelsStaff","SeraphsEmbrace","RodofAges","Malignance","BlackfireTorch","Riftmaker",
    "LiandrysTorment","CosmicDrive","RylaisCrystalScepter","Morellonomicon","HorizonFocus",
    "HextechRocketbelt","SunfireAegis","HollowRadiance","Thornmail","FrozenHeart","RanduinsOmen",
    "DeadMansPlate","ForceofNature","KaenicRookern","SpiritVisage","AbyssalMask",
    "JakShoTheProtean","UnendingDespair","WarmogsArmor","Heartsteel","IcebornGauntlet",
    "ZekesConvergence","KnightsVow","LocketoftheIronSolari","Redemption","MikaelsBlessing",
    "ArdentCenser","StaffofFlowingWater","Dawncore","ImperialMandate","MoonstoneRenewer",
    "EchoesofHelia","ShurelyasBattlesong","BlackCleaver","TitanicHydra","RavenousHydra",
    "ProfaneHydra","Stridebreaker","SunderedSky","Eclipse","DeathsDance","MawOfMalmortius",
    "GuardianAngel","SteraksGage","ChempunkChainsword","SpearOfShojin","Hexplate","Hullbreaker",
    "OverlordsBloodmail","SerpentsFang","Opportunity","YoumuusGhostblade","EdgeOfNight",
    "UmbralGlaive","AxiomArc","Hubris","VoltaicCyclosword","SeryldasGrudge",
    "YunTalWildarrows","Manamune","Muramana","MercurialScimitar","SilvermereDawn",
    "WintersApproach","Fimbulwinter","CappaJuice","ScoutSlingshot","Tunneler","Rectrix",
    "WorldAtlas","RunicCompass","BountyofWorlds","Bloodsong","CelestialOpposition",
    "DreamMaker","ZazZaksRealmspike","NavoriFlickerblade","LordDominiksRegards",
    "MortalReminder","Deathcap","Goredrinker","Galeforce","Everfrost","Protobelt",
    "NightHarvester","Sunfire","Frostfire","Chemtank","Iceborn","Divine","Trinity",
    "Shieldbow","Kraken","LDR","Collector","Navori","Crown","Liandry",
    "JakSho","Radiant","Virtue","Evenshroud","Locket","Moonstone","Shurelya",
    "Mandate","Helia","Seraph","Manamune","Archangel","Zhonya","Banshee","Void",
    "Morello","Rylai","Cosmic","Horizon","Shadowflame",
    "Thornmail","Randuin","Frozen","Force","Spirit","Abyssal","Sterak","GA","DeathDance",
    "Maw","Edge","Cleaver","Hydra","Tiamat","Shojin","Serpent","Chainsword",
    "Youmuu","Duskblade","Serylda","Umbral","EdgeNight","Ghostblade","Boots",
    "Sorc","Berserker","Merc","Tabi","Ionian","Swift","Mobi","Steelcaps",
    "DoranBlade","DoranRing","DoranShield","DarkSeal","Cull","LongSword","Pickaxe",
    "BFSword","VampiricScepter","RecurveBow","KircheisShard","Noonquiver","HearthboundAxe",
    "AmpTome","BlastingWand","NeedlesslyLargeRod","FiendishCodex","LostChapter",
    "SeekersArmguard","AetherWisp","BandleglassMirror","ClothArmor","NullMagicMantle",
    "NegatronCloak","SpectresCowl","ChainVest","BrambleVest","WardensMail","GiantsBelt",
    "RubyCrystal","SapphireCrystal","TearoftheGoddess","Sheen","GlacialBuckler",
    "BamisCinder","RejuvenationBead","FaerieCharm","HealthPotion","RefillablePotion",
    "CorruptingPotion","ControlWard","StealthWard","FarsightAlteration","OracleLens",
    "ElixirofIron","ElixirofSorcery","ElixirofWrath","BerserkerGreaves","SorcererShoes",
    "IonianBoots","MercuryTreads","NinjaTabi","SwiftnessBoots","MobilityBoots","PlatedSteelcaps",
    "QSS","Mercurial","Silvermere","Stopwatch","Crucible","Knights","Zeke","Ardent",
    "Sleigh","Trailblazer","Solstice","Bounty",
]

# 游戏模式
game_modes = [
    "Classic","ARAM","URF","OneForAll","NexusBlitz","TFT","Arena","Swarm","PracticeTool",
    "Tutorial","Custom","Normal","Ranked","Draft","Blind","Clash",
    "SummonersRift","HowlingAbyss","TwistedTreeline","CrystalScar",
    "SR","HA","TT","CS",
    "ODIN","TUTORIAL","ARAM","URF","ONEFORALL","ASCENSION","FIRSTBLOOD",
    "KINGPORO","SIEGE","ASSASSINATE","DARKSTAR","STARGUARDIAN","PROJECT",
    "ODYSSEY","NEXUSBLITZ","TFT","PRACTICETOOL",
]

# 召唤师技能
summoner_spells = [
    "Flash","Ignite","Exhaust","Teleport","Smite","Heal","Ghost","Barrier","Cleanse",
    "Snowball","Mark","Clarity","Garrison","Promote","Surge","Revive",
    "SummonerFlash","SummonerIgnite","SummonerExhaust","SummonerTeleport",
    "SummonerSmite","SummonerHeal","SummonerGhost","SummonerBarrier","SummonerCleanse",
]

# 游戏系统术语
game_terms = [
    "Attack","Defense","Magic","Health","Mana","Damage","Range","Speed","Armor",
    "Resistance","Penetration","Lethality","Critical","Cooldown","Ability",
    "Power","Haste","Heal","Shield","Stun","Slow","Silence","Root","Knockup",
    "Fear","Charm","Taunt","Blind","Stealth","Invulnerable","Untargetable",
    "OnHit","LifeSteal","SpellVamp","OmniVamp","Tenacity","MoveSpeed","AttackSpeed",
    "AbilityHaste","AP","AD","HP","MP","MR","Percent","Current","Missing","Bonus",
    "Base","Total","Scaling",
    "Orbwalker","TargetSelector","Prediction","Evade","Awareness","Activator",
    "AutoLevel","AutoLastHit","AutoLaneClear","AutoHarass","AutoSmite","AutoJungle",
    "AutoHeal","AutoShield","AutoIgnite",
    "Menu","GUI","HUD","Overlay","Renderer","Config",
    "Load","Save","Reset","Default","Preset","Profile",
    "SkinChanger","SkinHack","SkinSwap","AutoSkin",
    "Combo","Harass","LaneClear","LastHit","Flee","None",
    "ComboMode","HarassMode","LaneClearMode","LastHitMode","FleeMode",
    "DrawDamage","DrawRange","DrawSpell","DrawSkillshot","DrawTarget",
    "Enable","Disable","Active","Inactive","Visible","Hidden","Show","Hide",
    "On","Off","Yes","No","True","False",
    "Key","Value","Name","ID","Type","Flag","State","Mode","Format","Version",
    "Size","Count","Index","Offset","Address","Pointer","Handle","Module",
    "Min","Max","Default","Current","Target","Source","Destination",
    "Width","Height","X","Y","Z","W","Left","Right","Top","Bottom",
    "Front","Back","Center","Middle","Origin","Pivot","Anchor",
    "Red","Green","Blue","Alpha","RGBA","ARGB","RGB",
    "Color","Opacity","Transparency","Brightness","Contrast","Saturation","Hue",
    "Font","Text","Label","Title","Caption","Header","Footer","Body","Content",
    "Border","Outline","Shadow","Glow","Blur","Gradient","Fill","Stroke",
    "Radius","Corner","Padding","Margin","Spacing","Gap","Indent","Alignment",
    "Horizontal","Vertical","Diagonal","Row","Column","Grid","Table","List","Tree",
    "Stack","Panel","Group","Box","Frame","Window","Dialog","Popup","Tooltip",
    "Button","Checkbox","Radio","Slider","Scrollbar","ProgressBar","Spinner",
    "Tab","Page","Section","Divider","Separator","Icon","Image","Thumbnail",
    "Collapsed","Expanded","Open","Closed","Selected","Checked","Unchecked",
    "Hovered","Focused","ReadOnly","Editable","Draggable","Resizable","Movable",
    "Fixed","Absolute","Relative","Static","Normal","Hover","Active","Disabled",
    "Primary","Secondary","Success","Danger","Warning","Info","Light","Dark",
    "Small","Medium","Large","ExtraLarge","Compact","Full","Half","Quarter",
    "Auto","Manual","SemiAuto","Semi","Hybrid","Mixed","Combined","Integrated",
    "Single","Double","Triple","Multiple","All","None","Some","Any",
    "First","Last","Next","Previous","Forward","Backward","Up","Down","Random",
    "Sequential","Concurrent","Parallel","Serial","Batch","Bulk","Individual",
    "Local","Remote","Online","Offline","Connected","Disconnected","Synced","Cached",
    "Hot","Cold","Warm","Cool","Freeze","Melt","Burn","Chill","Heat","Frost",
    "Soft","Hard","Smooth","Rough","Sharp","Blunt","Round","Square","Curved","Straight",
    "Thin","Thick","Narrow","Wide","Short","Tall","Long","Tiny","Huge","Massive",
    "Simple","Complex","Basic","Advanced","Expert","Beginner","Intermediate","Pro",
    "Easy","Normal","Hard","Insane","Nightmare","Impossible","Legendary","Mythic",
    "Spell","Item","Rune","Mastery","Champion","Hero","Unit","Monster","Minion",
    "Turret","Inhibitor","Nexus","Buff","Debuff","Aura","Effect","Modifier","Status",
    "Game","Lobby","Client","Server","Match","Session","Party","Team","Queue",
    "Win","Lose","Victory","Defeat","KDA","CS","Ping","Chat","AllChat","Surrender","Remake",
    "Loot","Chest","Key","Fragment","Essence","Riot","RP","IP","BE","OE",
    "Eternal","Challenge","Mission","Quest","Event","Pass",
    "Honor","Report","Ban","Mute","AFK","Int","Feed","Troll",
    "Enemy","Ally","Solo","Duo","Flex",
    "Execute","Push","Freeze","SlowPush","FastPush","Bounce","Invade","Counter",
    "Gank","Dive","Rotate","Roam","Soul","Grub","Plate","Tower","Inhib",
    "Base","Fountain","River","Bush","Wall","Terrain","Pit",
    "Dragon","Baron","Herald","Atakhan","Elder",
    "Sound","Music","Volume","Audio","Voice","HUD","UI","Scale","Resolution",
    "Fullscreen","Windowed","Borderless","Setting","Config","Option","Toggle",
    "Debug","Log","Error","Warning","Info","Trace","Assert",
    "Frame","FPS","Latency","Packet","Loss","Memory","CPU","GPU","Disk","Network",
    "Input","Output","Keyboard","Mouse","Gamepad","Joystick",
    "Click","DoubleClick","RightClick","MiddleClick","Scroll","Press","Release","Hold","Tap",
    "Window","Process","Thread","DLL","Hook","Bypass","Inject","Detect","Anti","Cheat","Vanguard",
    "Cursor","Position","Screen","World","Camera","Zoom","Minimap","Map","Fog","Vision","Sweeper",
    "execute","combo","harass","laneclear","lasthit","flee","push","freeze","slowpush","fastpush",
    "bounce","invade","counter","gank","dive","rotate","roam",
    "dragon","baron","herald","atakhan","elder","soul","grub","plate","tower","inhib",
    "base","fountain","river","bush","wall","terrain","pit",
    "ignite","exhaust","flash","teleport","smite","heal","ghost","barrier","cleanse",
    "attack","defense","magic","health","mana","damage","range","speed","armor",
    "ap","ad","hp","mp","mr","true","percent","max","current","missing","bonus","base","total",
    "enabled","disabled","active","inactive","visible","hidden","show","hide",
    "on","off","true","false","yes","no",
    "Draw","Render","Update","Tick","Init","Cleanup","Setup","Teardown",
    "Create","Read","Update","Delete","CRUD","Insert","Select","Where","Join","Group",
    "Sort","Filter","Search","Find","Replace","Match","Parse","Format",
    "Split","Join","Concat","Merge","Zip","Pack","Unpack","Serialize","Deserialize",
    "Encode","Decode","Encrypt","Decrypt","Hash","Sign","Verify","Compress","Decompress",
    "Allocate","Free","New","Delete","Create","Destroy","Start","Stop",
    "Pause","Resume","Restart","Shutdown","Reboot","Reload","Refresh","Reset","Clear",
    "Open","Close","Lock","Unlock","Acquire","Release","Enter","Leave","Try","Catch",
    "Throw","Raise","Handle","Process","Dispatch","Route","Forward","Redirect","Proxy",
    "Connect","Disconnect","Bind","Listen","Accept","Send","Recv","Read","Write",
    "Subscribe","Unsubscribe","Publish","Broadcast","Emit","Notify","Alert","Trigger",
    "Set","Get","Add","Remove","Clear","Contains","Empty","Count","Length",
    "Capacity","Reserve","Shrink","Grow","Expand","Collapse","Insert","Erase","Push",
    "Pop","Enqueue","Dequeue","Peek","Top","Bottom","Begin","End",
    "Copy","Move","Swap","Exchange","Replace","Assign","Transfer","Convert","Cast",
    "Compare","Equal","Less","Greater","Sort","Reverse","Rotate","Shuffle","Random",
    "Skin","Chroma","Skin0","Skin1","Skin2","Skin3","Skin4","Skin5","Skin6","Skin7","Skin8","Skin9",
]
for i in range(10, 300):
    game_terms.append(f"Skin{i}")

# ============================================================
# 构建候选集
# ============================================================
candidates = set()
for lst in [lol_champions, champion_spells, jungle_monsters, map_objects,
            skin_themes, items, game_modes, summoner_spells, game_terms]:
    candidates.update(lst)

# 英雄+皮肤组合
for champ in lol_champions:
    for skin in skin_themes[:80]:
        candidates.add(f"{champ}{skin}")
        candidates.add(f"{champ}_{skin}")

# 带数字后缀
for base in ["Sword","Dagger","Mask","Bow","Staff","Ring","Tome","Belt","Cloak","Chain",
             "Crystal","Charm","Lens","Ward","Potion","Bead","Level","Tier","Skin","Chroma",
             "Buff","Effect","Spell","Item","Rune","Mastery","Config","Setting","Option"]:
    for i in range(0, 200):
        candidates.add(f"{base}{i}")
        candidates.add(f"{base}_{i}")

# 小写版本
lower_candidates = set()
for s in list(candidates):
    lower_candidates.add(s.lower())
    lower_candidates.add(s.upper())
candidates.update(lower_candidates)

# 去重去空
candidates = {s for s in candidates if s and len(s) > 0}
print(f"初始候选: {len(candidates)}")

# ============================================================
# 建立哈希→字符串映射
# ============================================================
print("计算 FNV-1a 哈希...")
hash_to_string = {}
for s in candidates:
    h = fnv1a_str(s)
    hash_to_string[h] = s

# ============================================================
# 匹配所有目标哈希
# ============================================================
print("\n" + "=" * 80)
print("哈希匹配结果")
print("=" * 80)

matched = {}
unmatched = {}
for h, desc in all_target_hashes.items():
    s = hash_to_string.get(h)
    if s:
        matched[h] = (s, desc)
        print(f"  [✓] 0x{h:016X} -> '{s}'  ({desc})")
    else:
        unmatched[h] = desc
        print(f"  [✗] 0x{h:016X} -> ???  ({desc})")

# ============================================================
# 暴力搜索未匹配的哈希值
# ============================================================
if unmatched:
    print("\n" + "=" * 80)
    print("暴力搜索未匹配的哈希值")
    print("=" * 80)

    # 扩展候选集
    extra = set()
    
    # 英雄+所有技能后缀
    for champ in lol_champions:
        for suffix in ["","_","_"+"Passive","_"+"Q","_"+"W","_"+"E","_"+"R",
                       "Passive","Q","W","E","R",
                       "BasicAttack","BasicAttack2","CritAttack",
                       "Q1","Q2","Q3","W1","W2","W3","E1","E2","E3","R1","R2","R3",
                       "Attack","Attack1","Attack2","Attack3","Attack4","Attack5",
                       "Crit","Crit1","Crit2","Crit3",
                       "Cast","Channel","Charge","Empowered","EmpoweredQ","EmpoweredW","EmpoweredE","EmpoweredR",
                       "Recall","Death","Respawn","Idle","Run","Walk","Taunt","Joke","Laugh","Dance",
                       "Spell","SpellQ","SpellW","SpellE","SpellR",
                       "Ability","AbilityQ","AbilityW","AbilityE","AbilityR",
                       "Skin","Skin0","Skin1","Skin2","Skin3","Skin4","Skin5","Skin6","Skin7","Skin8","Skin9",
                       "Default","Classic","Base","Original",
                       "Model","Texture","Particle","Sound","Voice","Anim","Animation"]:
            extra.add(f"{champ}{suffix}")
    
    # 英雄+皮肤组合扩展
    for champ in lol_champions:
        for skin in skin_themes[:120]:
            extra.add(f"{champ}{skin}")
            extra.add(f"{champ}_{skin}")
            extra.add(f"{champ} {skin}")
            extra.add(f"{champ}Skin{skin}")
            extra.add(f"{champ}_Skin_{skin}")
    
    # 常见游戏内部字符串
    game_strings = [
        "Game","Lobby","Client","Server","Match","Session","Party","Team","Queue",
        "game","lobby","client","server","match","session","party","team","queue",
        "CHARACTER","Character","character","SPELL","Spell","spell",
        "ITEM","Item","item","SKIN","Skin","skin","CHROMA","Chroma","chroma",
        "EFFECT","Effect","effect","BUFF","Buff","buff","DEBUFF","Debuff","debuff",
        "AURA","Aura","aura","STATUS","Status","status","MODIFIER","Modifier","modifier",
        "ATTACK","Attack","attack","DEFENSE","Defense","defense",
        "MAGIC","Magic","magic","PHYSICAL","Physical","physical",
        "HEALTH","Health","health","MANA","Mana","mana",
        "DAMAGE","Damage","damage","RANGE","Range","range",
        "SPEED","Speed","speed","ARMOR","Armor","armor",
        "MAGICRESIST","MagicResist","magicresist","MR","mr",
        "CRITICAL","Critical","critical","LETHALITY","Lethality","lethality",
        "COOLDOWN","Cooldown","cooldown","ABILITY","Ability","ability",
        "POWER","Power","power","HASTE","Haste","haste",
        "HEAL","Heal","heal","SHIELD","Shield","shield",
        "STUN","Stun","stun","SLOW","Slow","slow",
        "SILENCE","Silence","silence","ROOT","Root","root",
        "KNOCKUP","Knockup","knockup","FEAR","Fear","fear",
        "CHARM","Charm","charm","TAUNT","Taunt","taunt",
        "BLIND","Blind","blind","STEALTH","Stealth","stealth",
        "INVULNERABLE","Invulnerable","invulnerable",
        "UNTARGETABLE","Untargetable","untargetable",
        "ONHIT","OnHit","onhit","LIFESTEAL","LifeSteal","lifesteal",
        "SPELLVAMP","SpellVamp","spellvamp","OMNIVAMP","OmniVamp","omnivamp",
        "TENACITY","Tenacity","tenacity","MOVESPEED","MoveSpeed","movespeed",
        "ATTACKSPEED","AttackSpeed","attackspeed","ABILITYHASTE","AbilityHaste","abilityhaste",
        "AP","AD","HP","MP","TRUE","True","PERCENT","Percent","MAX","Max",
        "CURRENT","Current","MISSING","Missing","BONUS","Bonus","BASE","Base","TOTAL","Total",
        "ORBWALKER","Orbwalker","TARGETSELECTOR","TargetSelector",
        "PREDICTION","Prediction","EVADE","Evade","AWARENESS","Awareness",
        "ACTIVATOR","Activator","AUTOLVL","AutoLvl","AUTOLAST","AutoLast",
        "AUTOLANECLEAR","AutoLaneClear","AUTOHARASS","AutoHarass",
        "AUTOSMITE","AutoSmite","AUTOJUNGLE","AutoJungle",
        "AUTOHEAL","AutoHeal","AUTOSHIELD","AutoShield","AUTOIGNITE","AutoIgnite",
        "MENU","Menu","GUI","Gui","HUD","Hud","OVERLAY","Overlay",
        "RENDERER","Renderer","CONFIG","Config",
        "LOAD","Load","SAVE","Save","RESET","Reset","DEFAULT","Default","PRESET","Preset","PROFILE","Profile",
        "SKINCHANGER","SkinChanger","SKINHACK","SkinHack","SKINSWAP","SkinSwap","AUTOSKIN","AutoSkin",
        "DRAW","Draw","RENDER","Render","UPDATE","Update","TICK","Tick",
        "INIT","Init","CLEANUP","Cleanup","SETUP","Setup","TEARDOWN","Teardown",
        "DRAWDAMAGE","DrawDamage","DRAWRANGE","DrawRange","DRAWSPELL","DrawSpell",
        "DRAWSKILLSHOT","DrawSkillshot","DRAWTARGET","DrawTarget",
        "DRAWHITBOX","DrawHitbox","DRAWHITBOXES","DrawHitboxes",
        "DRAWCIRCLES","DrawCircles","DRAWLINES","DrawLines","DRAWTEXT","DrawText",
        "DRAWMENU","DrawMenu","DRAWHUD","DrawHUD","DRAWOVERLAY","DrawOverlay",
        "DRAWMINIMAP","DrawMinimap","DRAWWORLD","DrawWorld","DRAWSCREEN","DrawScreen",
        "DRAWINDICATOR","DrawIndicator","DRAWRANGEINDICATOR","DrawRangeIndicator",
        "DRAWSPELLRANGE","DrawSpellRange","DRAWAARANGE","DrawAARange",
        "DRAWTURRETRANGE","DrawTurretRange","DRAWWARDRANGE","DrawWardRange",
        "DRAWPING","DrawPing","DRAWFPS","DrawFPS","DRAWTIME","DrawTime",
        "COMBO","Combo","HARASS","Harass","LANECLEAR","LaneClear","LASTHIT","LastHit","FLEE","Flee",
        "COMBOMODE","ComboMode","HARASSMODE","HarassMode","LANECLEARMODE","LaneClearMode",
        "LASTHITMODE","LastHitMode","FLEEMODE","FleeMode",
        "EXECUTE","Execute","PUSH","Push","FREEZE","Freeze","SLOWPUSH","SlowPush",
        "FASTPUSH","FastPush","BOUNCE","Bounce","INVADE","Invade","COUNTER","Counter",
        "GANK","Gank","DIVE","Dive","ROTATE","Rotate","ROAM","Roam",
        "DRAGON","Dragon","BARON","Baron","HERALD","Herald","ATAKHAN","Atakhan","ELDER","Elder",
        "SOUL","Soul","GRUB","Grub","PLATE","Plate","TOWER","Tower","INHIB","Inhib",
        "BASE","Base","FOUNTAIN","Fountain","RIVER","River","BUSH","Bush","WALL","Wall","TERRAIN","Terrain","PIT","Pit",
        "IGNITE","Ignite","EXHAUST","Exhaust","FLASH","Flash","TELEPORT","Teleport",
        "SMITE","Smite","HEAL","Heal","GHOST","Ghost","BARRIER","Barrier","CLEANSE","Cleanse",
        "SNOWBALL","Snowball","MARK","Mark","CLARITY","Clarity",
        "Q","W","E","R","Passive","passive",
        "Q1","Q2","W1","W2","E1","E2","R1","R2",
        "SpellQ","SpellW","SpellE","SpellR","spellQ","spellW","spellE","spellR",
        "Skin0","Skin1","Skin2","Skin3","Skin4","Skin5","Skin6","Skin7","Skin8","Skin9",
        "Head","head","Hood","hood","On","on","Off","off",
        "HeadOn","HeadOff","headon","headoff","Head on","Head off","head on","head off",
        "WithHood","WithoutHood","withhood","withouthood",
        "With hood","Without hood","with hood","without hood",
        "Risen","Immortalized","Legend","Legends","Parallel","World","Revenant","Conquered","King",
        "Starswarm","Hour","Zero","Scarlet","Fair","Hall","Royal","Arms","Fins","Unconquered",
        "Unknown","Exception","Pick","Car","Card","Cards",
        "Blue","Red","Yellow","Green","Purple","Pink","White","Black","Orange","Gray",
        "blue","red","yellow","green","purple","pink","white","black","orange","gray",
        "Gold","Silver","Bronze","Iron","Platinum","Diamond","Master","Grandmaster","Challenger",
        "gold","silver","bronze","iron","platinum","diamond","master","grandmaster","challenger",
        "Sword","Dagger","Mask","Bow","Staff","Ring","Tome","Belt","Cloak","Chain",
        "sword","dagger","mask","bow","staff","ring","tome","belt","cloak","chain",
        "Crystal","Charm","Lens","Ward","Potion","Bead","Level","Tier","Skin","Chroma",
        "crystal","charm","lens","ward","potion","bead","level","tier","skin","chroma",
        "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "one","two","three","four","five","six","seven","eight","nine","ten",
        "First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Ninth","Tenth",
        "first","second","third","fourth","fifth","sixth","seventh","eighth","ninth","tenth",
        "Version","Phase","Stage","Wave","Set","Type","Class","Category","Group","Family",
        "Series","Bundle","Pack","Collection","Form","Style","Mode","Variant","Theme","Color","Pattern",
        "version","phase","stage","wave","set","type","class","category","group","family",
        "NA","EUW","EUNE","KR","BR","TR","RU","OCE","LAN","LAS","JP","VN","TW","PH","SG","TH","ID","CN",
        "enUS","enGB","frFR","deDE","esES","ptBR","plPL","ruRU","trTR","jaJP","koKR","zhCN","zhTW",
        "en_US","en_GB","fr_FR","de_DE","es_ES","pt_BR","pl_PL","ru_RU","tr_TR","ja_JP","ko_KR","zh_CN","zh_TW",
        "x64","x86","amd64","win32","win64","arm64",
        "debug","release","profile","optimize","retail","staging","production","testing",
        "local","remote","host","guest","admin","user",
        "public","private","protected","internal","external","native","managed",
        "static","dynamic","shared","lib","dll","exe","sys","drv",
        "flyinput","fly","input","pe2","pe","packer","unpack","encrypt","decrypt","obfuscate",
        "lol","riot","league","legends","leagueoflegends","LeagueOfLegends",
        "tft","tft_set","tft_champion","tft_trait","tft_item","tft_augment",
        "Soft","Hard","Easy","Normal","Extreme","ExtremeMode","Expert","Beginner","Pro",
        "Show","Hide","Draw","Enable","Disable","Toggle","Switch",
        "Key","KeyBind","Hotkey","HotKey","Shortcut","ShortCut",
        "Checkbox","CheckBox","Slider","SliderBar","ComboBox","Combo","ListBox","TextBox",
        "Menu","SubMenu","Sub","MenuItem","GroupBox","Group",
        "ColorPicker","Color","ColorSelect","ColorList",
        "Red","Green","Blue","Alpha","White","Black","Transparent",
        "Always","Never","Sometimes","When","If","Else","Then","While","For","Each",
        "Before","After","During","Between","Above","Below","Near","Far","Inside","Outside",
        "Start","End","Begin","Finish","Middle","Half","Full","Partial","Complete","Incomplete",
        "Top","Bottom","Left","Right","Center","Corner","Edge","Side","Front","Back",
        "Width","Height","Length","Size","Scale","Zoom","Radius","Thickness",
        "Thick","Thin","Bold","Normal","Regular","Italic","Underline","Strike",
        "Font","Text","Word","Line","Paragraph","Sentence","String","Letter","Character",
        "Small","Medium","Large","Huge","Tiny","Mini","Micro","Macro",
        "0","1","2","3","4","5","6","7","8","9",
        "00","01","02","03","04","05","06","07","08","09",
        "10","11","12","13","14","15","16","17","18","19","20",
        "v1","v2","v3","v4","v5","v6","v7","v8","v9","v10",
        "V1","V2","V3","V4","V5","V6","V7","V8","V9","V10",
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
        "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
        "_","-","."," ","+","=","*","/","\\","|","!","@","#","$","%","^","&","(",")","[","]","{","}","<",">","?","~","`",
        "\"","'",":",";",",",
        # 更多 LOL 内部名称
        "game_client","game_server","game_lobby","game_match","game_session",
        "GameClient","GameServer","GameLobby","GameMatch","GameSession",
        "champion_select","champion_select_phase","ban_phase","pick_phase",
        "ChampionSelect","ChampionSelectPhase","BanPhase","PickPhase",
        "loading_screen","loading_screen_phase","game_phase","end_of_game",
        "LoadingScreen","LoadingScreenPhase","GamePhase","EndOfGame",
        "minimap","minimap_icon","minimap_ping","minimap_ward",
        "Minimap","MinimapIcon","MinimapPing","MinimapWard",
        "scoreboard","scoreboard_team","scoreboard_player","scoreboard_item",
        "Scoreboard","ScoreboardTeam","ScoreboardPlayer","ScoreboardItem",
        "chat","chat_all","chat_team","chat_party","chat_whisper",
        "Chat","ChatAll","ChatTeam","ChatParty","ChatWhisper",
        "shop","shop_item","shop_category","shop_search","shop_recommended",
        "Shop","ShopItem","ShopCategory","ShopSearch","ShopRecommended",
        "spellbook","spellbook_slot","spellbook_cooldown","spellbook_level",
        "Spellbook","SpellbookSlot","SpellbookCooldown","SpellbookLevel",
        "inventory","inventory_slot","inventory_item","inventory_gold",
        "Inventory","InventorySlot","InventoryItem","InventoryGold",
        "recall","recall_channel","recall_complete","recall_cancel",
        "Recall","RecallChannel","RecallComplete","RecallCancel",
        "death","death_timer","death_recap","death_damage","death_assist",
        "Death","DeathTimer","DeathRecap","DeathDamage","DeathAssist",
        "kill","kill_streak","kill_shutdown","kill_bounty","kill_shutdown_bounty",
        "Kill","KillStreak","KillShutdown","KillBounty","KillShutdownBounty",
        "assist","assist_streak","assist_count","assist_score",
        "Assist","AssistStreak","AssistCount","AssistScore",
        "cs","cs_total","cs_minion","cs_monster","cs_champion","cs_turret",
        "CS","CsTotal","CsMinion","CsMonster","CsChampion","CsTurret",
        "gold","gold_total","gold_earned","gold_spent","gold_current",
        "Gold","GoldTotal","GoldEarned","GoldSpent","GoldCurrent",
        "xp","xp_total","xp_level","xp_current","xp_next","xp_required",
        "XP","XpTotal","XpLevel","XpCurrent","XpNext","XpRequired",
        "level","level_up","level_max","level_current",
        "Level","LevelUp","LevelMax","LevelCurrent",
        "ward","ward_placed","ward_destroyed","ward_type","ward_duration",
        "Ward","WardPlaced","WardDestroyed","WardType","WardDuration",
        "ping","ping_ms","ping_latency","ping_packet_loss","ping_jitter",
        "Ping","PingMs","PingLatency","PingPacketLoss","PingJitter",
        "fps","fps_current","fps_min","fps_max","fps_avg","fps_drop",
        "FPS","FpsCurrent","FpsMin","FpsMax","FpsAvg","FpsDrop",
        "memory","memory_usage","memory_peak","memory_available","memory_total",
        "Memory","MemoryUsage","MemoryPeak","MemoryAvailable","MemoryTotal",
        "cpu","cpu_usage","cpu_temp","cpu_clock","cpu_core",
        "CPU","CpuUsage","CpuTemp","CpuClock","CpuCore",
        "gpu","gpu_usage","gpu_temp","gpu_clock","gpu_memory",
        "GPU","GpuUsage","GpuTemp","GpuClock","GpuMemory",
        "sru","SRU","Sru","SRU_","sru_","Sru_",
        "sru_drag","sru_Drag","sru_Dragon","SRU_Drag","SRU_Dragon","Sru_Drag","Sru_Dragon",
        "sru_baro","sru_Baro","sru_Baron","SRU_Baro","SRU_Baron","Sru_Baro","Sru_Baron",
        "sru_atak","sru_Atak","sru_Atakhan","SRU_Atak","SRU_Atakhan",
        "sru_blue","sru_Blue","SRU_Blue","SRU_blue",
        "sru_red","sru_Red","SRU_Red","SRU_red",
        "sru_gromp","sru_Gromp","SRU_Gromp","SRU_gromp",
        "sru_wolf","sru_Wolf","SRU_Wolf","SRU_wolf",
        "sru_raptor","sru_Raptor","SRU_Raptor","SRU_raptor",
        "sru_krug","sru_Krug","SRU_Krug","SRU_krug",
        "sru_crab","sru_Crab","SRU_Crab","SRU_crab",
        "sru_scuttle","sru_Scuttle","SRU_Scuttle","SRU_scuttle",
        "sru_herald","sru_Herald","SRU_Herald","SRU_herald",
        "sru_elder","sru_Elder","SRU_Elder","SRU_elder",
        "sru_voidgrub","sru_Voidgrub","SRU_Voidgrub","SRU_voidgrub",
        "sru_chaos","sru_Chaos","SRU_Chaos","SRU_chaos",
        "sru_order","sru_Order","SRU_Order","SRU_order",
        "sru_murkwolf","sru_Murkwolf","SRU_Murkwolf","SRU_murkwolf",
        "sru_razorbeak","sru_Razorbeak","SRU_Razorbeak","SRU_razorbeak",
        "sru_dragon_elder","sru_dragon_fire","sru_dragon_water","sru_dragon_air",
        "sru_dragon_earth","sru_dragon_chemtech","sru_dragon_hextech",
        "SRU_Dragon_Elder","SRU_Dragon_Fire","SRU_Dragon_Water","SRU_Dragon_Air",
        "SRU_Dragon_Earth","SRU_Dragon_Chemtech","SRU_Dragon_Hextech",
        "AI","Ai","ai","Bot","bot","BOT","Intermediate","intermediate",
        "Easy","easy","Medium","medium","Hard","hard","Doom","doom",
        "Tutorial","tutorial","Intro","intro","Beginner","beginner",
        "Practice","practice","Custom","custom","Normal","normal","Ranked","ranked",
        "Solo","solo","Duo","duo","Flex","flex","Clash","clash",
        "ARAM","aram","URF","urf","Arena","arena","Swarm","swarm",
        "TFT","tft","OneForAll","oneforall","NexusBlitz","nexusblitz",
        "Spellbook","spellbook","UltimateSpellbook","ultimatespellbook",
        "PracticeTool","practicetool","CustomGame","customgame",
        "Blue","Red","Neutral","blue","red","neutral",
        "Order","Chaos","order","chaos",
        "Top","Jungle","Middle","Bottom","Support","Fill",
        "top","jungle","middle","bottom","support","fill",
        "TOP","JUNGLE","MIDDLE","BOTTOM","SUPPORT","FILL",
        "Lane","lane","Jungle","jungle","River","river",
        "TOP_LANE","JUNGLE_LANE","MID_LANE","BOTTOM_LANE","SUPPORT_LANE",
        "Melee","Ranged","melee","ranged",
        "Fighter","Tank","Mage","Assassin","Marksman","Support","Specialist",
        "fighter","tank","mage","assassin","marksman","support","specialist",
        "FIGHTER","TANK","MAGE","ASSASSIN","MARKSMAN","SUPPORT","SPECIALIST",
        "Physical","Magic","True","Mixed","physical","magic","true","mixed",
        "PHYSICAL","MAGIC","TRUE","MIXED",
        "Colorblind","ColorBlind","colorblind","colorblind_mode",
        "QuickCast","Quickcast","quickcast","QuickCastWithIndicator","quickcastwithindicator",
        "NormalCast","Normalcast","normalcast","SelfCast","Selfcast","selfcast",
        "SmartCast","Smartcast","smartcast","AutoCast","Autocast","autocast",
        "CameraLock","CameraLocked","cameralock","cameralocked",
        "Camera","CameraMode","CameraStyle","camera","cameramode","camerastyle",
        "Fixed","SemiLocked","PerSide","fixed","semilocked","perside",
        "WindowMode","Fullscreen","Borderless","Windowed","windowmode","fullscreen","borderless","windowed",
        "Resolution","resolution","Quality","quality","Graphics","graphics",
        "Low","Medium","High","VeryHigh","Ultra","low","medium","high","veryhigh","ultra",
        "ShadowQuality","Shadow","shadowquality","shadow",
        "EffectQuality","Effect","effectquality","effect",
        "EnvironmentQuality","Environment","environmentquality","environment",
        "CharacterQuality","Character","characterquality","character",
        "AntiAliasing","antialiasing","PostProcessing","postprocessing",
        "VSync","vsync","FrameRateCap","frameratecap","FPSLimit","fpslimit",
        "DX9","DX11","DX12","Vulkan","OpenGL","dx9","dx11","dx12","vulkan","opengl",
        "DirectX","directx","DirectX9","DirectX11","DirectX12",
        "MouseSpeed","Mouse","mouse","mousespeed",
        "KeyboardSpeed","Keyboard","keyboard","keyboardspeed",
        "ScrollSpeed","Scroll","scroll","scrollspeed",
        "ZoomSpeed","Zoom","zoom","zoomspeed",
    ]
    extra.update(game_strings)
    
    # 更多数字扩展
    for base in ["Sword","Dagger","Mask","Bow","Staff","Ring","Tome","Belt","Cloak","Chain",
                 "Crystal","Charm","Lens","Ward","Potion","Bead","Level","Tier","Skin","Chroma",
                 "Buff","Effect","Spell","Item","Rune","Mastery","Config","Setting","Option",
                 "Color","Font","Text","Key","Value","Mode","Phase","Stage","Wave","Set",
                 "Type","Class","Category","Group","Family","Version","Step","Part","Section",
                 "Slot","Row","Col","Column","Page","Tab","Panel","Layer","Channel","Index"]:
        for i in range(0, 300):
            extra.add(f"{base}{i}")
            extra.add(f"{base}_{i}")
            extra.add(f"{base} {i}")
    
    # 小写变体
    lower_extra = set()
    for s in list(extra):
        lower_extra.add(s.lower())
        lower_extra.add(s.upper())
        lower_extra.add(s.capitalize())
    extra.update(lower_extra)
    
    # 移除已存在的候选
    extra -= candidates
    print(f"  扩展候选: {len(extra)}")
    
    for h, desc in list(unmatched.items()):
        found = False
        for s in extra:
            if fnv1a_str(s) == h:
                print(f"  [✓] 0x{h:016X} -> '{s}' (暴力搜索找到)  ({desc})")
                matched[h] = (s, desc)
                del unmatched[h]
                found = True
                break
        if not found:
            # 尝试 1-3 字符
            for length in range(1, 4):
                if found: break
                for combo in itertools.product(string.ascii_letters + string.digits + "_- ", repeat=length):
                    s = ''.join(combo)
                    if fnv1a_str(s) == h:
                        print(f"  [✓] 0x{h:016X} -> '{s}' ({length}字符)  ({desc})")
                        matched[h] = (s, desc)
                        del unmatched[h]
                        found = True
                        break
            if not found:
                print(f"  [✗] 0x{h:016X} -> 暴力搜索未找到  ({desc})")

# ============================================================
# 验证已知字符串
# ============================================================
print("\n" + "=" * 80)
print("已知字符串 FNV-1a 哈希验证")
print("=" * 80)

verify_strings = [
    "LuxAir","LuxWater","LuxStorm","LuxDark","LuxNature","LuxFire","LuxIce","LuxMystic","LuxMagma",
    "SonaDJGenre02","SonaDJGenre03",
    "BlueCard","GoldCard","RedCardL",
    "sru_drag","SRU_Baro","SRU_Atak",
    "Sword1","Sword2","Sword3","Sword4","Sword5","Sword6","Sword7",
    "Dagger1","Dagger2","Dagger3","Dagger4","Dagger5","Dagger6",
    "Mask1","Mask2","Mask3","Mask4","Mask5","Mask6",
    "Level1","Level2","Level3",
    "Dagger 1","Dagger 2","Dagger 3","Dagger 4","Dagger 5","Dagger 6",
    "Level 1","Level 2","Level 3",
    "PickACar","Iron Revenant","Fins","Royal arms","Hall of Legends",
    "Zero hour","Scarlet fair","Head on","Head off","Starswarm","Sahn-Uzal",
    "Without hood","With hood","Risen Legend","Immortalized Legend","Parallel world",
    "Blue","Gold","Red","Ultimate","Unconquered King",
]

for s in verify_strings:
    h = fnv1a_str(s)
    marker = " ✓" if h in all_target_hashes else "  "
    print(f"  {marker} 0x{h:016X} <- '{s}'")

# ============================================================
# 保存结果
# ============================================================
output_path = r"D:\SRC\SRC\buried_data\fnv_hash_analysis.txt"
os.makedirs(os.path.dirname(output_path), exist_ok=True)

with open(output_path, 'w', encoding='utf-8') as f:
    f.write("=" * 80 + "\n")
    f.write("flyinput.dll FNV-1a 哈希值反向解析结果\n")
    f.write("=" * 80 + "\n\n")
    
    f.write("FNV-1a 参数:\n")
    f.write(f"  offset_basis = 0x{FNV_BASIS:016X}\n")
    f.write(f"  prime        = 0x{FNV_PRIME:016X}\n\n")
    
    f.write("Python FNV-1a 哈希函数:\n")
    f.write("```python\n")
    f.write("def fnv1a_64(data: bytes) -> int:\n")
    f.write("    h = 0xCBF29CE484222325\n")
    f.write("    for b in data:\n")
    f.write("        h = ((h ^ b) * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF\n")
    f.write("    return h\n\n")
    f.write("def fnv1a_str(s: str) -> int:\n")
    f.write("    return fnv1a_64(s.encode('utf-8'))\n")
    f.write("```\n\n")
    
    f.write("-" * 80 + "\n")
    f.write("哈希表条目 (sub_180001180 行 525-590)\n")
    f.write("-" * 80 + "\n")
    for h, desc in hash_table.items():
        s = matched.get(h, ("???",))[0] if h in matched else "???"
        f.write(f"  0x{h:016X} -> '{s}'  ({desc})\n")
    
    f.write("\n" + "-" * 80 + "\n")
    f.write("额外哈希值 (sub_180001180 / sub_1800111D0)\n")
    f.write("-" * 80 + "\n")
    for h, desc in extra_hashes.items():
        s = matched.get(h, ("???",))[0] if h in matched else "???"
        f.write(f"  0x{h:016X} -> '{s}'  ({desc})\n")
    
    f.write("\n" + "-" * 80 + "\n")
    f.write("已匹配的哈希值\n")
    f.write("-" * 80 + "\n")
    for h, (s, desc) in matched.items():
        f.write(f"  0x{h:016X} -> '{s}'  ({desc})\n")
    
    f.write("\n" + "-" * 80 + "\n")
    f.write("未匹配的哈希值\n")
    f.write("-" * 80 + "\n")
    for h, desc in unmatched.items():
        f.write(f"  0x{h:016X} -> ???  ({desc})\n")
    
    f.write("\n" + "-" * 80 + "\n")
    f.write("已知字符串 FNV-1a 哈希值\n")
    f.write("-" * 80 + "\n")
    for s in verify_strings:
        h = fnv1a_str(s)
        f.write(f"  0x{h:016X} <- '{s}'\n")
    
    f.write("\n" + "-" * 80 + "\n")
    f.write("分析说明\n")
    f.write("-" * 80 + "\n")
    f.write("1. 哈希表位于 sub_180001180 函数中，通过 FNV-1a 计算字符串哈希后与 10 个硬编码值比较\n")
    f.write("2. 匹配到的条目指向 .rdata 中的关联数据（unk_180017210 区域）\n")
    f.write("3. 关联数据是 UTF-8 编码的中文文本，每个条目 16 字节\n")
    f.write("4. 额外哈希值来自 sub_1800111D0 函数，用于游戏对象分类\n")
    f.write("5. 0x2B992DDFA232 是 __security_cookie，不是字符串哈希\n")
    f.write("6. 哈希计算代码（行 518-524）:\n")
    f.write("   v55 = 0xCBF29CE484222325;  // FNV_BASIS\n")
    f.write("   do { v55 = 0x100000001B3 * ((char)_R8 ^ v55); _R8 = *v54++; } while (_R8);\n")

print(f"\n结果已保存到: {output_path}")
print(f"匹配: {len(matched)}/{len(all_target_hashes)}, 未匹配: {len(unmatched)}/{len(all_target_hashes)}")
print("完成!")