#include <vector>
#include <list>
#include <deque>
#include <map>
#include <iostream>

#include "easyfind.hpp"
#include <algorithm>

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::list<int>		l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::deque<int>		d(arr, arr + sizeof(arr) / sizeof(arr[0]));

	try
	{
		int &n = easyfind(v, 2);
		n = -2;
		std::cout << easyfind(v, -2) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		std::cout << easyfind(d, 3) << "\n";
		std::cout << easyfind(l, 5) << "\n";
		std::cout << easyfind(l, -2) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}