#include "Game.h"
#include "EnemyEncounter.h"

Game::Game()
{
	IsRunning = false;
	CurrentTurn = 0;
	CurrentEncounter = EnemyEncounter("Goblin", 10, 2);
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

	cout << CurrentTurn << ": Taking a turn\n";

	cout << CurrentEncounter.GetState();

	if (CurrentEncounter.GetType() == EncounterType::Monster) {
		
		
		
		//ThePlayer.TakeDamage(15);

		// start a loop here and do an entire fight until someone is dead

		//cout << ThePlayer.GetStatus();
	}
	else if (CurrentEncounter.GetType() == EncounterType::Default) {
		cout << CurrentEncounter.GetState();
	}

	

	if (!ThePlayer.IsAlive()) {
		cout << "The player has died\n";
		IsRunning = false;
	}
	
	if (CurrentTurn >= 10) {
		IsRunning = false;
	}
}
