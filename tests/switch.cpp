#include <string>
#include <iostream>
#include <cstdlib>

// int	main(int argc, char **argv)
// {
// 	char	c;
// 	std::cout << "Escribe una letra: ";
// 	std::cin >> c;

// 	switch (c)
// 	{
// 		case 'a':
// 		case 'e':
// 		case 'i':
// 		case 'o':
// 		case 'u':
// 			std::cout << c << " es una vocal" << std::endl;
// 			break ;
// 		default :
// 			std::cout << c << "es una consonante" << std::endl;
// 	}

// 	return (0);
// }

using namespace std;

int main(void)
{
	int n1, n2;
	char op;

	cout << "N1: ";
	cin >> n1;
	cout << "N2: ";
	cin >> n2;
	cout << "OP: ";
	cin >> op;

	switch (op)
	{
		case '+':
			cout << "\nRESULT: " << n1 + n2 << endl;
			break;
		case '-':
			cout << "\nRESULT: " << n1 - n2 << endl;
			break;
		case '*':
			cout << "\nRESULT: " << n1 * n2 << endl;
			break;
		case '/':
			cout << "\nRESULT: " << n1 / n2 << endl;
			break;
		default:
			cout << "oeprator not suported :(" << endl;
			break;
	}
	return 0;
}
