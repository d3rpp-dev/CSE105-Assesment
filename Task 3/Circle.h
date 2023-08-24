#pragma once
#include "Shape.h"

class Circle : public Shape
{
private:

	float radius;

public:

	Circle(float _radius);

	virtual std::string draw_shape() override;

	virtual float calculate_area() override;
	virtual float calculate_perimeter() override;

};

