#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
	Point();
	Point & operator=(Point const & rhs);
	
public:
	Point(Fixed const x, Fixed const y);
	Point(Point const & rhs);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

};

bool bsp( Point * const a, Point * const b, Point * const c, Point * const point);

#endif

