#include <iostream>
#include <string>

#include "iter.hpp"
#include "add_one.hpp"
#include "print_array.hpp"

int	main(void)
{
	std::cout << "\n:: PRINT_ARRAY ::\n";
	int		n_int[5] = {1, 2, 3, 4, 5};
	iter<int>(n_int, 5, print_array<int>);

	float	n_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter<float>(n_float, 5, print_array<float>);

	std::string	str[5] = {"aaa", "bbb", "ccc", "ddd", "eee"};
	iter<std::string>(str, 5, print_array<std::string>);

	std::cout << "\n:: ADD_ONE ::\n";
	iter<int>(n_int, 5, add_one<int>);
	iter<int>(n_int, 5, print_array<int>);

	iter<float>(n_float, 5, add_one<float>);
	iter<float>(n_float, 5, print_array<float>);

	iter<std::string>(str, 5, add_one<std::string>);
	iter<std::string>(str, 5, print_array<std::string>);

	std::cout << "\n:: NOW PRINTING A CONST ARRAY ::\n";
	const int const_int[5] = {5, 4, 3, 2, 1};
	iter(const_int, 5, print_array<const int>);
}
