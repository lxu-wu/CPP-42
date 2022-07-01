# include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}


Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal & Animal::operator=(Animal const & src)
{
	this->_type = src._type;
	return *this;
}

// void Animal::makeSound() const
// {
// 	std::cout << "Animal sound : ani ani animal" << std::endl;
// }

std::string Animal::getType() const
{
	return this->_type;
}