#include "Point.hpp"

# define X getX()
# define Y getY()

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed m;
	Fixed p;

	if (a.X != b.X)
	{
		m = (a.Y - b.Y) / (a.X - b.X);
		p = a.Y - (m * a.X);

		if ((c.Y - (m * c.X + p)) * (point.Y - (m * point.X + p)) <= Fixed(0))
			return (false);
	}
	else
	{
		if ((a.X <= c.X && a.X >= point.X) || (a.X >= c.X && a.X <= point.X))
			return (false);
	}


	if (b.X != c.X)
	{
		m = (b.Y - c.Y) / (b.X - c.X);
		p = b.Y - (m * b.X);

		if ((a.Y - (m * a.X + p)) * (point.Y - (m * point.X + p)) <= Fixed(0))
			return (false);
	}
	else
	{
		if ((b.X <= a.X && b.X >= point.X) || (b.X >= a.X && b.X <= point.X))
			return (false);
	}


	if (a.X != c.X)
	{
		m = (a.Y - c.Y) / (a.X - c.X);
		p = a.Y - (m * a.X);

		if ((b.Y - (m * b.X + p)) * (point.Y - (m * point.X + p)) <= Fixed(0))
			return (false);
	}
	else
	{
		if ((a.X <= b.X && a.X >= point.X) || (a.X >= b.X && a.X <= point.X))
			return (false);
	}
	return (true);
}