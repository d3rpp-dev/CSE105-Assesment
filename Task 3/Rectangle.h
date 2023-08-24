#pragma once
#include "Shape.h"

class Rect : public Shape
{
private:

	float width;
	float height;

public:

	Rect(float _width, float _height);

	virtual std::string draw_shape() override;

	virtual float calculate_area() override;
	virtual float calculate_perimeter() override;

};

