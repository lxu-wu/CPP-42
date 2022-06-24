#include "Point.hpp"

int main( void ) 
{
	Point p(11, 19);
	Point l(12, 18);
	Point d(10, 2);
	Point h(13, 7);

	Point * a = new Point(0, 0);
	Point * b = new Point(50, 100);
	Point * c = new Point(100, 0);
	Point * point = new Point(50, 101);

	std::cout << "y" << std::endl << a->getY() << "   " << b->getY() << std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}