#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:

	Fixed();
	Fixed(Fixed const &src);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);

	int	getRawBits( void ) const;

	void setRawBits( int const raw );

private:
	static int const _nBits = 8;
	int	_raw;
};


#endif