#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)//: ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = name;
}

FragTrap::FragTrap(FragTrap const & rhs)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "FragTrap " << this->_name << " asking hive five guys!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " can't ask hive five, has 0 hit point, is died." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " can't ask hive five, has 0 energy point, is tired." << std::endl;
}