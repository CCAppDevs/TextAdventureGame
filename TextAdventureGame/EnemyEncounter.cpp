#include "EnemyEncounter.h"
#include "Enemy.h"
#include <iostream>

EnemyEncounter::EnemyEncounter(std::string name, int health, int damage, int gold, int exp)
{
	TheEnemy = Enemy(name, health, damage);
	Description = "A " + TheEnemy.GetName() + " appears!\n";
	Type = EncounterType::Monster;
	GoldReward = gold;
	ExperienceReward = exp;
}

EnemyEncounter::~EnemyEncounter()
{
	std::cout << "Enemy Encounter has died\n";
}

Enemy& EnemyEncounter::GetEnemy()
{
	return TheEnemy;
}

void EnemyEncounter::SetComplete()
{
	IsCompleted = true;
}

std::string EnemyEncounter::GetState()
{
	if (IsCompleted) {
		return "There is a dead body of a " + TheEnemy.GetName() + " here\n";
	}
	else {
		return Description;
	}
}

Reward EnemyEncounter::GetReward()
{
	if (IsCompleted) {
		return Reward(0, 0);
	}

	return Reward(GoldReward, ExperienceReward);
}
