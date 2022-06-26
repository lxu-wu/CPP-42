#include "DiamandTrap.hpp"
DiamandTrap::DiamandTrap()
{
	std::cout << "DiamandTrap default constructor called" << std::endl;
}

DiamandTrap::DiamandTrap(std::string name): ClapTrap(name + "_trap_name")
{
	std::cout << "DiamandTrap name constructor called" << std::endl;
	// ClapTrap::_name = name + "_trap_name";
	// ScavTrap::_name = name;
	// FragTrap::_name = name;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
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
	std::cout << "I am " << this->_name << " " << ClapTrap::_name << std::endl;
}