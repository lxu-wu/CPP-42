#ifndef INTER_HPP
# define INTER_HPP

# include <iostream>

template< typename T, typename U>
void iter(T * tab, U const & size, void (*ft)(T const &))
{
	for (U i = 0; i < size; i++)
	{
		(*ft)(tab[i]);
	}
}

template< typename T >
void print(T const & value)
{
	std::cout << value << std::endl;
}

#endif