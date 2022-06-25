#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name): _hitPoints(100), _energyPoints(50), _attackDamage(20), _name(name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & rhs)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap overload =" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack, has 0 hit point, is died." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't attack, has 0 energy point, is tired." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " is taken " << amount << " points of damage!" << std::endl;

	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " has repaired " << amount << "hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't be repaired, has 0 hit point, is died." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't be repaired, has 0 energy point, is tired." << std::endl;
}