#pragma once

#include <string>
#include <sstream>

#define _USE_MATH_DEFINES
#include <math.h>

class Shape
{
private:

	// ...

public:

	virtual std::string draw_shape() = 0;

	virtual float calculate_area() = 0;
	virtual float calculate_perimeter() = 0;

};

