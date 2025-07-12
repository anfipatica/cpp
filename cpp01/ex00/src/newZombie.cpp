#include "Zombie.hpp"

/**
 * @brief Creates a Zombie object in *heap*.
 * 
 * It will not be autocatically eliminated once this function ends
 * and since we are returning it as a pointer, we can use it in other functions as well.
 * @param name 
 * @return Zombie* 
 */
Zombie*	newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	return (zombie);
}
