#include "Player.h"
#include <time.h>


Player::Player()
{
	MaxHealth = 100;
	Health = MaxHealth;
	Name = "Player";
	DamageMin = 1;
	DamageMax = 10;
	Experience = 0;
	Gold = 0;
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
	return "Character: " + Name +
		" (" + std::to_string(Health) +	"/" + std::to_string(MaxHealth) + ")\n" +
		"Level: " + std::to_string(GetLevel()) +
		" - Gold: " + std::to_string(Gold) + "\n";
}

int Player::GetLevel()
{
	return 1 + (Experience / 100);
}

void Player::GainExperience(int exp)
{
	Experience += exp;
}

int Player::GetGold()
{
	return Gold;
}

void Player::SetGold(int amount)
{
	// set the value of gold to amount, don't increase it
	Gold = amount;
}

void Player::IncreaseGold(int amount)
{
	// increase, don't reset it
	Gold += amount;
}

int Player::GetDamage()
{
	// TODO: fix the min max range issue. will return wrong values when range is above 1 min
	int damage = rand() % DamageMax + DamageMin;

	return damage;
}
