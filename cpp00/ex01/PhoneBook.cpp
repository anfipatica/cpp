#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Creating a PhoneBook\n";
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "eliminating a PhoneBook\n";
}

void	PhoneBook::func(char *s)
{
	std::cout << "n = " << this->n << std::endl;
	std::cout << "We've received a message: " << s << std::endl;
}

void	PhoneBook::func(int n)
{
	std::cout << "We've received a message: " << n << std::endl;
}