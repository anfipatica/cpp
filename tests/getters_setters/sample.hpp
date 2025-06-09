#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
public:
	Sample(void);
	~Sample(void);

	int getFoo(void) const;
	void setFoo(int n);

private:
	int _foo;
};

#endif