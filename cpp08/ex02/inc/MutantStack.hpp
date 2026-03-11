#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack(void): std::stack<T>() {}
	MutantStack(const MutantStack &ms): std::stack<T>(ms)
	{
		*this = ms;
	}
	const MutantStack &operator=(const MutantStack &ms)
	{
		if (this != &ms)
			std::stack<T>::operator=(ms);
		return (*this);
	}
	~MutantStack(void){}

	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};

#endif