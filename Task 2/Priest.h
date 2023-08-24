#pragma once
#include "Player.h"
class Priest : public Player
{
public:
	Priest(std::string _name, Race _race);

	std::string attack() override;
	std::string get_class() override;
};

