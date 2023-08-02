#pragma once

class Location
{
private:
	uint8_t degrees;
	float minutes;
	char direction;
public:
	Location() = default; // I don't get it why is this needed?
	Location(uint8_t deg, float min, char dir);

};

