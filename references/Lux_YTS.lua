script = "Lux Script" -- Name of the script
ChampionName = "Lux"  -- Champion name Jinx,.. , leave empty if this is Utility

local orbwalker = game.orbwalker
local prediction = game.prediction
local targetselector = game.targetselector
local renderer = game.renderer
local evade = game.evade

local Q = { Type = SkillshotType.SkillshotLine,
            Delay = 0.25,
            Radius = 70,
            Range = 1100,
            Radius = 30,
            Range = 1240,
            Speed = 1200,
            Collision = true,
            CollisionFlags = { CollisionableObjects.YasuoWall, CollisionableObjects.Minions } }
local W = { Type = SkillshotType.SkillshotCircle,
            Delay = 0.25,
            Radius = 110,
            Radius = 50,
            Range = 1175,
            Speed = 2400,
            Collision = false,
            CollisionFlags = {  } }
local E = { Type = SkillshotType.SkillshotLine,
            Delay = 0.25,
            Radius = 155,
            Radius = 50,
            Range = 1100,
            Speed = 1200,
            Collision = true,
            CollisionFlags = { CollisionableObjects.YasuoWall } }
local R = { Type = SkillshotType.SkillshotLine,
            Delay = 1,
            Radius = 100,
            Radius = 30,
            Range = 3400,
            Speed = 999999,
            Collision = false,
            CollisionFlags = {  } }
local useQ = nil
local useW = nil
local useE = nil
local useR = nil

local autoQ = nil
local autoW = nil
local autoWHeal = nil
local autoE = nil
local autoR = nil

local qRange = nil
local eRange = nil
local rRange = nil

local manaHarass = nil
local manaFarm = nil
local minMinionE = nil

local killStealQ = nil
local killStealW = nil
local killStealE = nil
local killStealR = nil

local useQFarm = nil
local useWFarm = nil
local useEFarm = nil
local useRFarm = nil

local useQHarass = nil
local useEHarass = nil
local useRHarass = nil

local drawQ = nil
local drawW = nil
local drawE = nil
local drawR = nil

local SpellQ = game.localPlayer:GetSpellBook():GetSpellSlotByID(SpellSlot.Q)
local SpellW = game.localPlayer:GetSpellBook():GetSpellSlotByID(SpellSlot.W)
local SpellE = game.localPlayer:GetSpellBook():GetSpellSlotByID(SpellSlot.E)
local SpellR = game.localPlayer:GetSpellBook():GetSpellSlotByID(SpellSlot.R)
package.path = package.path .. ";./scripts/libs/?.lua"
local Util = require("util")

if Util.isExpired then
    print("Expired!")
    return
