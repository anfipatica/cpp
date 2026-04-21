#include "PMergeMe.hpp"
#include <ctime>

template <typename T>
void	printContainer(T &t)
{
	for (typename T::iterator it = t.begin(); it != t.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 == t.end())
			std::cout << "\n";
		else
			std::cout << " ";
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Invalid arguments\n";
		return (1);
	}

	PMergeMe			pm;
	std::vector<int>	v;
	std::deque<int>		d;
	clock_t				start;
	clock_t				end;

	try
	{
		pm.fillContainer(&argv[1], v);
		
		std::cout << "Before: ";
		printContainer(v);
		start = clock();
		pm.sort(1, v);
		end = clock();
		std::cout << "after: ";
		printContainer(v);
		std::cout << "Time to process with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms\n\n";

		pm.fillContainer(&argv[1], d);
		std::cout << "Before: ";
		printContainer(d);
		start = clock();
		pm.sort(1, d);
		end = clock();
		std::cout << "after: ";
		printContainer(d);
		std::cout << "Time to process with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms\n";

	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
}
