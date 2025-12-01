#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data data;
	data.n = 5;

	uintptr_t data_ptr = Serializer::serialize(&data);
	std::cout << "data_ptr: " << data_ptr << "\n";
	std::cout << "   &data: " << &data << "\n";
}