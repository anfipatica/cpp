#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "../inc/AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(PresidentialPardonForm &form);
	PresidentialPardonForm	&operator=(PresidentialPardonForm &form);
	~PresidentialPardonForm(void);

	PresidentialPardonForm(const std::string &target);
	void	execute(void) const; //override

private:
	PresidentialPardonForm(void);
	std::string		_target;
};


#endif