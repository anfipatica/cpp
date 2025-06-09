#include <iostream>
#include "sample.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called." << std::endl;
	this->_privateFoo = 1;
	this->_privateBar();
}

Sample::~Sample(void)
{
	std::cout << "Destructor called." << std::endl;
}

void Sample::publicBar(void) const
{
	std::cout << "publicBar\n";
	this->_privateBar();
}

void Sample::_privateBar(void) const
{
	std::cout << "_privateBar\n";
	std::cout << "this->publicFoo = " << this->publicFoo << std::endl;
	std::cout << "this->privateFoo = " << this->_privateFoo << std::endl;
}


