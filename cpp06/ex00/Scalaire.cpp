#include "Scalaire.hpp"

Scalaire::Scalaire() {}

Scalaire::Scalaire(Scalaire const & src) : _str(src._str)
{
	*this = src;
}

Scalaire::Scalaire(std::string const & str) : _str(str)
{

	_int = std::atoi(_str.c_str());
	_char = static_cast<char>(std::atoi(_str.c_str()));
	_float = static_cast<float>(std::atof(_str.c_str()));
	_double = std::atof(_str.c_str());
	if (this->_isInt())
	{
		_type = 1;
		_int = std::atoi(_str.c_str());
	}
	else if (this->_isChar())
	{
		_type = 2;
		_char = _str[0];
	}
	else if (this->_isFloat())
	{
		_type = 3;
		_float = static_cast<float>(std::atof(_str.c_str()));
	}
	else if (this->_isDouble())
	{
		_type = 4;
		_double = std::atof(_str.c_str());
	}
	else
	{
		_type = 0;
		throw Impossible();
	}
}

Scalaire::~Scalaire() {}

Scalaire & Scalaire::operator=(Scalaire const & src)
{
	this->_type = src._type;
	this->_int = src._int;
	this->_char = src._char;
	this->_float = src._float;
	this->_double = src._double;
	return *this;

}

bool Scalaire::_isInt() const
{
	for (int i = 0; this->_str[i]; i++)
	{
		if (this->_str[i] > '9' || this->_str[i] < '0')
			return false;
	}
	if (this->_str[0] == 0)
		return false;
	return true;
}

bool Scalaire::_isChar() const
{
	if (this->_str[0])
	{
		if (this->_str.length() > 1 || (this->_str[0] <= '9' && this->_str[0] >= '0'))
			return false;
		return true;
	}
	return false;
}

bool Scalaire::_isFloat() const
{
	int i = 0;

	if (this->_str == "-inff" || this->_str == "+inff" || this->_str == "nanf")
		return true;
	if (this->_str[i] <= '9' || this->_str[i] >= '0')
	{
		while (this->_str[++i] && this->_str[i] != '.')
			if (this->_str[i] > '9' || this->_str[i] < '0')
				return false;
		while (this->_str[++i] && this->_str[i] != 'f')
			if (this->_str[i] > '9' || this->_str[i] < '0')
				return false;
		if (this->_str[++i])
			return false;
		return true;
	}
	return false;
}

bool Scalaire::_isDouble() const
{
	int i = 0;


	if (this->_str == "-inf" || this->_str == "+inf" || this->_str == "nan")
		return true;
	if (this->_str[i] <= '9' || this->_str[i] >= '0')
	{
		while (this->_str[++i] && this->_str[i] != '.')
			if (this->_str[i] > '9' || this->_str[i] < '0')
				return false;
		while (this->_str[++i] && this->_str[i] != 0)
			if (this->_str[i] > '9' || this->_str[i] < '0')
				return false;
		return true;
	}
	return false;
}

int Scalaire::getInt() const
{
	if (this->_type == 0)
		throw Impossible();
	else if (_type == 1)
		return this->_int;
	else if (_type == 2)
		return static_cast<int>(this->_char);
	else if (_type == 3)
	{
		if (this->_int == 0 && this->_float)
			throw Impossible();
		return static_cast<int>(this->_float);
	}
	else
	{
		if (this->_int == 0 && this->_double)
			throw Impossible();
		return static_cast<int>(this->_double);
	}

}

char Scalaire::getChar() const
{
	if (this->_type == 0)
		throw Impossible();
	else if (_type == 1)
	{
		if (this->_int > 255 || this->_int < 0)
			throw Impossible();
		if (!isprint(this->_int))
			throw NonDisplayable();
		return static_cast<char>(this->_int);
	}
	else if (_type == 2)
	{
		return this->_char;
	}
	else if (_type == 3)
	{
		if ((this->_int == 0 && this->_float) || (this->_int != this->_float))
			throw Impossible();
		if (!isprint(this->_int))
			throw NonDisplayable();
		return static_cast<char>(this->_float);
	}
	else
	{
		if ((this->_int == 0 && this->_double) || (this->_int != this->_float))
			throw Impossible();
		if (!isprint(this->_int))
			throw NonDisplayable();
		return static_cast<char>(this->_double);
	}
}

float Scalaire::getFloat() const
{
	if (this->_type == 0)
		throw Impossible();
	else if (_type == 1)
		return static_cast<float>(this->_int);
	else if (_type == 2)
		return static_cast<float>(this->_char);
	else if (_type == 3)
		return this->_float;
	else
		return static_cast<float>(this->_double);
}

double Scalaire::getDouble() const
{
	if (this->_type == 0)
		throw Impossible();
	else if (_type == 1)
		return static_cast<double>(this->_int);
	else if (_type == 2)
		return static_cast<double>(this->_char);
	else if (_type == 3)
		return static_cast<double>(this->_float);
	else
		return this->_double;
}