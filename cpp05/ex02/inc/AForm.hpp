#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

using std::cout;

class	Bureaucrat;

class	AForm
{
public:
	AForm(void);
	AForm(const AForm &form);
	AForm	&operator=(const AForm &form);
	virtual	~AForm(void);

	AForm(const std::string name, const int sign_grade, const int exec_grade);

	const std::string	&get_name(void) const;
	const bool			&get_signed(void) const;
	const int			&get_sign_grade(void) const;
	const int			&get_exec_grade(void) const;

	void			be_signed(const Bureaucrat &bureaucrat);
	void			execute(const Bureaucrat &bureaucrat) const;
	virtual void	execute(void) const = 0;

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
	class AlreadySignedException: public std::exception
	{
	public:
		const char *what() const throw() //override
		{
			return ("Form already signed");
		}
	};
	class FormNotSignedException: public std::exception
	{
	public:
		const char *what() const throw() //override
		{
			return ("This form has not been signed");
		}
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exec_grade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif