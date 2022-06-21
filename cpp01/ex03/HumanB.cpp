#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	// std::cout << "b creat" << std::endl;
}

HumanB::~HumanB()
{
	// std::cout << "b des" << std::endl;
}

void HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with their hand" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

//pq ca marche avec une reference ici?

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}