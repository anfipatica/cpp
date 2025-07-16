#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid arguments :( \n\n-> Usage ./harl_switch <level_of_warning>\n"\
		"The valid levels are: DEBUG, INFO, WARNING, ERROR.\n"\
		"You can write some other level but Harl will mumble nonsense" << std::endl;
		return 1;
	}

	Harl harl = Harl();
	harl.complain(argv[1]);
}
