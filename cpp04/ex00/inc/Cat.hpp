#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat(void);
	Cat(Cat &animal);
	Cat &operator=(const Cat &animal);
	~Cat(void);
	void make_sound(void) const override;
};

#endif