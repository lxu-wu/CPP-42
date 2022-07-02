#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm assginement constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form("PresidentialPardon", 25, 5), _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	return (*this);
}

void PresidentialPardonForm::action(Bureaucrat const & executor) const
{
	this->execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}