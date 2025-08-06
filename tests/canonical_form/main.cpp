#include "Sample.hpp"

int main(void)
{
	Sample sample1;
	Sample sample2(42);
	Sample sample3(sample2);

	std::cout << &sample1 << " - " << sample1 << std::endl;
	std::cout << &sample2 << " - " << sample2 << std::endl;
	std::cout << &sample3 << " - " << sample3 << std::endl;

	sample3 = sample1;
	std::cout << &sample3 << " - " << sample3 << std::endl;
	Sample sample4 = sample1;
	std::cout << &sample4 << " - " << sample4 << std::endl;
	Sample *sample5 = &sample1;
	std::cout << sample5 << " - " << *sample5 << std::endl;

	return 0;
}
