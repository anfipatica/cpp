#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
	std::cout << _name << " is... dead, this time for real" << std::endl;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie zombie;

	zombie._name = name;
	return (&zombie);
}

void	Zombie::randomChump(std::string name)
{
	Zombie zombie;

	zombie._name = name;
	announce();
}

void	Zombie::set_name(std::string name) {
	this->_name = name;
}

std::string	Zombie::get_name(void) const {
	return (this->_name);
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}
