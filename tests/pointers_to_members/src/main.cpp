#include "Sample.hpp"
#include <iostream>
#include <cstdio>

int main(void) {

	Sample	instance;
	Sample	instance2;
	Sample	*instancep = &instance;

	int		Sample::*p1 = &Sample::n1; // Pointer to member
	int	Sample::*p2 = &Sample::n2; // Pointer to member
	int		Sample::*p3 = &Sample::n3; // Pointer to member
	int	(Sample::*f)(void) const = &Sample::bar;
	
	instance.*p1 = 21;
	std::cout << "Value of instance.n1: " << instance.n1 << std::endl;
	instance2.*p1 = 999;
	std::cout << "Value of instance2.n1: " << instance2.n1 << std::endl;
	instancep->*p1 = 42;
	std::cout << "Value of instance.n1: " << instance.n1 << std::endl;
	std::cout << "Value of member n1: " << instance.n1 << std::endl;

	// f = &Sample::bar;
	std::cout << (instance.*f)() << std::endl;
	std::cout << (instance2.*f)() << std::endl;
	std::cout << (instancep->*f)() << std::endl;

	// (instance.*f)();
	// (instancep->*f)();
	
	return 0;
}
