#include "Character.hpp"

Character::Character() : _name("Unnamed")
{
	// std::cout << "Character default constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		this->_items[i] = 0;
}

Character::Character(std::string const & name) : _name(name)
{
	// std::cout << "Character name constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		this->_items[i] = 0;
}

Character::Character(Character const & src) : _name(src._name)
{
	// std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character()
{
	// std::cout << "Character destructor called" << std::endl;
	
	for(int i = 0;i < 4; i++)
		if (this->_items[i])
			delete this->_items[i];
}

Character & Character::operator=(Character const & src)
{
	this->_name = src._name;
	
	for(int i = 0;i < 4; i++)
		if (this->_items[i])
			delete this->_items[i];


	for (int i = 0; i < 4; i++)
	{
		if (src._items[i])
			this->_items[i] = src._items[i]->clone();
		else
			this->_items[i] = 0;
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (m)
	{
		while (i < 4 && this->_items[i])
			i++;
		if (i < 4)
			this->_items[i] = m;
		else
			std::cout << "Inventory's full, you can't add new item" << std::endl;
	}
	else
		std::cout << "Nothing to add in inventory" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index: " << idx << " no exist" << std::endl;
		return ;
	}
	
	if (this->_items[idx])
	{
		std::cout << this->_items[idx]->getType() << " at index: " << idx;
		this->_items[idx] = 0;
		std::cout << " unequiped" << std::endl;
	}
	else
		std::cout << "Inventory in index: "  << idx << " is empty" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->_items[idx])
		 this->_items[idx]->use(target);
	else if (this->_items[idx])
		std::cout << "No materia to use" << std::endl;
	else
		std::cout << "Index: " << idx << " no exist. ([0-3])" << std::endl;
}
