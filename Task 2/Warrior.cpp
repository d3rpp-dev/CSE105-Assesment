#include "Warrior.h"

Warrior::Warrior(std::string _name, Race _race):
	Player(_name, _race, 200, 0)
{ }

std::string Warrior::attack()
{
	return "I will destroy you with my sword!";
}

std::string Warrior::get_class()
{
	return "Warrior";
}
