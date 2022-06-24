#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
}

Point::Point(Point const & rhs): _x(rhs.getX()), _y(rhs.getY())
{
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