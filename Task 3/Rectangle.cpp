#include "Rectangle.h"

Rect::Rect(float _width, float _height)
	: width(_width), height(_height)
{ }

std::string Rect::draw_shape()
{
	std::stringstream ss;

	ss
		<< "\t**********************" << std::endl
		<< "\t Rectangle Calculator " << std::endl
		<< "\t**********************" << std::endl
		<< std::endl << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * ";

	return ss.str();
}

float Rect::calculate_area()
{
	return width * height;
}

float Rect::calculate_perimeter()
{
	return ( 2 * width ) + ( 2 * height );
}
