#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;
	std::deque<int>		dq;

	mstack.push(5);
	mstack.push(17);
	dq.push_back(5);
	dq.push_back(17);
	std::cout << mstack.top() << "\n";
	std::cout << dq.at(dq.size() - 1) << "\n";

	mstack.pop();
	dq.pop_back();

	std::cout << mstack.size() << "\n";
	std::cout << dq.size() << "\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	// std::deque<int>::iterator
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << "\n";

}