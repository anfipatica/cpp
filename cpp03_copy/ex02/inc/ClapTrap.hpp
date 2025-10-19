#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const std::string name, const int hit, const int energy, const int attack);
	ClapTrap(const ClapTrap &clap);
	ClapTrap &operator=(const ClapTrap &clap);
	~ClapTrap(void);

	std::string	get_name(void) const;
	int			get_energy_points(void) const;
	int			get_attack_damage(void) const;

	void	attack(const std::string &target);
	void	attack(ClapTrap &target);
	void	take_damage(unsigned int amount);
	void	be_repaired(unsigned int amount);

protected:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;
};

#endif