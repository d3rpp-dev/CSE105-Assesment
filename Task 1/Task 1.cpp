#include <iostream>
#include "Yacht.h"

int main()
{
	Yacht* yachts[3]{};

	for (uint8_t i = 0; i < 3; i++) {
		yachts[i] = new Yacht();
		std::cout << "Getting Position of yacht #" << yachts[i]->get_id() << std::endl;
		yachts[i]->get_pos();
		std::cout << std::endl;
	}

	for (Yacht* yacht : yachts) {
		yacht->display();
	}
}
