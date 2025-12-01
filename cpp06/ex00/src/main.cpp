#include "../inc/ScalarConverter.hpp"
#include <iostream>

//! Revisar el tema del overflow al imprimir ints :'( no sé cómo
//! gestionarlo y quiero llorar
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