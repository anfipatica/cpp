#include "Animal.hpp"
#include <iostream>

Animal::Animal(void): _type("animal")
{
	std::cout << "Default Animal constructor called\n";
}

Animal::Animal(Animal &animal)
{
	std::cout << "Copy Animal constructor called\n";
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Copy Animal operator called\n";
	if (this != &animal)
		this->_type = animal._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

std::string	Animal::get_type(void) const
{
	return (_type);
}

void Animal::make_sound(void) const
{
	std::cout <<  "*Generic animal sound*\n";
}
