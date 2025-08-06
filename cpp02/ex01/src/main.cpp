#include <iostream>
#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed d(-11.55f);
	// Fixed e(1234.4321f);
	// Fixed f(42.42f);
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	return 0;
}

/* int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	c.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
} */