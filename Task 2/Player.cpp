#include "Player.h"
#include "Util.h"

Player::Player(std::string _name, Race _race, int16_t _hit_points, int16_t _magic_points) 
	: name(_name), race(_race), hit_points(_hit_points), magic_points(_magic_points)
{}

std::string Player::get_name()
{
	return name;
}

Race Player::get_race()
{
	return race;
}

std::string Player::what_race()
{
	return race_to_string(race);
}

int16_t Player::get_hit_points()
{
	return hit_points;
}

int16_t Player::get_magic_points()
{
	return magic_points;
}

void Player::set_name(std::string _name)
{
	name = _name;
}

void Player::set_race(Race _race)
{
	race = _race;
}

void Player::set_hit_points(int16_t _hit_points)
{
	hit_points = _hit_points;
}

void Player::set_magic_points(int16_t _magic_points)
{
	magic_points = _magic_points;
}
