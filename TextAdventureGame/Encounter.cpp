#include "Encounter.h"

Encounter::Encounter(std::string desc)
{
	Description = desc;
	IsCompleted = false;
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
