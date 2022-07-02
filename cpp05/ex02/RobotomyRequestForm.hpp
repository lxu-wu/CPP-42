#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm();

	void action(Bureaucrat const & executor) const;

private:

	std::string const _target;
	

	RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
};


#endif