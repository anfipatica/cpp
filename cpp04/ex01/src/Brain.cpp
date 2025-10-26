#include "../inc/Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called\n";
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy assignment operator called\n";
	if (this != &brain)
	{
		for (int i = 0; i < _number_of_ideas; ++i)
			_ideas[i] = brain._ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}


std::string	Brain::get_idea(const unsigned int index) const
{
	if (index >= _number_of_ideas)
		return ("Invalid index");
	else
		return (_ideas[index]);
}

void	Brain::set_idea(const std::string idea, const unsigned int index)
{
	if (index >= _number_of_ideas)
		std::cerr << "Index out of range\n";
	else
		_ideas[index] = idea;
}

void	Brain::print_ideas(void) const
{
	for (int i = 0; i < _number_of_ideas; ++i)
	{
		if (_ideas[i].empty() == false)
			std::cout << i << ". " << _ideas[i] << "\n";
	}
}
