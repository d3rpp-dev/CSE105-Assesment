#include "../Utils/Utils.h"

#include <iostream>
#include <vector>
#include <map>
#include <optional>

#include "Mage.h"
#include "Priest.h"
#include "Warrior.h"

std::string player_to_string(Player* player) {
	std::stringstream ss;

	ss
		<< "I am a "
		<< player->get_class()
		<< " named "
		<< player->get_name()
		<< ", my race is "
		<< player->what_race()
		<< ", and my attack is \""
		<< player->attack()
		<< "\".";

	return ss.str();
}

int main()
{
	std::vector<Mage> mages{};
	std::vector<Priest> priests{};
	std::vector<Warrior> warriors{};

	bool creation_complete = false;

	std::cout << GREEN << "Character Creation" << RESET << std::endl << std::endl;

	do {
		PlayerClass* player_class = nullptr;

		PlayerClass _class =
			utils::parse_input<PlayerClass>(
				"What class would you like your character to be?",
				"1: Warrior, 2: Priest, or 3: Mage",
				[](std::string _inp) {
					utils::to_lower(_inp);
					trim::trim(_inp);

					static const std::map<std::string, PlayerClass> map{
						{ "warrior", PlayerClass::ClassWarrior }, { "1", PlayerClass::ClassWarrior }, { "w", PlayerClass::ClassWarrior },
						{ "priest",  PlayerClass::ClassPriest  }, { "2", PlayerClass::ClassPriest  }, { "p", PlayerClass::ClassPriest  },
						{ "mage",    PlayerClass::ClassMage    }, { "3", PlayerClass::ClassMage    }, { "m", PlayerClass::ClassMage    },
					};

					try {
						return std::make_optional<PlayerClass>(map.at(_inp));
					}
					catch (std::out_of_range _e) {
						return static_cast<std::optional<PlayerClass>>(std::nullopt);
					}
				}
		);

		Race _race =
			utils::parse_input<Race>(
				"What Race would you like your character to be?",
				"1: Human, 2: Elf, 3: Dwarf, 4: Orc, 5: Troll",
				[](std::string _inp) {
					utils::to_lower(_inp);
					trim::trim(_inp);

					static const std::map<std::string, Race> map{
						{ "human", Race::Human }, { "1", Race::Human }, { "h", Race::Human },
						{ "elf",   Race::Elf   }, { "2", Race::Elf   }, { "e", Race::Elf   },
						{ "dwarf", Race::Dwarf }, { "3", Race::Dwarf }, { "d", Race::Dwarf },
						{ "orc",   Race::Orc   }, { "4", Race::Orc   }, { "o", Race::Orc   },
						{ "troll", Race::Troll }, { "5", Race::Troll }, { "t", Race::Troll },
					};

					try {
						return std::make_optional<Race>(map.at(_inp));
					}
					catch (std::out_of_range _e) {
						return static_cast<std::optional<Race>>(std::nullopt);
					}
				}
		);

		std::string _name = utils::get_line("What would you like to name your character?", false);

		// switch statements broke
		if (_class == PlayerClass::ClassWarrior) {
			Warrior w = Warrior(_name, _race);
			warriors.push_back(w);
		}
		else if (_class == PlayerClass::ClassPriest) {
			Priest p = Priest(_name, _race);
			priests.push_back(p);
		}
		else {
			Mage m = Mage(_name, _race);
			mages.push_back(m);
		}

		char done_answer = utils::get_char("Would you like to make another character? [y/N]");
		utils::to_lower(done_answer);

		if (done_answer != 'y') creation_complete = true;

	} while (!creation_complete);

	std::cout << std::endl
		<< GREEN << "=========================" << RESET << std::endl
		<< RESET << "        Warriors         " << RESET << std::endl
		<< GREEN << "=========================" << RESET << std::endl;

	for (auto& w : warriors) {
		std::cout << player_to_string(&w) << std::endl;
	}

	std::cout << std::endl
		<< GREEN << "=========================" << RESET << std::endl
		<< RESET << "         Priests         " << RESET << std::endl
		<< GREEN << "=========================" << RESET << std::endl;

	for (auto& p : priests) {
		std::cout << player_to_string(&p) << std::endl;
	}

	std::cout << std::endl
		<< GREEN << "=========================" << RESET << std::endl
		<< RESET << "          Mages          " << RESET << std::endl
		<< GREEN << "=========================" << RESET << std::endl;

	for (auto& m : mages) {
		std::cout << player_to_string(&m) << std::endl;
	}

	std::cout 
		<< std::endl << GREEN 
		<< "Character Creation Complete!"  
		<< RESET << std::endl;
}
