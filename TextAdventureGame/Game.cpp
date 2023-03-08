#include "Game.h"
#include "EnemyEncounter.h"
#include "LootEncounter.h"

Game::Game()
{
	IsRunning = false;
	CurrentTurn = 0;
	ThePlayer = Player();

	// load ten encounters
	for (int i = 0; i < 10; i++) {
		// add a new goblin encounter
		if (i >= 1) {
			Map.push_back(new LootEncounter(100, 100));
		}
		else {
			Map.push_back(new EnemyEncounter("Goblin", 10, 5, 20, 20));
		}
	}

	CurrentEncounter = Map[0];
}

void Game::StartGame()
{
	using namespace std;

	IsRunning = true;
	cout << "Starting Game\n";

	cout << "The player is level: " << ThePlayer.GetLevel() << "\n";

	cout << "Press any key to begin.\n";
	cin.get();

	while (IsRunning) {
		// clear the screen
		system("cls");
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

		while (!enc->IsCompleted) {
			// do stuff to the enemy
			cout << ThePlayer.GetStatus();
			cout << enc->GetEnemy().GetStatus();

			// prompt the user for an action

			cout << "What would you like to do?\n";
			cout << "A) Attack\n";
			cout << "R) Run\n";
			char option;
			cin.get(option);

			// TODO: Fix multi character inputs from choosing multiple options.
			option = tolower(option);

			switch (option) {
			case 'a':
				// attack the enemy
				enc->GetEnemy().TakeDamage(ThePlayer.GetDamage());
				break;
			case 'r':
				// run away
				cout << "You attempt to run away!\n";
				cout << "No luck! You are stuck!\n";
				enc->SetComplete();
				break;
			default:
				cout << "Invalid option, please choose again.\n";
				break;
			}
			
			cin.clear();
			cin.ignore();

			if (!enc->GetEnemy().IsAlive()) {
				Reward reward = enc->GetReward();

				ThePlayer.GainExperience(reward.Experience);
				ThePlayer.IncreaseGold(reward.Gold);

				cout << "You gain: " << reward.Experience << " experience and " << reward.Gold << " gold.\n";

				enc->SetComplete();
				cout << "Press any key to continue.\n";
				cin.get();
			}
			else {
				int damage = enc->GetEnemy().GetDamage();
				cout << "The " << enc->GetEnemy().GetName() << " hits you for " << damage << "!\n";
				ThePlayer.TakeDamage(damage);
				cout << ThePlayer.GetStatus();
				cout << "Press any key to continue.\n";
				cin.get();
			}
		}
		
		if (CurrentTurn < 10) {
			CurrentEncounter = Map[CurrentTurn];
		}
	}
	else if (CurrentEncounter->GetType() == EncounterType::Default) {
		// print out the description
		cout << CurrentEncounter->GetState();

		if (CurrentTurn < 10) {
			CurrentEncounter = Map[CurrentTurn];
		}
	}
	else if (CurrentEncounter->GetType() == EncounterType::Loot) {
		// pick up some loot and finish
		cout << CurrentEncounter->GetState();

		// capture the loot
		LootEncounter* enc = dynamic_cast<LootEncounter*>(CurrentEncounter);

		Reward reward = enc->GetReward();

		ThePlayer.GainExperience(reward.Experience);
		ThePlayer.IncreaseGold(reward.Gold);

		cout << ThePlayer.GetStatus();

		// advance the turn
		if (CurrentTurn < 10) {
			CurrentEncounter = Map[CurrentTurn];
		}

		cout << "\nPress enter to continue\n";
		cin.get();
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
