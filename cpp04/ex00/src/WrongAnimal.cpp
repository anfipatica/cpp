#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): _type("wrong_animal")
{
	std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &wrong_animal)
{
	std::cout << "Copy WrongAnimal constructor called\n";
	*this = wrong_animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
	std::cout << "Copy WrongAnimal operator called\n";
	if (this != &wrong_animal)
		this->_type = wrong_animal._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
}

std::string	WrongAnimal::get_type(void) const
{
	return (_type);
}

void WrongAnimal::make_sound(void) const
{
	std::cout <<  "*Generic wrong_animal sound*\n";
}
