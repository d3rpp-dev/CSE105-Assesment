#pragma once
#include <string>
#include <sstream>
#include "Race.h"

std::string race_to_string(const Race& race) {
	switch (race) {
	case Human:
		return "Human";
	case Elf:
		return "Elf";
	case Dwarf:
		return "Dwarf";
	case Orc:
		return "Orc";
	case Troll:
		return "Troll";
	default:
		return "Alien (Unknown)";
	}
}
