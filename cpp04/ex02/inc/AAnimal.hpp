#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal &animal);
	AAnimal &operator=(const AAnimal &animal);
	virtual ~AAnimal(void);
	std::string get_type(void) const;
	virtual	void make_sound(void) const = 0;

protected:
	std::string	_type;
};

#endif