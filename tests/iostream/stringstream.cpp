#include <iostream>
#include <sstream>

using namespace std;

int	main(void)
{
	stringstream ss; // stream without IO channels, it does not make IO operations.
	// It can read and write data from a string. It's treating a string
	// as a file. ¿Why do that?
	//	- To reuse the formatting functions of a stream to process a string.
	/*
		Cuando hemos querido pasar de un int a un string, hemos usado string stream:
			std::stringstream ss;
			ss << i + 1;
			format_field(ss.str());
	*/
	ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89 << endl;
	cout << ss.str(); // 89 Hex: 59 Oct: 131

	int	a, b, c;
	string s1;
	ss >> hex >> a; // this is formatted input. It works token by token.
					// tokens are separated by spaces, tabs and new lines.
					// therefore, since ss is "89 Hex: 59 Oct: 131", only 89 will be
					// sent to hex.
	cout << a << endl; // 137. ss >> hex >> a; received "89" as hexadecimal, therefore a holds
					   // its decimal value.
	/*
		ss << hex << 15; -> will transform everything after hex into hexadecimal format.
		ss >> hex >> a; -> Will think everything it received was in hexadecimal, therefore it will
			transform it into decimal unless specified otherwise with:
			cout << hex << a;
	*/
	cout << hex << a << dec << endl; // 89
	ss >> s1;
	cout << s1 << endl; // "Hex:" As with files, you kinda read the stream with a cursor, everytime you
				// read one token, the cursor moves to the next one.
	ss >> dec >> b;
	cout << b << endl; // 59
	ss.ignore(5); // will simply move the cursor of ss. We will skip this:
				  //	Already read: [89 Hex: 59]
				  //	Ignored: (Oct: )
				  //	Rest: 131.
	ss >> oct >> c;
	cout << c << endl; // 89
	// to sumarize, string stream provides powerful tools to format strings and extract information from them.
	// this are things that cannot be (easily at least, not sure if it's possible since I hadn't try)
	// with a normal string:
	/*
		string str;
		str << " hola " << 123; THIS CANNOT BE DONE WITH A STRING!
	*/

	/*
		We have two other more specialized classes, istringstream and ostringstream.
		They are basically the same as stringstream but only for input or output, so
		if I have a string I don't want to do input operations on such as "ss >> oct >> c;"
		it would be better to use ostringstream.
		If I want to do both things, then I need stringstream.
	*/
}