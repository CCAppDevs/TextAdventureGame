#include "Game.h"

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
	CurrentTurn++;

	std::cout << "Taking a turn\n";

	if (!ThePlayer.IsAlive()) {
		std::cout << "The player has died\n";
		IsRunning = false;
	}
	
	if (CurrentTurn >= 10) {
		IsRunning = false;
	}
}
