#include <string>
#include <iostream>

class Animal
{
public:
	virtual ~Animal(){std::cout << "animal destructor called\n";};
	virtual std::string	make_sound(void) const {return ("_____");};
};

class Cat: public Animal
{
public:
	~Cat(){std::cout << "cat destructor called\n";};
	std::string	make_sound(void) const {return ("MIAU");};
	int n[1000];
};

void	animal_noise(Animal *animal)
{
	std::cout << animal->make_sound() << std::endl;
	//delete(animal);
}

int	main(void)
{
	Animal	*a = new Animal();
	Animal	*c = new Cat();

	animal_noise(a);
	animal_noise(c);

	delete(a);
	delete(c);
	return (0);
}
