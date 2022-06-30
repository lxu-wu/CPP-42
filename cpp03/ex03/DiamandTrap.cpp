#include "DiamandTrap.hpp"
DiamandTrap::DiamandTrap()
{
	std::cout << "DiamandTrap default constructor called" << std::endl;
}

DiamandTrap::DiamandTrap(std::string name):
{
	std::cout << "DiamandTrap name constructor called" << std::endl;
	this->ClapTrap::_name = name + "_trap_name";
	this->_name = name;
	this-> FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamandTrap::DiamandTrap(DiamandTrap const & rhs): ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "DiamandTrap copy constructor called" << std::endl;
	*this = rhs;
}

DiamandTrap::~DiamandTrap()
{
	std::cout << "Destructor called" << std::endl;
}

DiamandTrap & DiamandTrap::operator=(DiamandTrap const & rhs)
{
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_name = rhs._name;
	return *this;
}

void DiamandTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamandTrap::whoAmI()
{
}
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "I am " << this->_name << " " << ClapTrap::_name << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << this->_name << this->_name << " can't speak, has 0 hit point, is died." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " can't speak, has 0 energy point, is tired." << std::endl;
}