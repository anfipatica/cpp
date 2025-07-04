#include "Sample.hpp"
#include <iostream>

Sample::Sample(void) {
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Sample::bar(void) const{
	std::cout << "bar has been called" << std::endl;
	return (this->n1);
}
