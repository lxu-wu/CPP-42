#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

class NoMatchException : public std::exception
{
	public:
		virtual const char * what() const throw()
		{
			return "No find in container";
		}
};


template< typename T >
typename T::iterator easyfind(T & container, int toFind)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), toFind);

	if (iter != container.end())
		return iter;
	else
		throw NoMatchException();
}

#endif
