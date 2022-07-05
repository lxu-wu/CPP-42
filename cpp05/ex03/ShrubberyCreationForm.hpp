#ifndef SHRUBBERYCREATIONFORM_CPP
# define SHRUBBERYCREATIONFORM_CPP

# include "Form.hpp"
# include <iostream>

class ShrubberyCreationForm : public Form
{
public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	~ShrubberyCreationForm();

	void action(const Bureaucrat& executor) const;

private:

	std::string const _target;
	

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
};


#endif