#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Toda operación de IO tiene 2 pasos:
1. Formatear la información. --> Se encarga una clase stream.
2. Comunicar la información a dispositivos externos. --> se encarga stream buffer.
*/

int	main(void)
{
	cout << 34 << endl;
	streambuf *pbuf = cout.rdbuf();

	//El constructor de ostream recibe un objeto buffer como parámetro.
	// Recordemos que cout ES UN OBJETO DE OSTREAM. podemos crear nuestro propio
	// ostream llamando al constructor y pasándole el buffer.
	/*
	      explicit
      basic_ostream(__streambuf_type* __sb)
      { this->init(__sb); }
	*/
	ostream myCout(pbuf);
	myCout << 99 << endl;
	myCout << hex << 99 << endl;
	myCout << 15 << endl;
	cout << 99 << endl; // esta instancia de ostream no ha sido modificada. No escribirá en hexadecimal.
	{
		/*
		ofstream of("MyLog.txt");
		cout.rdbuf(of.rdbuf());
		 - Redirecting the stdout to a file.
		 - We need to restore it later! otherwise it will segfault.
		 - Therefore, this is not the best way to do this, we need a temp variable.
		cout << 99 << endl; // this will write 99 into MyLog.txt.
		*/
	}
	{
		ofstream of("MyLog.txt");

		streambuf *original_buf = cout.rdbuf();
		cout.rdbuf(of.rdbuf());
		cout << "Hola holita vecinitos" << endl;
		cout.rdbuf(original_buf);
		cout << "buffer restaurado correctamente" << endl;
		/*
		POR TANTO:
		 - SI RDBUF RECIBE UN BUFFER, MODIFICA EL
		   BUFFER ACTUAL DEL OBJETO OSTREAM QUE LO LLAMA POR EL NUEVO BUFFER.
		 - SI NO RECIBE NINGÚN PARÁMETRO, SIMPLEMENTE DEVUELVE EL BUFFER.
		*/
	}
}