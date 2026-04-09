#include "MutantStack.hpp"
#include <list>
#include <vector>

void	test_vector(void)
{
	std::vector<int>	v;

	std::cout << "\n:: VECTOR TEST\n";
	v.push_back(5);
	v.push_back(17);

	std::cout << v.back() << "\n";
	v.pop_back();
	std::cout << v.size() << "\n\n";

	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	v.push_back(9);

	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int, std::vector<int> > s(v);
	std::cout << "stack.top(): " << s.top() << "\n";
}

void	test_list(void)
{
	std::list<int>	lst;

	std::cout << "\n:: LIST TEST\n";
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << "\n";
	lst.pop_back();
	std::cout << lst.size() << "\n\n";

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(9);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int, std::list<int> > s(lst);
	std::cout << "stack.top(): " << s.top() << "\n";
}

void	test_deque(void)
{
	std::deque<int>	dq;

	std::cout << "\n:: DEQUE TEST\n";
	dq.push_back(5);
	dq.push_back(17);

	std::cout << dq.back() << "\n";
	dq.pop_back();
	std::cout << dq.size() << "\n\n";

	dq.push_back(3);
	dq.push_back(5);
	dq.push_back(737);
	dq.push_back(9);

	std::deque<int>::iterator it = dq.begin();
	std::deque<int>::iterator ite = dq.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int> s(dq);
	std::cout << "stack.top(): " << s.top() << "\n";
}

void	test_mutant(void)
{
	MutantStack<int>	mstack;

	std::cout << "\n:: MUTANT TEST\n";
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << "\n";
	mstack.pop();
	std::cout << mstack.size() << "\n\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(9);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "stack.top(): " << s.top() << "\n";
}

void	test_constructors(void)
{
	std::cout << "\n:: TEST CONSTRUCTORS AND COPY OPERATOR\n";
	MutantStack<int>	mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	MutantStack<int>	copy(mstack);
	std::cout << mstack.top() << "\n";
	std::cout << copy.top() << "\n";
	copy.pop();
	std::cout << mstack.top() << "\n";
	std::cout << copy.top() << "\n";
	mstack = copy;
	std::cout << mstack.top() << "\n";
	std::cout << copy.top() << "\n";
}

int	main(void)
{
	test_constructors();
	test_mutant();
	test_deque();
	test_list();
	test_vector();
}