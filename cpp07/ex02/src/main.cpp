#include <iostream>
#include <Array.hpp>

#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{

		std::cout << "numbers[50]: " << &numbers[50] <<" - " << numbers[50] << "\n";
		Array<int> tmp = numbers;
		std::cout << "tmp[50]: " << &tmp[50] <<" - " << tmp[50] << "\n";
		Array<int> test(tmp);
		std::cout << "test[50]: " << &test[50] <<" - " << test[50] << "\n";
		tmp[50] = 999;
		test[50] = 707;
		std::cout << "numbers[50]: " << numbers[50] << "\n";
		std::cout << "tmp[50]: "  << tmp[50] << "\n";
		std::cout << "test[50]: " << test[50] << "\n";
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;
	return 0;
}