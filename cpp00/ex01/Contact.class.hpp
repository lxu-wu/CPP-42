#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <iomanip>

class Contact
{
public:

	Contact(void);
	~Contact(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;

	void	setFirstName(std::string str);
	void	setLastName(std::string str);
	void	setNickname(std::string str);
	int		setPhoneNumber(std::string str);
	void	setDarkestSecret(std::string str);

	void	resetData(void);

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};

#endif