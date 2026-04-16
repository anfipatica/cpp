#include "PMergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Invalid arguments\n";
		return (1);
	}
	PMergeMe	pm;

	try
	{
		pm.fillContainer(&argv[1]);
		pm.sort(1);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
}
