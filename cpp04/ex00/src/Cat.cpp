#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal()
{
	_type = "Cat";
	std::cout << "Default Cat constructor called\n";
}

Cat::Cat(Cat &cat): Animal()
{
	std::cout << "Copy Cat constructor called\n";
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Copy Cat operator called\n";
	if (this != &cat)
		this->_type = cat._type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
}

void Cat::make_sound(void) const
{
	std::cout << "≽^•⩊•^≼ MIAU ≽^•⩊•^≼\n";
}