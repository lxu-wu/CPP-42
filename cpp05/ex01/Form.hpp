#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:

	Form();
	Form(Form const & src);
	Form(std::string const name, int const signGrade, int const execGrade);
	~Form();

	Form & operator=(Form const & src);

	int const getSignGrade() const;
	int const getExecGrade() const;

	std::string getName() const;

	bool getSign() const;


	void beSigned(Bureaucrat const & i);

	class GradeTooHighExeption : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return "GradeTooHigh";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return "GradeTooLow";
			}
	};

private:
	
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;

};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif