#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice(void);
	Ice(const Ice &ice);
	Ice &operator=(const Ice &ice);

	Ice		*clone(void) const; //override
	void	use(ICharacter &target); //override
private:
	~Ice(void);

};

#endif