#include "Array.hpp"

int main()
{
	std::cout << "------- My test -------" << std::endl;
	{
		Array<int> tab_empty;
		Array<int> tab_int(5);
		for (unsigned int i = 0; i < tab_int.size(); i++)
			tab_int[i] = i;
	
		Array<std::string> tab_string(5);
		tab_string[0] = "Je";
		tab_string[1] = "Suis";
		tab_string[2] = "Le";
		tab_string[3] = "Goat";
		tab_string[4] = "Sheeeesshhh";

		Array<std::string> tab_copy(tab_string);

		/* Before Changes */
		std::cout << "Tabs: " << std::endl;
		for (unsigned int i = 0; i < tab_int.size(); i++)
			std::cout << "Tab int index " << i << " = " << tab_int[i] << std::endl;

		for (unsigned int i = 0; i < tab_string.size(); i++)
			std::cout << "Tab string index " << i << " = " << tab_string[i] << std::endl;

		for (unsigned int i = 0; i < tab_copy.size(); i++)
			std::cout << "Tab copy index " << i << " = " << tab_copy[i] << std::endl;
		
		/* ------ Change Values ------ */
		for (unsigned int i = 0; i < tab_int.size(); i++)
			tab_int[i] = tab_int[i] * 100;
		
		for (unsigned int i = 0; i < tab_string.size(); i++)
			tab_string[i] = tab_string[i].append("_2");
		
		/* After Changes */
		std::cout << std::endl << "Tabs After: " << std::endl;
		for (unsigned int i = 0; i < tab_int.size(); i++)
			std::cout << "Tab int index " << i << " = " << tab_int[i] << std::endl;
			
		for (unsigned int i = 0; i < tab_string.size(); i++)
			std::cout << "Tab string index " << i << " = " << tab_string[i] << std::endl;
		
		for (unsigned int i = 0; i < tab_copy.size(); i++)
			std::cout << "Tab copy index " << i << " = " << tab_copy[i] << std::endl;

		/* Execption Test */
		std::cout << std::endl << "Exceptions test: " << std::endl;
		try
		{
			std::cout << tab_empty[0] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << tab_int[10] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}