#include "PMergeMe.hpp"
#include <cstdlib>

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

void	PMergeMe::sort(size_t pairSize)
{
	std::cout << "pairSize: " << pairSize << "\n";
	printVector();
	// pairStart is the iterator where pairings begin, lonely nodes are skipped.
	std::vector<int>::reverse_iterator start = _v.rbegin() + (_v.size() % (pairSize * 2));

	for (std::vector<int>::reverse_iterator rit = start; rit != _v.rend(); rit += (pairSize * 2))
	{
		if (rit + 1 == _v.rend()) // a ver como gestionamos esto mejor jeje
			break;
		if (*rit < *(rit + pairSize))
			swapPairs(rit, pairSize);
	//	std::cout << *rit << "\n";
	}

 	// esta condición no sirve creo, pero por ahora pa que no pete jeje
	//*He puesto *4 en vez de *2, creo que ahora tiene más sentido pero no estoy segura
	if (pairSize * 4 < _v.size())
		sort(pairSize * 2);
	else
		printVector();
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