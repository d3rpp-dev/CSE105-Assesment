#pragma once
#include "Player.h"

class Mage : public Player
{
public:
	Mage(std::string _name, Race _race);

	std::string attack() override;
	std::string get_class() override;
};

