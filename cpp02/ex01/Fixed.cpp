#include "Fixed.hpp"
#include <cmath>

int const Fixed::_nBits = 8;

Fixed::Fixed(): _raw(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb): _raw(nb * (1 << Fixed::_nBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb): _raw(roundf(nb * (1 << Fixed::_nBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_raw = rhs.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_raw / (1 << Fixed::_nBits));
}

int Fixed::toInt( void ) const
{
	return (this->_raw / (1 << Fixed::_nBits));
}

std::ostream& operator<<(std::ostream & o, Fixed const & i)
{
	std::cout << i.toFloat();
	return (o);
}