#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class	Bureaucrat;

class	Form
{
public:
	Form(void);
	Form(const Form &form);
	Form	&operator=(const Form &form);
	~Form(void);

	Form(const std::string name, const int sign_grade, const int exec_grade);

	const std::string	&get_name(void) const;
	const bool			&get_signed(void) const;
	const int			&get_sign_grade(void) const;
	const int			&get_exec_grade(void) const;

	void	be_signed(const Bureaucrat &bureaucrat);

	class	GradeTooHighException: public std::exception
	{
		const char *what(void) const throw() //override
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char* what(void) const throw() //override
		{
			return ("Grade too low");
		}
	};
private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exec_grade;
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif