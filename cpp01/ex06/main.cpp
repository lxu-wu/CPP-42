#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error: enter one argument" << std::endl;
	else
	{
		Harl harl;

		harl.complain(argv[1]);
	}
	return (0);
}