#include "Sample.hpp"
#include <iostream>
#include <cstdio>

int main(void) {

	Sample	instance;
	Sample	instance2;
	Sample	*instancep = &instance;

	int		Sample::*p1 = &Sample::n1; // Pointer to member
	double	Sample::*p2 = &Sample::n2; // Pointer to member
	int		Sample::*p3 = &Sample::n3; // Pointer to member

	void	(Sample::*f)(void) const;

	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%p, %p, %p, %p\n", &instance, &(instance.*p1), &(instance.*p2), &(instance.*p3));
	std::cout << "Value of member foo__: " << instance.n1 << std::endl;
	instance.*p1 = 21;
	std::cout << "Value of member n1: " << instance.n1 << std::endl;
	// instancep->*p1 = 42;
	// std::cout << "Value of member n1: " << instance.n1 << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();

	return 0;
}
