#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Default Cat constructor called\n";
}

Cat::Cat(Cat &cat)
{
	std::cout << "Copy Cat constructor called\n";
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Copy Cat operator called\n";
	if (this != &cat)
		this->_type = cat._type;
}

Cat::~Cat(void)
{
	std::cout << "Copy Cat destructor called\n";
}

void Cat::make_sound(void) const
{
	std::cout <<  "MIAU\n";
}