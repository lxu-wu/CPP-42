#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name) 
{
	// std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}