#include <iostream>

// Lo que hacíamos hasta ahora.
/* int	max(int x, int y)
{
	return (x >= y ? x : y);
} */

// Una template.
/*template<typename T>
 T	max(T x, T y)
{
	return (x >= y ? x : y);
} */

int	function(int n)
{
	printf("Haciendo cositas con %d...\n", n);
	return (n);
}

// mejorada:
template<typename T>
const T	&max(const T &x, const T &y)
{
	return (x >= y ? x : y);
}

int	main(void)
{
	std::cout << max<int>(function(3), function(8)) << "\n"; // Explícito
	std::cout << max(5, 1) << "\n"; // Implícito
	return (0);
}