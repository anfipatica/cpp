#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <list>
# include <string>

using std::string;

class BitcoinExchange
{
private:
	std::map<string, float>	_csv;
public:
	void	savecsv(void);
	void	calculateExchange(char *fileName);
	float	getDateValue(std::string date);
};

#endif
