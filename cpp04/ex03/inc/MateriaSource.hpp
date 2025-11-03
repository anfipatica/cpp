#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# include "AMateria.hpp"

# define N_MATERIAS 4

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource(void);
	~MateriaSource(void);

	void learn_materia(AMateria*);
	AMateria* create_materia(std::string const & type);
private:
	MateriaSource(const MateriaSource &materia_source);
	MateriaSource	&operator=(const MateriaSource &materia_source);

	AMateria	*_materia[N_MATERIAS];
};

#endif