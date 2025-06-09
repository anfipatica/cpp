#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
public:
	Sample(void);
	~Sample(void);

	int getInstanceFoo(void) const;
	void setInstanceFoo(int n);
	static int getClassFoo(void);
	static void setClassFoo(int n);
private:
	int _instanceFoo = 0;
	static int _classFoo;
};

#endif