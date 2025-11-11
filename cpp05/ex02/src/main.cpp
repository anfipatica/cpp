#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>

void test_executing_forms(void)
{
	cout << "\n\n:: let's test executing and signing forms ::\n\n";
	try
	{
		PresidentialPardonForm	pform("Evarista");
		RobotomyRequestForm		rform("Pancracio");
		ShrubberyCreationForm	sform("home");

		Bureaucrat b1("b1", 1);
		Bureaucrat b150("b150", 150);
		Bureaucrat b42("b42", 42);

		cout << "\n------------------------------------------\n";
		b150.sign_form(sform);
		b1.execute_form(sform);
		b150.increase_grade();
		b150.increase_grade();
		b150.increase_grade();
		b150.increase_grade();
		b150.increase_grade();
		cout << b150 << "\n";
		b150.sign_form(sform);
		b150.execute_form(sform);
		b1.execute_form(sform);

		cout << "\n------------------------------------------\n";

		b150.sign_form(rform);
		b1.execute_form(rform);
		b42.sign_form(rform);
		b150.execute_form(rform);
		b42.execute_form(rform);
		b42.decrease_grade();
		b42.decrease_grade();
		b42.decrease_grade();
		b42.decrease_grade();
		cout << b42 << "\n";
		b42.execute_form(rform);
		b42.increase_grade();
		cout << b42 << "\n";
		b42.execute_form(rform);
		b1.execute_form(rform);

		cout << "\n------------------------------------------\n";

		b1.sign_form(pform);
		b42.execute_form(pform);
		b1.execute_form(pform);
		cout << "\n------------------------------------------\n";
	}
	catch (const std::exception &e)
	{
		cout << e.what() << "\n";
	}
}

void	test_create_forms(void)
{
	std::cout << "\n\n:: let's test form constructors ::\n\n";
	try
	{
		RobotomyRequestForm	rform("Federico");
		RobotomyRequestForm	rform_copy(rform);
		RobotomyRequestForm	rform_copy2("Hermenegildo");
		Bureaucrat			paco("paco", 1);

		paco.sign_form(rform);
		paco.sign_form(rform_copy);
		paco.sign_form(rform_copy2);

		paco.execute_form(rform);
		paco.execute_form(rform_copy);
		paco.execute_form(rform_copy2);

		rform_copy = rform_copy2;
		rform_copy2 = rform;

		paco.execute_form(rform);
		paco.execute_form(rform_copy);
		paco.execute_form(rform_copy2);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << "\n";
	}
}

int	main(void)
{
	std::srand(std::time(0));
	test_create_forms();
	test_executing_forms();
	return (0);
}