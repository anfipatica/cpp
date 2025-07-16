#include "Harl.hpp"
#include <iostream>

#define N_LEVELS 4

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::complain(std::string level)
{
	static std::string levels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	static void (Harl::*f[])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < N_LEVELS; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cerr << "... what? e.e'" << std::endl;
}

void	Harl::_debug(void) {
	std::cout << "[ DEBUG ]\n"\
	"This is a debug message that my creator was not inspired to write\n" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "[ INFO ]\n"\
	"Now this on the other hand is a not very inspired informative message.\n"\
		"Make good use of this information, it's important.\n" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "[ WARNING ]\n"\
	"And this, a warning message written without much thought put into it.\n"\
	"Be careful out there kiddo.\n" << std::endl;
}

void	Harl::_error(void) {
	std::cout << "[ ERROR ]\n"\
	"ERROR! That's it that's the error message. RUN\n" << std::endl;
}