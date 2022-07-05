#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:

	Character();
	Character(std::string const & name);
	Character(Character const & src);
	~Character();

	Character & operator=(Character const & src);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	// static void * getItemPtr(Character * target, int idx);

private:
	
	std::string _name;
	AMateria* _items[4];
	AMateria* _dropped[128];
};


#endif