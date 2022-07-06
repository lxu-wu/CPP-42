#ifndef SCALAIRE_HPP
# define SCALAIRE_HPP

# include <iostream>

class Scalaire
{
public:
	Scalaire(Scalaire const & src);
	Scalaire(std::string const & str);
	~Scalaire();

	int getInt() const;
	char getChar() const;
	float getFloat() const;
	double getDouble() const;

	class Impossible : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("impossible");
			}
	};

	class NonDisplayable : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Non displayable");
			}
	};

private:

	Scalaire();
	Scalaire & operator=(Scalaire const & src);

	std::string const _str;
	int _type;

	int _int;
	char _char;
	float _float;
	double _double;


	bool _isInt() const;
	bool _isChar() const;
	bool _isFloat() const;
	bool _isDouble() const;
	
};



#endif