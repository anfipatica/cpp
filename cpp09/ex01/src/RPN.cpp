#include "RPN.hpp"
#include <exception>
#include <cstdlib>


void	RPN::sum(void)
{
	if (_s.size() < 2)
		throw std::runtime_error("Error: Not enough numbers to operate on.");

	int	n2 = _s.top();
	_s.pop();
	int	n1 = _s.top();
	_s.pop();
	_s.push(n1 + n2);
}

void	RPN::subs(void)
{
	if (_s.size() < 2)
		throw std::runtime_error("Error: Not enough numbers to operate on.");

	int	n2 = _s.top();
	_s.pop();
	int	n1 = _s.top();
	_s.pop();
	_s.push(n1 - n2);
}

void	RPN::mult(void)
{
	if (_s.size() < 2)
		throw std::runtime_error("Error: Not enough numbers to operate on.");

	int	n2 = _s.top();
	_s.pop();
	int	n1 = _s.top();
	_s.pop();
	_s.push(n1 * n2);
}

void	RPN::div(void)
{
	if (_s.size() < 2)
		throw std::runtime_error("Error: Not enough numbers to operate on.");

	int	n2 = _s.top();
	if (n2 == 0)
		throw std::runtime_error("Error: Can't divide by 0!!");
	_s.pop();
	int	n1 = _s.top();
	_s.pop();
	_s.push(n1 / n2);
}

void	RPN::printResult(void)
{
	if (_s.size() > 1)
		std::cerr << "Error: Some number wasn't operated\n"; //!Estoy demasaido cansada como para escribir esto bien.
	else
		std::cout << "RESULT: " << _s.top() << "\n";
}

void	RPN::insertNumber(std::string &strnum)
{
	if (strnum.length() > 1 || isdigit(strnum.at(0)) == false)
		throw std::runtime_error("Error"); //? mejorar quizás los mensajes de error

	_s.push(std::atoi(strnum.c_str()));

}
