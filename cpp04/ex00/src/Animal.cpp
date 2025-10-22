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
}

Animal::~Animal(void)
{
	std::cout << "Copy Animal destructor called\n";
}

void Animal::make_sound(void) const
{
	std::cout <<  "*Generic animal sound*\n";
}

