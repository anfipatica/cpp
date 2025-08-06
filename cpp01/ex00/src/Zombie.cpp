#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): _name(name)
{
//	std::cout << "("<< this << ") " <<_name << " is ALIVE!!" << std::endl;
}

Zombie::~Zombie(void) {
//	std::cout << "("<< this << ") " << _name << " is... dead, this time for real" << std::endl;
	std::cout << _name << " is... dead, this time for real" << std::endl;
}

void Zombie::announce(void)
{
//	std::cout << "("<< this << ") " << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
