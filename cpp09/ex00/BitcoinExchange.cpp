#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(), _valid(false)
{
	if (_data_extract("data.csv"))
		_valid = true;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _data(other._data), _valid(other._valid) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	_data = other._data;
	_valid = other._valid;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::action(std::string const &file)
{
	if (!_valid)
	{
		std::cerr << "Invalid BitcoinExchange can't do action" << std::endl;
		return;
	}
	std::ifstream f(file);
	std::string line;
	std::string date;
	std::string value;
	double qty;

	if (!f.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}


	std::getline(f, line);
	std::stringstream ss(line);
	std::getline(ss, date, '|');
	std::getline(ss, value, '|');
	std::stringstream dss(date);
	std::stringstream vss(value);
	dss >> date;
	vss >> value;
	if (!ss.eof() || date != "date" || value != "value"|| !_one_token(dss.str()) || !_one_token(vss.str()))
	{
		std::cerr << "Invalid input file" << std::endl;
		return;
	}

	while (std::getline(f, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, value, '|');
		std::stringstream dss(date);
		std::stringstream vss(value);
		dss >> date;
		vss >> value;
		BitcoinExchange::Date d(date);
		
		qty = _atof(value.c_str());
		// if (date.empty() || value.empty())
		// 	std::cout << ""
		if (!ss.eof() || !_one_token(dss.str()) || !_one_token(vss.str()) || qty == INFINITY)
			std::cout << "Error: line." << std::endl;
		else if (!d.valid())
			std::cout << "Error: bad input => " << d.str() << std::endl;
		else if (qty < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (qty > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			if (d < _data.begin()->first)
				std::cout << "Error: too early." << std::endl;
			else
				std::cout << d.str() << " => " << qty << " = " << (qty * _get_price(d)) << std::endl;
		}
		date.clear();
		value.clear();
	}

}


bool BitcoinExchange::_data_extract(std::string const &file)
{
	std::ifstream f(file);
	std::string line;
	std::string date;
	std::string value;
	double tmp;

	if (!f.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return false;
	}
	

	std::getline(f, line);
	std::stringstream ss(line);
	std::getline(ss, date, ',');
	std::getline(ss, value, ',');
	std::stringstream dss(date);
	std::stringstream vss(value);
	dss >> date;
	vss >> value;
	if (date != "date" || value != "exchange_rate" || !_one_token(dss.str()) || !_one_token(vss.str()))
	{
		std::cerr << "Invalid data" << std::endl;
		return false;
	}
	if (f.eof())
		return false;
	while (std::getline(f, line))
	{
		if (line.empty())
			return false;
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value, ',');
		std::stringstream dss(date);
		std::stringstream vss(value);
		dss >> date;
		vss >> value;
		BitcoinExchange::Date d(date);
		if (!ss.eof() || !d.valid() || !_one_token(dss.str()) || !_one_token(vss.str()))
		{
		
			std::cerr << "Invalid data" << std::endl;
			return false;
		}
		tmp = _atof(value.c_str());
		if (tmp == INFINITY || tmp < 0)
			return false;
		_data[d] = tmp;
		date.clear();
		value.clear();
	}
	return true;
}

double BitcoinExchange::_atof(std::string const &str) const
{
    char *end;
    double d = std::strtod(str.c_str(), &end);
    if (*end)
		return INFINITY;
	return d;
}

double BitcoinExchange::_get_price(BitcoinExchange::Date const &d) const
{
	std::map<Date, double>::const_iterator it = _data.find(d);

	if (it == _data.end())
	{
		it = _data.upper_bound(d);
		if (it != _data.begin())
			--it;
	}
	return it->second;
}

bool BitcoinExchange::_one_token(std::string const &str) const
{
	std::string::const_iterator it = str.begin();
	
	while (it != str.end() && std::isspace(*it))
		++it;
	while (it != str.end() && !std::isspace(*it))
		++it;
	while (it != str.end() && std::isspace(*it))
		++it;
	return (!str.empty() && it == str.end());
}

BitcoinExchange::Date::Date() : _year(2009), _month(1), _day(2), _valid(true), _str("0000-01-00") {}

BitcoinExchange::Date::Date(std::string const &str)
{
	_str = str;
	if (_valid_date_str(str))
	{
		_year = atoi(str.substr(0, 4).c_str());
		_month = atoi(str.substr(5, 2).c_str());
		_day = atoi(str.substr(8, 2).c_str());
		if (_valid_date())
			_valid = true;
		else
			_valid = false;
	}
	else
		_valid = false;
}

BitcoinExchange::Date::Date(BitcoinExchange::Date const &other) : _year(other._year), _month(other._month), _day(other._day), _valid(other._valid), _str(other._str) {}

BitcoinExchange::Date &BitcoinExchange::Date::operator=(BitcoinExchange::Date const &other)
{
	_year = other._year;
	_month = other._month;
	_day = other._day;
	_valid = other._valid;
	_str = other._str;
	return (*this);
}

BitcoinExchange::Date::~Date() {}

bool BitcoinExchange::Date::valid() const
{
	return _valid;
}

std::string BitcoinExchange::Date::str() const
{
	return _str;
}

bool BitcoinExchange::Date::operator==(BitcoinExchange::Date const &other) const
{
	return (_year == other._year && _month == other._month && _day == other._day);
}

bool BitcoinExchange::Date::operator!=(BitcoinExchange::Date const &other) const
{
	return !(*this == other);
}

bool BitcoinExchange::Date::operator<(BitcoinExchange::Date const &other) const
{
	return (_year < other._year ||
		(_year == other._year && _month < other._month) ||
			(_year == other._year && _month == other._month && _day < other._day));
}

bool BitcoinExchange::Date::operator>(BitcoinExchange::Date const &other) const
{
	return other < *this;
}

bool BitcoinExchange::Date::operator<=(BitcoinExchange::Date const &other) const
{
	return !(other < *this);
}

bool BitcoinExchange::Date::operator>=(BitcoinExchange::Date const &other) const
{
	return !(*this < other);
}

bool BitcoinExchange::Date::_valid_date_str(std::string const &str)
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

bool BitcoinExchange::Date::_valid_date()
{
	if (_month < 1 || _month > 12 || _day < 1 || _day > 31)
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
