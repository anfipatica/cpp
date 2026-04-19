#include "PMergeMe.hpp"
#include <cstdlib>
#include <algorithm>
#include <cmath>


int PMergeMe::Jacobsthal(int k)
{
	return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

void	PMergeMe::printVector(std::vector<int> &v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 == v.end())
			std::cout << "\n";
		else
			std::cout << " - ";
	}
}

void	PMergeMe::printVector(void)
{
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 == _v.end())
			std::cout << "\n";
		else
			std::cout << " - ";
	}
}

static bool	isValidNumber(char *strnum)
{
	for (int i = 0; strnum[i]; ++i)
	{
		if (std::isdigit(strnum[i]) == false && strnum[i] != '+')
			return (false);
	}
	return (true);
}

static void	swapPairs(std::vector<int>::reverse_iterator &rit, size_t pairSize)
{
	for (size_t	i = 0; i < pairSize; ++i)
	{
		std::swap(*(rit + i), *(rit + pairSize + i));
	}
}

int		PMergeMe::binarySearch(std::vector<int> &main, int n)
{
	int	low = 0;

	int	high = main.size() -1;
	int	mid = high / 2;


	while (high >= low)
	{
	//	std::cout << "     _low = " << low << ". mid = " << mid << ". high = " << high << "\n";
		if (n < main.at(mid))
			high = mid - 1;
		else if (n > main.at(mid))
			low = mid + 1;
		mid = low + (high - low) / 2;
		++_checks;
	}
	return (high); // devuelve la posición previa a la inserción
}


static void	reconstructVector(std::vector<int> &main, std::vector<int> &v, int pairSize)
{
	std::vector<int>			new_vector;
	std::vector<int>::iterator	it;

	for (size_t i = 0; i < main.size() ; ++i)
	{
		it = std::find(v.begin(), v.end(), main.at(i));
		for (int j = pairSize - 1; j >= 0; --j)
			new_vector.push_back(*(it - j));
	}
	for (size_t i = new_vector.size(); i < v.size(); ++i)
		new_vector.push_back(v.at(i));

	v = new_vector;
}


void	PMergeMe::pendMain(size_t pairSize)
{
	std::cout << "pairSize: " << pairSize << "\n";

	std::vector<int> main;
	std::vector<int> pend;

	main.push_back(*(_v.begin() + pairSize - 1));
	main.push_back(*(_v.begin() + (pairSize * 2) - 1));

	std::vector<int>::iterator start = _v.begin() + (pairSize * 2) - 1;

	int limit = _v.size() / pairSize - 2;

	for (int i = 1; i <= limit ; ++i)
	{
		if (i % 2 == 0)
			main.push_back(*(start + (pairSize * i)));
		else
			pend.push_back(*(start + (pairSize * i)));
	}
	
	for (size_t i = 0; i < pend.size(); ++i)
		main.insert(main.begin() + binarySearch(main, pend.at(i)) + 1, pend.at(i));

	reconstructVector(main, _v, pairSize);
}


void	PMergeMe::sort(size_t pairSize)
{
	std::cout << "pairSize: " << pairSize << "\n";
	printVector();

	// pairStart is the iterator where pairings begin, lonely nodes are skipped.
	std::vector<int>::reverse_iterator start = _v.rbegin() + (_v.size() % (pairSize * 2));

	for (std::vector<int>::reverse_iterator rit = start; rit != _v.rend(); rit += (pairSize * 2))
	{
		if (*rit < *(rit + pairSize))
			swapPairs(rit, pairSize);
	}

	//*He puesto *4 en vez de *2, creo que ahora tiene más sentido pero no estoy segura
	if (pairSize * 4 < _v.size())
	{
		sort(pairSize * 2);
		pendMain(pairSize);
		printVector();
	}
	else
	{
		printVector();
		std::cout << "---------------- DESHACEMOS RECURSIVIDAD -----------------\n";
	}
	if (pairSize == 1)
		std::cout << "checks totales:    " << _checks << "\n";
}


void	PMergeMe::fillContainer(char **argv)
{
	for (int i = 0; argv[i]; ++i)
	{
		if (isValidNumber(argv[i]) == false)
			throw std::runtime_error("Invalid number: "+std::string(argv[i]));
		//falta comprobar duplicados pero me da pereza.
		_v.push_back(std::atoi(argv[i]));
	}
}