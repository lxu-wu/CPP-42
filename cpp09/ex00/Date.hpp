#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <ostream>

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


#endif