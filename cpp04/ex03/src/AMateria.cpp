#include "AMateria.hpp"
#include "ItemList.hpp"

#include <iostream>

ItemList		*AMateria::_all_items = NULL;

AMateria::AMateria(void) {}

AMateria::AMateria(const AMateria &amateria) {(void)amateria;}

AMateria &AMateria::operator=(const AMateria &amateria)
	{(void)amateria; return (*this);}


/**
 * @brief The function that will delete the ItemList and all the created materias.
 * This function will be called from ~MateriaSource and ~Character.
 * It cannot be called inside ~Amateria since inside the function we delete
 * AMateria, which would result in a recursive loop.
 */
void	AMateria::clean_items_list(void)
{
	ItemList	*aux = _all_items;

	while (_all_items)
	{
		aux = _all_items->get_next();
		delete(_all_items);
		_all_items = aux;
	}
}
AMateria::~AMateria(void)
{
}

/**
 * @brief To handle materias, anytime a materia is created it is inserted in
 * ItemList, a static list which head is _all_items, and contains all the
 * materias created wether equiped or not.
 */
AMateria::AMateria(const std::string &type): _type(type), _equipable(true)
{
	if (_all_items == NULL)
		_all_items = new ItemList(*this);
	_all_items->insert_element(this);
}

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