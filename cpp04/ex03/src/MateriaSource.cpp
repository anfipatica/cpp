#include "MateriaSource.hpp"
#include <iostream>

void	MateriaSource::learn_materia(AMateria *materia)
{
	for (int i = 0; i < N_MATERIAS; ++i)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = materia->clone();
			return ;
		}
	}
	std::cout << this << " MateriaSource has no space left for new materias\n";
}

AMateria	*MateriaSource::create_materia(std::string const &type)
{
	
}