#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>

class Sample {
public:
	Sample(void);							// default constructor.
	Sample(int const n);					// parametized constructor.
	Sample(Sample const &src);				// copy constructor.
	~Sample(void);							// destructor.

//	Sample &operator=(Sample const &src);	// asigment operator.
	int	get_foo(void) const;
	int	get_foo2(void) const;
	int	get_foo3(void) const;
	int	get_a(void) const;
private:
	int _foo;
	int _foo2;
	int _foo3;
	char a;
};

std::ostream &operator<<(std::ostream &stream, Sample const &sample);




#endif