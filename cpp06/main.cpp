#include <iostream>

int main(int argc, char **argv)
{
	int f;

	if (10 == 10.0000005f)
		std::cout << "no" << std::endl;
	std::cout << f << std::endl;
}