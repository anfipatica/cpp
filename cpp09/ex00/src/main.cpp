#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments\n";
		return (1);
	}

	BitcoinExchange bc;
	try
	{
		bc.savecsv();
		bc.calculateExchange(argv[1]);
	} catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}
