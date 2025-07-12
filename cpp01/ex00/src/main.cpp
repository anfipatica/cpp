#include "Zombie.hpp"
#include <string>

int	main(void)
{
	Zombie stack_zombie = Zombie("Federico");
	randomChump("zombie_random_1");
	randomChump("zombie_random_2");
	randomChump("zombie_random_3");
	Zombie *zombie1 = newZombie("Manolo");
	zombie1->announce();
	stack_zombie.announce();

	delete(zombie1);
	return (0);
}