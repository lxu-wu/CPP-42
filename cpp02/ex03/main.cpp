#include "Point.hpp"

int main( void ) 
{
	Point a(0, 0);
	Point b(0, 100);
	Point c(100, 0);
	Point point(1, 1);

	std::cout << bsp(Point(a), Point(b), Point(c), Point(point)) << std::endl;
	return 0;
}