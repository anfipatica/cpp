#include <array>
#include <iostream>

int	main(void)
{
	std::array<int, 10> b;

	std::cout << b.size() << std::endl;
	std::cout << &b << std::endl;
	std::cout << b.data() << std::endl;

	for (int i = 0; i < 10; i++)
		b[i] = i;

	for (int i = 0; i < b.size(); i++)
		b[i] = i;

	for (std::array<int, 10>::iterator i = b.begin(); i != b.end(); ++i)
		*i = something();
}