#include "Circle.h"

Circle::Circle(float _radius)
	: radius(_radius)
{ }

std::string Circle::draw_shape()
{
	std::stringstream ss;

	ss
		<< "\t ***************************** " << std::endl
		<< "\t        Circle Calculator      " << std::endl
		<< "\t ***************************** " << std::endl
		<< std::endl << std::endl
		<< "\t         , - ~ ~ ~ - ,         " << std::endl
		<< "\t     , '               ' ,     " << std::endl
		<< "\t   ,                       ,   " << std::endl
		<< "\t  ,                         ,  " << std::endl
		<< "\t ,                           , " << std::endl
		<< "\t ,                           , " << std::endl
		<< "\t ,                           , " << std::endl
		<< "\t  ,                         ,  " << std::endl
		<< "\t   ,                       ,   " << std::endl
		<< "\t     ,                  , '    " << std::endl
		<< "\t       ' - , _ _ _ ,  '        ";

	return ss.str();
}

// PI * r^2
float Circle::calculate_area()
{
	return M_PI * radius * radius;
}

// 2 * PI * r
float Circle::calculate_perimeter()
{
	return 2 * M_PI * radius;
}
