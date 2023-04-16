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

	std::chrono::system_clock::time_point start, end;

	start = std::chrono::system_clock::now();
	_merge_insert_sort(vect, 0, vect.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::microseconds vdiff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	start = std::chrono::system_clock::now();
	_merge_insert_sort(deck, 0, deck.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::microseconds ddiff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);


	std::cout << "Before:	";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;

	std::cout << "After:	";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << vdiff.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << deck.size() << " elements with std::deque : " << ddiff.count() << " us" << std::endl;

}

bool PmergeMe::_parse(char ** argv)
{
	for (size_t i = 1; argv[i]; i++)
	{
		if (_isNumber(argv[i]))
		{
			_v.push_back(std::stoi(argv[i]));
			_d.push_back(std::stoi(argv[i]));
		}
		else
		{
			std::cout << "Error : argument format" << std::endl;
			return false;
		}
	}
	return !_v.empty() && !_d.empty();
}

bool PmergeMe::_isNumber(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}