#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>

int main(void)
{
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();

	WrongAnimal	*wrong_animal = new WrongAnimal();
	WrongAnimal	*wrong_cat = new WrongCat();
	WrongCat	*real_wrong_cat = new WrongCat();

	std::cout << "\n:: animal\n";
	std::cout << animal->get_type() << "\n";
	animal->make_sound();

	std::cout << "\n:: animal-cat\n";
	std::cout << cat->get_type() << "\n";
	cat->make_sound();

	std::cout << "\n:: animal-dog\n";
	std::cout << dog->get_type() << "\n";
	dog->make_sound();

	std::cout << "\n:: wrong_animal\n";
	std::cout << wrong_animal->get_type() << "\n";
	wrong_animal->make_sound();

	std::cout << "\n:: wrong_animal-wrong_cat\n";
	std::cout << wrong_cat->get_type() << "\n";
	wrong_cat->make_sound();

	std::cout << "\n:: wrong_cat-wrong_cat\n";
	std::cout << real_wrong_cat->get_type() << "\n";
	real_wrong_cat->make_sound();

	std::cout << "\n";
	delete(animal);
	delete(dog);
	delete(cat);
	delete(wrong_animal);
	delete(wrong_cat);
	delete(real_wrong_cat);
	return (0);
}
