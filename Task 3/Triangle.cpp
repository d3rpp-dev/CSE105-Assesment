#include "Triangle.h"

Triangle::Triangle(float _side_1, float _side_2, float _side_3)
	: side_1(_side_1), side_2(_side_2), side_3(_side_3)
{ }

std::string Triangle::draw_shape()
{
	std::stringstream ss;

	ss
		<< "            *            " << std::endl
		<< "          * * *          " << std::endl
		<< "        * * * * *        " << std::endl
		<< "      * * * * * * *      " << std::endl
		<< "    * * * * * * * * *    " << std::endl
		<< "  * * * * * * * * * * *  " << std::endl
		<< "* * * * * * * * * * * * *";

	return ss.str();
}

// NOTE: uses heron's formula for calculating the area of the triangle from 3 sides (SSS)
// supports all kinds of triangles since it uses a SSS triangle
float Triangle::calculate_area()
{
	float semi = 0.5f * (side_1 + side_2 + side_3);
	return sqrt(semi * (semi - side_1) * (semi - side_2) * (semi - side_3));
}

float Triangle::calculate_perimeter()
{
	return side_1 + side_2 + side_3;
}
