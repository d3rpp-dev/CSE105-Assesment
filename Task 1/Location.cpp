#include "Location.h"
#include <cstdint>

Location::Location(uint8_t deg, float min, char dir)
{
	degrees = deg;
	minutes = min;
	direction = dir;
}
