#include <iostream>
#include "../inc/Fixed.hpp"
#include <cstdio>
/* 
int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed d(10.2f);
	// Fixed e(1234.4321f);
	// Fixed f(42.42f);
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	return 0;
} */


void	see_float_process(float n)
{
	Fixed f(n);

	std::cout << "-------------------------------------------------------------\n";
	std::cout << "n(" << n <<") * 256 = "<< n * 256 << "\n";
	std::cout << "valor almacenado en f: " << f.getRawBits() << "\n";
	std::cout << "f = " << f << "\n";
	std::cout << "valor mínimo de un fixed point: " << (1.0 / (1 << 8)) << "\n";
	std::cout << (f.toFloat() - (1.0 / (1 << 8))) << " - " << f << " - " << (f.toFloat() + (1.0 / (1 << 8))) << "\n";
	printf("%b\n", f.getRawBits());
	std::cout << "-------------------------------------------------------------\n";
}

void	test_constructors(void)
{
	see_float_process(3.14f);
	see_float_process(0.00390625f);
}


int main( void ) {
	test_constructors();

	return 0;
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c(42.42f);
// 	Fixed const d(b);

// 	a = Fixed(1234.4321f);

// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;

// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// 	return 0;
// }