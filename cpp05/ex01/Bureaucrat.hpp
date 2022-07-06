#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:

	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();

	Bureaucrat & operator=(Bureaucrat const & src);


	std::string const getName() const;
	int getGrade() const;

	void promotion();
	void demotion();


	void signForm(Form & i);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Grade higher than 1");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Grade lower than 150");
			}
	};

private:
	std::string const _name;
	int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif