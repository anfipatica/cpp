#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <limits>

/*                       Printers for numeric conversions                     */

static void	print_int(double d, int n)
{
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int:     OVERFLOW\n";
	else
		std::cout << "int:    " << n << "\n";
}

static void	print_char(int n, char c)
{
	if (n < 0 || n > 127)
		std::cout << "char:    impossible\n";
	else if (std::isprint(n) == false)
		std::cout << "char:   non displayable\n";
	else
		std::cout << "char:   \'" << c << "\'\n";
}

/*                            Conversion functions                            */

static void	convert_char(char c)
{
	std::cout << ":: convert_char ::\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char:   \'" << c << "\'\n";
	std::cout << "int:    " << static_cast<int>(c) << "\n";
	std::cout << "float:  " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void	convert_int(std::string &value)
{
	std::cout << ":: convert_int ::\n";
	int		n = atoi(value.c_str());
	double	d = atof(value.c_str());
	
	std::cout << std::fixed << std::setprecision(1);
	print_char(n, static_cast<char>(n));
	print_int(d, n);
	std::cout << "float:  " << static_cast<float>(n) << "f\n";
	std::cout << "double: " << static_cast<double>(n) << "\n";
}

void	convert_double(std::string &value)
{
	std::cout << ":: convert_double ::\n";
	double	d = atof(value.c_str());

	std::cout << std::fixed;
	if (value.length() - value.find('.') == 1)
		std::cout.precision(1);
	else
		std::cout.precision(value.length() - value.find('.') - 1);
	print_char(d, static_cast<char>(d));
	print_int(d, static_cast<char>(d));
	std::cout << "float:  " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << "\n";
}

void	convert_float(std::string &value)
{
	std::cout << ":: convert_float ::\n";
	std::cout << value << "\n";
	double	d = atof(value.c_str());
	float	f = atof(value.c_str());

	std::cout << std::fixed;
	if (value.length() - value.find('.') == 2)
		std::cout.precision(1);
	else
		std::cout.precision(value.length() - value.find('.') - 2);
	print_char(f, static_cast<char>(f));
	print_int(d, static_cast<char>(f));
	std::cout << "float:  " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

static void	convert_naninf(double naninf)
{
	std::cout << ":: convert_double ::\n";
	std::cout << "char:   impossible\n";
	std::cout << "int:    impossible\n";
	std::cout << "float:  " << static_cast<float>(naninf) << "f\n";
	std::cout << "double: " << naninf << "\n";
}

static void convert_nanfinff(float nanfinff)
{
	std::cout << ":: convert_float ::\n";
	std::cout << "char:   impossible\n";
	std::cout << "int:    impossible\n";
	std::cout << "float:  " << nanfinff << "f\n";
	std::cout << "double: " << static_cast<double>(nanfinff) << "\n";
}

/*                           detection functions                              */

static bool	check_one_char(std::string value)
{
	if (value.length() == 1 && isdigit(value.at(0)) == false)
	{
		convert_char(value.at(0));
		return (true);
	}
	return (false);
}

static bool	check_naneinf(std::string value)
{
	if (value == "nan")
		return (convert_naninf(std::numeric_limits<double>::quiet_NaN()), true);
	if (value == "nanf")
		return (convert_nanfinff(std::numeric_limits<float>::quiet_NaN()), true);
	if (value == "inf")
		return (convert_naninf(std::numeric_limits<double>::infinity()), true);
	if (value == "inff")
		return (convert_nanfinff(std::numeric_limits<float>::infinity()), true);
	if (value == "ninf")
		return (convert_naninf(-std::numeric_limits<double>::infinity()), true);
	if (value == "ninff")
		return (convert_nanfinff(-std::numeric_limits<float>::infinity()), true);
	return (false);
}

#define CHAR 0
#define SIGN 1
#define NUMBER 2
#define DOT 3
#define F 4

#define INVALID_STATE 6
#define ACCEPT_STATES 3

static int automata(int	current_state, char c)
{
	const int	matrix[6][5] = {
		{6, 1, 3, 2, 6}, // Q0 - INITIAL STATE
		{6, 6, 3, 2, 6}, // Q1 - SIGN STATE
		{6, 6, 4, 6, 6}, // Q2 - DOT STATE
		{6, 6, 3, 4, 6}, // Q3 - INT STATE
		{6, 6, 4, 6, 5}, // Q4 - DOUBLE STATE
		{6, 6, 6, 6, 6}, // Q5 - FLOAT STATE
	//	 c -/+ n  . f/F
	};
	if (c == '-' || c == '+')
		return (matrix[current_state][SIGN]);
	if (c >= '0' && c <= '9')
		return (matrix[current_state][NUMBER]);
	if (c == '.')
		return (matrix[current_state][DOT]);
	if (c == 'F' || c == 'f')
		return (matrix[current_state][F]);
	return (matrix[current_state][CHAR]);
}

static void detect_type(std::string value)
{
	void	(*conversion_f_array[3])(std::string&) =
	{
		convert_int,
		convert_double,
		convert_float
	};

	int	current_state = 0;

	for (std::size_t i = 0; i < value.length(); i++)
	{
		current_state = automata(current_state, value.at(i));
		if (current_state == INVALID_STATE)
			break;
	}
	if (current_state == INVALID_STATE || current_state < ACCEPT_STATES)
		std::cerr << "INVALID INPUT: Not a valid data type\n";
	else
		conversion_f_array[current_state - 3](value);
}


void	ScalarConverter::convert(const std::string value)
{
	if (check_one_char(value) == true)
		return ;
	if (check_naneinf(value) == true)
		return ;
	detect_type(value);
}