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
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n): _value(n << _fractional_bits)
{
//	std::cout << "INT constructor called." << std::endl;
}

Fixed::Fixed(const float n): _value(roundf(n * (1 << _fractional_bits)))
{
//	std::cout << "FLOAT constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// --------------------- OPERATOR OVERLOADS -----------------------------------

Fixed &Fixed::operator=(const Fixed &fixed)
{
//	std::cout << "Copy assignment operator called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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

// /------------ Comparison operators ---------------------

#define left_operand this

bool	Fixed::operator>(const Fixed &right_operand) const
{
	if (left_operand->_value > right_operand._value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &right_operand) const
{
	if (left_operand->_value < right_operand._value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &right_operand) const
{
	if (left_operand->_value >= right_operand._value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &right_operand) const
{
	if (left_operand->_value <= right_operand._value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &right_operand) const
{
	if (left_operand->_value == right_operand._value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &right_operand) const
{
	if (left_operand->_value != right_operand._value)
		return (true);
	return (false);
}


// /------------ Arithmetic operators ---------------------

Fixed	Fixed::operator+(const Fixed &right_operand) const
{
	Fixed	fixed;

	fixed.setRawBits(left_operand->getRawBits() + right_operand.getRawBits());
	return (fixed);
	//return (left_operand->toFloat() + right_operand.toFloat());

}

Fixed	Fixed::operator-(const Fixed &right_operand) const
{
	Fixed	fixed;

	fixed.setRawBits(left_operand->getRawBits() - right_operand.getRawBits());
	return (fixed);
}

Fixed	Fixed::operator*(const Fixed &right_operand) const
{
	Fixed	fixed;

	fixed.setRawBits((left_operand->getRawBits() * right_operand.getRawBits()) >> _fractional_bits);
	return (fixed);
}

Fixed	Fixed::operator/(const Fixed &right_operand)
{
	Fixed	fixed;

	if (right_operand._value == 0)
	{
		std::cerr << "ERROR: Invalid division by 0" << std::endl;
		return (fixed);
	}

	fixed.setRawBits((left_operand->getRawBits() / right_operand.getRawBits()) << _fractional_bits);
	return (fixed);
}


// /------------ Increment / decrement  -------------------

Fixed	&Fixed::operator++(void)
{
	this->_value += 0b1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy = *this;

	this->_value += 0b1;
	return (copy);
}

Fixed	&Fixed::operator--(void)
{
	this->_value -= 0b1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy = *this;

	this->_value -= 0b1;
	return (copy);
}

// --------------------- STATIC MEMBER FUNCTIONS  -----------------------------

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1._value < n2._value)
		return (n1);
	return (n2);
}

Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
	std::cout << "(const min function called)\n";
	if (n1._value < n2._value)
		return ((Fixed &)n1);
	return ((Fixed &)n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1._value > n2._value)
		return (n1);
	return (n2);
}

Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
	std::cout << "(const max function called)\n";
	if (n1._value > n2._value)
		return ((Fixed &)n1);
	return ((Fixed &)n2);
}


// --------------------- DESTRUCTORS ------------------------------------------

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}