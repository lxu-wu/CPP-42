#include "Point.hpp"

int main( void ) 
{
	{
		Point a(0, 0);
		Point b(0, 100);
		Point c(100, 0);
		Point point(1, 1);

		if (bsp(Point(a), Point(b), Point(c), Point(point)))
			std::cout << "point is in the triangle a,b,c" << std::endl;
		else
			std::cout << "point is out the triangle a,b,c" << std::endl;
	}
	{
		Point a(-50, 0);
		Point b(0, 100);
		Point c(50, 0);
		Point point(0, -1);

		if (bsp(Point(a), Point(b), Point(c), Point(point)))
			std::cout << "point is in the triangle a,b,c" << std::endl;
		else
			std::cout << "point is out the triangle a,b,c" << std::endl;
	}
	return 0;
}