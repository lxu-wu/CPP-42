#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	return *this;
}

Form * Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	Form * tmp;

	for (i = 0; name[i]; i++)
		name[i] = tolower(name[i]);
	
	for (i = 0; i < 3; i++)
		if (formNames[i] == name)
			break ;
	
	switch (i)
	{
	case 0:
		tmp = new ShrubberyCreationForm(target);
		break;
	case 1:
		tmp = new RobotomyRequestForm(target);
		break;
	case 2:
		tmp = new PresidentialPardonForm(target);
		break;
	default:
		throw UnexisteFormExection();
	}

	std::cout << "Intern creates " << *tmp << std::endl;
	return tmp;
}
