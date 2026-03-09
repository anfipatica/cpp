#include "Span.hpp"
#include <iostream>


void	test_exceptions(void)
{
	std::cout << "\n :: Exceed limit\n";
	try
	{
		Span s1(2);
		s1.addNumber(1);
		s1.addNumber(2);
		s1.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n :: Invalid span search\n";
	try
	{
		Span s1(2);
		s1.addNumber(1);
		s1.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}
int	main(void)
{
	test_exceptions();
	// Span s1(10002);
	// std::vector<int> v = std::vector<int>();

	// for (int i = 0; i != 10000; ++i)
	// {
	// 	v.push_back(i);
	// }

	// std::vector<int> v2 = std::vector<int>(v.begin(), v.end());
	// try
	// {
	// 	s1.addRange(v.begin(), v.end());
	// 	s1.addNumber(6);
	// 	s1.addNumber(1);
	// 	s1.printValues();
	// 	std::cout << s1.longestSpan() << "\n";
	// 	std::cout << s1.shortestSpan() << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
}