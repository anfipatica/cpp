#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap{
public:
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &clap);
	ClapTrap &operator=(const ClapTrap &clap);
	~ClapTrap(void);

	std::string		get_name(void) const;
	int				get_hit_points(void) const;
	int				get_energy_points(void) const;
	int				get_attack_damage(void) const;

	void			attack(const std::string &target);
	void			take_damage(unsigned int amount);
	void			be_repaired(unsigned int amount);

private:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
};

#endif