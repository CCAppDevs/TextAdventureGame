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
	EnemyEncounter(std::string name, int health, int damage);
	~EnemyEncounter();

	Enemy& GetEnemy();

	void SetComplete();

	std::string GetState();

private:
	Enemy TheEnemy;
};

