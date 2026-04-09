#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

void	BitcoinExchange::savecsv()
{
	std::ifstream	file("data.csv");
	std::string		date;
	std::string		value;

	if (!file.is_open())
		throw std::runtime_error("Error: csv file could not be found");

	std::getline(file, value, '\n');
	while (!file.eof())
	{
		std::getline(file, date, ',');
		std::getline(file, value, '\n');
		_csv[date] = std::strtof(value.c_str(), NULL);
	}
	file.close();
}

float	BitcoinExchange::getDateValue(std::string date)
{
	std::map<std::string, float>::iterator it = _csv.lower_bound(date);

	if (it->first != date)
	{
		--it;
	}
	return (it->second);
}


static bool	validNumber(std::string strnum, int min, int max)
{

	char	*end = NULL;
	int		n = std::strtof(strnum.c_str(), &end);

	if (n < min)
		std::cout << "Error: Invalid date. Either a negative or a year prior to the existence of bitcoins => ";
	else if (n > max)
		std::cout << "Error: Invalid date. Either a true invalid date, or a future date => ";
	else if (*end != '\0')
		std::cout << "Error: Invalid date => ";
	else
		return (true);
	std::cout << "(" << strnum << ")";
	return (false);
}
static std::string	parseDate(std::string line, std::string separator)
{
	std::string	date = line.substr(0, line.find(separator));
	if (date.empty() || line.find(separator) == std::string::npos)
	{
		throw std::runtime_error("Error: bad input => " + line);
	}

	std::string year = line.substr(0, line.find("-"));
	if (validNumber(year, 2009, 2026) == false)
		throw std::runtime_error(line);

	std::string month = line.substr(year.length() + 1, line.find("-", year.length() + 1)); // que pasa aquí no sé estoy cansada me piro ;(
	if (validNumber(month, 1, 12) == false)
		throw std::runtime_error(line);
	std::cout << "asdasd\n";
	std::string day = line.substr(year.length() + month.length(), line.find("-"));
	if (validNumber(day, 1, 31) == false)
		throw std::runtime_error(line);
	return (date);
}

static float		parseQuantity(std::string line, std::string separator)
{
	std::string	quantity_str = line.substr(line.find(separator) + separator.length());
	char		*end;
	float		quantity = std::strtof(quantity_str.c_str(), &end);

	if (*end != '\0')
		throw std::runtime_error("Invalid quantity");
	return (quantity);
}

void	BitcoinExchange::calculateExchange(char *fileName)
{
	std::ifstream	file(fileName);
	std::string		line;
	std::string		date;
	float			quantity;
	float			bitcoinValue;

	if (!file.is_open())
		throw std::runtime_error("Error: csv file could not be found");
	std::getline(file, line, '\n');
	while (!file.eof())
	{
		try
		{
			std::getline(file, line, '\n');
			date = parseDate(line, " | ");
			quantity = parseQuantity(line, " | ");
			bitcoinValue = quantity * getDateValue(date);
			std::cout << bitcoinValue << "\n";
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}

}
