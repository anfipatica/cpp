#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	def;
	ClapTrap	manolo("manolo");

	for (int i = manolo.get_energy_points(); i >= 0; --i)
	{
		manolo.attack(def.get_name());
		def.take_damage(manolo.get_attack_damage());
	}

	manolo.take_damage(5);
	manolo.be_repaired(1);
	manolo.take_damage(5);
	manolo.be_repaired(1);
}