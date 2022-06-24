#include "Point.hpp"

Point::Point()
{
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
}

Point::Point(Point const & rhs)
{
	*this = rhs;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}

Point & Point::operator=(Point const & rhs)
{
	return (*this);
}