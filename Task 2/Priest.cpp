#include "Priest.h"

Priest::Priest(std::string _name, Race _race)
	: Player(_name, _race, 100, 200)
{}

std::string Priest::attack()
{
	return "I will assault you with holy wrath!";
}

std::string Priest::get_class()
{
	return "Priest";
}
