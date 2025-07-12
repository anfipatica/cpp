#include "HumanB.hpp"
#include <iostream>

#define STD "\033[0m"
#define GREY "\033[1;30m"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << GREY << "HB: " << _name << " (" << this <<
		") was born without a weapon :(" << STD << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << GREY << "HB: " << _name << " died" << STD << std::endl;
}


void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << GREY << "HB: " << _name << "(" << this << ") is now holding a " << _weapon->getType()
		 << " (" << _weapon << ")." << STD << std::endl;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << _name << "has no weapon to attack with :(" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}