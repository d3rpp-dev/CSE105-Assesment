#pragma once

#include "Race.h"
#include <string>

/*
	Note: this class is virtual
*/
class Player
{
private:
	std::string name;
	Race race;
	int16_t hit_points;
	int16_t magic_points;
public:
	Player(std::string _name, Race _race, int16_t _hit_points, int16_t _magic_points);

	// getters
	std::string get_name();
	Race get_race();
	std::string what_race();
	int16_t get_hit_points();
	int16_t get_magic_points();

	// setters
	void set_name(std::string _name);
	void set_race(Race _race);
	void set_hit_points(int16_t _hit_points);
	void set_magic_points(int16_t _magic_points);

	// other
	virtual std::string attack() = 0;
	virtual std::string get_class() = 0;
};

