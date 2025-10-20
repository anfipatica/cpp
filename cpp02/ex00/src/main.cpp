#include <iostream>
#include "Fixed.hpp"


/* void	test_constructors(void)
{
	Fixed a; // Default constructor.
	std::cout << "\n";
	Fixed b(a); // Copy constructor.
	std::cout << "\n";
	Fixed c = a; // Copy constructor.
	std::cout << "\n";
	c = b; // Copy Assignment operator.
	std::cout << "\n";

	std::cout << "a: " << a.getRawBits() << "\n";
	std::cout << "b: " << b.getRawBits() << "\n";
	std::cout << "c: " << c.getRawBits() << "\n";

	std::cout << "&a: " << &a << "\n";
	std::cout << "&b: " << &b << "\n";
	std::cout << "&c: " << &c << "\n";
}

int main( void )
{
	test_constructors();
	return 0;
} */

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}