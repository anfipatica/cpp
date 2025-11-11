#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
	~Bureaucrat(void);

	Bureaucrat(const std::string name, const int grade);

	const std::string	&get_name(void) const;
	const int					&get_grade(void) const;

	void		increase_grade(void);
	void		decrease_grade(void);
	void		sign_form(AForm &form);
	void		execute_form(const AForm &form) const;

	class GradeTooHighException: public std::exception
	{
	public:
		const char* what(void) const throw() //override
		{
			return ("Grade too high!");
		}
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char* what(void) const throw() //override
		{
			return ("Grade too low!!");
		}
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif