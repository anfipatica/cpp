#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	cout << 34 << endl; // 34.
	cout.setf(ios::oct, ios::basefield);
	cout << 34 << endl; // 42.
	cout.setf(ios::showbase);
	cout << 34 << endl; // 042.
	cout.setf(ios::hex, ios::basefield);
	cout << 34 << endl; //0x22
	cout.unsetf(ios::showbase);
	cout << 34 << endl; //22
	cout.unsetf(ios::hex);
	cout << 34 << endl; //34.

	//podemos crear un ancho predeterminado y modificar la alineación del texto
	cout.width(10);
	cout << "hola" << endl; //      hola
	cout.width(10);
	cout.setf(ios::left, ios::adjustfield);
	cout << "hola" << std::endl; //hola      
	/* Lo que dice ios_base.h
	    /// A mask of left|right|internal.  Useful for the 2-arg form of @c setf.
    static const fmtflags adjustfield = _S_adjustfield;

    /// A mask of dec|oct|hex.  Useful for the 2-arg form of @c setf.
    static const fmtflags basefield =   _S_basefield;

    /// A mask of scientific|fixed.  Useful for the 2-arg form of @c setf.
    static const fmtflags floatfield =  _S_floatfield
	*/

	//también podemos cambiar el formato del input:

	int	i;

	cin.setf(ios::hex, ios::basefield);
	cin >> i; // >> f
	cout << i << endl; // << 15
	cin.setf(ios::dec, ios::basefield);
	cout.setf(ios::dec, ios::basefield);

	//Member functions for unformatted IO:
	//input:
	string buffer;

	ifstream inf("my_log.txt");
	char	buf[200];
	inf.get(buf, 80); // lee hasta un máximo de 80 caracteres o hasta encontrar el salto de línea.
	cout << buf << endl;
	inf.seekg(ios::beg);
	getline(inf, buffer);
	cout << buffer << endl;
	inf.seekg(ios::beg);
	inf.read(buf, 80);
	cout << buf << endl;
	inf.ignore(3);
	cout << "................." << endl;
	cout << inf.peek() << endl;

	return 0;
}
