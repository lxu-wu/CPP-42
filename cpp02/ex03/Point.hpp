#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
	Fixed const _m;
	Fixed const _p;
	
public:
	Point();
	Point(Fixed const x, Fixed const y);
	Point(Point const & rhs);
	~Point();

	Point & operator=(Point const & rhs);
};

Point::Point(/* args */)
{
}

Point::~Point()
{
}


#endif

