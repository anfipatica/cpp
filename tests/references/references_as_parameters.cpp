#include <string>
#include <iostream>

void	by_ptr(std::string *str)
{
	*str += " and ponies";
}

void	by_const_ptr(const std::string *str)
{
	std::cout << *str << std::endl;
}

void	by_ref(std::string &str)
{
	str += " and ponies";
}

void	by_const_ref(const std::string &str)
{
	std::cout << str << std::endl;
}

int	main(void)
{
	std::string str = "I like butterflies";

	std::cout << str << std::endl;
	by_ptr(&str);
	by_const_ptr(&str);
	std::cout << str << std::endl;

	str = "I like otters";
	std::cout << str << std::endl;
	by_ref(str);
	by_const_ref(str);
	std::cout << str << std::endl;

	return (0);
}