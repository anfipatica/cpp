#include "Sample.hpp"

/* default constructor */
// Initialices an object with a default value
Sample::Sample(void): _foo(0), _foo2(0), _foo3(0), a('a')
{}

/* Parametrized constructor */
// Initialices an object with the values received as parameters.
Sample::Sample(int const n): _foo(n)
{}

Sample::Sample(Sample const &src)
{
	*this = src;
}

// Sample &Sample::operator=(Sample const &src)
// {
// 	if (this != &src)
// 		_foo = src.get_foo();
// 	return (*this);
// }

/* Destructor */
Sample::~Sample(void)
{};

int	Sample::get_foo(void) const
{
	return (_foo);
}

int	Sample::get_foo2(void) const
{
	return (_foo2);
}
int	Sample::get_foo3(void) const
{
	return (_foo3);
}
int	Sample::get_a(void) const
{
	return (a);
}

std::ostream &operator<<(std::ostream &stream, Sample const &sample)
{
	stream << sample.get_foo() << " " << sample.get_foo2() 
			<< " " << sample.get_foo3() << " " << sample.get_a();
	return (stream);
}