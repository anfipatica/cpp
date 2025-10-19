#include <iostream>
#include "../inc/Fixed.hpp"
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

void	test_post_pre_increment_decrement(void)
{
	Fixed n;
	std::cout << "n: " << (n) << "\n";
	std::cout << "++n: " << (++n) << "\n";
	std::cout << "--n: " << (--n) << "\n";
	std::cout << "n++: " << (n++) << "\n";
	std::cout << "n--: " << (n--) << "\n";
	std::cout << "n: " << (n) << std::endl;
}

void	test_min_max(void)
{
	Fixed n1 = Fixed(5);
	Fixed n2 = Fixed(4.9f);
	std::cout << "n1: " << &n1 << "\n";
	std::cout << "n2: " << &n2 << "\n";
	std::cout << "normal min: " << &(Fixed::min(n1, n2)) << "\n";
	
	const Fixed n3 = Fixed(5);
	const Fixed n4 = Fixed(4.9f);
	std::cout << "n3: " << &n3 << "\n";
	std::cout << "n4: " << &n4 << "\n";
	std::cout << "const min: " << &(Fixed::min(n3, n4)) << "\n";

	std::cout << "mixed min: " << &(Fixed::min(n1, n4)) << std::endl;


}

void	test_constructors(void)
{
	Fixed	default_fixed;
	Fixed	int_fixed(5);
	Fixed	float_fixed(5.5f);
	Fixed	copy_fixed_1(int_fixed);

	// In a declaration context, the "=" will call the copy constructor,
	//	not the operator=.
	Fixed	copy_fixed_2 = int_fixed;

	//Once you are not declaring an object, the = will act as the overloaded operator.
	default_fixed = int_fixed;
	std::cout << &default_fixed << "\n";
	std::cout << &int_fixed << "\n";

	//It happens the same with all constructors, not sure how correct this is,
	//	but it will call the int constructor.
	Fixed	int_fixed_test = 2;

	//As long as there is a constructor that receives that data type, it is the same.
	//	If we pass here a String, it will not work:
	// Fixed	int_fixed_test = "a";
}

void	test_comparison_operators(Fixed n1, Fixed n2, Fixed n3)
{
	std::cout << "n1(" << n1 << ") > n2(" << n2 << "):  " << (n1 < n2) << "\n";
	std::cout << "n1(" << n1 << ") < n2(" << n2 << "):  " << (n1 > n2) << "\n";
	std::cout << "n1(" << n1 << ") >= n2(" << n2 << "): " << (n1 <= n2) << "\n";
	std::cout << "n1(" << n1 << ") <= n2(" << n2 << "): " << (n1 >= n2) << "\n";
	std::cout << "n1(" << n1 << ") == n2(" << n2 << "): " << (n1 == n2) << "\n";
	std::cout << "n1(" << n1 << ") != n2(" << n2 << "): " << (n1 != n2) << "\n";

	std::cout << "n1(" << n1 << ") == n3(" << n3 << "): " << (n1 == n3) << "\n";
	std::cout << "n1(" << n1 << ") != n3(" << n3 << "): " << (n1 != n3) << "\n";

}

void	test_arithmetic_operators(Fixed n1, Fixed n2, Fixed n3)
{
	std::cout << "n1 = " << n1 << "\n";
	std::cout << "n2 = " << n2 << "\n";
	std::cout << "n3 = " << n3 << "\n";
	std::cout	<< "Operaciones básicas:\n";
	std::cout	<< "n1 + n2 = " << n1 + n2 << "\n";
	std::cout	<< "n1 - n2 = " << (n1 - n2) << "\n";
	std::cout	<< "n1 * n2 = " << (n1 * n2) << "\n";
	std::cout	<< "n1 / n2 = " << (n1 / n2) << "\n";

	std::cout << "Concatenación de operaciones:\n";
	std::cout	<< "n1 + n1 + n1 + n1 + n1 = " << (n1 + n1 + n1 + n1 + n1) << "\n";
	std::cout	<< "n2 + n2 + n2 + n2 + n2 = " << (n2 + n2 + n2 + n2 + n2) << "\n";
	std::cout	<< "n3 - n3 - n3 - n3 - n1 = " << (n3 - n3 - n3 - n3 - n1) << "\n";
	std::cout << "n1 * n1 * n1 * n1 * n2 = " << (n1 * n1 * n1 * n1 * n2) << "\n";
	std::cout << "n1 * n1 * n1 * n1 * n2 * 0 = " << (n1 * n1 * n1 * n1 * n2 * Fixed()) << "\n";
	std::cout << "n1 / n1 / n1 / n1 / n2 = " << (n1 / n1 / n1 / n1 / n2) << "\n";
	std::cout << "n1 / 0 / n1 / n1 / n1 / n2 = " << (n1 / Fixed() / n1 / n1 / n1 / n2) << "\n";
	std::cout << "0 / n1 / n1 / n1 / n1 / n2 = " << (Fixed() / n1 / n1 / n1 / n1 / n2) << "\n";

}

int main( void )
{
	//test_constructors();
	//test_comparison_operators(1, 2, 1.0f);
	test_arithmetic_operators(1, 0.5f, 1.0f);
	//test_post_pre_increment_decrement();
	//test_min_max();

	return 0;
}