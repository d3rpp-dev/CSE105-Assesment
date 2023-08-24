#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(std::string _name, Race _race);

	std::string attack() override;
	std::string get_class() override;
};

