#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <exception>

class	EasyfindException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("easyfind_exception: The value was not found :("); // override
	};
};

template<typename T>
int &easyfind(T &t, int n)
{
	for (typename T::iterator it = t.begin(); it != t.end(); ++it)
	{
		if (*it == n)
			return (*it);
	}
	throw EasyfindException();
}

#endif