#include "Date.hpp"

Date::Date() : _year(2009), _month(1), _day(2), _valid(true), _str("2009-01-02") {}

Date::Date(std::string const &str)
{
	_str = str;
	if (_valid_date_str(str))
	{
		_year = std::stoi(str.substr(0, 4));
		_month = std::stoi(str.substr(5, 2));
		_day = std::stoi(str.substr(8, 2));
		if (_valid_date())
			_valid = true;
		else
			_valid = false;
	}
	else
		_valid = false;
}

Date::Date(Date const &other) : _year(other._year), _month(other._month), _day(other._day), _valid(other._valid), _str(other._str) {}

Date &Date::operator=(Date const &other)
{
	_year = other._year;
	_month = other._month;
	_day = other._day;
	_valid = other._valid;
	_str = other._str;
	return (*this);
}

Date::~Date() {}

bool Date::valid() const
{
	return _valid;
}

std::string Date::str() const
{
	return _str;
}

bool Date::operator==(Date const &other) const
{
	return (_year == other._year && _month == other._month && _day == other._day);
}

bool Date::operator!=(Date const &other) const
{
	return !(*this == other);
}

bool Date::operator<(Date const &other) const
{
	return (_year < other._year ||
		(_year == other._year && _month < other._month) ||
			(_year == other._year && _month == other._month && _day < other._day));
}

bool Date::operator>(Date const &other) const
{
	return other < *this;
}

bool Date::operator<=(Date const &other) const
{
	return !(other < *this);
}

bool Date::operator>=(Date const &other) const
{
	return !(*this < other);
}

bool Date::_valid_date_str(std::string const &str)
{
	if (str.length() != 10)
		return false;
	for (int i = 0; i < 4; i++)
		if (isdigit(str[i]) == false)
			return false;
	for (int i = 5; i < 7; i++)
		if (isdigit(str[i]) == false)
			return false;
	for (int i = 8; i < 10; i++)
		if (isdigit(str[i]) == false)
			return false;
	if (str[4] != '-' || str[7] != '-')
		return false;
	return true;
}

bool Date::_valid_date()
{
	if (_year < 2009 || _month < 1 || _month > 12 || _day < 1 || _day > 31)
		return false;
	if (_month == 2)
	{
		if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
			return _day <= 29;
		else
			return _day <= 28;
	}
	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
		return _day <= 30;
	else
		return _day <= 31;
}

