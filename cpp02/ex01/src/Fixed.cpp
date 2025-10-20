#include "../inc/Fixed.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <bitset>

const int Fixed::_fractional_bits = 8;

// --------------------- CONSTRUCTORS -----------------------------------------

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n): _value(n << _fractional_bits)
{
	std::cout << "INT constructor called." << std::endl;
}


Fixed::Fixed(const float n): _value(roundf(n * (1 << _fractional_bits)))
{
	std::cout << "FLOAT constructor called." << std::endl;
}


Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// --------------------- OPERATOR OVERLOADS -----------------------------------

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed._value;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

// --------------------- MEMBER FUNCTIONS -------------------------------------

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fractional_bits));
}

// --------------------- DESTRUCTORS ------------------------------------------

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}