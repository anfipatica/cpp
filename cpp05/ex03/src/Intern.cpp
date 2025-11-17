#include "../inc/Intern.hpp"

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
			cout << "Intern creates " << form_name << "\n";
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
	throw (AForm::InvalidFormException());
}
