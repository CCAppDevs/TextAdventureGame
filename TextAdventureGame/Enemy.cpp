#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
	Name = "Default";
	MaxHealth = 10;
	Health = MaxHealth;
	DamageMin = 1;
	std::cout << "Enemy is created\n";
}

Enemy::Enemy(std::string name, int health, int damage)
{
	Name = name;
	MaxHealth = health;
	Health = MaxHealth;
	DamageMin = damage;
}

std::string Enemy::GetName()
{
	return Name;
}

int Enemy::GetHealth()
{
	return Health;
}

int Enemy::GetMaxHealth()
{
	return MaxHealth;
}

int Enemy::GetDamage()
{
	return DamageMin;
}

bool Enemy::IsAlive()
{
	return Health > 0;
}

void Enemy::TakeDamage(int amount)
{
	// clamp
	Health = Health - amount;

	std::cout << Name << " gets hit for " << amount << " damage!\n";

	if (Health <= 0) {
		std::cout << Name << " has died!\n";
		Health = 0;
	}
	else if (Health > MaxHealth) {
		Health = MaxHealth;
	}
}

std::string Enemy::GetStatus()
{
	return Name + " (" + std::to_string(Health) + "/" + std::to_string(MaxHealth) + ")\n";
}
