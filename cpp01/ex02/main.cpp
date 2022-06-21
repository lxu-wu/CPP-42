#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::endl << "memory address:" << std::endl;
	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout <<std::endl << "value:" << std::endl;
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}

	// string = "bonjour";
	// // *(stringPTR + 2) = 'b';
	// (*stringPTR)[1] = '1';
	// stringREF[2] = 'c';

	// std::cout << &string << std::endl;
	// std::cout << stringPTR << std::endl;
	// std::cout << &stringREF << std::endl;

	// std::cout << string << std::endl;
	// std::cout << *stringPTR << std::endl;
	// std::cout << stringREF << std::endl;

	// std::string str = "bye";

	// stringPTR = &str;

	// std::cout << &string << std::endl;
	// std::cout << stringPTR << std::endl;
	// std::cout << &stringREF << std::endl;

	// std::cout << string << std::endl;
	// std::cout << *stringPTR << std::endl;
	// std::cout << stringREF << std::endl;



	// stringPTR = &string;
	// std::cout << std::endl << *stringPTR << std::endl;
	// *stringPTR = str;
	// std::cout << &string << std::endl;
	// std::cout << stringPTR << std::endl;
	// std::cout << &stringREF << std::endl;

	// std::cout << string << std::endl;
	// std::cout << *stringPTR << std::endl;
	// std::cout << stringREF << std::endl;