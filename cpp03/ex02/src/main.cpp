#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
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
	FragTrap frank("frank");
	frank.info();

	std::cout << ":: frank avenges its friend carl\n";
	while (sarl.get_hit_points() > 0)
		frank.attack(sarl);

	std::cout << "\n:: sarl tries to guard_gate\n";
	sarl.guard_gate();

	std::cout << "\n:: frank high fives, many many times...\n";
	while (frank.get_energy_points() > 0)
	{
		std::cout << frank.get_energy_points() << " - ";
		frank.high_fives_guys();
	}
	std::cout << frank.get_energy_points() << " - ";
	frank.high_fives_guys();
	std::cout << std::endl;
}