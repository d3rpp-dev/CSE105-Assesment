#include <iostream>

#include <map>
#include <optional>

#include "../Utils/Utils.h"

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

void print_main_menu() {
	std::cout
		<< "*******************************" << std::endl
		<< "        Shape Calculator       " << std::endl
		<< "*******************************" << std::endl
		<< std::endl << std::endl
		<< "\t1. Square                    " << std::endl
		<< "\t2. Rectangle                 " << std::endl
		<< "\t3. Triangle                  " << std::endl
		<< "\t4. Circle                    " << std::endl
		<< std::endl
		<< "\t5. Exit                      " << std::endl 
		<< std::endl;
}

int main()
{
	bool should_quit = false;

	do {
		utils::clear_terminal();
		print_main_menu();

		// guaranteed to be 1, 2, 3, 4, or 5
		uint8_t choice = utils::parse_input<uint8_t>(
			"Enter Choice",
			"1-5 inclusive, or words",
			[](std::string _in) {
				utils::to_lower(_in);
				trim::trim(_in);

				std::map<std::string, uint8_t> map = {
					{ "1", 1 }, { "square",    1 },
					{ "2", 2 }, { "rectangle", 2 },
					{ "3", 3 }, { "triangle",  3 },
					{ "4", 4 }, { "circle",    4 },
					{ "5", 5 }, { "exit",      5 }
				};

				try {
					return std::make_optional<uint8_t>(map.at(_in));
				}
				catch (std::out_of_range) {
					return static_cast<std::optional<uint8_t>>(std::nullopt);
				}
			}
		);

		Shape* _shape = nullptr;

		switch (choice) {
		// Square
		case 1:
		{
			_shape = new Square(
				utils::get_number<float>("Enter length of one of the sides")
			);
		}
		break;

		// Rectangle
		case 2:
		{
			// There's a Rectangle type as a part of the Win32 API
			//
			// i hate windows man
			// at least in linux it's namespaced properly

			_shape = new Rect(
				utils::get_number<float>("Enter Width"), 
				utils::get_number<float>("Enter Height")
			);
		}
		break;

		// Triangle
		case 3:
		{
			// calls are in reverse order since arguments are added to the stack in a FiLo order, 
			// meaning to get the first one off, it needs to go on last
			//
			// hmm, computers :D
			_shape = new Triangle(
				utils::get_number<float>("Enter Side Length (3 of 3)"),
				utils::get_number<float>("Enter Side Length (2 of 3)"),
				utils::get_number<float>("Enter Side Length (1 of 3)")
			);
		}
		break;

		// Circle
		case 4:
		{
			_shape = new Circle(
				utils::get_number<float>("Enter Radius")
			);
		}
		break;

		case 5:
			should_quit = true;
			break;
		}

		if (_shape != nullptr) {
			utils::clear_terminal();

			std::cout << _shape->draw_shape();

			std::cout
				<< std::endl << std::endl
				<< "\t1. Calculate Perimeter / Circumference" << std::endl
				<< "\t2. Calculate Area                     " << std::endl
				<< "\t3. Exit / Done with Shape             " << std::endl
				<< std::endl;

			bool done_with_shape = false;

			do {

				uint8_t choice = utils::parse_input<uint8_t>(
					"Enter Choice",
					"1-3 inclusive, or words",
					[](std::string _in) {
						utils::to_lower(_in);
						trim::trim(_in);

						std::map<std::string, uint8_t> map = {
							{ "1", 1 }, { "perimeter", 1 },
							{ "2", 2 }, { "area",      2 },
							{ "3", 3 }, { "exit",      3 },
						};

						try {
							return std::make_optional<uint8_t>(map.at(_in));
						}
						catch (std::out_of_range) {
							return static_cast<std::optional<uint8_t>>(std::nullopt);
						}
					}
				);

				switch (choice) {
				case 1:
					std::cout << "Perimeter / Circumference: " << _shape->calculate_perimeter() << "units";
					break;
				case 2:
					std::cout << "Area: " << _shape->calculate_area() << "units^2";
					break;
				case 3:
					done_with_shape = true;
					break;
				}

				std::cout << std::endl << std::endl;

			} while (!done_with_shape);
		}

	} while (!should_quit);
}
