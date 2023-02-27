#pragma once
#include "Encounter.h"
#include "Enemy.h"

class EnemyEncounter : public Encounter
{
	// inherited:
		// description of the encounter
		// isCompleted Flag
		// type of encounter?

	// new stuff:
		// the enemy type
	
public:
	EnemyEncounter(std::string desc, std::string name, int health, int damage);

private:
	Enemy TheEnemy;
};

