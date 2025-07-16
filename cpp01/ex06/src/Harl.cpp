#include "Harl.hpp"
#include <iostream>

#define N_LEVELS 4

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::harl_switch(int level)
{
	enum levels {debug, info, warning, error};
	void (Harl::*f[])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	switch (level) {
		case debug:
			(this->*f[debug])();
			/*Fallthrough*/
		case info:
			(this->*f[info])();
			/*Fallthrough*/
		case warning:
			(this->*f[warning])();
			/*Fallthrough*/
		case error:
			(this->*f[error])();
			break;
		default :
			std::cerr << "[ Some message to show that you specified an inexistent level ]" << std::endl;
			break;
	}
}

void	string_lowercase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
}

void	Harl::complain(std::string level)
{
	int i = -1;

	std::string levels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	string_lowercase(level);
	while (++i < N_LEVELS)
	{
		if (levels[i] == level)
			break ;
	}
	harl_switch(i);
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