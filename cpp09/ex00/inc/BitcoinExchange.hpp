#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <list>
# include <string>

using std::string;

class BitcoinExchange
{
public:
	std::multimap<string, string>			csv;
	std::list<std::pair<string, string>>	input;
};

#endif
