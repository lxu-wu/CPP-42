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

	//comparison function
	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;
	
	//arithmetic function
	Fixed operator+(Fixed const & rhs);
	Fixed operator-(Fixed const & rhs);
	Fixed operator*(Fixed const & rhs);
	Fixed operator/(Fixed const & rhs);

	//incrementation and decrementation funtion
	Fixed & operator++();
	Fixed & operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	//public function
	static Fixed & min(Fixed &f1, Fixed &f2);
	static Fixed min(Fixed const f1, Fixed const f2);
	static Fixed & max(Fixed &f1, Fixed &f2);
	static Fixed max(Fixed const f1, Fixed const f2);

private:
	static int const _nBits;
	int	_raw;
};

std::ostream& operator<<(std::ostream & o, Fixed const & i);

#endif