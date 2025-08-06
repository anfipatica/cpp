#include "../inc/Fixed.hpp"

#include <iostream>
#include <sstream>
#include <string>

#include <bitset>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n): _value(n << _fractional_bits)
{
	std::bitset<16> n_bits(n);
	std::bitset<16> value_bits(_value);

	std::cout << sizeof(int) << std::endl;
	std::cout << "n = " << n << " | " << n_bits << "\n";
	std::cout << "v = " << _value << " | " << value_bits << "\n";

	std::cout << "Int constructor called - " << (n << _fractional_bits) << std::endl;
}


Fixed::Fixed(float n)
{
	std::cout << "Float constructor called" << std::endl;

	std::bitset<16> n_bits(n);
	std::cout << sizeof(float) << std::endl;
	std::cout << "n = " << n << " | " << n_bits << "\n";
}












// Fixed:: Fixed(const int int_nb) : fixed(int_nb << bits)
// {
//     std::cout << "INT constructor called." << std::endl;
// }

// Fixed:: Fixed(const float float_nb)
// {
//     std::cout << "FLOAT constructor called." << std::endl;
//     fixed = roundf((float)float_nb * (1 << bits));
// }



Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

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
