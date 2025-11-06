#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("no_name"), _grade(150)
{
	std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	std::cout << "Constructor called for bureaucrat " << name << "\n";
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat._name)
{
	std::cout << "Copy constructor called for bureaucrat " << _name << "\n";
	*this = bureaucrat;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for bureaucrat " << _name << "\n";
}

const std::string	&Bureaucrat::get_name(void) const
{
	return (_name);
}

const int	&Bureaucrat::get_grade(void) const
{
	return (_grade);
}

void	Bureaucrat::increase_grade(void)
{
	try
	{
		if (_grade - 1 < HIGHEST_GRADE)
			throw Bureaucrat::GradeTooHighException();
		--_grade;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << "\n";
	}
}

void	Bureaucrat::decrease_grade(void)
{
	try
	{
		if (_grade + 1 > LOWEST_GRADE)
			throw Bureaucrat::GradeTooLowException();
		++_grade;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "\n";
	}
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.get_name() << ", bureaucrat grade "
		<< bureaucrat.get_grade() << "\n";
	return (os);
}

