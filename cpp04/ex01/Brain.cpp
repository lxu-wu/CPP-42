#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i=0; i < 100; i++)
		this->_ideas[i] = "Ideas " + std::to_string(i);
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return *this;
}

std::string Brain::getIdea(int index)
{
	if (index < 0 || index > 99)
	{
		std::cout << "inxesitance index. [0 - 99]" << std::endl;
		return "[NO IDEA]";
	}
	return (this->_ideas[index]);
}