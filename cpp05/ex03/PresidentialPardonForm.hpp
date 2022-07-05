#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:

	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm();

	void action(Bureaucrat const & executor) const;

private:

	std::string const _target;
	

	PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
};


#endif