# include "../inc/A.hpp"
# include "../inc/B.hpp"
# include "../inc/C.hpp"

# include <cstdlib>
# include <ctime>
# include <iostream>

Base	*generate(void)
{
	int	rand_n = std::rand() % 3;

	std::cout << rand_n << "\n";
	if (rand_n == 0)
		return (new A());
	if (rand_n == 1)
		return (new B());
	if (rand_n == 2)
		return (new C());
	return (NULL);
}

void	identify(Base *p)
{
	Base	*aux = dynamic_cast<A*>(p);
	if (aux != NULL)
		std::cout << ">> A <<\n";
	aux = dynamic_cast<B*>(p);
	if (aux != NULL)
		std::cout << ">> B <<\n";
	aux = dynamic_cast<C*>(p);
	if (aux != NULL)
		std::cout << ">> C <<\n";
}

void	identify(Base &p)
{
	try
	{
		A	a = dynamic_cast<A&>(p);
		std::cout << ">> A <<\n";
	}
	catch (std::exception &e) {}
	try
	{
		B	b = dynamic_cast<B&>(p);
		std::cout << ">> B <<\n";
	}
	catch (std::exception &e) {}
	try
	{
		C	c = dynamic_cast<C&>(p);
		std::cout << ">> C <<\n";
	}
	catch (std::exception &e) {}
}

int	main(void)
{
	std::srand(std::time(0));
	Base	*base = generate();
	identify(base);
	identify(*base);
	delete (base);
	return (0);
}