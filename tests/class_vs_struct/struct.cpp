#include <iostream>
#include "struct.hpp"

StructSample::StructSample(void)
{
	std::cout << "Constructor called" << std::endl;
	this->foo = 42;
}

StructSample::~StructSample(void)
{
	std::cout << "Destructor called" << std::endl;
}

void StructSample::bar(void) const
{
	std::cout << this->foo << std::endl;
}