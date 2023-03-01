#pragma once
#include <string>

class Enemy
{
public:
	Enemy();
	Enemy(std::string name, int health, int damage);

	// getters
	std::string GetName();
	int GetHealth();
	int GetMaxHealth();
	int GetDamage();
	bool IsAlive();

	// take damage
	void TakeDamage(int amount);
	std::string GetStatus();

private:
	std::string Name;
	int Health;
	int MaxHealth;
	int DamageMin;
	// int DamageMax;
	// int Level;
};

