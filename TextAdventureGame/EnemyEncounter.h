#pragma once
#include "Encounter.h"
#include "Enemy.h"
#include "Reward.h"

class EnemyEncounter : public Encounter
{
public:
	EnemyEncounter(std::string name, int health, int damage, int gold = 1, int exp = 5);
	~EnemyEncounter();

	Enemy& GetEnemy();

	void SetComplete();

	std::string GetState();

	Reward GetReward();

private:
	Enemy TheEnemy;
	int GoldReward;
	int ExperienceReward;
};

