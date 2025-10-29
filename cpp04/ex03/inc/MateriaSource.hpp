#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# include "AMateria.hpp"

# define N_MATERIAS 4

class MateriaSource: public IMateriaSource
{
public:
	~MateriaSource();
	void learn_materia(AMateria*);
	AMateria* create_materia(std::string const & type);
private:
	AMateria	*_materia[N_MATERIAS];
};

#endif