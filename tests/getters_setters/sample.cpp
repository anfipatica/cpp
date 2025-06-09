#include "sample.hpp"
#include <iostream>

Sample::Sample(void)
{
	std::cout << "constructor called" << std::endl;
}

Sample::~Sample(void)
{
	std::cout << "destructor called" << std::endl;
}

int	Sample::getFoo(void) const
{
	return (this->_foo);
}

void	Sample::setFoo(int n)
{
	if (n < 0)
		return ;
	this->_foo = n;
}