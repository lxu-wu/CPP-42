#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & rhs)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	*this = rhs;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap overload =" << std::endl;
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_name = rhs._name;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't attack, has 0 hit point, is died." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " can't attack, has 0 energy point, is tired." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " entered in Gate keeper mode!" << std::endl;
}