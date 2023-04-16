#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <ostream>
#include <fstream>
#include "Date.hpp"
#include <stdio.h>


// std::fixed << std::setprecision(2)
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ex00 filename" << std::endl;
		return 1;
	}
	BitcoinExchange d;
	d.action(argv[1]);
}