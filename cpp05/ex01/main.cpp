#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
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
	{

	Bureaucrat Micheal("Micheal", 1);
	Bureaucrat Jim("Jim", 150);
	Form form1("form1", 100, 50);
	Form form2("form2", 1, 1);

	std::cout << std::endl << "---- Max and min Test ----" << std::endl;
	try
	{
		Form form_test("form1", 155, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form_test("form1", 100, -50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---- BeSigned Test ----";
	try
	{
		std::cout << std::endl;
		std::cout << Micheal << std::endl;
		std::cout << Jim << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl << std::endl;
	
		std::cout << "Micheal will sign " << std::endl;
		form1.beSigned(Micheal);
		std::cout << "Jim will sign " << std::endl;
		form2.beSigned(Jim);// Jim Not good level
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---- SignForm Test ----" << std::endl;
	Micheal.signForm(form1);
	Jim.signForm(form2);// Jim Not good level
	std::cout << std::endl;
	
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl << std::endl;
	
	Micheal.signForm(form2);
	std::cout << std::endl;

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl << std::endl;
	}
}