# include <iostream>

template <typename T = float>
class Vertex
{
public:
	Vertex(const T &x, const T &y, const T &z): _x(x), _y(y), _z(z) {};
	~Vertex(void) {};

	const T	&get_x(void) const { return (_x);};
	const T	&get_y(void) const { return (_y);};
	const T	&get_z(void) const { return (_z);};

private:
	const T	_x;
	const T	_y;
	const T	_z;

	Vertex(void);
};

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Vertex<T> &vertex)
{
	// buah me he perdido un poco creo. Ha dicho que esto es un template dentro de otro template
}

int main(void)
{
	Vertex<float> vertex(1,1,1);
	return 0;
}
