#include <iostream>
#include <fstream>
#include <string>
#include <ios>

using namespace std;


int	main(void)
{
	cout << 1 << "Hello" << endl; // \n and flush
	// What is endl?
	/*
		Object? built-in data type? function?
		It is a function. Something like this:
		ostream &endl(ostream &sm) {
			sm.put('\n');
			sm.flush();
			return (sm);
		}
		Ya sabemos que el output operator (<<) es una función miembro de ostream.
		con sobrecarga de parámetros para poder recibir diferentes tipos de datos.
		Recibe una referencia a un objeto ostream, lo modifica y lo devuelve.
		En este caso, como parámetro esperará recibir un puntero a una función que siga el formato de
		la función endl:
		Algo como: ostream &ostream::operator<<(ostream &(*func)(ostream &))
		De hecho, concretamente en el header ostream está definido como:
		    __ostream_type&
    		operator<<(__ostream_type& (*__pf)(__ostream_type&))
    		{
			return __pf(*this);
    		}
		endl tiene un nombre especial, "manipulator", una función que manipula un string. En la librería standard
		hay muchos manipuladores:
		- cout << ends; // pone un '\0'
		- cout << flush;
		- cin >> ws; // read and discard white spaces. ???
		- cout << setw(8) << left << setfill('_') << 99 << endl; // 99______
		- el cambio de base numérica también son manipuladores.
		
		Los diferentes manipuladores se pueden ver aquí: https://cplusplus.com/reference/ios/
		Aunque luego hay otros manipuladores especificos de subclases, por ejemplo, endl es un manipulador de <ostream>
		mientras que ws es de istream.
		iostream no tiene manipuladores propios.
	*/
}