#include "Yacht.h"
#include <iostream>

static uint16_t CURRENT_YACHT_COUNT = 1;

Yacht::Yacht()
{
	id = CURRENT_YACHT_COUNT++;
	location = Location();
}

Yacht::Yacht(Location loc)
	:location(loc)
{
	id = CURRENT_YACHT_COUNT++;
}

void Yacht::get_pos()
{
	location.get_pos();
}

void Yacht::display() const
{
	std::cout
		<< std::endl
		<< "Serial Number: "
		<< id
		<< std::endl;
	location.display();
}

Yacht::Yacht(const uint16_t& id, const Location& loc)
	: id(id), location(loc)
{}
