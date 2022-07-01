#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
				return ("Grade lower than 15");
			}
	};

private:
	std::string const _name;
	int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif