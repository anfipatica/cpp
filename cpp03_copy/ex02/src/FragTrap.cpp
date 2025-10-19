#include "../inc/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): ClapTrap("default_fragtrap", 100, 100, 30)
{
	std::cout << "(FRAG) default Constructor called for " << _name << "\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "(FRAG) Constructor called for " << _name << "\n";
}

FragTrap::FragTrap(const FragTrap &scavtrap): ClapTrap(scavtrap)
{
	std::cout << "(FRAG) copy Constructor called for " << _name << "\n";
}

FragTrap &FragTrap::operator=(const FragTrap &scavtrap)
{
	ClapTrap::operator=(scavtrap);
	return (*this);
};

FragTrap::~FragTrap(void)
{
	std::cout << "(FRAG) Destructor called for " << _name << std::endl;
}

void	FragTrap::high_fives_guys(void)
{
	std::cout << "(FRAG) ";
	if (_hit_points <= 0)
		std::cout << "FragTrap " << _name << " is a bit too dead for high fives :(\n";
	else if (_energy_points == 0)
		std::cout << "FragTrap " << _name << " has no energy to rise its hand!\n";
	else
	{
		std::cout << "[ HIGH FIVES GUYS ]\n";
		--_energy_points;
	}
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << "(FRAG) ";
	if (_hit_points <= 0)
		std::cout << "FragTrap " << _name << " is dead :(\n";
	else if (_energy_points == 0)
		std::cout << "FragTrap " << _name << " has no energy left to attack!\n";
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
			<< _attack_damage << " points of damage!\n";
		--_energy_points;
	}
}

void	FragTrap::attack(ClapTrap &target)
{
	if (this == &target)
		std::cout << "A FragTrap is trying to hurt itself! luckily, that can't happen\n";
	else
	{
		attack(target.get_name());
		if (_hit_points > 0 && _energy_points > 0)
			target.take_damage(_attack_damage);
	}
}
