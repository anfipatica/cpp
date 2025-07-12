#include "Zombie.hpp"

/**
 * @brief Will create a zombie object *in stack*.
 * 
 * 
 *  This means it's scope it's the variable it's created in,
 *  once this function ends, this zombie will automatically
 *  be deconstructed.
 * 
 * @param name 
 */
void	randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}