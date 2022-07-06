#include <iostream>

class Base {public: virtual ~Base() {}};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
	srand(time(0));
	int i = rand() % 3;

	std::cout << "generate: ";
	switch (i)
	{
	case 0:
		std::cout << "A class" << std::endl;
		return new A;

	case 1:
		std::cout << "B class" << std::endl;
		return new B;

	default:
		std::cout << "C class" << std::endl;
		return new C;
	}
}

void identify(Base * p)
{
	std::cout << std::endl << "~~~Pointer~~~" << std::endl;
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "Is A class" << std::endl;
	if (dynamic_cast<B *>(p) != 0)
		std::cout << "Is B class" << std::endl;
	if (dynamic_cast<C *>(p) != 0)
		std::cout << "Is C class" << std::endl;
	if (dynamic_cast<A *>(p) == 0 && dynamic_cast<B *>(p) == 0 && dynamic_cast<C *>(p) == 0)
		std::cout << "Unknow type" << std::endl;
}

void identify(Base& p)
{
	std::cout << std::endl << "~~~Reference~~~" << std::endl;
	try
	{
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Is A class" << std::endl;
	}
	catch (const std::bad_cast & e)
	{
		std::cerr << "Converion to A is not ok " << e.what() << std::endl;
	}

	try
	{
 		B & b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Is B class" << std::endl;
	}
	catch (const std::bad_cast & e)
	{
		std::cerr << "Converion to B is not ok " << e.what() << std::endl;
	}
	
	try
	{
		C & c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Is C class" << std::endl;
	}
	catch (const std::bad_cast & e)
	{
		std::cerr << "Converion to C is not ok " << e.what() << std::endl;
	}
}

int main()
{
	Base *a;

	a = generate();

	identify(a);
	identify(*a);
}