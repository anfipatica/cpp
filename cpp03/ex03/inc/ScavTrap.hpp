#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

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

protected:
	static const int _base_hit_points;
	static const int _base_energy_points;
	static const int _base_attack_damage;
};

#endif