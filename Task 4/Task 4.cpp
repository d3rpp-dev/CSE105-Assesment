#include <iostream>
#include <optional>
#include <vector>
#include <map>

#include "../Utils/Utils.h"
#include "Alien.h"

int main()
{
    bool should_quit = false;

    std::vector<std::tuple<Alien, Alien>> parents{};
    std::vector<Alien> offspring{};

    do {
        utils::clear_terminal();

        std::cout
            << "**********************" << std::endl
            << "  Alien Breeder 2023  " << std::endl
            << "**********************" << std::endl
            << std::endl
            << "\tParent Count: "<< parents.size() * 2 << std::endl // they are in pairs so this makes sense
            << "\tOffspring Count: " << offspring.size() << std::endl
            << std::endl
            << "\t1. Create Alien Pairs" << std::endl
            << "\t2. Create Alien Offspring" << std::endl
            << "\t3. Compare Offspring Prestige" << std::endl
            << "\t4. Exit" << std::endl
            << std::endl;

        uint8_t choice = utils::parse_input<uint8_t>(
            "Please Enter your Choice",
            "1, 2, 3, 4, exit",
            [](std::string _in) {
                trim::trim(_in);
                utils::to_lower(_in);

                static std::map<std::string, uint8_t> map{
                    {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"exit", 4}
                };

                try {
                    return std::make_optional<uint8_t>(map.at(_in));
                }
                catch (std::out_of_range _e) {
                    return static_cast<std::optional<uint8_t>>(std::nullopt);
                }
            }
        );

        utils::clear_terminal();

        switch (choice) {
        case 1:
            // create parent pair
        {
            Alien a[2]{};

            for (uint8_t i = 0; i < 2; i++) {
                std::cout << "Creating Alien" << std::endl << std::endl;

                a[i] = Alien(
                    utils::get_number<uint16_t>("Alien Weight"),
                    utils::get_number<uint16_t>("Alien Height"),
                    utils::parse_input<char>(
                        "Alien Gender",
                        "m or f",
                        [](std::string _in) {
                            trim::trim(_in);
                            utils::to_lower(_in);

                            char a = _in[0];

                            switch (a) {
                            case 'm':
                            case 'f':
                                return std::make_optional<char>(a);
                            default:
                                return static_cast<std::optional<char>>(std::nullopt);
                            }
                        }
                    )
                );

                std::cout
                    << std::endl << "Created " << a[i].get_name()
                    << std::endl << std::endl;
            }

            parents.push_back(std::tuple<Alien, Alien>(a[0], a[1]));

            utils::get_line("Press any key to Continue");
        }
            break;
        case 2:
            // breed

            if (parents.size() < 1) {
                std::cout << RED << "Please Create some Alien Pairs First" << RESET << std::endl << std::endl;
            }
            else {

                for (auto& i : parents) {
                    Alien a = std::get<0>(i) + std::get<1>(i);

                    std::cout << "Created " << a.get_name() << " With Parents " << std::get<0>(i).get_name() << " & " << std::get<1>(i).get_name() << std::endl;

                    offspring.push_back(a);
                }

                std::cout << std::endl;
            }

            utils::get_line("Press any key to Continue");

            break;
        case 3:

            if (offspring.size() < 2) {
                std::cout << RED << "Please Create Offspring First!" << RESET << std::endl << std::endl;
            }
            else {
                // compare offspring
                uint16_t cnt = 1;

                for (auto& i : offspring) {
                    for (uint16_t j = cnt; j < offspring.size(); j++) {
                        Alien& lhs = i;
                        Alien& rhs = offspring[j];

                        std::cout << std::endl
                            << "Comparing " << lhs.get_name() << " & " << rhs.get_name() << std::endl
                            << std::endl
                            << "\t " << lhs.get_name() << " == " << rhs.get_name() << " ? " << (lhs == rhs ? "true" : "false") << std::endl
                            << "\t " << lhs.get_name() << " != " << rhs.get_name() << " ? " << (lhs != rhs ? "true" : "false") << std::endl
                            << "\t " << lhs.get_name() << " <  " << rhs.get_name() << " ? " << (lhs > rhs ? "true" : "false") << std::endl
                            << "\t " << lhs.get_name() << " <= " << rhs.get_name() << " ? " << (lhs <= rhs ? "true" : "false") << std::endl
                            << "\t " << lhs.get_name() << " >  " << rhs.get_name() << " ? " << (lhs > rhs ? "true" : "false") << std::endl
                            << "\t " << lhs.get_name() << " >= " << rhs.get_name() << " ? " << (lhs >= rhs ? "true" : "false") << std::endl
                            << std::endl;
                    }

                    cnt++;
                }

            }
            std::cout << std::endl;
            utils::get_line("Press any key to Continue");

            break;
        case 4:
            // exit
            should_quit = true;
            break;
        }
    } while (!should_quit);
}
