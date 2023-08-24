#pragma once
#include "Shape.h"
class Triangle : public Shape
{
private:

	float side_1;
	float side_2;
	float side_3;

public:

	Triangle(float _side_1, float _side_2, float _side_3);

	virtual std::string draw_shape() override;

	virtual float calculate_area() override;
	virtual float calculate_perimeter() override;

};

