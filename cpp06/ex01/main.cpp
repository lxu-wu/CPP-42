#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data a;

	a.dataInt = 100;
	a.dataString = "Bonjour";

	uintptr_t b = serialize(&a);

	std::cout << b << std::endl; //decimal
	std::cout << &a << std::endl; //hexa

	Data * c = deserialize(b);

	std::cout << c->dataInt << std::endl;
	std::cout << c->dataString << std::endl;
}