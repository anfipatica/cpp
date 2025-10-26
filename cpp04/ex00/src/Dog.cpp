#include "Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal()
{
	_type = "Dog";
	std::cout << "Default Dog constructor called\n";
}

Dog::Dog(Dog &dog): Animal()
{
	std::cout << "Copy Dog constructor called\n";
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Copy Dog operator called\n";
	if (this != &dog)
		this->_type = dog._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
}

void Dog::make_sound(void) const
{
	std::cout << "U・ᴥ・U WOOF U・ᴥ・U\n";
}