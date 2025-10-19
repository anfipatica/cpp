#include "../inc/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
	_name = "default";
	std::cout << "(DIAM) default Constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	_name = name;
	_hit_points = FragTrap::_base_hit_points;
	_energy_points = ScavTrap::_base_energy_points;
	_attack_damage = FragTrap::_base_attack_damage;

	std::cout << "(DIAM) Constructor called for DiamondTrap " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond): ClapTrap(diamond), FragTrap(), ScavTrap()
{
	std::cout << "(DIAM) copy Constructor called for " << _name << "\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	ClapTrap::operator=(diamond);
	return (*this);
};

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "(DIAM) Destructor called for " << _name << std::endl;
}

void	DiamondTrap::who_am_i(void) const
{
	std::cout << "______________I_AM_::  " << _name << "\n";
	std::cout << "_MY_GRANDFATHER_IS_::  " << ClapTrap::_name << "\n";
}