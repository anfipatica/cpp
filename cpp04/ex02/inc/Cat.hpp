#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "../inc/AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
public:
	Cat(void);
	Cat(Cat &cat);
	Cat &operator=(const Cat &cat);
	~Cat(void);
	void make_sound(void) const; //override

	std::string	remember(const unsigned int index) const;
	void	learn(const std::string idea, const unsigned int index);
	void	thinking_thoughtful_thoughts(void) const;

private:
	Brain	*_brain;
};

#endif