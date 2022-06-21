#include "main.hpp"

int main()
{
	Zombie *zombie;

	zombie = newZombie("ZombieA");
	randomChump("ZombieB");

	delete zombie;
	return (0);
}