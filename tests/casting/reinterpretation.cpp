#include <iostream>

using std::cout;

int	main(void)
{
	float	a = 420.042f;
	void	*b = &a;
	void	*c = (void *)&a;

	void	*d = &a;
	//int		*e = &a; // no me deja hacer un implicit demotion.
	int		*f = (int *)&a;
	int		e = (int) a;

	int		n1 = 42;
	float	*n2 = (float *) &n1;

	cout << a << "\n"; // valor original
	cout << *f << "\n"; // reinterpretación
	cout << e << "\n"; // casteo

	cout << n1 << "\n";
	cout << *n2 << "\n";
}