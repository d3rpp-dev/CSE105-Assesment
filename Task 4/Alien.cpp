#include "Alien.h"

Alien::Alien(uint16_t _weight, uint16_t _height, char _gender) : weight(_weight), height(_height), gender(_gender)
{
    static uint16_t ALIEN_NAME_COUNT = 1;

    std::stringstream ss;

    ss << "Alien " << ALIEN_NAME_COUNT++;

    name = ss.str();
}

std::string Alien::get_name()
{
    return name;
}

uint16_t Alien::get_weight()
{
    return weight;
}

uint16_t Alien::get_height()
{
    return height;
}

char Alien::get_gender()
{
    return gender;
}

uint16_t Alien::get_prestige()
{
    int gender_mul;

    if (gender == 'm')
        gender_mul = 2;
    else
        gender_mul = 3;

    return height * weight * gender_mul;
}

bool Alien::operator==(Alien& rhs)
{
    return this->get_prestige() == rhs.get_prestige();
}

bool Alien::operator!=(Alien& rhs)
{
    return this->get_prestige() != rhs.get_prestige();
}

bool Alien::operator>(Alien& rhs)
{
    return this->get_prestige() > rhs.get_prestige();
}

bool Alien::operator>=(Alien& rhs)
{
    return this->get_prestige() >= rhs.get_prestige();
}

bool Alien::operator<(Alien& rhs)
{
    return this->get_prestige() < rhs.get_prestige();
}

bool Alien::operator<=(Alien& rhs)
{
    return this->get_prestige() <= rhs.get_prestige();
}

Alien Alien::operator+(Alien& other)
{
    return Alien(
        (this->get_weight() + other.get_weight()) / 2,
        (this->get_height() + other.get_height()) / 2,
        utils::gen_random_int(0, 1) == 0 ? 'm' : 'f'
    );
}