end
local _delayAction = { }
local DelayAction = function(delay, funct, args)
    _delayAction[#_delayAction + 1] = { funct = funct, time = game.GameTick + delay, args = args }
end

local ExecuteDelay = function()
    for i = #_delayAction, 1, -1 do
        if _delayAction[i].time < game.GameTick then
            _delayAction[i].funct(table.unpack(_delayAction[i].args or {}))
            _delayAction[i] = _delayAction[#_delayAction]
            _delayAction[#_delayAction] = nil
        end
    end
end

local function Rotate(startPos, endPos, height, theta)
    local dx, dy = endPos.x - startPos.x, endPos.z - startPos.z
    local px, py = dx * math.cos(theta) - dy * math.sin(theta), dx * math.sin(theta) + dy * math.cos(theta)
    return Vector3(px + startPos.x, height, py + startPos.z)
end

local function Perpendicular(v)
    return Vector3(-v.z, v.y, v.x)
end

local function Perpendicular2(v)
    return Vector3(v.z, v.y, -v.x)
end
local function Lerp(from, to, t)
    local newT = math.clamp(t, 0, 1)
    return Vector3(from.x + (to.x - from.x) * newT, from.y + (to.y - from.y) + newT, from.z + (to.z - from.z) * newT)
end
local function FindBestWallPos(startPos, mousePos, objectHeight)
    local mPos, height = mousePos, objectHeight
    for i = 100, 2000, 100 do
        -- search range
        local endPos = startPos:Extended(mPos, i)
        for j = 20, 360, 20 do
            -- angle step
            local testPos = Rotate(startPos, endPos, height, math.rad(j))
            if testPos then
                if game.IsWall(testPos) then
                    return testPos
                end
            end
        end
    end
    return nil
end
local function DrawAllTroys()
    for _, troy in pairs(game.troys) do
        local troyName = troy:Name()
        renderer:DrawCircle3D(troy:Position(),
                troy:BoundingRadius() + 5,
                Color.ARGB(100, 255, 0, 0), 1, 50)
        renderer:DrawText3D(troy:Position(), 30, Color.ARGB(100, 0, 255, 0), true, true, troyName)
    end
end
local function VectorPointProjectionOnLineSegment(v1, v2, v)
    local cx, cy, ax, ay, bx, by = v.x, (v.z or v.y), v1.x, (v1.z or v1.y), v2.x, (v2.z or v2.y)
    local rL = ((cx - ax) * (bx - ax) + (cy - ay) * (by - ay)) / ((bx - ax) * (bx - ax) + (by - ay) * (by - ay))
    local pointLine = { x = ax + rL * (bx - ax), y = ay + rL * (by - ay) }
    local rS = rL < 0 and 0 or (rL > 1 and 1 or rL)
    local isOnSegment = rS == rL
    local pointSegment = isOnSegment and pointLine or { x = ax + rS * (bx - ax), y = ay + rS * (by - ay) }
    return pointSegment, pointLine, isOnSegment
end
local function Ready(spellSlot)
    local spell = game.localPlayer:GetSpellBook():GetSpellSlotByID(spellSlot)
    if spell:GetSpellData():Name() == 'NilahE' then
        return spell:ManaCost() < game.localPlayer:Mana()
                and spell:Ammo() > 0
    end
    return spell:ManaCost() < game.localPlayer:Mana()
            and spell:IsReady()
end

local function GetDistanceToTarget(target)
    return target:ServerPosition():Distance(game.localPlayer:ServerPosition())
end

local function CountEnemiesInRange(range)
    local count = 0
    for _, enemy in pairs(game.enemy_heros) do
        if GetDistanceToTarget(enemy) < range then
            count = count + 1
        end
    end
    return count
end
local function CountObjectNearPos(pos, range, radius, objects)
    local count = 0
    for _, object in pairs(objects) do
        if pos:Distance(object:ServerPosition()) <= radius + range then
            count = count + 1
        end
    end
    return count
end
local function GetBestMinionInRange(range)
    local health = 999999
    local best = nil
    for _, minion in pairs(game.enemy_minions) do
        if GetDistanceToTarget(minion) < range then
            if minion:Health() < health then
                health = minion:Health()
                best = minion
            end
        end
    end
    return best
end

local function GetBestJungleInRange(range)
    local health = 999999
    local best = nil
    for _, jungle in pairs(game.jungles) do
        if GetDistanceToTarget(jungle) < range then
            if jungle:Health() < health then
                health = jungle:Health()
                best = jungle
            end
        end
    end
    return best
end

local function GetDistanceSqr2(p1, p2)
    p2x, p2y, p2z = p2.x, p2.y, p2.z
    p1x, p1y, p1z = p1.x, p1.y, p1.z
    local dx = p1x - p2x
    local dz = (p1z or p1y) - (p2z or p2y)
    return dx * dx + dz * dz
end
local function CountObjectOnLineSegment(startPos, endPos, width, objects)
    local count = 0
    for _, object in pairs(objects) do
        local pointSegment, pointLine, isOnSegment = VectorPointProjectionOnLineSegment(startPos, endPos, object:ServerPosition())
        if isOnSegment
                and GetDistanceSqr2(pointSegment, object:ServerPosition()) < width * width
                and GetDistanceSqr2(startPos, endPos) > GetDistanceSqr2(startPos, object:ServerPosition()) then
            count = count + 1
        end
    end
    return count
end
local function GetAllMinionInRange(range)
    local inRangeMinion = {}
    for _, minion in pairs(game.enemy_minions) do
        if GetDistanceToTarget(minion) < range then
            table.insert(inRangeMinion, minion)
        end
    end
    return inRangeMinion
end
local function GetJFarmPosition(range, width)
    local BestMinion = nil
    local BestHit = 0
    local inRangeMinion = GetAllMinionInRange(range)
    for _, minion in pairs(game.enemy_minions) do
        local hit = CountObjectNearPos(minion:ServerPosition(), 0, width, inRangeMinion)
        if hit > BestHit then
            BestHit = hit
            BestMinion = minion
        end
    end

    return BestMinion, BestHit
end
local function GetLineFarmPosition(range, width, source)
    local BestMinion = nil
    local BestHit = 0
    local source = source or game.localPlayer
    local inRangeMinion = GetAllMinionInRange(range)

    for _, minion in pairs(game.enemy_minions) do
        local endPos = source:ServerPosition()
                + (Vector3(range, range, range) * (minion:ServerPosition() - source:ServerPosition()):Normalized())
        local hit = CountObjectOnLineSegment(source:ServerPosition(), endPos, width, inRangeMinion)
        if hit > BestHit then
            BestHit = hit
            BestMinion = minion
        end
    end

    return BestMinion, BestHit
end
local function IsImmobile(target)
    for _, buff in pairs(target:Buffs()) do
        if (buff.Type == 5
                or buff.Type == 8
                or buff.Type == 12
                or buff.Type == 22
                or buff.Type == 23
                or buff.Type == 25
                or buff.Type == 30
                or buff.Type == 35) and buff.Count > 0 then

            return true
        end
        return false
    end
end

local function GetEnemyImmobileInRange(range)
    for _, hero in pairs(game.enemy_heros) do
        if GetDistanceToTarget(hero) < range then
            if IsImmobile(hero) then
                return hero
            end
        end
    end
    return nil
end

local function IsUnderEnemyTurret(pos)
    for _, turret in pairs(game.turrets) do
        if turret:Team() ~= game.localPlayer:Team() then
            if pos:Distance(turret:ServerPosition()) < 800 then
                return true
            end
        end
    end
    return false
end

local function CalcPhysicalDamage(source, target, amount)
    local armorPenetrationPercent = source:PercentArmorPenetration()
    local armorPenetrationFlat = source:FlatArmorPenetration()
    local bonusArmorPenetrationMod = source:PercentBonusArmorPenetration()

    local armor = target:Armor()
    local bonusArmor = target:BonusArmor()
    local value

    if armor < 0 then
        value = 2 - 100 / (100 - armor)
    elseif armor * armorPenetrationPercent - bonusArmor *
            (1 - bonusArmorPenetrationMod) - armorPenetrationFlat < 0 then
        value = 1
    else
        value = 100 / (100 + armor * armorPenetrationPercent - bonusArmor *
                (1 - bonusArmorPenetrationMod) - armorPenetrationFlat)
    end

    return math.max(math.floor(value * amount), 0)

end

local function CalcMagicDamage(source, target, amount)
    local magicPenetrationPercent = source:PercentMagicPenetration()
    local magicPenetrationFlat = source:FlatMagicPenetration()
    local bonusMagicPenetrationMod = source:PercentBonusMagicPenetration()

    local magicResist = target:MagicResist()
    local bonusMagicResist = target:BonusMagicResist()

    local value

    if magicResist < 0 then
        value = 2 - 100 / (100 - magicResist)
    elseif magicResist * magicPenetrationPercent - bonusMagicResist *
            (1 - bonusMagicPenetrationMod) - magicPenetrationFlat < 0 then
        value = 1
    else
        value = 100 / (100 + magicResist * magicPenetrationPercent - bonusMagicResist *
                (1 - bonusMagicPenetrationMod) - magicPenetrationFlat)
    end

    return math.max(math.floor(value * amount), 0)

end
function Init()
    local menu = Menu.CreateMenu("Lux", "Lux YTS++")
    Combo = menu:AddMenu("Combo", "Combo")
    useQ = Combo:AddCheckBox("CheckBox", "[Q] Use Q", true)
    qRange = Combo:AddSlider("Slider", "[Q] Max range to use Q", 1200, 0, 1200, 100)
    useW = Combo:AddCheckBox("CheckBox", "[W] Use W", true)
    useE = Combo:AddCheckBox("CheckBox", "[E] Use E", true)
    useR = Combo:AddCheckBox("CheckBox", "[R] Use R", true)

    KillSteal = menu:AddMenu("KillSteal", "KillSteal")
    killStealQ = KillSteal:AddCheckBox("CheckBox", "[Q] Kill Steal", true)
    killStealE = KillSteal:AddCheckBox("CheckBox", "[E] Kill Steal", true)
    killStealR = KillSteal:AddCheckBox("CheckBox", "[R] Kill Steal", true)

    Auto = menu:AddMenu("Auto", "Auto")
    autoQ = Auto:AddCheckBox("CheckBox", "[Q] Auto", true)
    autoW = Auto:AddCheckBox("CheckBox", "[W] Auto", true)
    autoWHeal = Auto:AddSlider("Slider", "[W] When hp < x %", 50, 0, 100, 10)
    autoE = Auto:AddCheckBox("CheckBox", "[E] Auto", true)
    autoR = Auto:AddCheckBox("CheckBox", "[R] Auto", true)

    Harass = menu:AddMenu("Harass", "Harass")
    useQHarass = Harass:AddCheckBox("CheckBox", "[Q] Harass", true)
    useEHarass = Harass:AddCheckBox("CheckBox", "[E] Harass", true)
    manaHarass = Harass:AddSlider("Slider", "Min mana harass %", 20, 0, 100, 10)

    Farm = menu:AddMenu("Farm", "Farm")
    useQFarm = Farm:AddCheckBox("CheckBox", "[Q] Farm", true)
    useEFarm = Farm:AddCheckBox("CheckBox", "[E] Farm", true)
    minMinionE = Farm:AddSlider("Slider", "Min minion cast E", 3, 1, 6, 1)
    manaFarm = Farm:AddSlider("Slider", "Min mana farm %", 20, 0, 100, 10)

    Drawing = menu:AddMenu("Drawing", "Drawing")
    drawQ = Drawing:AddCheckBox("CheckBox", "Draw [Q]", true)
    drawW = Drawing:AddCheckBox("CheckBox", "Draw [W]", true)
    drawE = Drawing:AddCheckBox("CheckBox", "Draw [E]", true)
    drawR = Drawing:AddCheckBox("CheckBox", "Draw [R]", true)
end

function Tick()
    if game.combo_mode == ScriptMode.Combo then
        LuxCombo()
    end
    if game.combo_mode == ScriptMode.Mixed then
        LuxHarass()
    end
    if game.combo_mode == ScriptMode.LaneClear then
        LuxClear()
        LuxJungleClear()
    end
    LuxAutoQ()
    LuxAutoW()
    LuxAutoE()
    LuxAutoR()
    LuxKillSteal()
end

function LuxQDamage(target)
    local damage = ({ 80, 120, 160, 200, 240 })[SpellQ:Level()] + 0.6 * game.localPlayer:TotalAbilityPower()
    return CalcMagicDamage(game.localPlayer, target, damage)
end

function LuxEDamage(target)
    local damage = ({ 70, 120, 170, 220, 270 })[SpellE:Level()] + 0.8 * game.localPlayer:TotalAbilityPower()
    return CalcMagicDamage(game.localPlayer, target, damage)
end

function LuxRDamage(target)
    local damage = ({ 300, 400, 500 })[SpellR:Level()] + 1.2 * game.localPlayer:TotalBonusAttackDamage()
    return CalcMagicDamage(game.localPlayer, target, damage)
end

function LuxCastQ(target, hitchance)
    local pred = prediction:GetPredicton(target, PredictionInput:SetSkillShot(
            {
                Range = Q.Range,
                Delay = Q.Delay,
                Radius = Q.Radius,
                Speed = Q.Speed,
                Collision = Q.Collision,
                Type = Q.Type,
                useBoundingRadius = true,
                Target = target,
                CollisionFlags = Q.CollisionFlags
            }))
    if pred:HitChance() >= hitchance then
        CastSpell.CastOnPos(SpellSlot.Q, pred.CastPosition)
    end
end

function LuxCastE(target, hitchance)
    local pred = prediction:GetPredicton(target, PredictionInput:SetSkillShot(
            {
                Range = E.Range,
                Delay = E.Delay,
                Radius = E.Radius,
                Speed = E.Speed,
                Collision = E.Collision,
                Type = E.Type,
                useBoundingRadius = true,
                Target = target,
                CollisionFlags = E.CollisionFlags
            }))
    if pred:HitChance() >= hitchance then
        CastSpell.CastOnPos(SpellSlot.E, pred.CastPosition)
    end
end

function LuxCastW(target)
    local pred = prediction:GetPredicton(target, PredictionInput:SetSkillShot(
            {
                Range = W.Range,
                Delay = W.Delay,
                Radius = W.Radius,
                Speed = W.Speed,
                Collision = W.Collision,
                Type = W.Type,
                useBoundingRadius = true,
                Target = target,
                CollisionFlags = W.CollisionFlags
            }))
    if pred:HitChance() >= HitChance.Medium then
        CastSpell.CastOnPos(SpellSlot.W, pred.CastPosition)
    end
end

function LuxCastR(target)
    local pred = prediction:GetPredicton(target, PredictionInput:SetSkillShot(
            {
                Range = R.Range,
                Delay = R.Delay,
                Radius = R.Radius,
                Speed = R.Speed,
                Collision = R.Collision,
                Type = R.Type,
                useBoundingRadius = true,
                Target = target,
                CollisionFlags = R.CollisionFlags
            }))
    if pred:HitChance() >= HitChance.Immobile then
        CastSpell.CastOnPos(SpellSlot.R, game.localPlayer:ServerPosition():Extended(pred.CastPosition, 300))
    end
end

function LuxAutoQ()
    for _, target in pairs(game.enemy_heros) do
        if target:IsValidTarget() and GetDistanceToTarget(target) <= 1175
                and autoQ.Value
                and Ready(SpellSlot.Q) then
            LuxCastQ(target, HitChance.Immobile)
        end
    end
end

function LuxAutoR()
    for _, target in pairs(game.enemy_heros) do
        if target:IsValidTarget() and GetDistanceToTarget(target) <= R.Range
                and autoR.Value
                and Ready(SpellSlot.R) then
            LuxCastR(target, HitChance.Immobile)
        end
    end
end

local function IsELanded(unit)
    local LuxBuff = game.localPlayer:HasBuff("LuxLightStrikeKugel")
    local targetBuff = unit:HasBuff("slow")
    if LuxBuff and targetBuff then
        return true
    end
    return false
end

function LuxAutoE()
    for _, target in pairs(game.enemy_heros) do

        if game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= 1100
                and target:IsValidTarget()
                and IsELanded(target) then
            CastSpell.Cast(SpellSlot.E)
        end

        if GetDistanceToTarget(target) <= 1000
                and Ready(SpellSlot.E)
        then
            if autoE.Value then
                LuxCastE(target, HitChance.Immobile)
            end
        end
    end
end

function LuxAutoW()
    local target = targetselector:GetTarget(2000)
    if target == nil then
        return
    end
    if target:IsValidTarget() and CountEnemiesInRange(1000) > 0 then
        if autoW.Value and Ready(SpellSlot.W) and not game.localPlayer:IsRecalling() then
            if game.localPlayer:HealthPercent() <= autoWHeal.Value then
                CastSpell.Cast(SpellSlot.W)
            end
            for _, ally in pairs(game.ally_heros) do
                if ally:IsValidTarget()
                        and game.localPlayer:ServerPosition():Distance(ally:ServerPosition()) <= 1075
                        and ally:HealthPercent() <= autoWHeal.Value then
                    LuxCastW(ally)
                end
            end
        end
    end
end

function LuxCombo()
    local target = targetselector:GetTarget(1300)
    if target == nil then
        return
    end
    if target:IsValidTarget() then

        if game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= qRange.Value
                and useQ.Value
                and Ready(SpellSlot.Q) then
            LuxCastQ(target, HitChance.VeryHigh)
        end

        if useE.Value and Ready(SpellSlot.E) then
            if IsELanded(target) then
                CastSpell.Cast(SpellSlot.E)
            elseif game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= 1000 then
                LuxCastE(target, HitChance.VeryHigh)
            end
        end
    end
end

function LuxHarass()
    local target = targetselector:GetTarget(1300)
    if target == nil then
        return
    end
    if target:IsValidTarget() and game.localPlayer:ManaPercent() >= manaHarass.Value then

        if game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= qRange.Value
                and useQHarass.Value
                and Ready(SpellSlot.Q) then
            LuxCastQ(target, HitChance.VeryHigh)
        end

        if useEHarass.Value
                and Ready(SpellSlot.E) then
            if IsELanded(target) then
                CastSpell.Cast(SpellSlot.E)
            elseif game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= 1000 then
                LuxCastE(target, HitChance.VeryHigh)
            end
        end
    end
end

function LuxClear()
    for _, minion in pairs(game.enemy_minions) do
        if game.localPlayer:ServerPosition():Distance(minion:ServerPosition()) <= 1000 and minion:IsValidTarget() then
            local mana_ok = game.localPlayer:ManaPercent() >= manaFarm.Value

            if useEFarm.Value then
                if IsELanded(minion) then
                    CastSpell.Cast(SpellSlot.E)
                elseif mana_ok and Ready(SpellSlot.E) then
                    local count = CountObjectNearPos(minion:ServerPosition(), 0, E.Radius * 2, game.enemy_minions)
                    if count >= minMinionE.Value then
                        CastSpell.CastOnPos(SpellSlot.E, minion:ServerPosition())
                    end
                end
            end
        end
    end
end

function LuxJungleClear()
    for _, minion in pairs(game.jungles) do
        if game.localPlayer:ServerPosition():Distance(minion:ServerPosition()) <= 1000 and minion:IsValidTarget() then
            local mana_ok = game.localPlayer:ManaPercent() >= manaFarm.Value

            if useEFarm.Value then
                if IsELanded(minion) then
                    CastSpell.Cast(SpellSlot.E)
                elseif mana_ok and Ready(SpellSlot.E) then
                    CastSpell.CastOnPos(SpellSlot.E, minion:ServerPosition())
                end
            end
        end
    end
end

function LuxKillSteal()
    for _, target in pairs(game.enemy_heros) do
        if game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= 3500
                and target:IsValidTarget() then
            local hp = target:Health()
            if killStealQ.Value
                    and game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= qRange.Value
                    and Ready(SpellSlot.Q) then
                local QDmg = LuxQDamage(target)
                if QDmg >= hp then
                    LuxKillStealQ(target)
                end
            end
            if killStealE.Value
                    and game.localPlayer:ServerPosition():Distance(target:ServerPosition()) <= 1000
                    and Ready(SpellSlot.E) then
                local EDmg = LuxEDamage(target)
                if EDmg >= hp then
                    LuxKillStealE(target)
                end
            end
            if killStealR.Value
                    and game.localPlayer:ServerPosition():Distance(target:ServerPosition()) >= game.localPlayer:RealAttackRange()
                    and Ready(SpellSlot.R) then
                local RDmg = LuxRDamage(target)
                local RDmg2 = LuxRDamage(target) + (10 + 10 * game.localPlayer:Level() + game.localPlayer:BonusMagicDamage() * 0.2)
                local buff = target:HasBuff("LuxIlluminatingFraulein")
                if buff and RDmg2 >= hp then
                    LuxKillStealR(target)
                end
                if RDmg >= hp then
                    LuxKillStealR(target)
                end
            end
        end
    end
end

function LuxKillStealQ(target)
    LuxCastQ(target, HitChance.VeryHigh)
end

function LuxKillStealE(target)
    LuxCastE(target, HitChance.VeryHigh)
end

function LuxKillStealR(target)
    LuxCastR(target, HitChance.Immobile)
end

function Draw()
    if drawQ.Value and Ready(SpellSlot.Q) then
        renderer:DrawCircle3D(game.localPlayer:Position(),
                qRange.Value,
                Color.ARGB(100, 255, 0, 0), 1, 50)
    end
    if drawW.Value and Ready(SpellSlot.W) then
        renderer:DrawCircle3D(game.localPlayer:Position(),
                W.Range,
                Color.ARGB(100, 255, 0, 0), 1, 50)
    end
    if drawE.Value and Ready(SpellSlot.E) then
        renderer:DrawCircle3D(game.localPlayer:Position(),
                E.Range,
                Color.ARGB(100, 255, 0, 0), 1, 50)
    end
    if drawR.Value and Ready(SpellSlot.R) then
        renderer:DrawCircle3D(game.localPlayer:Position(),
                R.Range,
                Color.ARGB(100, 255, 0, 0), 1, 50)
    end
end

