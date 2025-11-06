#include <stdexcept>
#include <iostream>
void	test(void)
{
	try
	{
		int i = -1;
		if (i < 0)
		{
			throw std::exception();
			std::cout << "vaya a ver si llegamos a este línea\n"; //NO LLEGAMOS
		}
		else
			std::cout << "oleee todo ok\n";
		std::cout << "O a esta otra lelelele\n"; // NI AQUIIIIII

	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

class test_exception: public std::exception
{
public:
	virtual	const char* what() const throw()
	{
		return ("Problem exists between keyboard and chair");
	}
};

void	test3(void)
{
	int i = 1;
	if (i < 0)
		throw std::exception();
	else if (i > 0)
		throw test_exception();
}

void	test2(void)
{
	try
	{
		test3();
	}
	catch(test_exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}

int	main(void)
{
	test2();
}