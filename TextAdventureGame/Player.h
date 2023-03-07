#pragma once
#include <string>

class Player
{
private:
	int Health;
	int MaxHealth;
	std::string Name;
	int DamageMin;
	int DamageMax;
	int Experience;
	int Gold;

public:
	Player();
	bool IsAlive();

	// combat
	void TakeDamage(int damage);
	std::string GetStatus();

	int GetLevel();
	void GainExperience(int exp);

	int GetGold();
	void SetGold(int amount);
	void IncreaseGold(int amount);

	int GetDamage();
};

