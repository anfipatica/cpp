#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "Default WrongCat constructor called\n";
}

WrongCat::WrongCat(WrongCat &wrong_cat): WrongAnimal()
{
	std::cout << "Copy WrongCat constructor called\n";
	*this = wrong_cat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrong_cat)
{
	std::cout << "Copy WrongCat operator called\n";
	if (this != &wrong_cat)
		this->_type = wrong_cat._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::make_sound(void) const
{
	std::cout << "≽^•⩊•^≼ MIAU ≽^•⩊•^≼\n";
}