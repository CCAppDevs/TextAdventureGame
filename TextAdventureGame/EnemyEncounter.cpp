#include "EnemyEncounter.h"
#include "Enemy.h"

EnemyEncounter::EnemyEncounter(std::string desc, std::string name, int health, int damage) : Encounter(desc)
{
	TheEnemy = Enemy(name, health, damage);
}
