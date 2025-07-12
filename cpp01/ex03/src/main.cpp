#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

/* int	main(void)
{
	Weapon weapon = Weapon("crude spiked club");

	HumanA federico = HumanA("Federico", weapon);
	federico.attack();
	weapon.setType("some other type of club");
	federico.attack();

	HumanB anarosa = HumanB("Anarosa");
	anarosa.attack();
	anarosa.set_weapon(&weapon);
	anarosa.attack();
	return (0);
} */

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}