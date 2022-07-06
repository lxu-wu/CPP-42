#include "Form.hpp"

Form::Form() : _name("TOP SECRET"), _signed(0), _signGrade(1), _execGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string const name, int const signGrade, int const execGrade) : _name(name), _signed(0), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form assignation constructor called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighExeption();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(Form const & src)
{
	this->_signed = src._signed;
	return *this;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSign() const
{
	return this->_signed;
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
	o << std::boolalpha;
	o << "Form name: " << i.getName() << ", signed: " << i.getSign() << ", require grade:" << i.getSignGrade() << " to sign and require grade:" << i.getExecGrade() << " to execute.";
	return o;
}

void Form::beSigned(Bureaucrat const & i)
{
	if (this->_signGrade < i.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = 1;

}

void Form::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw FormNoSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
}