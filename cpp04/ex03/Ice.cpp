#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & src)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & src)
{
	this->_type = src._type;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}