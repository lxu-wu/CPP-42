#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm assginement constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form("RobotomyRequest", 72, 45), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	return (*this);
}

void RobotomyRequestForm::action(Bureaucrat const & executor) const
{
	this->execute(executor);
	std::cout << "Makes some drilling noises" << std::endl;
	if (rand() % 2 == 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->_target << " has failed." << std::endl;
}
