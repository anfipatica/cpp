#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(void): _name("no_name_form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	cout << "AForm default constructor called\n";
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade):
	_name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	cout << "Constructor called for form " << name << "\n";
	if (_sign_grade > LOWEST_GRADE || _exec_grade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	if (_sign_grade < HIGHEST_GRADE || _exec_grade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &form):
	_name(form._name), _sign_grade(form._sign_grade), _exec_grade(form._exec_grade)
{
	*this = form;
}

AForm	&AForm::operator=(const AForm &form)
{
	if (this != &form)
	{
		_signed = form._signed;
	}
	return (*this);
}

AForm::~AForm(void)
{
	cout << "Destructor called for form " << _name << "\n";
}

const std::string	&AForm::get_name(void) const
{
	return (_name);
}

const bool			&AForm::get_signed(void) const
{
	return (_signed);
}

const int			&AForm::get_sign_grade(void) const
{
	return (_sign_grade);
}

const int			&AForm::get_exec_grade(void) const
{
	return (_exec_grade);
}

void	AForm::be_signed(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() > _sign_grade)
		throw AForm::GradeTooLowException();
	if (_signed == true)
		throw AForm::AlreadySignedException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &bureaucrat) const
{
	if (_signed == false)
		throw AForm::FormNotSignedException();
	if (bureaucrat.get_grade() > _exec_grade)
		throw AForm::GradeTooLowException();
	execute();
}

std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.get_name() << ":: signed(" << form.get_signed() << ")\n"
		<< "-> Grade to be signed:   " << form.get_sign_grade() << "\n"
		<< "-> Grade to be executed: " << form.get_exec_grade();
	return (os);
}
