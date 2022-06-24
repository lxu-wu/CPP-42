#include "Fixed.hpp"

int main( void ) 
{
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed c(10);
		Fixed const d(3.5f);
		Fixed e = c;
		
		std::cout << std::endl << "---- My tests ----" << std::endl;
		std::cout << "c + d = " << c + d << std::endl;
		std::cout << "c + e = " << c + e << std::endl;
		std::cout << "c - d = " << c - d << std::endl;
		std::cout << "c * d = " << c * d << std::endl;
		std::cout << "c / d = " << c / d << std::endl;
		std::cout << "c > d = " << (c > d) << std::endl;
		std::cout << "c < d = " << (c < d) << std::endl;
		std::cout << "c >= d = " << (c >= d) << std::endl;
		std::cout << "c <= d = " << (c <= d) << std::endl;
		std::cout << "c == d = " << (c == d) << std::endl;
		std::cout << "c != d = " << (c != d) << std::endl;
		std::cout << "c = " << c << " then c++ = " << c++ << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "max = " <<Fixed::max(c, d) << std::endl;
		std::cout << "min = " <<Fixed::min(c, d) << std::endl;
	}
	return 0;
}