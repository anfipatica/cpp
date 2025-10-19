#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main(void)
{
	FragTrap	dummy("dummy");

	ClapTrap	carl("carl");
	ScavTrap	sarl("sarl");
	FragTrap	farl("farl");


	carl.attack(dummy);
	sarl.attack(dummy);
	farl.attack(dummy);

	dummy.be_repaired(100);
	farl.attack(carl);
	farl.high_fives_guys();
}