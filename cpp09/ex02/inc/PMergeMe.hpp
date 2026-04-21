#ifndef PMERGEME
# define PMERGEME

# include <iostream>
# include <vector>
# include <deque>

class PMergeMe
{
public:
	void	fillContainer(char **argv, std::vector<int> &v);
	void	fillContainer(char **argv, std::deque<int> &d);
	void	sort(size_t pairSize, std::vector<int> &v);
	void	sort(size_t pairSize, std::deque<int> &d);


private:
	void	pendMain(size_t pairSize, std::vector<int> &v);
	void	pendMain(size_t pairSize, std::deque<int> &d);
	void	jacobsthalInsert(std::vector<int> &main, std::vector<int> &pend);
	void	jacobsthalInsert(std::deque<int> &main, std::deque<int> &pend);
	int		jacobsthal(int k);
};

#endif