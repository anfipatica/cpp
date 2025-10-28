#include "Character.hpp"
#include <iostream>

#include <cstdlib>

Character::Character(void): _name("no_name")
{
	for (int i = 0; i < N_ITEMS; ++i)
		_items[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < N_ITEMS; ++i)
		_items[i] = NULL;
}

Character::Character(const Character &character)
{
	(void)character;
}

Character	&Character::operator=(const Character &character)
{
	(void)character;
	return (*this);
}

Character::~Character(void)
{ }

void Character::equip(AMateria *m)
{
	if (m->get_equipable() == false)
	{
		std::cout << _name << ": this object (" << m << ")is already in use\n";
		return ;
	}
	for (int i = 0; i < N_ITEMS; ++i)
	{
		if (_items[i] == NULL)
		{
			_items[i] = m;
			std::cout << _name << ": succesfully equiped " << m->get_type() << " (" << m << ").\n";
			return ;
		}
	}
	std::cout << _name << ": No empty space left in inventory.\n";
}

void	Character::unequip(int idx)
{
	if (idx >= N_ITEMS || _items[idx] == NULL)
		std::cout << _name << ": Invalid index. There is no item in slot" << idx << ".\n";
	else
	{
		_items[idx];
		_items[idx]->set_equipable(true);
		_items[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= N_ITEMS || _items[idx] == NULL)
		std::cout << _name << ": Invalid index. There is no item in slot" << idx << ".\n";
	else
	{
		_items[idx]->use(target);
	}
}

const std::string	&Character::get_name(void) const
{
	return (_name);
}
