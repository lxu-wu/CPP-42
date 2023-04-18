#include "PmergeMe.hpp"

int main(int argc, char ** argv)
{
	if (argc == 1)
	{
		std::cout << "No arguments" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe me(argv);
		me.sort();
	}
	catch (std::exception & e)
	{
		std::cout << "Int overflow" << std::endl;
	}
	
}


// #include <chrono>
// #include <iostream>

// int main() {
//     std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Temps de début

//     for (int i = 0; i < 1000;i++);

//     std::chrono::system_clock::time_point end = std::chrono::system_clock::now(); // Temps de fin

//     std::chrono::nanoseconds elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Calcul` de la durée écoulée en ns
//     std::cout << "Temps écoulé : " << elapsed_ns.count() << " ns" << std::endl;

//     return 0;
// }
