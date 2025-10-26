#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
public:
	Animal(void);
	Animal(Animal &animal);
	Animal &operator=(const Animal &animal);
	virtual ~Animal(void);
	std::string get_type(void) const;
	virtual	void make_sound(void) const;
protected:
	std::string	_type;
};

#endif