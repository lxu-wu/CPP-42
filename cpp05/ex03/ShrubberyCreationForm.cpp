#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreation", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm assginement constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form("ShrubberyCreation", 145, 137), _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	return (*this);
}

void ShrubberyCreationForm::action(Bureaucrat const & executor) const
{
	this->execute(executor);
	std::ofstream ofs(this->_target + "_shrubbery");

	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}