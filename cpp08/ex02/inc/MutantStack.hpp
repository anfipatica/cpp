#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
public:

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::deque<T>::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
};

#endif