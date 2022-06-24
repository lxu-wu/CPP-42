#include "Point.hpp"

int main( void ) 
{
	Point p(11, 19);
	Point l(12, 18);
	Point d(10, 2);
	Point h(0.1f, 0.1f);

	Point * a = new Point(11, 19);
	Point * b = new Point(12, 18);
	Point * c = new Point(10, 2);
	Point * point = new Point(0.1f, 0.1f);

	std::cout << "y" << std::endl << a->getY() << "   " << b->getY() << std::endl;
	bsp(*a, *b, *c, *point);
	return 0;
}