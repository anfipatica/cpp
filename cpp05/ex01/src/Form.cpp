#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(void): _name("no_name_form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form default constructor called\n";
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade):
	_name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Constructor called for form " << name << "\n";
	if (_sign_grade > LOWEST_GRADE || _exec_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	else if (_sign_grade < HIGHEST_GRADE || _exec_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &form):
	_name(form._name), _sign_grade(form._sign_grade), _exec_grade(form._exec_grade)
{
	*this = form;
}

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
	{
		_signed = form._signed;
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Destructor called for form " << _name << "\n";
}

const std::string	&Form::get_name(void) const
{
	return (_name);
}

const bool			&Form::get_signed(void) const
{
	return (_signed);
}

const int			&Form::get_sign_grade(void) const
{
	return (_sign_grade);
}

const int			&Form::get_exec_grade(void) const
{
	return (_exec_grade);
}

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.get_name() << ":: signed( " << form.get_signed() << ")\n"
		<< "-> Grade to be signed:   " << form.get_sign_grade() << "\n"
		<< "-> Grade to be executed: " << form.get_exec_grade() << "\n";
}
