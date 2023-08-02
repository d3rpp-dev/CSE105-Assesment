#include "Yacht.h"

static uint16_t CURRENT_YACHT_COUNT = 0;

Yacht::Yacht(Location loc)
{
	id = CURRENT_YACHT_COUNT++;
	location = loc;
}
