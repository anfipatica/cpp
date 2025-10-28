#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

# include "ItemList.hpp"

# define N_ITEMS 4


class	Character: public ICharacter
{
public:
	Character(void);
	Character(std::string name);
	Character(const Character &character);
	Character &operator=(const Character &character);
	~Character();

	const std::string	&get_name() const; //override

	void	equip(AMateria *m); //override
	void	unequip(int idx); //override
	void	use(int idx, ICharacter &target); //override

private:
	const std::string		_name;
	AMateria		*_items[4];
	static ItemList	_all_items;
};

#endif