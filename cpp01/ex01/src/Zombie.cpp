#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(void) {
	std::cout << _name << " is... dead, this time for real" << std::endl;
}

void	Zombie::set_name(std::string name) {
	this->_name = name;
}

std::string	Zombie::get_name(void) const {
	return (this->_name);
}

void Zombie::announce(void)
{
	//std::cout << "("<< this << ") " << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
