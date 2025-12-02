#include <iostream>

int	main(void)
{
	int			n1 = 1;
	const int	*n2 = &n1;
	//int			*n3 = n2; No deja hacerlo ni de coña
	int			*n3 = (int *) n2;

	n1 = 2;
	// *n2 = 3; Es const, no se puede cambiar.
	*n3 = 3;

	// Pese a que n2 es const, podemos cambiar su valor tanto a través del original
	// n1 o con n3, que ha permitido la asignación con un 
	std::cout << n1 << "\n";
	std::cout << *n2 << "\n";
	std::cout << *n3 << "\n";
}