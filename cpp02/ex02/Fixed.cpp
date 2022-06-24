#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _raw(0)
{
	// std::cout << "default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb): _raw(nb * 256)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb): _raw(roundf(nb * 256))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_raw = rhs.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_raw / 256);
}

int Fixed::toInt( void ) const
{
	return (this->_raw / 256);
}

std::ostream& operator<<(std::ostream & o, Fixed const & i)
{
	std::cout << i.toFloat();
	return (o);
}

//comparison function
bool Fixed::operator>(Fixed const & rhs) const
{
	if (this->_raw > rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	if (this->_raw < rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_raw >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_raw <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->_raw == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_raw != rhs.getRawBits());
}

//arithmetic function
Fixed Fixed::operator+(Fixed const & rhs)
{
	Fixed plus;

	plus.setRawBits(this->_raw + rhs.getRawBits());
	return (plus);
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	Fixed minus;

	minus.setRawBits(this->_raw - rhs.getRawBits());
	return (minus);
}

Fixed Fixed::operator*(Fixed const & rhs)
{
	Fixed multiply;

	multiply.setRawBits(this->_raw * rhs.getRawBits() / 256);
	return (multiply);
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	Fixed divide;

	divide.setRawBits(this->_raw * 256 / rhs.getRawBits());
	return (divide);

}

//incrementation and decrementation funtion
Fixed & Fixed::operator++()
{
	this->_raw++;
	return (*this);
}

Fixed & Fixed::operator--()
{
	this->_raw--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed plus;

	plus.setRawBits(this->_raw);
	this->_raw++;
	return (plus);
}

Fixed Fixed::operator--(int)
{
	Fixed minus;

	minus.setRawBits(this->_raw);
	this->_raw--;
	return (minus);
}

	//member function
Fixed & Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed Fixed::min(Fixed const f1, Fixed const f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed & Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed Fixed::max(Fixed const f1, Fixed const f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}