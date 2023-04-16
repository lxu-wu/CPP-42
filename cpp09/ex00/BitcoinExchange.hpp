#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <sstream>
# include <ostream>
# include <fstream>
# include "Date.hpp"

class BitcoinExchange {

	private:
		std::map<Date, double> _data;
		bool _valid;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		virtual ~BitcoinExchange();

		void action(std::string const &file);

	private:

		bool _data_extract(std::string const &file);
		bool _is_number(std::string const &str) const;
		double _get_price(Date const &d) const;
};

#endif
