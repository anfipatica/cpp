#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(void) {}

AMateria::AMateria(const AMateria &amateria) {(void)amateria;}

AMateria &AMateria::operator=(const AMateria &amateria) {(void)amateria; return (*this);}

AMateria::~AMateria(void) {}

AMateria::AMateria(const std::string &type): _type(type), _equipable(true) {}

const std::string	&AMateria::get_type(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target) {(void)target;}


bool	AMateria::get_equipable(void) const
{
	return (_equipable);
}

void	AMateria::set_equipable(bool state)
{
	_equipable = state;
}