#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
public:

	virtual ~Animal();
	std::string getType() const ;

	virtual void makeSound() const = 0;

protected:
	Animal();

	std::string _type;

private:
	Animal(Animal const & src);

	Animal & operator=(Animal const & src);

};

#endif