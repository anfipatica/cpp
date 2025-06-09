#include <iostream>
#include "class.hpp"

ClassSample::ClassSample(void)
{
	std::cout << "Constructor called" << std::endl;
	this->foo = 42;
}

ClassSample::~ClassSample(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClassSample::bar(void) const
{
	std::cout << this->foo << std::endl;
}