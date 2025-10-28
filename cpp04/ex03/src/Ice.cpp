#include "Ice.hpp"

#include <iostream>

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(const Ice &ice): AMateria("ice") {(void)ice;}

Ice &Ice::operator=(const Ice &ice) {(void)ice; return (*this);}

Ice::~Ice(void) {}

Ice	*Ice::clone(void) const
{
	Ice *ice = new Ice(*this);
	return (ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.get_name() << " *\n";
}
