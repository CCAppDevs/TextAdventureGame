#pragma once
#include <string>

class Player
{
private:
	int Health;
	int MaxHealth;
	std::string Name;

public:
	Player();
	bool IsAlive();

	// combat
	void TakeDamage(int damage);
	std::string GetStatus();
};

