#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <sstream>
# include <ostream>
# include <fstream>
# include <cmath>

class BitcoinExchange {

	private:

		class Date {

			private:

				int _year;
				int _month;
				int _day;
				
				bool _valid;
				std::string _str;

			public:
				Date();
				Date(std::string const &str);
				Date(Date const &other);
				Date &operator=(Date const &other);
				virtual ~Date();

				bool valid() const;
				std::string str() const;

				bool operator==(Date const &other) const;
				bool operator!=(Date const &other) const;
				bool operator<(Date const &other) const;
				bool operator>(Date const &other) const;
				bool operator<=(Date const &other) const;
				bool operator>=(Date const &other) const;
			
			private:

				bool _valid_date_str(std::string const &str);
				bool _valid_date();

		};

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
		double _atof(std::string const &str) const;
		double _get_price(Date const &d) const;
		bool _one_token(std::string const &str) const;
};

#endif
