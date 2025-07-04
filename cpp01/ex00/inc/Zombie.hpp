#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);

		Zombie*		newZombie(std::string name);
		void		randomChump(std::string name);

		void		set_name(std::string name);
		std::string	get_name(void) const;

		void		announce(void);

	private:
		std::string	_name;
};

#endif
