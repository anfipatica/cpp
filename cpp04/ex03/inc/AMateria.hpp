#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class	AMateria
{
public:
	AMateria(const std::string &type);

	const std::string	&get_type(void) const;
	virtual	AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);
protected:
	const std::string	type;
};

#endif