#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "./FragTrap.hpp"
# include "./ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
public:
	DiamondTrap(void);
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &clap);
	DiamondTrap &operator=(const DiamondTrap &clap);
	~DiamondTrap(void);

	using	ScavTrap::attack;
	void		who_am_i(void) const;
private:
	std::string	_name;
};

#endif