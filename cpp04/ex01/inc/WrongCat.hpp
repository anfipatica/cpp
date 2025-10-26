#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat &animal);
	WrongCat &operator=(const WrongCat &wrong_cat);
	~WrongCat(void);
	void make_sound(void) const;
};

#endif