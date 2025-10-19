#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// CLAPTRAP ::  10,  10,  0;
// SCAVTRAP :: 100,  50, 20;
// FRAGTRAP :: 100, 100, 30;
// DIAMOND  :: 100,  50, 30;

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &scavtrap);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &scavtrap);

	void	attack(const std::string &target);
	void	attack(ClapTrap &target);
	void	high_fives_guys(void);

protected:
	static const int	_base_hit_points;
	static const int	_base_energy_points;
	static const int	_base_attack_damage;
};

std::ostream &operator<<(std::ostream &os, const FragTrap &frag);

#endif
