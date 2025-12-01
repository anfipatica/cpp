#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer(void);
	Serializer(Serializer &serializer);
	Serializer	&operator=(Serializer &serializer);
	~Serializer(void);
};
#endif