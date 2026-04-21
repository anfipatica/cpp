#include "PMergeMe.hpp"
#include <cstdlib>
#include <algorithm>
#include <cmath>

int PMergeMe::jacobsthal(int k)
{
	return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

template <typename T>
static void	swapPairs(T &rit, size_t pairSize)
{
	for (size_t	i = 0; i < pairSize; ++i)
		std::swap(*(rit + i), *(rit + pairSize + i));
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

static void	reconstructVector(std::deque<int> &main, std::deque<int> &d, int pairSize)
{
	std::deque<int>			new_deque;
	std::deque<int>::iterator	it;

	for (size_t i = 0; i < main.size() ; ++i)
	{
		it = std::find(d.begin(), d.end(), main.at(i));
		for (int j = pairSize - 1; j >= 0; --j)
			new_deque.push_back(*(it - j));
	}
	for (size_t i = new_deque.size(); i < d.size(); ++i)
		new_deque.push_back(d.at(i));
	d = new_deque;
}


void	PMergeMe::jacobsthalInsert(std::vector<int> &main, std::vector<int> &pend)
{
	std::vector<int>::iterator	end;

	if (pend.size() == 1)
		end = std::upper_bound(main.begin(), main.end(), pend.at(0));
	else
	{
		size_t	jc_index = 2;
		size_t	count = 0;
		size_t	pend_index;
		size_t	decrease;
		while (pend.empty() == false)
		{
			pend_index = jacobsthal(jc_index) - jacobsthal(jc_index - 1);
			if (pend_index > pend.size())
				pend_index = pend.size();
			decrease = 0;
			while (pend_index > 0)
			{
				if (jacobsthal(jc_index + count) - decrease < main.size())
					end = main.begin() + jacobsthal(jc_index + count) - decrease;
				else
					end = main.end();
				end = std::upper_bound(main.begin(), end, *(pend.begin() + pend_index - 1));
				main.insert(end, *(pend.begin() + pend_index - 1));
				pend.erase(pend.begin() + pend_index - 1);
				--pend_index;
				++decrease;
				++count;
			}
			++jc_index;
		}
	}
}

void	PMergeMe::jacobsthalInsert(std::deque<int> &main, std::deque<int> &pend)
{
	std::deque<int>::iterator	end;

	if (pend.size() == 1)
		end = std::upper_bound(main.begin(), main.end(), pend.at(0));
	else
	{
		size_t	jc_index = 2;
		size_t	count = 0;
		size_t	pend_index;
		size_t	decrease;
		while (pend.empty() == false)
		{
			pend_index = jacobsthal(jc_index) - jacobsthal(jc_index - 1);
			if (pend_index > pend.size())
				pend_index = pend.size();
			decrease = 0;
			while (pend_index > 0)
			{
				if (jacobsthal(jc_index + count) - decrease < main.size())
					end = main.begin() + jacobsthal(jc_index + count) - decrease;
				else
					end = main.end();
				end = std::upper_bound(main.begin(), end, *(pend.begin() + pend_index - 1));
				main.insert(end, *(pend.begin() + pend_index - 1));
				pend.erase(pend.begin() + pend_index - 1);
				--pend_index;
				++decrease;
				++count;
			}
			++jc_index;
		}
	}
}


void	PMergeMe::pendMain(size_t pairSize, std::vector<int> &v)
{
	std::vector<int> main;
	std::vector<int> pend;

	main.push_back(*(v.begin() + pairSize - 1));
	main.push_back(*(v.begin() + (pairSize * 2) - 1));

	std::vector<int>::iterator start = v.begin() + (pairSize * 2) - 1;
	int limit = v.size() / pairSize - 2;
	for (int i = 1; i <= limit ; ++i)
	{
		if (i % 2 == 0)
			main.push_back(*(start + (pairSize * i)));
		else
			pend.push_back(*(start + (pairSize * i)));
	}

	jacobsthalInsert(main, pend);
	reconstructVector(main, v, pairSize);
}

void	PMergeMe::pendMain(size_t pairSize, std::deque<int> &d)
{
	std::deque<int> main;
	std::deque<int> pend;

	main.push_back(*(d.begin() + pairSize - 1));
	main.push_back(*(d.begin() + (pairSize * 2) - 1));

	std::deque<int>::iterator start = d.begin() + (pairSize * 2) - 1;
	int limit = d.size() / pairSize - 2;
	for (int i = 1; i <= limit ; ++i)
	{
		if (i % 2 == 0)
			main.push_back(*(start + (pairSize * i)));
		else
			pend.push_back(*(start + (pairSize * i)));
	}

	jacobsthalInsert(main, pend);
	reconstructVector(main, d, pairSize);
}



void	PMergeMe::sort(size_t pairSize, std::vector<int> &v)
{
	std::vector<int>::reverse_iterator start = v.rbegin() + (v.size() % (pairSize * 2));
	for (std::vector<int>::reverse_iterator rit = start; rit != v.rend(); rit += (pairSize * 2))
	{
		if (*rit < *(rit + pairSize))
			swapPairs(rit, pairSize);
	}

	if (pairSize * 4 < v.size())
	{
		sort(pairSize * 2, v);
		pendMain(pairSize, v);
	}
}


void	PMergeMe::sort(size_t pairSize, std::deque<int> &d)
{
	std::deque<int>::reverse_iterator start = d.rbegin() + (d.size() % (pairSize * 2));
	for (std::deque<int>::reverse_iterator rit = start; rit != d.rend(); rit += (pairSize * 2))
	{
		if (*rit < *(rit + pairSize))
			swapPairs(rit, pairSize);
	}

	if (pairSize * 4 < d.size())
	{
		sort(pairSize * 2, d);
		pendMain(pairSize, d);
	}
}


/* -------------------------------------------------------------------------- */

static bool	isValidNumber(char *strnum)
{
	for (int i = 0; strnum[i]; ++i)
	{
		if (std::isdigit(strnum[i]) == false && strnum[i] != '+')
			return (false);
	}
	return (true);
}

void	PMergeMe::fillContainer(char **argv, std::vector<int> &v)
{
	for (int i = 0; argv[i]; ++i)
	{
		if (isValidNumber(argv[i]) == false)
			throw std::runtime_error("Invalid number: "+std::string(argv[i]));
		//falta comprobar duplicados pero me da pereza.
		v.push_back(std::atoi(argv[i]));
	}
}

void	PMergeMe::fillContainer(char **argv, std::deque<int> &d)
{
	for (int i = 0; argv[i]; ++i)
	{
		if (isValidNumber(argv[i]) == false)
			throw std::runtime_error("Invalid number: "+std::string(argv[i]));
		//falta comprobar duplicados pero me da pereza.
		d.push_back(std::atoi(argv[i]));
	}
}