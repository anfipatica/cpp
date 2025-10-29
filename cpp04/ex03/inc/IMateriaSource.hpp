#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learn_materia(AMateria*) = 0;
	virtual AMateria* create_materia(std::string const & type) = 0;
};

#endif