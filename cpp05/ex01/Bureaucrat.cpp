#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat assignation constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src._grade;
	return *this;
}

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::promotion()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::demotion()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}

void Bureaucrat::signForm(Form & i)
{
	try
	{
		i.beSigned(*this);
		std::cout << *this << " signed " << i << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << *this << " couldn't sign " << i << " because " << e.what() << "." << std::endl;
	}
}
