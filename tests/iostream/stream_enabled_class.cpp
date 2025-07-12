#include <iostream>
#include <string>

using namespace std;

/* Enable streaming for our own classes*/

/*
We are going to override the << and >> operators so We can easily print information
about our class without making a printer function.
*/

struct Dog {
	int age;
	string name;
};

ostream	&operator<<(ostream &sm, const Dog &d)
{
	sm << "My name is " << d.name << " and my age is " << d.age << endl;
	return sm;
}

istream	&operator>>(istream &sm, Dog &d)
{
	sm >> d.age; // if as input we enter something that it's not an int, this function will stop and age will be 0.
	sm >> d.name;
	return sm;
}

int	main()
{
	Dog dog{2, "Bob"};// Universal initialization. https://www.geeksforgeeks.org/cpp/uniform-initialization-in-c/
					  // it is from C++11 so no valid for 42 proyects but useful to know it you ask me.
	cout << dog;
	cin >> dog;
	cout << dog;
}