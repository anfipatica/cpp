#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

#include <iostream>


int main(void)
{
	Cat	cat;
	Dog	dog;
	//AAnimal animal;

	AAnimal	*animal_cat = new Cat();
	AAnimal	*animal_dog = new Dog();
	//AAnimal	*animal = new AAnimal();

	cat.make_sound();
	dog.make_sound();
	animal_cat->make_sound();
	animal_dog->make_sound();

	delete(animal_cat);
	delete(animal_dog);
	return (0);
}
