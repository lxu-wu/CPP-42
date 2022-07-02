#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Micheal("Micheal", 2);
	Bureaucrat Jim("Jim", 149);
	std::cout << std::endl;

	try
	{
		Bureaucrat Jim("Jim", 155);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Jim("Jim", -120);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << std::endl;
		std::cout << Micheal << std::endl;
		std::cout << Jim << std::endl;
		std::cout << std::endl;
		
		Micheal.promotion();
		Jim.demotion();
		std::cout << std::endl;
		
		std::cout << Micheal << std::endl;
		std::cout << Jim << std::endl;
		std::cout << std::endl;
		
		Micheal.promotion();//Execptions Tro
		Jim.demotion();
		std::cout << std::endl;
		
		std::cout << Micheal << std::endl;
		std::cout << Jim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
