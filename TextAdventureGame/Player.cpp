#include "Player.h"

Player::Player()
{
	MaxHealth = 100;
	Health = MaxHealth;
	Name = "Player";
}

bool Player::IsAlive()
{
	return Health > 0;
}

void Player::TakeDamage(int damage)
{
	Health = Health - damage;

	if (Health < 0) {
		Health = 0;
	}
	else if (Health > MaxHealth) {
		Health = MaxHealth;
	}
}

std::string Player::GetStatus()
{
	return "Character: " + Name + " (" + std::to_string(Health) + "/" + std::to_string(MaxHealth) + ")\n";
}
