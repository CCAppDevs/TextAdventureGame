#include "EnemyEncounter.h"
#include "Enemy.h"

EnemyEncounter::EnemyEncounter(std::string name, int health, int damage)
{
	TheEnemy = Enemy(name, health, damage);
	Description = "A " + TheEnemy.GetName() + " appears!\n";
	Type = EncounterType::Monster;
}

Enemy EnemyEncounter::GetEnemy()
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
