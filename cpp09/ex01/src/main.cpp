#include "RPN.hpp"
#include <sstream>

int main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid arguments\n";
		return (1);
	}
	std::istringstream iss(argv[1]);

	RPN	rpn;
	std::string strnum;
	try
	{
		while (!iss.eof())
		{
			iss >> strnum;
			if (strnum == "+")
				rpn.sum();
			else if (strnum == "-")
				rpn.subs();
			else if (strnum == "*")
				rpn.mult();
			else if (strnum == "/")
				rpn.div();
			else
				rpn.insertNumber(strnum);
		}
		rpn.printResult();
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	return 0;
}
