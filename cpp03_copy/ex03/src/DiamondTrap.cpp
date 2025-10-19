#include "../inc/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
	std::cout << "(DIAM) default Constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name)
{
	DiamondTrap::_name = name;

	std::cout << "________" << this->_hit_points << "\n";
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_base_attack_damage;
	std::cout << "(DIAM) Constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond):  ClapTrap(diamond._name + "_clap_name"), ScavTrap(), FragTrap()
{
	*this = diamond;
	std::cout << "(DIAM) copy Constructor called for " << _name << "\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	ScavTrap::operator=(diamond);
	_name = diamond._name;
	return (*this);
};

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "(DIAM) Destructor called for " << _name << std::endl;
}

void	DiamondTrap::who_am_i(void) const
{
	std::cout << "\n _Who_am_i_and_where_do_i_come_from_\n";
	std::cout << "|            my_name: " << this->_name << "            |\n";
	std::cout << "|  my_ancestors_name: " << this->ClapTrap::_name << "  |\n";
	std::cout << " ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯\n";
}

std::ostream &operator<<(std::ostream &os, const DiamondTrap &diam)
{
	os << " __DIAMONDTRAP__ -> " << diam.get_name() << "\n";
	os << "	:: HIT_POINTS :: " << diam.get_hit_points() << "\n";
	os << "	:: ENERGY_POINTS :: " << diam.get_energy_points()<< "\n";
	os << "	:: ATTACK_DAMAGE :: " << diam.get_attack_damage()<< "\n";
	return (os);
}