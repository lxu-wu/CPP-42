#include "Point.hpp"

# define X getX()
# define Y getY()

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed m;
	Fixed p;

	std::cout << "y" << std::endl << a.Y << "    " << b.Y << std::endl;
	// m = (a.Y - b.Y) / (a.X - b.X);
	// p = a.Y - (m * a.X);

	// if (c.Y - (m * c.X + p) - point.Y - (m * point.X + p) <= Fixed(0))
	// 	return (false);

	// m = (b.Y - c.Y) / (b.X - c.X);
	// p = b.Y - (m * b.X);

	// if (a.Y - (m * a.X + p) - point.Y - (m * point.X + p) <= Fixed(0))
	// 	return (false);

	// m = (a.Y - c.Y) / (a.X - c.X);
	// p = a.Y - (m * a.X);

	// if (b.Y - (m * b.X + p) - point.Y - (m * point.X + p) <= Fixed(0))
	// 	return (false);



	return (true);
}