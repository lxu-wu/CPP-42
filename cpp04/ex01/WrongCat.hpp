#ifndef WrongCAT_HPP
# define WrongCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:

	WrongCat();
	WrongCat(WrongCat const & src);
	~WrongCat();

	WrongCat & operator=(WrongCat const & src);

	void makeSound() const;
};


#endif