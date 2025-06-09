#ifndef SAMPLE1_HPP
# define SAMPLE1_HPP

#include <iostream>

class Sample1 {
public:
	float const pi;
	int			qd;

	Sample1(float const f);
	~Sample1(void);

	void bar(void) const;
};

#endif