#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap:public ScavTrap, public FragTrap {
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &scavtrap);
	~DiamondTrap(void);
	DiamondTrap &operator=(const DiamondTrap &scavtrap);

	void	who_am_i(void) const;
	using ScavTrap::attack;
	
private:
	std::string	_name;
	// using FragTrap::_hit_points;
	// using ScavTrap::_energy_points;
	// using FragTrap::_attack_damage;
};

std::ostream &operator<<(std::ostream &os, const DiamondTrap &diam);


#endif