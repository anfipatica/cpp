#include "Zombie.hpp"

int	main(void)
{
	int n = 0;

	Zombie *zombie_horde = zombieHorde(n, "Rigoberto");

	for (int i = 0; i < n; i++)
		zombie_horde[i].announce();

	delete [] zombie_horde;
	return (0);
}