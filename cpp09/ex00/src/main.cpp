#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

#define MAX_LEN 1000

std::pair<string, string>	split(std::string line, std::string separator)
{
	string str1;
	string str2;

	str1 = line.substr(0, line.find(separator));
	if (line.find(separator) != std::string::npos)
		str2 = line.substr(line.find(separator) + separator.length());
	return (std::pair<string, string>(str1, str2));
}

void	read_files(std::ifstream &csv, std::ifstream &input, BitcoinExchange &bc)
{
	char	line[MAX_LEN];

	csv.getline(line, MAX_LEN, '\n');
	while (csv.eof() == false)
	{
		csv.getline(line, MAX_LEN, '\n');
		bc.csv.insert(split(line, ","));
	}

	input.getline(line, MAX_LEN, '\n'); //? refactorizar esto quizás???
	while (input.eof() == false)
	{
		input.getline(line, MAX_LEN, '\n');
		bc.input.push_back(split(line, " | "));
	}
}

void	calculate_bitcoin(std::pair<string, string> search, BitcoinExchange &bc)
{
	if (bc.csv.find(search.first) != ) // ay estoy cansadita lo dejamos aquí por hoy
	std::multimap<string, string>::iterator it = bc.csv.find(search.first);

	std::cout << (*it).first << "...\n";

}

void	test(std::ifstream &csv, std::ifstream &input)
{
	BitcoinExchange	bc;

	read_files(csv, input, bc);

	for (std::list<std::pair<string, string>>::iterator it = bc.input.begin(); it != bc.input.end(); ++it)
	{
		std::cout << (*it).first << "___" << (*it).second << "\n";
		calculate_bitcoin(*it, bc);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments\n";
		return (1);
	}

	std::ifstream csv("data.csv");
	if (csv.is_open() == false)
	{
		std::cerr << "Error: csv could not be found\n";
		return (1);
	}

	std::ifstream file(argv[1]);
	if (file.is_open() == false)
		std::cerr << "Error: File not found\n";
	else
		test(csv, file);

	csv.close();
	file.close();  //??? pasa algo si ha fallado?
	return (0);
}
