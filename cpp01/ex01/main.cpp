#include "main.hpp"

int main()
{
	Zombie *horde;
	const int N = 10;

	horde = zombieHorde(N, "Name");
	for(int i=0;i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}