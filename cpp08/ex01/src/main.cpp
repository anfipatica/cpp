#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
void	subject_test(void)
{
	std::cout << "\n :: Subject test\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << "\n";
	std::cout << sp.longestSpan() << "\n";
}

void	tons_of_random_numbers(void)
{
	std::cout << "\n :: Now testing with 100000 random numbers...\n";
	std::vector<int>	v(100000);
	Span				span(100000);
	for (int i = 0; i < 100000; ++i)
		v[i] = std::rand() % 10000000;

	span.addRange(v.begin(), v.end());
	std::cout << span.shortestSpan() << "\n";
	std::cout << span.longestSpan() << "\n";
}

// to generate more non repeated random numbers: https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php
void	more_tests(void)
{
	std::cout << "\n :: And lastly, with no repeated numbers...\n";
	int	arr[] = {27, 43, 46, 48, 66, 72, 78, 86, 96, 98, 115, 144, 156, 165, 172,
		197, 202, 204, 207, 221, 244, 264, 273, 306, 315, 339, 357, 372, 388, 402,
		421, 424, 444, 523, 561, 579, 644, 651, 657, 765, 768, 770, 825, 873, 891,
		900, 909, 916, 983, 994};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(int));
	Span	span(100);
	span.addRange(v.begin(), v.end());

	std::cout << span.shortestSpan() << "\n";
	std::cout << span.longestSpan() << "\n";
}

void	test_constructors(void)
{
	std::cout << "\n :: Basic constructors and copy operator test\n";
	Span span(5);

	span.addNumber(1);
	span.addNumber(2);
	span.addNumber(3);
	Span copy(span);
	std::cout << span.longestSpan() << "\n";
	std::cout << copy.longestSpan() << "\n";
	copy.addNumber(10);
	std::cout << span.longestSpan() << "\n";
	std::cout << copy.longestSpan() << "\n";
	span = copy;
	std::cout << span.longestSpan() << "\n";
	std::cout << copy.longestSpan() << "\n\n";
}

int	main(void)
{
	std::srand(time(0));
	test_constructors();
	test_exceptions();
	subject_test();
	tons_of_random_numbers();
	more_tests();
}