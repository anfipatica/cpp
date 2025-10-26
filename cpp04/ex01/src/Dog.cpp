#include "../inc/Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal()
{
	std::cout << "Default Dog constructor called\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog &dog): Animal()
{
	std::cout << "Copy Dog constructor called\n";
	_brain = new Brain();
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Copy Dog operator called\n";
	if (this != &dog)
	{
		_type = dog._type;
		*_brain = *dog._brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete(_brain);
	std::cout << "Dog destructor called\n";
}

void Dog::make_sound(void) const
{
	std::cout << "U・ᴥ・U WOOF U・ᴥ・U\n";
}

std::string	Dog::remember(const unsigned int index) const
{
	return (_brain->get_idea(index));
}

void	Dog::learn(const std::string idea, const unsigned int index)
{
	_brain->set_idea(idea, index);
}

void	Dog::thinking_thoughtful_thoughts(void) const
{
	std::cout << "dog: " << this << " . dog_brain: " << this->_brain << "\n";
	std::cout << "Let's see what my dog brain has stored inside...\n";
	_brain->print_ideas();
	std::cout << "\n";
}