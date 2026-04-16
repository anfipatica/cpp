#ifndef PMERGEME
# define PMERGEME

# include <iostream>
# include <list>
# include <vector>

class PMergeMe
{
public:
	void	fillContainer(char **argv);
	void	sort(size_t pairSize);
	void	printVector();
private:
	std::vector<int>	_v;
};

#endif