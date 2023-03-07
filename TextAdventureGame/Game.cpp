#include "Game.h"
#include "EnemyEncounter.h"

Game::Game()
{
	IsRunning = false;
	CurrentTurn = 0;
	ThePlayer = Player();

	// load ten encounters
	for (int i = 0; i < 10; i++) {
		// add a new goblin encounter
		Map.push_back(new EnemyEncounter("Goblin", 10, 5, 20, 20));
	}

	CurrentEncounter = Map[0];
}

void Game::StartGame()
{
	using namespace std;

	IsRunning = true;
	cout << "Starting Game\n";

	cout << "The player is level: " << ThePlayer.GetLevel() << "\n";

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
			enc->GetEnemy().TakeDamage(ThePlayer.GetDamage());

			if (!enc->GetEnemy().IsAlive()) {
				Reward reward = enc->GetReward();

				ThePlayer.GainExperience(reward.Experience);
				ThePlayer.IncreaseGold(reward.Gold);

				enc->SetComplete();
			}
			else {
				int damage = enc->GetEnemy().GetDamage();
				cout << "The " << enc->GetEnemy().GetName() << " hits you for " << damage << "!\n";
				ThePlayer.TakeDamage(damage);
				cout << ThePlayer.GetStatus();
			}
		}
		
		if (CurrentTurn < 10) {
			CurrentEncounter = Map[CurrentTurn];
		}
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
