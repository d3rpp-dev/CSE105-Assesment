#include "Location.h"
#include <cstdint>

#include "../Utils/Utils.h"

bool direction_is_longtitude(Direction& dir) {
	switch (dir) {
	case Direction::North:
	case Direction::South:
		return true;
	}
	return false;
}

bool direction_is_latitude(Direction& dir) {
	switch (dir) {
	case Direction::East:
	case Direction::West:
		return true;
	}
	return false;
}

bool directions_are_same_axis(Direction& lhs, Direction& rhs) {
	if (direction_is_latitude(lhs) && direction_is_latitude(rhs)) return true;
	if (direction_is_longtitude(lhs) && direction_is_longtitude(rhs)) return true;
	return false;
}

char direction_to_char(Direction& dir) {
	switch (dir) {
	case Direction::North:
		return 'N';
	case Direction::South:
		return 'S';
	case Direction::East:
		return 'E';
	case Direction::West:
		return 'W';
	default:
		return '\x00';
	}
}

Location::Location(Coordinate lon, Coordinate lat)
{
	lon = lon;
	lat = lat;
}

void Location::get_pos()
{
	uint8_t first_deg;

	// for(;;) -> infinite loop with exit condition
	for (;;) {
		first_deg = utils::get_number<uint8_t>("Enter Degrees (0-180 inc.)");
		if (first_deg >= 0 && first_deg <= 180) break;
		else std::cout << "Invalid Input: must be between 0 and 180 (inclusive)" << std::endl;
	}

	float first_min;

	for (;;) {
		first_min = utils::get_number<float>("Enter Minutes (0-60 inc.)");
		if (first_min >= 0.0f && first_min <= 60.0f) break;
		else std::cout << "Invalid Input: must be between 0 and 60 (inclusive)" << std::endl;
	}

	Direction first_dir;

	for (;;) {
		first_dir = parse_direction(utils::get_char("Enter Direction (N, S, E, W)"));
		if (first_dir != Direction::Nil) break;
		else std::cout << "Invalid Input: must be a compass direction" << std::endl;
	}

	Coordinate first_loc = std::make_tuple(first_deg, first_min, first_dir);

	uint8_t second_deg;

	// for(;;) -> infinite loop with exit condition
	for (;;) {
		second_deg = utils::get_number<uint8_t>("Enter Degrees (0-180 inc.)");
		if (second_deg >= 0 && second_deg <= 180) break;
		else std::cout << "Invalid Input: must be between 0 and 180 (inclusive)" << std::endl;
	}

	float second_min;

	for (;;) {
		second_min = utils::get_number<float>("Enter Minutes (0-60 inc.)");
		if (second_min >= 0.0f && second_min <= 60.0f) break;
		else std::cout << "Invalid Input: must be between 0 and 60 (inclusive)" << std::endl;
	}

	Direction second_dir;

	for (;;) {
		second_dir = parse_direction(utils::get_char("Enter Direction (N, S, E, W)"));
		// i hate how you can do this
		if (second_dir != Direction::Nil)
			if (!directions_are_same_axis(first_dir, second_dir)) break;
			else std::cout 
				<< "Invalid Input: " 
				<< direction_to_char(first_dir) 
				<< " is on the same axis as " 
				<< direction_to_char(second_dir) 
				<< std::endl;
		else std::cout << "Invalid Input: must be a compass direction" << std::endl;
	}

	Coordinate second_loc = std::make_tuple(second_deg, second_min, second_dir);

	lat = first_loc;
	lon = second_loc;

	// assign then swap if needed
	if (direction_is_longtitude(first_dir))
		std::swap(lat, lon);
}

void Location::display() const
{
	// c++ tuples are weird
	// in rust you can just use tuple.0, instead of std::get<0>(tuple), weird.
	std::cout
		<< "Position: "
		<< std::get<0>(lat) << "°" << std::setprecision(2) << std::fixed << std::get<1>(lat) << " " << std::get<2>(lat) << " Latitude "
		<< std::get<0>(lon) << "°" << std::setprecision(2) << std::fixed << std::get<1>(lon) << " " << std::get<2>(lon) << " Longitude "
		<< std::endl;
}

Direction Location::parse_direction(char from)
{
	utils::to_lower(from);

	switch (from) {
	case 'n':
		return Direction::North;
	case 's':
		return Direction::South;
	case 'e':
		return Direction::East;
	case 'w':
		return Direction::West;
	default:
		return Direction::Nil;
	}
}
