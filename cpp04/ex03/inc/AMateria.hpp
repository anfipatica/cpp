#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"
class	AMateria
{
public:
	AMateria(const std::string &type);
	virtual ~AMateria(void);
	
	const std::string	&get_type(void) const;
	virtual	AMateria	*clone(void) const = 0;
	virtual	void		use(ICharacter &target) = 0; //!en el subject no tiene el = 0

	void				set_equipable(bool state);
	bool				get_equipable(void) const;

protected:
	const std::string	_type;
	bool				_equipable;
private:
	AMateria(void);
	AMateria(const AMateria &amateria);
	AMateria &operator=(const AMateria &amateria);
};

#endif