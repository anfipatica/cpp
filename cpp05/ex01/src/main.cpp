#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << "\n\n:: CONSTRUCTOR TEST ::\n\n";
		Bureaucrat	paco;
		Bureaucrat	lola("lola", 2);
		Bureaucrat	ernesto(lola);
		Bureaucrat	error("error", 200);
		std::cout << "Esto no se va a imprimir\n";
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n\n:: INCREMENT TEST ::\n\n";
		Bureaucrat	lola("lola", 2);
		std::cout << lola;
		lola.increase_grade();
		std::cout << lola;
		lola.increase_grade();
		std::cout << lola;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n\n:: DECREMENT TEST ::\n\n";
		Bureaucrat	lola("lola", 149);
		std::cout << lola;
		lola.decrease_grade();
		std::cout << lola;
		lola.decrease_grade();
		std::cout << lola;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}