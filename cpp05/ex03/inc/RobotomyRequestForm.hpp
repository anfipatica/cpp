#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "../inc/AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(RobotomyRequestForm &form);
	RobotomyRequestForm	&operator=(RobotomyRequestForm &form);
	~RobotomyRequestForm(void);

	RobotomyRequestForm(const std::string &target);
	void	execute(void) const; //override

private:
	RobotomyRequestForm(void);
	std::string		_target;
};


#endif