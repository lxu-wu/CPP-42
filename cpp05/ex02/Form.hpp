#ifndef FORM_HPP
# define FORM_HPP

# include "fstream"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:

	Form();
	Form(Form const & src);
	Form(std::string const name, int const signGrade, int const execGrade);
	virtual ~Form();

	Form & operator=(Form const & src);

	int const getSignGrade() const;
	int const getExecGrade() const;

	std::string getName() const;

	bool getSign() const;


	void beSigned(Bureaucrat const & i);

	void execute(Bureaucrat const & executor) const;
	virtual void action(Bureaucrat const & executor) const = 0;

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
	class FormNoSignedException : public std::exception
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Form no signed!");
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