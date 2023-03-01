#include "EnemyEncounter.h"
#include "Enemy.h"
#include <iostream>

EnemyEncounter::EnemyEncounter(std::string name, int health, int damage)
{
	TheEnemy = Enemy(name, health, damage);
	Description = "A " + TheEnemy.GetName() + " appears!\n";
	Type = EncounterType::Monster;
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
