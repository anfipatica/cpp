#include "../inc/DiamondTrap.hpp"
#include "iostream"

// CLAPTRAP ::  10,  10,  0;
// SCAVTRAP :: 100,  50, 20;
// FRAGTRAP :: 100, 100, 30;
// DIAMOND  :: 100,  50, 30;

int	main(void)
{
	ClapTrap c("c");
	ScavTrap s("s");
	FragTrap f("f");
	DiamondTrap d("d");

	std::cout << c << "\n";
	std::cout << s << "\n";
	std::cout << f << "\n";
	std::cout << d << "\n";

}