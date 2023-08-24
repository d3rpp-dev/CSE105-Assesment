#pragma once
#include <cstdint>
#include "Location.h"

class Yacht
{
private:
	uint16_t id;
	Location location;
public:
	Yacht(); 	// I don't get it why is this needed?
	Yacht(Location location);
	Yacht(const uint16_t& id, const Location& location);

	uint16_t get_id() const {
		return id;
	}
	void get_pos();
	void display() const;
};

