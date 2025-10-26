#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "../inc/AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
public:
	Dog(void);
	Dog(Dog &dog);
	Dog &operator=(const Dog &dog);
	~Dog(void);
	void make_sound(void) const; //override

	std::string	remember(const unsigned int index) const;
	void	learn(const std::string idea, const unsigned int index);
	void	thinking_thoughtful_thoughts(void) const;

private:
	Brain	*_brain;
};

#endif