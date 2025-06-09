#include "sample.hpp"
#include <iostream>
int Sample::_classFoo = 0;

Sample::Sample(void)
{
	std::cout << "constructor called" << std::endl;
	this->_instanceFoo += 1;
	Sample::_classFoo += 1;
}

Sample::~Sample(void)
{
	std::cout << "destructor called" << std::endl;
}

int	Sample::getInstanceFoo(void) const
{
	return (this->_instanceFoo);
}

void	Sample::setInstanceFoo(int n)
{
	if (n < 0)
		return ;
	this->_instanceFoo = n;
}

int	Sample::getClassFoo(void)
{
	return (Sample::_classFoo);
}

void	Sample::setClassFoo(int n)
{
	if (n < 0)
		return ;
	Sample::_classFoo = n;
}