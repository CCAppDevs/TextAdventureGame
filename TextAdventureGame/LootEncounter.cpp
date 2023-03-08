#include "LootEncounter.h"

LootEncounter::LootEncounter()
{
    LootEncounter(1, 0);
}

LootEncounter::LootEncounter(int gold, int exp)
{
    Gold = gold;
    Experience = exp;
    Description = "You encounter a pile of loot... you find " + std::to_string(Gold) + " gold!\n";
    Description += "You gain " + std::to_string(Experience) + " experience!\n";
    Type = EncounterType::Loot;
}

Reward LootEncounter::GetReward()
{
    if (IsCompleted) {
        return Reward(0, 0);
    }

    return Reward(Gold, Experience);
}
