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

static std::string	parseDate(std::string line, std::string separator)
{
	if (line.empty() || line.at(4) != '-' || line.at(7) != '-' || line.find(separator) != 10)
	{
		throw std::runtime_error("Error: bad format => " + line);
	}

	std::string year = line.substr(0, 4);
	if (std::atoi(year.c_str()) < 2009 || std::atoi(year.c_str()) > 2026)
		throw std::runtime_error("Error: Invalid date (year) => " + line);

	std::string month = line.substr(5, 2);
	if (std::atoi(month.c_str()) < 1|| std::atoi(month.c_str()) > 12)
		throw std::runtime_error("Error: Invalid date (month) => " + line);

	std::string day = line.substr(8, 3);
	if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
		throw std::runtime_error("Error: Invalid date (day) => " + line);
	
	return (line.substr(0, 10));
}

static float	parseAmount(std::string line, std::string separator)
{
	std::string	quantity_str = line.substr(line.find(separator) + separator.length());
	char		*end;
	float		quantity = std::strtof(quantity_str.c_str(), &end);

	if (quantity_str.empty() == true ||  *end != '\0')
		throw std::runtime_error("Error: Invalid quantity");
	if (quantity < 0)
		throw std::runtime_error("Error: not a positive number");
	if (quantity > 1000)
		throw std::runtime_error("Error: bitcoin amount limited to 1000");

	return (quantity);
}

void	BitcoinExchange::calculateExchange(char *fileName)
{
	std::ifstream	file(fileName);
	std::string		line;
	std::string		date;
	float			amount;
	float			bitcoinValue;

	if (!file.is_open())
		throw std::runtime_error("Error: input file could not be found");
	std::getline(file, line, '\n');
	while (!file.eof())
	{
		try
		{
			std::getline(file, line, '\n');
			date = parseDate(line, " | ");
			amount = parseAmount(line, " | ");
			bitcoinValue = amount * getDateValue(date);
			std::cout << date << " => " << amount << " = " << bitcoinValue << "\n";
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}

}
