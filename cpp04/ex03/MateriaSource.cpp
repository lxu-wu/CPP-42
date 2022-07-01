#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MaterialSource default constructor" << std::endl;
	for (int i=0; i < 4; i++)
		this->_source[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	// std::cout << "MaterialSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete this->_source[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._source[i])
			this->_source[i] = src._source[i];
		else
			this->_source[i] = 0;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (this->_source[i] == 0)
		{
			this->_source[i] = m;
			return ;
		}
		i++;
	}
	if (i == 4)
	{
		std::cout << "MateriaSource can't learn more" << std::endl;
		std::cout << "AMateria * m deleted" << std::endl;
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == this->_source[i]->getType())
			return this->_source[i]->clone();
	}

	return (0);
}