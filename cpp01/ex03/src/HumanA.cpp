#include "HumanA.hpp"
#include <iostream>

#define STD "\033[0m"
#define GREY "\033[1;30m"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << GREY << "HA: " << _name << "(" << this << ") was born holding a " << _weapon.getType()
		 << " (" << &_weapon << ")." << STD << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << GREY << "HA: " << _name << " died" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
