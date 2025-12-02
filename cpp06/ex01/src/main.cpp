#include "../inc/Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data data;
	data.n = 5;

	uintptr_t serialized_data = Serializer::serialize(&data);
	std::cout << "serialized_data: " << serialized_data << "\n";
	Data *copy = Serializer::deserialize(serialized_data);
	std::cout << copy->n << "\n";
	std::cout << "   &data: " << &data << "\n";
	std::cout << "    copy: " << copy << "\n";

	char	a[6] = "abcde";
	uintptr_t serialized_char = reinterpret_cast<uintptr_t>(&a);
	std::cout << serialized_char << "\n";
	std::cout << &a << "\n";
	serialized_char += 1;
	char *b = reinterpret_cast<char *>(serialized_char);
	std::cout << b << "\n";
}