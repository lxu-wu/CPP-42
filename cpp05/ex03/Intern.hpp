#ifndef INTERN_HPP
# define INTERN_HPP


# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:

	Intern();
	~Intern();

	Form * makeForm(std::string name, std::string target);

	class UnexisteFormExection : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Form type isn't exist!");
			}
	};

private:

	Intern(Intern const & src);

	Intern & operator=(Intern const & src);

};


#endif