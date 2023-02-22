#pragma once
#include <string>

class Encounter
{
private:
	std::string Description;
	bool IsCompleted;

public:
	Encounter(std::string desc);
	std::string GetState();
};

