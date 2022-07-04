#include "iter.hpp"

int main()
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter<>(tab, 10, print);
}
