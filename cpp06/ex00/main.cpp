#include "Scalaire.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Use one argument!" << std::endl;
		return (1);
	}
	std::string str(argv[1]);
	
	try
	{
		Scalaire sc(str);
		try
		{
			std::cout << "char: ";
			sc.getChar();
			std::cout << "'" << sc.getChar() << "'" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "int: ";
			std::cout << sc.getInt() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "float: " << sc.getFloat();
		if (static_cast<int>(sc.getFloat()) == sc.getFloat())
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
		
		
		std::cout << "double: " << sc.getDouble();
		if (static_cast<int>(sc.getDouble()) == sc.getDouble())
			std::cout << ".0";
		std::cout << std::endl; 
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	

	
}