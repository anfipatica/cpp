#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "../inc/AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(ShrubberyCreationForm &form);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &form);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(const std::string &target);
	void	execute(void) const; //override

private:
	ShrubberyCreationForm(void);
	std::string		_target;
};


#endif
