#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const & src);
	~WrongAnimal();

	WrongAnimal & operator=(WrongAnimal const & src);
	
	void makeSound() const;

	std::string getType() const;

protected:

	std::string _type;
	
};


#endif