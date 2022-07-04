#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:

	Fixed();
	Fixed(Fixed const &src);
	Fixed(int const nb);
	Fixed(float const nb);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);

	int	getRawBits( void ) const;

	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

private:
	static int const _nBits;
	int	_raw;
};

std::ostream& operator<<(std::ostream & o, Fixed const & i);

#endif