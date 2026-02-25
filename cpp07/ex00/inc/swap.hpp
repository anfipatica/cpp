#ifndef SWAP_HPP
# define SWAP_HPP

template<typename T>
void	swap(T &value1, T &value2)
{
	T	aux = value1;

	value1 = value2;
	value2 = aux;
}

#endif