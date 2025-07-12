#include "Weapon.hpp"
#include <iostream>

#define STD "\033[0m"
#define GREY "\033[1;30m"
Weapon::Weapon(std::string type): _type(type)
{
	std::cout << GREY << "W:  Weapon " << _type << " created (" << this << ")" << STD << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << GREY << "W:  Weapon " << _type << " destroyed (" << this << ")" << STD <<  std::endl;
}

std::string const &Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
