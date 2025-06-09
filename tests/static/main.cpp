#include "sample.hpp"
#include <iostream>

int main(void)
{
	Sample	instance1;
	Sample	instance2;
	Sample	instance3;

	std::cout << "instanceFoo1: " << instance1.getInstanceFoo() << std::endl;
	std::cout << "instanceFoo2: " << instance1.getInstanceFoo() << std::endl;
	std::cout << "instanceFoo3: " << instance1.getInstanceFoo() << std::endl;

	std::cout << "classFoo1: " << instance1.getClassFoo() << std::endl;
	std::cout << "classFoo2: " << instance2.getClassFoo() << std::endl;
	std::cout << "classFoo3: " << instance3.getClassFoo() << std::endl;
	std::cout << "SAMPLE::  " << Sample::getClassFoo() << std::endl;
	Sample::setClassFoo(80);
	std::cout << "SAMPLE::  " << Sample::getClassFoo() << std::endl;
	Sample::getInstanceFoo();
	return 0;
}
