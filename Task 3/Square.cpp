#include "Square.h"


Square::Square(float _side_length) 
	: side_length(_side_length)
{ }

std::string Square::draw_shape()
{
	std::stringstream ss;

	ss 
		<< "\t**********************" << std::endl
		<< "\t   Square Calculator  " << std::endl
		<< "\t**********************" << std::endl
		<< std::endl << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * " << std::endl
		<< "\t* * * * * * * * * * * ";

	return ss.str();
}

float Square::calculate_area()
{
	return side_length * side_length;
}

float Square::calculate_perimeter()
{
	return 4.0f * side_length;
}
