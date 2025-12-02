#include <iostream>

//?UPCAST_DOWNCAST;

/* class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

int	main(void)
{
	Child1	a;					// Reference value;
	Parent	*b = &a;			// Implicit reinterpretation cast;
	Parent	*c = (Parent *)&a;	// Explicit reinterpretation cast;

	Parent	*d = &a;			// Implicit upcast;
	//Child1	*e = d;				// Implicit downcast, NO SE PUEDE HACER;
	Child2	*f = (Child2 *)d;	// Explicit downcast.
} */

//? STATIC_CAST;

/*
	-> Static cast: will allow us to make a certain number of conversions.
*/

/* class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

class Unrelated	{};

int	main(void)
{
	Child1		a;					// Reference value;
	Parent		*b = &a;			// Implicit reinterpretation cast;
	Parent		*c = (Parent *)&a;	// Explicit reinterpretation cast;

	Parent		*d = &a;			// Implicit upcast;
	//Child1	*e = d;				// Implicit downcast, NO SE PUEDE HACER;
	Child2		*f = (Child2 *)d;	// Explicit downcast.
	Unrelated	*g = (Unrelated *)d;
	Unrelated	*h = static_cast<Unrelated *>(d);
	Child2		*i = static_cast<Child2	*>(d);
	Child1		*j = static_cast<Child1	*>(i);
	// El static_cast se asegura que la conversión sea de la misma jerarquía
}

int	main(void)
{
	int		a = 42;

	double	b = a;
	int		c = b;
	int		d = static_cast<int>(b);
} */

//? DYNAMIC_CAST;

/*
	Es el único casteo que sucede en tiempo de ejecución y no de compilación.
	Por lo que el programa podrá compilar pero en ejecución podrá fallar, por lo
	que habrá que tener en cuenta esto en el código.

	Además, sólo funcionará con instancias polimórficas. A menos una de las funciones miembros
	tendrá que ser virtual.
*/
//! Buscar info del rrti -> run-time type information
/*
	El usar una función virtual lo que hace es activar el rrti, que contiene mucha informaciñon
	útil para que el dynamic_cast compruebe si el casteo es posible.
	DYNAMIC_CAST SE USA solo para downcast después de comprobar si es o no posible.

	* Usa dynamic_cast cuando necesites seguridad en conversiones polimórficas, 
	* y static_cast cuando estés absolutamente seguro de que la conversión es válida.
*/

/* class Parent {	public: virtual ~Parent(void){};};
class Child1: public Parent{};
class Child2: public Parent{};

int	main(void)
{
	Child1	a;
	Parent	*b = &a;

	Child1	*c = dynamic_cast<Child1 *>(b);
	if (c == NULL)
		std::cout << "Conversion is NOT OK\n";
	else
		std::cout << "Conversion is OK\n";
	
	try
	{
		Child2	&d = dynamic_cast<Child2 &>(*b); // Comprueba si b es realmente Parent.
		// Comprueba que b pese a ser un Parent se construye en base a Child1, ergo
		// El casteo de Child1 a Child2 no es válido.
		std::cout << "Conversion is OK\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Child2	&d = static_cast<Child2 &>(*b); // No comprueba si b es realmente un Parent, asume que si
		// Y mientras jerárquicamente la conversión sea válida todo ok.
		std::cout << "Conversion is OK\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
} */

//? REINTERPRET_CAST
/*
	Permite reinterpretar. Es el más abierto, podremos reinterpretar cualquier dirección como
	cualquier otra.
 */

int	main(void)
{
	float	a = 420.042f;
	//int		*b = static_cast<int *>(&a);
	int		*c = reinterpret_cast<int *>(&a);
	int		*e = (int *)&a;

	std::cout << a << "\n";
	std::cout << *c << "\n";
	std::cout << *e << "\n";
}

//? CONST_CAST

/* int	main(void)
{
	const int	a = 42;
	int			*b = (int *)&a;
	int			*c = const_cast<int *>(&a); // más especifico cuando lo que queremos es quitar
	// el const del valor original en nuestra nueva variable. Mejor no usarlo a menos
	// que podamos justificar bien pq, pero esto ya lo sabiamos jejeje.
	*b = 45;
	*c = 67;
} */

//? CAST_OPERATORS
/* 
class	Foo {
public:
	Foo(float const v): _v(v){};
	float	getv(void) { return (_v);};

	operator float() { return (_v);};
	operator int() { return (static_cast<int>(_v));};
private:
	float	_v;
};

int	main(void)
{
	Foo		foo(5.2f);
	float	f = foo;
	int		n = foo;
	Foo		t = 99;

	std::cout << n << "\n";
	std::cout << f << "\n";
	std::cout << t.getv() << "\n";
} */

class father {};
class son: public father {
	int a[1000];
};


// int	main(void)
// {
// 	const int a = 5;
// 	int b = a;
// 	int *c = (int*)&a;
// 	int *d = const_cast<int*>(&a);
// 	int *d = static_cast<int*>(&a);
// 	int *e = &b;

// 	double a = 5.065;
// 	int b = a;
// 	int *c = dynamic_cast<int*>(a);

// 	return (0);
// }