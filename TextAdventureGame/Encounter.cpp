#include "Encounter.h"

Encounter::Encounter()
{
	Description = "You have encountered a mystery!\n";
	IsCompleted = false;
	Type = EncounterType::Default;
}

Encounter::Encounter(std::string desc)
{
	Description = desc;
	IsCompleted = false;
	Type = EncounterType::Default;
}

std::string Encounter::GetState()
{
	if (IsCompleted) {
		return "There is no encounter here.\n";
	}
	else {
		IsCompleted = true;
		return Description;
	}
}

EncounterType Encounter::GetType()
{
	return Type;
}
