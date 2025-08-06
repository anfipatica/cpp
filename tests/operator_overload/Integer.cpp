#ifndef INTEGER
# define INTEGER

# include <iostream>

class Integer {
	public:
		Integer(int const n);
		~Integer();

		int getValue(void) const;
		Integer &operator=(Integer const & rhs); // rhs = right hand side, the operand of the right side.
		// Necesito que devuelva una referencia para poder concatenar operaciones tal que: a = b = c = d = e;
		Integer operator+(Integer const & rhs) const;
	private:
		int	_n;
};


Integer::Integer(int const n): _n(n) {
	std::cout << "creando un objeto integer con valor " << _n << std::endl;
};
Integer::~Integer() {
	std::cout << "destructor called with value " << _n << std::endl;
};

int Integer::getValue(void) const
{
	return (_n);
}

Integer &Integer::operator=(Integer const & rhs)
{
	std::cout << "USANDO NUESTRO OPERADOR =============" << std::endl;
	this->_n = rhs.getValue();
	return (*this);
}

Integer Integer::operator+(Integer const & rhs) const
{
	std::cout << "USANDO NUESTRO OPERADOR +++++" << std::endl;
	return (Integer(this->_n + rhs.getValue()));
}

std::ostream &operator<<(std::ostream &os, Integer const & rhs)
{
	os << rhs.getValue();
	return (os);
}

int main(void)
{
	Integer x = Integer(99);
	Integer y = Integer(42);
	Integer z = Integer(24);

	std::cout << "Value of x: " << x << "\n";
	std::cout << "Value of y: " << y << "\n";
	std::cout << "Value of z: " << z << "\n";

	y = 32; // CONVERSIÓN IMPLÍCITA!!
	std::cout << "Value of y: " << y << "\n";
	y = Integer(23);
	std::cout << "Value of y: " << y << "\n";
	z = x + y;
	std::cout << "Value of z: " << z << std::endl;
	return 0;
}










#endif