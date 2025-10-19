#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "../inc/ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavtrap);
	~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &scavtrap);

	void	attack(const std::string &target);
	void	attack(ClapTrap &target);
	void	guard_gate(void);
};

std::ostream &operator<<(std::ostream &os, const ScavTrap &scav);

#endif