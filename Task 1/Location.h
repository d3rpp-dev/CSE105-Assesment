#pragma once
#include <tuple>

enum Direction {
	North = 0,
	South,
	East, 
	West,
	Nil = 255
};

// degrees, minutes, direction
#define Coordinate std::tuple<uint8_t, float, Direction>

class Location
{
private:
	Coordinate lon;
	Coordinate lat;
public:
	Location() = default; // I don't get it why is this needed?
	Location(Coordinate longtitude, Coordinate latitude);

	void get_pos();
	void display() const;

private:
	static Direction parse_direction(char from);
};

