#include "../inc/DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	carl("carl");
	ScavTrap	slav("slav");
	FragTrap	frank("frank");
	DiamondTrap dio("dio");

	carl.info();
	slav.info();
	frank.info();
	dio.info();

	dio.who_am_i();
}