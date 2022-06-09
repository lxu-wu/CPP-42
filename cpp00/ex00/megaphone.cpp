#include <iostream>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::locale loc;

		for(int i=1;argv[i];i++)
			for(int i2=0;argv[i][i2];i2++)
				std::cout << std::toupper(argv[i][i2], loc);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}