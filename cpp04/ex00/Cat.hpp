#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
public:

	Cat();
	Cat(Cat const & src);
	~Cat();

	Cat & operator=(Cat const & src);

	void makeSound() const;
};


#endif