#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"


void	test_form_constructors(void)
{
	std::cout << "\n\n:: let's test form constructors ::\n\n";
	try
	{
		Form	default_form;
		std::cout << default_form << "\n\n";
		Form	form1("valid_form", 100, 100);
		std::cout << form1 << "\n\n";
		Form	copy_form(form1);
		std::cout << copy_form << "\n\n";
		Form	form2("invalid_form", 200, 100);
		std::cout << form2 << "\n\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Form	form("invalid_form", 100, 250);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	form("invalid_form", -5, 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		form1("very_important_form", 5, 20);
		Form		form2("form2", 100, 100);
		Bureaucrat	lola("lola", 1);
		lola.sign_form(form1);
		form2 = form1;
		std::cout << form1 << "\n\n";

		std::cout << form2 << "\n\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_signing_forms()
{
	std::cout << "\n\n:: let's test signing forms ::\n\n";
	try
	{
		Bureaucrat	low_bureaucrat("low_bureaucrat", 149);
		Bureaucrat	high_bureaucrat("high_bureaucrat", 1);
		Form		low_form("low_form", 150, 150);
		Form		high_form("high_form", 5, 5);
		std::cout << low_bureaucrat << "\n\n";
		std::cout << high_bureaucrat << "\n\n";
		std::cout << low_form << "\n\n";
		std::cout << high_form << "\n\n";

		low_bureaucrat.sign_form(high_form);
		std::cout << high_form << "\n\n";
		high_bureaucrat.sign_form(high_form);
		std::cout << high_form << "\n\n";

		low_bureaucrat.sign_form(low_form);
		std::cout << low_form << "\n\n";
		high_bureaucrat.sign_form(low_form);
		std::cout << low_form << "\n\n";

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
int	main(void)
{
	test_form_constructors();
	test_signing_forms();
	return (0);
}