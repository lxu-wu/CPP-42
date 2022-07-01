#include "AMateria.hpp"

AMateria::AMateria() : _type("Untype")
{
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) : _type(src._type)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & src)
{
	this->_type = src._type;
	return (*this);
}


AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria type constructor called" << std::endl;
}

//Returns the materia type
std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	// useless cout
	std::cout << this->_type << " do action on " << target.getName() << "!" << std::endl;
}
