#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure(void);
	Cure(const Cure &ice);
	Cure &operator=(const Cure &ice);

	Cure		*clone(void) const; //override
	void	use(ICharacter &target); //override
private:
	~Cure(void);
};

#endif