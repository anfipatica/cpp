#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);

		void	set_name(std::string name);
		std::string	get_name(void) const;
		void	announce(void);

	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
