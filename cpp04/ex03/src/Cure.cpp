#include "Cure.hpp"

#include <iostream>

Cure::Cure(void): AMateria("cure") {
}

Cure::Cure(const Cure &cure): AMateria("cure") {(void)cure;}

Cure &Cure::operator=(const Cure &cure) {(void)cure; return (*this);}

Cure::~Cure(void) {}

Cure	*Cure::clone(void) const
{
	Cure *cure = new Cure(*this);
	return (cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.get_name() << "'s wounds *\n";
}
