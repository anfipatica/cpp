#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

void	test_inventory(void)
{
	Character	paco("paco");
	Cure		*cure1 = new Cure();
	//Cure		*cure2 = new Cure();
	Cure		*cure3 = new Cure();
	Cure		*cure4 = new Cure();
	Cure		*cure5 = new Cure();

	std::cout << "paco en main: " << &paco << "\n";
	std::cout << "111111\n";
	paco.equip(cure1);
	paco.equip(cure1);
	std::cout << "2\n";
	paco.equip(cure3);
	paco.equip(cure4);
	paco.equip(cure5);
}

int main(void)
{
	test_inventory();

	return 0;
}
