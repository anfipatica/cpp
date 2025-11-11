#include "../inc/RobotomyRequestForm.hpp"

#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	cout << "constructor called for RobotomyRequestForm\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &form):
	AForm(form)
{
	*this = form;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		_target = form._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	cout << "Destructor called for RobotomyRequestForm\n";
}

void	RobotomyRequestForm::execute(void) const
{
	cout << "Bzzzzzzz Zzzzzz .... clink .... zzzzzt ..... CLONK\n";
	int	result = std::rand();
	if (result % 2 == 0)
		cout << ">> 🤖 " << _target << " has been robotomized 🤖 <<\n";
	else
		cout << ">> Robotomization failed on " << _target << " :( <<\n";
}