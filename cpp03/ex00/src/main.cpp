#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	def;
	ClapTrap	manolo("manolo");

	std::cout << "\n :: manolo starts atacking...\n";
	for (int i = manolo.get_energy_points(); i >= 0; --i)
	{
		std::cout << "(" << i << ") ";
		manolo.attack(def.get_name());
		def.take_damage(manolo.get_attack_damage());
	}

	std::cout << "\n  :: manolo does it's things...\n";
	manolo.take_damage(5);
	manolo.be_repaired(1);
	manolo.take_damage(5);
	manolo.be_repaired(1);

	std::cout << "\n :: DESTRUCTORS\n";

}