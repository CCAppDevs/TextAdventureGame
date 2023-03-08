#pragma once
#include "Encounter.h"
#include "Reward.h"

class LootEncounter :
    public Encounter
{
private:
    int Gold;
    int Experience;

public:
    LootEncounter();
    LootEncounter(int gold, int exp);

    Reward GetReward();
};

