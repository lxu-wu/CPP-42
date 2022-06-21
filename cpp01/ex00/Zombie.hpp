#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
public:

	Zombie(std::string name);
	~Zombie();

	void announce(void);

	// std::string getName(void);
	// void setName(std::string str);

private:
	std::string const _name;
};

#endif