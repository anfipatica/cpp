#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	check_deep_copy(void)
{
	Cat	cat1;
	cat1.learn("I'm a cat with no deep thoughts", 0);

	Cat	cat2 = cat1;
	cat1.thinking_thoughtful_thoughts();
	cat2.thinking_thoughtful_thoughts();

	cat1.learn("miau miau miau :3", 0);
	cat2.learn("okay maybe just one thought", 99);

	cat1.thinking_thoughtful_thoughts();
	cat2.thinking_thoughtful_thoughts();
}

void	more_copy_test(void)
{
	Animal	*animal = new Cat();
	animal->make_sound();

	Dog	dog1;

	dog1.learn("hello", 0);
	dog1.learn("my", 1);
	dog1.learn("friend", 2);
	Dog	dog2 = dog1;
	Dog	dog3 = dog1;

	dog1.thinking_thoughtful_thoughts();
	dog2.thinking_thoughtful_thoughts();
	dog3.thinking_thoughtful_thoughts();


	std::cout << "\n :::: dog3 learns new stuff ::::\n\n";
	dog3.learn("I am", 3);
	dog3.learn("a", 4);
	dog3.learn("dog", 4);
	dog1.thinking_thoughtful_thoughts();
	dog2.thinking_thoughtful_thoughts();
	dog3.thinking_thoughtful_thoughts();

	std::cout << "\n :::: dog1 copies dog3, he likes his ideas ::::\n\n";
	dog1 = dog3;
	dog1.thinking_thoughtful_thoughts();
	dog2.thinking_thoughtful_thoughts();
	dog3.thinking_thoughtful_thoughts();

	std::cout << "\n :::: dog3 misses the simplicity of dog2's mind ::::\n\n";
	dog3 = dog2;
	dog1.thinking_thoughtful_thoughts();
	dog2.thinking_thoughtful_thoughts();
	dog3.thinking_thoughtful_thoughts();

	delete(animal);
}
void	subject_test(void)
{
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	delete(j);
	delete(i);
}

int main(void)
{
	//check_deep_copy();
	// subject_test();
	more_copy_test();
	return (0);
}
