#include <iostream>

int	main(void)
{
	int	number_balls = 42;

	int	*balls_ptr = &number_balls;
	int	&balls_ref = number_balls;

	std::cout << number_balls << " " << *balls_ptr << " " << balls_ref << std::endl;

	*balls_ptr = 21;
	std::cout << number_balls << std::endl;
	balls_ref = 84;
	std::cout << number_balls << std::endl;

	std::cout << &number_balls << " " << balls_ptr << " " << &balls_ref << std::endl;
	return (0);
}