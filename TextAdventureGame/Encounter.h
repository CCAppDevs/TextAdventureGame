#pragma once
#include <string>
#include "EncounterType.h"

class Encounter
{
protected: // all child classes have access
	std::string Description;
	EncounterType Type;
	bool IsCompleted;

public: // anyone can access
	Encounter();
	Encounter(std::string desc);
	virtual std::string GetState();
	EncounterType GetType();
};
