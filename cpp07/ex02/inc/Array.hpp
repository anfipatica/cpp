#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array(void): _size(0)
	{
		_t = new T[0];
	};

	Array(unsigned int n): _size(n)
	{
		_t = new T[n];
		for (unsigned int i = 0; i < n; ++i)
			_t[i] = 0;
	};

	Array(const	Array &array): _size(array._size)
	{
		_t = new T[_size];
		*this = array;
	}

	Array	&operator=(const Array &array)
	{
		if (this == &array)
			return *this;
		if (_size != array._size)
		{
			_size = array._size;
			delete[](_t);
			_t = new T[array._size];
		}
		for (unsigned int i = 0; i < _size; ++i)
			_t[i] = array._t[i];
		return (*this);
	}

	~Array(void)
	{
		delete[](_t);
	};

	T	&operator[](size_t pos)
	{
		if (pos >= _size)
			throw std::exception();
		return _t[pos];
	}
	const T	&operator[](size_t pos) const
	{
		if (pos >= _size)
			throw std::exception();
		return _t[pos];
	}

	size_t	size(void) { return (_size); };
private:
	T		*_t;
	size_t	_size;
};

#endif