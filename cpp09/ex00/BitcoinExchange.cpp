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
	if (date != "date" || value != "value")
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
		Date d(date);
		qty = stod(value);
		if (!ss.eof())
			std::cout << "Error: line." << std::endl;
		else if (!d.valid())
			std::cout << "Error: bad input => " << d.str() << std::endl;
		else if (!_is_number(value))
			std::cout << "Error: number error." << std::endl;
		else if (qty < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (qty > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << d.str() << " => " << qty << " = " << (qty * _get_price(d)) << std::endl;
			// std::cout << d.str() << " => " << qty << " = " << (qty * (_data.lower_bound(d))->second) << std::endl;
	}

}


bool BitcoinExchange::_data_extract(std::string const &file)
{
	std::ifstream f(file);
	std::string line;
	std::string date;
	std::string value;
	
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
	if (date != "date" || value != "exchange_rate")
	{
		std::cerr << "Invalid data" << std::endl;
		return false;
	}


	while (std::getline(f, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value, ',');
		std::stringstream dss(date);
		std::stringstream vss(value);
		dss >> date;
		vss >> value;
		Date d(date);
		if (ss.eof() && d.valid() && _is_number(value))
			_data[d] = std::stod(value);
		else
		{
			std::cerr << "Invalid data" << std::endl;
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::_is_number(std::string const &str) const
{
	std::string::const_iterator it = str.begin();
	
	while (it != str.end() && std::isdigit(*it))
		++it;
	if (it != str.end() && *it == '.')
		++it;
	while (it != str.end() && std::isdigit(*it))
		++it;
	return (!str.empty() && it == str.end());
}

double BitcoinExchange::_get_price(Date const &d) const
{
	std::map<Date, double>::const_iterator it = _data.find(d);

	if (it == _data.end())
	{
		return (--_data.lower_bound(d))->second;
	}
	return it->second;
}