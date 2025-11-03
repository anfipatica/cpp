#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < N_MATERIAS; ++i)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materia_source)
{(void)materia_source;}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materia_source)
{(void)materia_source; return (*this);}

MateriaSource::~MateriaSource(void) {
	AMateria::clean_items_list();
}


void	MateriaSource::learn_materia(AMateria *materia)
{
	for (int i = 0; i < N_MATERIAS; ++i)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = materia;
			return ;
		}
	}
	std::cout << this << " MateriaSource has no space left for new materias\n";
}

AMateria	*MateriaSource::create_materia(std::string const &type)
{
	for (int i = 0; i < N_MATERIAS; ++i)
	{
		if (_materia[i]->get_type() == type)
			return (_materia[i]->clone());
	}
	std::cout << "No material found with type " << type << ".\n";
	return (0);
}