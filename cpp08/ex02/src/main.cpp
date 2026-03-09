#include "MutantStack.hpp"

int	main(void)
{
	std::deque<int> d;
	d.push_front(1);
	int	*n = new int;

	*n = 1;

	std::cout << n << "\n";
	std::cout << *n << "\n";
	std::cout << &(*n) << "\n\n";

	std::deque<int>::iterator it = d.begin();
	std::cout << &it << "\n";
	std::cout << *it << "\n";
	std::cout << &(*it) << "\n"; //!Qué pasa exactamente aquí preguntar al chatgpt o algo mañana que hoy estoy cansadita



	// MutantStack<int> m;
	// m.push(1);
	// m.push(2);
	// m.push(3);

	// MutantStack<int>::iterator it = m.begin();
	// std::cout << &(*it) << "\n";
	// std::cout << *it << "\n";
	// it = m.begin();
	// std::cout << &(*it) << "\n";
	// std::cout << *it << "\n";
	// it = m.begin();
	// std::cout << &(*it) << "\n";
	// std::cout << *it << "\n";
}