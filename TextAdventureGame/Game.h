#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "Encounter.h"


class Game
{
private:
	bool IsRunning;
	Player ThePlayer;
	std::vector<Encounter> Map;
	int CurrentTurn;

	Encounter *CurrentEncounter;

public:
	Game();

	void StartGame();
	void TakeTurn();
};

