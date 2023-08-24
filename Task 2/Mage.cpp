#include "Mage.h"

Mage::Mage(std::string _name, Race _race)
	: Player(_name, _race, 200, 0)
{}

std::string Mage::attack()
{
	return "I will crush you with my arcane missiles!";
}

std::string Mage::get_class()
{
	return "Mage";
}

