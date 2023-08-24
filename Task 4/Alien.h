#pragma once
#include <cstdint>
#include <sstream>
#include <string>

#include "../Utils/Utils.h"

class Alien
{
private:
	std::string name;
	uint16_t weight;
	uint16_t height;
	char gender;

public:
	Alien() = default;

	Alien(uint16_t _weight, uint16_t _height, char _gender);

	std::string get_name();
	uint16_t get_weight();
	uint16_t get_height();
	char get_gender();
	uint16_t get_prestige();

	bool operator==(Alien &rhs);
	bool operator!=(Alien &rhs);
	bool operator>(Alien &rhs);
	bool operator>=(Alien &rhs);
	bool operator<(Alien &rhs);
	bool operator<=(Alien &rhs);

	// alien breeding
	Alien operator+(Alien &other);
};

