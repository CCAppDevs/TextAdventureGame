#include "Game.h"
#include "EnemyEncounter.h"

Game::Game()
{
	IsRunning = false;
	CurrentTurn = 0;
}

void Game::StartGame()
{
	using namespace std;

	IsRunning = true;
	cout << "Starting Game\n";

	while (IsRunning) {
		TakeTurn();
	}
}

void Game::TakeTurn()
{
	using namespace std;

	CurrentTurn++;

	EnemyEncounter enc = EnemyEncounter("You encounter a goblin. He hits you for 15 damage!\n", "Goblin", 10, 2);

	cout << CurrentTurn << ": Taking a turn\n";

	cout << enc.GetState();

	ThePlayer.TakeDamage(15);
	cout << ThePlayer.GetStatus();

	cout << enc.GetState();

	if (!ThePlayer.IsAlive()) {
		cout << "The player has died\n";
		IsRunning = false;
	}
	
	if (CurrentTurn >= 10) {
		IsRunning = false;
	}
}
