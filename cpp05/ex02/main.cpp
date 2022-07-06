#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main () 
{
	Bureaucrat Micheal("Micheal", 1);
	Bureaucrat Jim("Jim", 72);
	PresidentialPardonForm P_form("Obama");//LVL 25, 5
	RobotomyRequestForm R_form("Lincoln");//LVL 72, 45
	ShrubberyCreationForm S_form("Tree_file");//LVL 145, 137

	std::cout << std::endl << " ---- Lvl Tests ---- " << std::endl;
	try
	{
		Jim.executeForm(P_form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		P_form.execute(Jim);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Jim signs Form" << std::endl;
	Jim.signForm(R_form);
	try
	{
		Jim.executeForm(R_form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << " ---- Actions Tests ---- " << std::endl;
	Micheal.signForm(P_form);
	Micheal.signForm(R_form);
	Micheal.signForm(S_form);
	Micheal.executeForm(P_form);
	Micheal.executeForm(R_form);
	Micheal.executeForm(S_form);
	std::cout << std::endl;	
}