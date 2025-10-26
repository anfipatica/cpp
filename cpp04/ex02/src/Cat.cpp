#include "../inc/Cat.hpp"
#include <iostream>

Cat::Cat(void): AAnimal()
{
	std::cout << "Default Cat constructor called\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat &cat): AAnimal()
{
	std::cout << "Copy Cat constructor called\n";
	_brain = new Brain();
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Copy Cat operator called\n";
	if (this != &cat)
	{
		_type = cat._type;
		*_brain = *cat._brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete(_brain);
	std::cout << "Cat destructor called\n";
}

void Cat::make_sound(void) const
{
	std::cout << "≽^•⩊•^≼ MIAU ≽^•⩊•^≼\n";
}

std::string	Cat::remember(const unsigned int index) const
{
	return (_brain->get_idea(index));
}

void	Cat::learn(const std::string idea, const unsigned int index)
{
	_brain->set_idea(idea, index);
}

void	Cat::thinking_thoughtful_thoughts(void) const
{
	std::cout << "cat: " << this << " . cat_brain: " << this->_brain << "\n";
	std::cout << "Let's see what my cat brain has stored inside...\n";
	_brain->print_ideas();
	std::cout << "\n";
}
