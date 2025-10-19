#include "../inc/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void):
	_name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "(CLAP) default constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string name):
	_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "(CLAP) Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	*this = clap;
	std::cout << "(CLAP) copy Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	if (this != &clap)
	{
		this->_name = clap._name;
		this->_hit_points = clap._hit_points;
		this->_energy_points = clap._energy_points;
		this->_attack_damage = clap._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "(CLAP) Destructor called for ClapTrap " << _name << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "(CLAP) ";
	if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is dead :(\n";
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy left to attack!\n";
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< _attack_damage << " points of damage!\n";
		--_energy_points;
	}
}

void	ClapTrap::attack(ClapTrap &target)
{
	if (this == &target)
		std::cout << "(CLAP) A ClapTrap is trying to hurt itself! luckily, that can't happen\n";
	else
	{
		attack(target.get_name());
		if (_hit_points > 0 && _energy_points > 0)
			target.take_damage(_attack_damage);
	}
}

void	ClapTrap::take_damage(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << _name << " is already dead :(\n";
	else
	{
		_hit_points -= amount;
		std::cout << _name << " received " << amount
			<< " points of damage! (hit points: " << _hit_points << ")\n";
		if (_hit_points <= 0)
			std::cout << _name << " died!\n";
	}
}

void	ClapTrap::be_repaired(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << _name << " is dead :(\n";
	else if (_energy_points == 0)
		std::cout <<  _name << " has no energy left to repair itself!\n";
	else
	{
		_hit_points += amount;
		std::cout <<  _name << " repairs itself " << amount
			<< " points. (hit points: " << _hit_points << ")\n";
		--_energy_points;
	}
}


std::string	ClapTrap::get_name(void) const
{
	return (_name);
}

int			ClapTrap::get_hit_points(void) const
{
	return (_hit_points);
}

int			ClapTrap::get_energy_points(void) const
{
	return (_energy_points);
}

int			ClapTrap::get_attack_damage(void) const
{
	return (_attack_damage);
}

void		ClapTrap::info(void) const
{
	std::cout << " >> " << _name << ";\n";
	std::cout << " ::    hit_points :: " << _hit_points << "\n";
	std::cout << " :: energy_points :: " << _energy_points << "\n";
	std::cout << " :: attack_damage :: " << _attack_damage << "\n\n";
}
