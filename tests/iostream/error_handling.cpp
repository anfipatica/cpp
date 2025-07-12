#include <iostream>
#include <fstream>

int main(void)
{
	{
		std::ofstream file("my_log.txt"); // ope file for write, clear the content of the file.
		//std::ofstream file("my_log.txt", std::ofstream::app); // Move the output pointer to the end of the file.
		file << "\0Honesty is the best policy" << std::endl;
		file << "Honesty is the best policy" << std::endl;

	}
	{
		std::ofstream file("my_log.txt", std::ofstream::in | std::ofstream::out);
		file.seekp(10, std::ios::beg); //move the output poointer 10 chars after begin.
		file << "*******"; //overwrite the file from the output pointer.
		// Honesty i*******est policy
		// Honesty is the best policy
		file.seekp(-5, std::ios::end); // move the output pointer 5 chars before eof.
		file << "Veamos que pasa con esto lel";
		/*
		Honesty is*******st policy
		Honesty is the best poVeamos que pasa con esto lel
		*/
		file.seekp(-5, std::ios::cur); //move the output pointer 5 chars before current position.
		file << "_";
		/*
		Honesty is*******st policy
		Honesty is the best poVeamos que pasa con est_ lel
		*/
	}
	std::ifstream inf("my_loasdasdg.txt");
	int	i;
	inf >> i; // read one word.
	/*
		If the first word is not a number it will fail.
		Error status: goodbit, badbit, failbit, eofbit.
	*/
	std::cout << i << std::endl;
	std::cout << inf.good() << std::endl; // Everything is OK (goodbit == 1);
	std::cout << inf.bad() << std::endl; // Non-recoverable error (badbit == 1, failbit == 1,);
	std::cout << inf.fail() << std::endl; // Failed stream operation (failbit == 1)
	std::cout << inf.eof() << std::endl; // end of file (eofbit == 1, (a veces tmb failbit == 1));
	//this functions are usefull to check the state of the stream.

	//if some error has happened and I have handled it, I need to clear this error states.
	inf.clear();
	std::cout << "-----------------" << std::endl;
	std::cout << inf.good() << std::endl; // Everything is OK (goodbit == 1);
	std::cout << inf.bad() << std::endl; // Non-recoverable error (badbit == 1);
	std::cout << inf.fail() << std::endl; // Failed stream operation (failbit == 1, badbit == 1)
	std::cout << inf.eof() << std::endl;

	inf.clear(std::ios::failbit); // sets a new value to the error flag.
	std::cout << "-----------------" << std::endl;
	std::cout << inf.good() << std::endl; // Everything is OK (goodbit == 1);
	std::cout << inf.bad() << std::endl; // Non-recoverable error (badbit == 1);
	std::cout << inf.fail() << std::endl; // Failed stream operation (failbit == 1, badbit == 1)
	std::cout << inf.eof() << std::endl;
	//! Therefore, inf.clear() without parameters it's equivalent to inf.clear(std::ios::goodbit);
	std::cout << "-----------------" << std::endl;
	std::cout << inf.rdstate() << std::endl; //read the current status flag.
	/* It will return:
	0 -> goodbit.
	1 -> badbit.
	2 -> eofbit.
	4-> failbit.*/

	//inf.clear(inf.rdstate() & ~std::ios::failbit); // clear *only* the failbit.

	if (inf) // == if (!inf.fail())
		std::cout << "Read succesfully" << std::endl;
	
	if (inf >> i) // the >> operator returns a reference to the stream itself.
		std::cout << "Read successfully";

	//we can also handle errors with exceptions.
	inf.exceptions(std::ios::badbit | std::ios::failbit); // setting the exception mask
	//when badbit or failbit set to 1, exception of ios::failure will be thrown.
	inf.exceptions(std::ios::goodbit); //No exception will be generated. ?? esto no lo he entendidopero estoy cansadita jefe.


	return 0;
}
