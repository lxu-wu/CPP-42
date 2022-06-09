#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);


	void	add(void);
	void	search(void) const;

private:

	Contact	_contact[8];
	int		_count;
	int		_index;

	Contact	_getContact(int index) const;
	int		_getCount(void) const;
	int		_getIndex(Contact contact) const;
	std::string _trunc(std::string str) const;
	int		_getInput(void) const;

};

#endif