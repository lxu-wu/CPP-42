#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & rhs);
	~ClapTrap();

	ClapTrap & operator=(ClapTrap const & rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	ClapTrap();
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};


#endif