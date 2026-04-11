#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
#include <iostream>

class RPN
{
public:
	void	insertNumber(std::string &strnum);
	void	sum(void);
	void	subs(void);
	void	mult(void);
	void	div(void);
	void	printResult();
private:
	std::stack<int> _s;
};

#endif