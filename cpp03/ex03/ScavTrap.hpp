#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:

	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & rhs);
	~ScavTrap();

	ScavTrap & operator=(ScavTrap const & rhs);

	void attack(const std::string& target);

	void guardGate();

protected:
	ScavTrap();
};

#endif