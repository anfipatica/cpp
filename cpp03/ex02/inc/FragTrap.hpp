#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap: public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &scavtrap);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &scavtrap);

	void	attack(const std::string &target);
	void	attack(ClapTrap &target);
	void	high_fives_guys(void);
};

#endif