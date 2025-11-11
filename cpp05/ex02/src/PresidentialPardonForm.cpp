#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	cout << "constructor called for PresidentialPardonForm\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &form):
	AForm(form)
{
	*this = form;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		_target = form._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	cout << "Destructor called for PresidentialPardonForm\n";
}

void	PresidentialPardonForm::execute(void) const
{
	cout << "\n >> " << _target << " has been pardoned by Zaphod Beeblebrox <<\n\n";
}