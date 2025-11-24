#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
	static void	convert(const std::string value);
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &sc);
	ScalarConverter	&operator=(const ScalarConverter &sc);
	~ScalarConverter(void);
};

#endif