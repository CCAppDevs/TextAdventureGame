#include "Player.h"
#include <time.h>


Player::Player()
{
	MaxHealth = 100;
	Health = MaxHealth;
	Name = "Player";
	DamageMin = 1;
	DamageMax = 10;
	// seed the random number generator
	srand(time(NULL));
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

int Player::GetDamage()
{
	// TODO: fix the min max range issue. will return wrong values when range is above 1 min
	int damage = rand() % DamageMax + DamageMin;

	return damage;
}
