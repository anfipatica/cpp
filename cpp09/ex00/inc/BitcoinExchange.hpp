#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <list>
# include <string>

using std::string;

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	~BitcoinExchange(void);

	void	savecsv(void);
	void	calculateExchange(char *fileName);
	float	getDateValue(std::string date);

private:
	BitcoinExchange(BitcoinExchange &bc);
	BitcoinExchange &operator=(BitcoinExchange &bc);
	std::map<string, float>	_csv;
};

#endif
