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
	void	printVector(std::vector<int> &v); //!Esta es de parseooooo

private:
	std::vector<int>	_v;
	int					_checks;
	void	pendMain(size_t pairSize);
	int		binarySearch(std::vector<int> &main, int n);
	int		Jacobsthal(int k);
};

#endif