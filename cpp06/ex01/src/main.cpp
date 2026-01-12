#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data data;
	data.n = 5;
	data.s = "Hola caracola :)";
	std::cout << "Before serialization: \n";
	std::cout << data.n << "\n";
	std::cout << data.s << "\n";

	uintptr_t data_ptr = Serializer::serialize(&data);
	std::cout << " data_ptr: " << data_ptr << "\n";
	std::cout << "    &data: " << &data << "\n";

	Data *copy = Serializer::deserialize(data_ptr);

	std::cout << "After deserialization: \n";
	std::cout << copy->n << "\n";
	std::cout << copy->s << "\n";
}