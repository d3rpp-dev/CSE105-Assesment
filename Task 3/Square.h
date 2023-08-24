#pragma once
#include "Shape.h"

class Square : public Shape
{
private:

	float side_length;

public:

	Square(float _side_length);

	virtual std::string draw_shape() override;

	virtual float calculate_area() override;
	virtual float calculate_perimeter() override;

};

