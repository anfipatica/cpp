#include "../inc/Intern.hpp"

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"


Intern::Intern(void) {}

Intern::Intern(const Intern &intern) {(void)intern;}

Intern	&Intern::operator=(const Intern &intern) {(void)intern; return (*this);}
Intern::~Intern(void) {}

AForm	*Intern::make_form(const std::string &form_name, std::string target)
{
	static std::string available_forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i)
	{
		if (form_name == available_forms[i])
		{
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	//?Quizás molaría que saltara una excepción??? no estoy segura mi pana.
	return (NULL);
}
