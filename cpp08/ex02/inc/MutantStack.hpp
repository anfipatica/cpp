#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iostream>


template<typename T>
class MutantStack: public std::stack<T>
{
public:
	// typedef typename std::deque<T>::iterator iterator;

	// MutantStack(): std::stack<T>() {}
	// iterator	begin(void)
	// {
	// 	std::deque<T>	d = static_cast<std::deque<T> >(this->c);
	// 	typename std::deque<T>::iterator it = d.begin();
	// 	it = d.begin();
	// 	std::cout << &(*it) << "\n";
	// 	std::cout << *it << "\n";
	// 	return (it);
	// }
	// typename std::deque<T>::iterator	end(void)
	// {
	// 	std::deque<T>	d = static_cast<std::deque<T> >(this->c);
	// 	return (d.end());
	// }
};

#endif