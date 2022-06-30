#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat : Nian nian" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}