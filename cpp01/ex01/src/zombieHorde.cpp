#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie *zombie = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		std::ostringstream ss;
		ss << name << "_" << i;
		zombie[i].set_name(ss.str());
	}
	return (zombie);
}