#include "../inc/AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void): _type("animal")
{
	std::cout << "Default AAnimal constructor called\n";
}

AAnimal::AAnimal(AAnimal &animal)
{
	std::cout << "Copy AAnimal constructor called\n";
	*this = animal;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	std::cout << "Copy AAnimal operator called\n";
	if (this != &animal)
		this->_type = animal._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called\n";
}

std::string	AAnimal::get_type(void) const
{
	return (_type);
}

void AAnimal::make_sound(void) const
{
	std::cout <<  "*Generic animal sound*\n";
}
