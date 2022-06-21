#include "Zombie.hpp"

Zombie::Zombie()//: _name("Unnamed")
{
	this->_name = "Unnamed";
}

Zombie::Zombie(std::string name): _name(name) 
{
	// std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}