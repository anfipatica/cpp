#include "../inc/ScalarConverter.hpp"
#include <iostream>


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid arguments\nUsage: ./convert value\n"
		"Example of values: 0, 42.f\n";
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	
}