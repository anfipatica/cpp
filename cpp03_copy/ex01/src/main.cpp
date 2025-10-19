#include "../inc/ScavTrap.hpp"

int	main(void)
{
	ClapTrap	julia("julia");
	ScavTrap	manolo("manolo");

	manolo.attack(julia);
	julia.attack(manolo);
	manolo.guard_gate();
}