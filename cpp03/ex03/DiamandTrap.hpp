#ifndef DIAMANDTRAP_HPP
# define DIAMANDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamandTrap : public ScavTrap, public FragTrap
{
public:

	DiamandTrap(std::string name);
	DiamandTrap(DiamandTrap const & rhs);
	~DiamandTrap();

	DiamandTrap & operator=(DiamandTrap const & rhs);

	void attack(const std::string& target);

	void whoAmI();

private:

	DiamandTrap();
	std::string _name;

};



#endif