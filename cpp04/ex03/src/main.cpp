#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

void	test_inventory(void)
{
	Character	paco("paco");
	Cure		*cure1 = new Cure();
	Cure		*cure2 = new Cure();
	Cure		*cure3 = new Cure();
	Cure		*cure4 = new Cure();
	Cure		*cure5 = new Cure();

	paco.equip(cure1);
	paco.use(0, paco);
	paco.equip(cure1);
	paco.equip(cure2);
	paco.equip(cure3);
	paco.equip(cure4);
	paco.equip(cure5);
}

int main(void)
{
	test_inventory();

	return 0;
}
