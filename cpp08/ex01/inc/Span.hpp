#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

//!excepción por usar shortest o longest span con 0 o 1 números metidos.


typedef std::vector<int>::iterator iterator;
typedef std::vector<int>::const_iterator const_iterator;


class	Span
{
public:
	Span(unsigned int max_ints);
	Span(const Span &span);
	Span &operator=(const Span &Span);
	~Span(void);

	void	addNumber(int n);
	void	addRange(iterator begin, iterator end);

	int		shortestSpan(void);
	int		longestSpan(void);
	void	printValues(void) const;

	class	InvalidSpanException: public std::exception
	{
		const char *what(void) const throw()
		{
			return ("InvalidSpanException: There's not enough values to calculate spans.");
		}
	} ;

	class	MaxLenException: public std::exception
	{
		const char	*what(void)const throw()
		{
			return ("MaxLenException: Can't add new values, limit reached.");
		}
	};
private:
	Span();
	std::vector<int>	_vector;
	unsigned int		_max_len;
};

#endif