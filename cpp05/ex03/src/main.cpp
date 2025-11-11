#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"
#include <cstdlib>
#include <ctime>

void test_interns(void)
{
	Bureaucrat	filberta("filberta", 1);
	Intern		godofredo;

	AForm	*form1 = godofredo.make_form("robotomy request", "Paulina");
	cout << *form1 << "\n";
	AForm	*form2 = godofredo.make_form("presidential pardon", "Paulina");
	cout << *form2 << "\n";
	AForm	*form3 = godofredo.make_form("shrubbery creation", "park");
	cout << *form3 << "\n";
	AForm	*form4 = godofredo.make_form("give money", "ME"); // da un segfault, meter algún try catch o algo no se pero me piro ya
	cout << *form4 << "\n";

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