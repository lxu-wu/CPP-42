#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & src)
{
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog : Woof Woof" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}