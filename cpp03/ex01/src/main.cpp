#include "../inc/ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap carl("carl");
	ScavTrap sarl("sarl");

	carl.info();
	sarl.info();

	std::cout << ":: attacks:\n";
	carl.attack(sarl);
	sarl.attack(carl);

	std::cout << "\n:: carl tries to do stuff but it is dead\n";
	carl.be_repaired(10);
	carl.attack(sarl);

	std::cout << "\n:: A new character appears...\n";
	ScavTrap cooler_sarl("cooler_sarl");
	cooler_sarl.be_repaired(4242);
	cooler_sarl.info();

	std::cout << ":: cooler_sarl avenges its friend carl\n";
	while (sarl.get_hit_points() > 0)
		cooler_sarl.attack(sarl);

	std::cout << "\n:: sarl tries to guard_gate\n";
	sarl.guard_gate();

	std::cout << "\n:: cooler_sarl guards, as it's the only thing left to do\n";
	cooler_sarl.guard_gate();

	std::cout << "\n:: Creating a claptrap copy of cooler_sarl\n";
	ClapTrap copy(cooler_sarl);
	copy.info();

	std::cout << std::endl;
}