#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

void	test_inventory(void)
{
	Character	*paco = new Character("paco");
	Character	julia("julia");

	Cure		*cure1 = new Cure();
	Cure		*cure2 = new Cure();
	Cure		*cure3 = new Cure();
	Cure		*cure4 = new Cure();
	Cure		*cure5 = new Cure();

	std::cout << "\n :: Paco starts to take all the items... ::\n";
	paco->equip(cure1);
	paco->use(0, *paco);
	paco->equip(cure1);
	paco->equip(cure2);
	paco->equip(cure3);
	paco->equip(cure4);
	paco->equip(cure5);
	std::cout << "\n :: Now julia wants to take something... but paco has it ::\n";
	julia.equip(cure1);
	std::cout << "\n :: Paco decides \"you know what, I have many stuff, I'll leave this behind\"... ::\n";
	paco->unequip(0);
	std::cout << "\n :: Now both can take the item they wanted ::\n";
	paco->equip(cure5);
	julia.equip(cure1);
	delete(paco);
}

void	test_copy(void)
{
	Character	paco("paco");
}

void	clone_test(void)
{

}

int main(void)
{
	//test_inventory();
	//test_copy();
	clone_test();
	return 0;
}
