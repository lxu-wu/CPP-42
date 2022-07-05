#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:

	Cat();
	Cat(Cat const & src);
	~Cat();

	Cat & operator=(Cat const & src);

	void makeSound() const;

	Brain * getBrain() const;

private:

	Brain* _brain;

};


#endif