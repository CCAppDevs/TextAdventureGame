#include "Game.h"
#include "EnemyEncounter.h"

Game::Game()
{
	IsRunning = false;
	CurrentTurn = 0;
	CurrentEncounter = new EnemyEncounter("Goblin", 10, 2);
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

	if (CurrentEncounter->GetType() == EncounterType::Monster) {
		cout << CurrentEncounter->GetState();
		
		EnemyEncounter* enc = dynamic_cast<EnemyEncounter*>(CurrentEncounter);

		while (enc->GetEnemy().IsAlive()) {
			// do stuff to the enemy
			cout << enc->GetEnemy().GetStatus();
			enc->GetEnemy().TakeDamage(2);

			if (!enc->GetEnemy().IsAlive()) {
				enc->SetComplete();
			}
		}
		// while the monster is alive and the player is not dead
			// prompt for our action
			// do the action
			// monster attack (if alive)
			// say our current status (health, etc)
	}
	else if (CurrentEncounter->GetType() == EncounterType::Default) {
		// print out the description
		cout << CurrentEncounter->GetState();
	}
	else if (CurrentEncounter->GetType() == EncounterType::Loot) {
		// pick up some loot and finish
	}
	else if (CurrentEncounter->GetType() == EncounterType::Puzzle) {
		// display the puzzle and prompt for the correct answer
	}
	else {
		cout << "The encounter here is invalid.\n";
	}

	

	if (!ThePlayer.IsAlive()) {
		cout << "The player has died\n";
		IsRunning = false;
	}
	
	if (CurrentTurn >= 10) {
		IsRunning = false;
	}
}
