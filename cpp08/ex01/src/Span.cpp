#include "Span.hpp"

#include <iostream>
#include <algorithm>

Span::Span(unsigned	int max_ints): _max_len(max_ints)
{
	_vector = std::vector<int>();
}

Span::Span(const Span &span)
{
	*this = span;
}

Span	&Span::operator=(const Span &span)
{
	if (this != &span)
	{
		_max_len = span._max_len;
		_vector = span._vector;
	}
	return *this;
}

Span::~Span(void)
{}

void	Span::addNumber(int n)
{
	if (_vector.size() >= _max_len)
		throw MaxLenException();
	_vector.push_back(n);
}

int	Span::longestSpan(void)
{
	if (_vector.size() <= 1)
		throw InvalidSpanException();

	sort(_vector.begin(), _vector.end());
	return (_vector[_vector.size() - 1] - _vector[0]);
}

int	Span::shortestSpan(void)
{
	std::vector<int>	spans;

	if (_vector.size() <= 1)
		throw InvalidSpanException();

	sort(_vector.begin(), _vector.end());
	for (int i = _vector.size() - 1; i != 0; --i)
	{
		spans.push_back(_vector.at(i) - _vector.at(i - 1));
	}
	sort(spans.begin(), spans.end());
	return (*spans.begin());
}

void	Span::printValues(void) const
{
	std::cout << "\n------(" << _vector.size() << ")------\n";
	for (const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------------\n\n";
}

void	Span::addRange(iterator begin, iterator end)
{
	_vector.insert(_vector.end(), begin, end);
}
