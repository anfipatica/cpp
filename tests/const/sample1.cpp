#include "sample1.hpp"
#include <iostream>

Sample1::Sample1(float const f): qd(42)
{
	this->pi = 3.14;
	std::cout << "constructor called" << std::endl;
}

Sample1::~Sample1(void)
{
	std::cout << "destructor called" << std::endl;
}

void Sample1::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;
}

