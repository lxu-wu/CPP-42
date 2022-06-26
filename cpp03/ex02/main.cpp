#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
	std::cout << "OLD TEST" << std::endl;
	ClapTrap claptrap("Watermelon");
	ClapTrap claptrap2(claptrap);

	claptrap.attack("Banana");
	claptrap.takeDamage(2);
	claptrap.beRepaired(5);
	claptrap.attack("Mango");
	claptrap.attack("Strawberry");
	claptrap.attack("Blueberry");
	claptrap.attack("Melon");
	claptrap.attack("Kaki");
	claptrap.attack("Blackberry");
	claptrap.attack("Passion");
	claptrap.attack("Jack");
	claptrap.attack("Durian");
	claptrap.beRepaired(5);
	claptrap.takeDamage(12);
	claptrap.attack("Grape");
	claptrap.beRepaired(5);
	claptrap.takeDamage(12);
	claptrap.attack("Peach");
	claptrap.beRepaired(5);

	std::cout << std::endl;

	claptrap2.attack("Banana");
	claptrap2.takeDamage(2);
	claptrap2.beRepaired(5);
	claptrap2.attack("Mango");
	claptrap2.attack("Strawberry");
	claptrap2.attack("Blueberry");
	claptrap2.attack("Melon");
	claptrap2.attack("Kaki");
	claptrap2.attack("Blackberry");
	claptrap2.attack("Passion");
	claptrap2.attack("Jack");
	claptrap2.attack("Durian");
	claptrap2.beRepaired(5);
	claptrap2.takeDamage(12);
	claptrap2.attack("Grape");
	claptrap2.beRepaired(5);
	claptrap2.takeDamage(12);
	claptrap2.attack("Peach");
	claptrap2.beRepaired(5);

	std::cout << std::endl;

	ClapTrap claptrap3(claptrap2);

	claptrap3.attack("Banana");
	}
	{
		std::cout << "----- ScavTrap Test ------" << std::endl << std::endl;
		ScavTrap a("Scav");
		ScavTrap b(a);

		a.attack("Bla");
		a.guardGate();
		a.takeDamage(99);
		a.attack("Bla");
		a.beRepaired(1);
		a.guardGate();
		a.takeDamage(2);
		a.beRepaired(1);
		a.guardGate();

		std::cout << std::endl;
		b.attack("Bla");
		b.guardGate();
		b.takeDamage(99);
		b.attack("Bla");
		b.beRepaired(1);
		b.guardGate();
		b.takeDamage(2);
		b.beRepaired(1);
		b.guardGate();
		std::cout << std::endl;

		ScavTrap c(b);

		c.attack("Ploi");
		c.guardGate();

	}
	{
	
	FragTrap a("Me");
	ClapTrap b("Ally");
	
	a.attack("Enemy");
	b.attack("Enemy");
	a.takeDamage(99);
	a.beRepaired(1);
	a.highFivesGuys();
	a.attack("Enemy");
	a.takeDamage(2);
	a.beRepaired(1);
	a.highFivesGuys();
	}
}