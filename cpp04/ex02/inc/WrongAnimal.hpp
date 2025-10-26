#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal &wrong_animal);
	WrongAnimal &operator=(const WrongAnimal &wrong_animal);
	~WrongAnimal(void);
	std::string get_type(void) const;
	void make_sound(void) const;
protected:
	std::string	_type;
};

#endif