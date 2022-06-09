#include "PhoneBook.class.hpp"

int main(int argc, char **argv)
{
	PhoneBook	phonebook;
	std::string	str("");

	(void)argv;
	if (argc > 1)
	{
		std::cout << "without argument. exec: ./phonebook" << std::endl;
		return (1);
	}
	
	
	
	std::cout << "In your phone book" << std::endl << std::endl;
	
	
	while (1)
	{
		std::cout << "chose your action: ";
		getline(std::cin, str);
		// std::cout << "action == " << str << std::endl;
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str == "EXIT")
		{
			std::cout << "Exit phone book" << std::endl;
			break;
		}
		else if (!std::cin.eof())
			std::cout << "you can ADD / SEARCH / EXIT" << std::endl;
		if (std::cin.eof())
		{
			std::cout << std::endl << "End Of File, program quit" << std::endl;
			return (0);
		}
	}
	return (0);
}