#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include <cstdlib>
#include <ctime>

void test_interns(void)
{
	Bureaucrat	filberta("filberta", 1);
	Intern		godofredo;

	cout << "\n\n";
	AForm	*form1 = godofredo.make_form("robotomy request", "Paulina");
	cout << *form1 << "\n\n";
	AForm	*form2 = godofredo.make_form("presidential pardon", "Paulina");
	cout << *form2 << "\n\n";
	AForm	*form3 = godofredo.make_form("shrubbery creation", "park");
	cout << *form3 << "\n\n";
	try
	{
		AForm	*form4 = godofredo.make_form("give money", "ME");
		cout << *form4 << "\n";
		delete (form4);
	}
	catch (const AForm::InvalidFormException &e)
	{
		std::cout << e.what() << "\n\n";
	}

	filberta.sign_form(*form1);
	filberta.execute_form(*form1);
	cout << "\n\n";
	delete (form1);
	delete (form2);
	delete (form3);
}

int	main(void)
{
	std::srand(std::time(0));
	test_interns();
	return (0);
}