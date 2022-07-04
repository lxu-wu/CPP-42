#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _count(0), _index(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::add()
{
	std::string	str;

	std::cout << std::endl << "Adding contact..." << std::endl << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return ;
	
	
	this->_contact[this->_index].setFirstName(str);
	std::cout << "Last name: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return ;
	
	
	this->_contact[this->_index].setLastName(str);
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return ;
	
	
	this->_contact[this->_index].setNickname(str);
	while (1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, str);
		if (!this->_contact[this->_index].setPhoneNumber(str))
			break ;
	}
	
	
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return ;
	this->_contact[this->_index].setDarkestSecret(str);
	
	
	std::cout << std::endl << "contact added" << std::endl;
	this->_index = (this->_index + 1) % 8;
	if (this->_count < 8)
		this->_count++;
}

void	PhoneBook::search() const
{
	int input;

	std::cout << std::endl << "|-------------------------------------------|" << std::endl;
	std::cout << "|               CONTACT  LIST               |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	
	
	
	if (this->_count == 0)
	{
		std::cout << std::endl << "Contact list is empty" << std::endl;
		return ;
	}



	for(int i = 0; i < this->_count; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << this->_trunc(this->_getContact(i).getFirstName());
		std::cout << "|" << std::setw(10) << this->_trunc(this->_getContact(i).getLastName());
		std::cout << "|" << std::setw(10) << this->_trunc(this->_getContact(i).getNickname()) << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl << std::endl;
	}



	input = this->_getInput();
	if (input == -1)
		return ;
	std::cout << "index: " << input << std::endl;
	std::cout << "First name: " << this->_getContact(input).getFirstName() << std::endl;
	std::cout << "Last name: " << this->_getContact(input).getLastName() << std::endl;
	std::cout << "Nickname: " << this->_getContact(input).getNickname() << std::endl;
	std::cout << "Phone number: " << this->_getContact(input).getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_getContact(input).getDarkestSecret() << std::endl << std::endl;

}

Contact	PhoneBook::_getContact(int index) const
{
	if (this->_count == 8)
		return this->_contact[(index + this->_index) % 8];
	return (this->_contact[index]);
}

int		PhoneBook::_getCount(void) const
{
	return this->_count;
}

int		PhoneBook::_getIndex(Contact contact) const
{
	int i(0);
	
	while (i < 8)
		if (&this->_contact[i++] == &contact)
			break ;
	if (this->_count == 8)
		return abs(i - this->_index);
	return i;
}

std::string	PhoneBook::_trunc(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int		PhoneBook::_getInput(void) const
{
	std::string str;
	int			i;

	while (1)
	{
		std::cout << "what is contact's index: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (-1);
		while (i < str.length())
		{
			if (std::isdigit(str[i++]) == 0)
			{
				std::cout << "Only digit" << std::endl;
				break ;
			}
		}
		if (i >= str.length())
		{
			i = std::atoi(str.c_str());
			if (i < this->_count)
				return i;
			std::cout << "use index 0 to " << this->_count - 1 << std::endl;
		}
	}
}