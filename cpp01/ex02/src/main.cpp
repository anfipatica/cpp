#include <string>
#include <iostream>

int	main(void)
{
	std::string	string= "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "   string: " << &string << " | " << string << std::endl;
	std::cout << "stringPTR: " << stringPTR << " | " << *stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << " | " << stringREF << std::endl;

	return (0);
}