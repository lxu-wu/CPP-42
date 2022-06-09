#include "Contact.class.hpp"

Contact::Contact()
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::getFirstName(void) const
{
	return this->_first_name;
}

std::string Contact::getLastName(void) const
{
	return this->_last_name;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phone_number;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_darkest_secret;
}

void	Contact::setFirstName(std::string str)
{
	this->_first_name = str;
}

void	Contact::setLastName(std::string str)
{
	this->_last_name = str;
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
}

int	Contact::setPhoneNumber(std::string str)
{
	int	digit(0);

	for (int i=0;str[i];i++)
	{
		if (!(str[i] == ',' || str[i] == ';' || str[i] == '+' || str[i] == '#' || str[i] == '*') && (std::isdigit(str.c_str()[i]) == 0 || (digit++ && false)))
		{
			std::cout << "Phone number is composed of '+' '#' '*' ';' ',' and digits" << std::endl;
			return 1;
		}
	}
	if (digit < 4)
	{
		std::cout << "Phone number is composed of at least 4 digit" << std::endl;
		return 1;
	}
	this->_phone_number = str;
	return 0;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkest_secret = str;
}
