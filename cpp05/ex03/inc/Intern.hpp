#ifndef INTERN_HPP
# define INTERN_HPP

# include "../inc/AForm.hpp"

class	Intern
{
public:
	Intern(void);
	Intern(const Intern &intern);
	Intern	&operator=(const Intern &intern);
	~Intern(void);

	AForm	*make_form(const std::string &form_name, std::string target);

};
#endif