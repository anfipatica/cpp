#include "../inc/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap("default_scavtrap", 100, 50, 20)
{
	std::cout << "(SCAV) default Constructor called for " << _name << "\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "(SCAV) Constructor called for " << _name << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap)
{
	std::cout << "(SCAV) copy Constructor called for " << _name << "\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	ClapTrap::operator=(scavtrap);
	return (*this);
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "(SCAV) Destructor called for " << _name << std::endl;
}

void	ScavTrap::guard_gate(void)
{
	std::cout << "(SCAV) ";
	if (_hit_points <= 0)
		std::cout << "Scavtrap " << _name << " is dead :(\n";
	else if (_energy_points == 0)
		std::cout << "Scavtrap" << _name << " has no energy to guard the gate!\n";
	else
	{
		std::cout << "Scavtrap " << this->_name << " is now in gate keeper mode!\n";
		--_energy_points;
	}
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "(SCAV) ";
	if (_hit_points <= 0)
		std::cout << "Scavtrap " << _name << " is dead :(\n";
	else if (_energy_points == 0)
		std::cout << "Scavtrap " << _name << " has no energy left to attack!\n";
	else
	{
		std::cout << "Scavtrap " << _name << " attacks " << target << ", causing "
			<< _attack_damage << " points of damage!\n";
		--_energy_points;
	}
}

void	ScavTrap::attack(ClapTrap &target)
{
	if (this == &target)
		std::cout << "A ScavTrap is trying to hurt itself! luckily, that can't happen\n";
	else
	{
		attack(target.get_name());
		if (_hit_points > 0 && _energy_points > 0)
			target.take_damage(_attack_damage);
	}
}