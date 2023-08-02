#pragma once
#include <cstdint>
#include "Location.h"

class Yacht
{
private:
	uint16_t id;
	Location location;
public:
	Yacht() = default; 	// I don't get it why is this needed?
	Yacht(Location location);

};

