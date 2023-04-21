#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _v(), _d(), _valid(false) {}

PmergeMe::PmergeMe(char ** argv) : _v(), _d(), _valid(false)
{
	if (_parse(argv))
		_valid = true;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		_v = rhs._v;
		_d = rhs._d;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort()
{
	if (!_valid)
		return;
	std::vector<int> vect(_v);
	std::deque<int> deck(_d);

	clock_t start, end;
	double vdiff = 0, ddiff = 0;

	start = clock();
	_merge_insert_sort(vect, 0, vect.size() - 1);
	end = clock();
	vdiff = 1000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = clock();;
	_merge_insert_sort(deck, 0, deck.size() - 1);
	end = clock();
	ddiff = 1000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
 
	std::cout << "Before:	";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;

	std::cout << "After:	";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << vdiff << " us" << std::endl;
	std::cout << "Time to process a range of " << deck.size() << " elements with std::deque : " << ddiff << " us" << std::endl;

}

bool PmergeMe::_parse(char ** argv)
{
	long val;

	for (size_t i = 1; argv[i]; i++)
	{
		if (!std::string(argv[i]).empty())
		{
			val = _atoi(argv[i]);
			if (val < 0 || val > INT_MAX)
			{
				std::cout << "Error : argument format" << std::endl;
				return false;
			}
			_v.push_back(val);
			_d.push_back(val);
		}
	}
	if (_v.empty() || _d.empty())
	{
		std::cout << "Error : argument empty" << std::endl;
		return false;
	}
	return true;
}

// bool PmergeMe::_isNumber(std::string str)
// {
// 	for (size_t i = 0; i < str.length(); i++)
// 	{
// 		if (!isdigit(str[i]))
// 			return false;
// 	}
// 	return true;
// }

long PmergeMe::_atoi(std::string const &str) const
{
    char *end;
    long l = std::strtol(str.c_str(), &end, 10);
    if (*end)
		return LONG_MAX;
	return l;
}