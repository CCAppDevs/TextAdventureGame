#include "Enemy.h"

Enemy::Enemy()
{
	Name = "Default";
	MaxHealth = 10;
	Health = MaxHealth;
	DamageMin = 1;
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

	if (Health < 0) {
		Health = 0;
	}
	else if (Health > MaxHealth) {
		Health = MaxHealth;
	}
}
