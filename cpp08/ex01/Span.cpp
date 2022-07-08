#include "Span.hpp"
#include <algorithm>

Span::Span() : _max(0) {}
Span::Span(unsigned int max) : _max(max) {}
Span::Span(Span const & src) : _max(src._max)
{
	*this = src;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (this->_vect.size() < this->_max)
		this->_vect.push_back(n);
	else
		throw MaxException();
}

void Span::addPlageNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_vect.size() + end - begin < this->_max)
		this->_vect.insert(this->_vect.end(), begin, end);
	else
		throw MaxException();
}

unsigned int Span::getMax() const
{
	return this->_max;
}

std::vector<int> & Span::getVector()
{
	return this->_vect;
}

unsigned int Span::longestSpan()
{
	if (this->_vect.size() < 2)
		throw SizeException();
	else
	{
		std::vector<int>::iterator min = std::min_element(this->_vect.begin(), this->_vect.end());
		std::vector<int>::iterator max = std::max_element(this->_vect.begin(), this->_vect.end());
		return *max - *min;
	}
}
unsigned int Span::shortestSpan()
{
	if (this->_vect.size() < 2)
		throw SizeException();
	else
	{
		std::vector<int> v = this->_vect;

		std::sort(v.begin(), v.end());
		unsigned int ret = longestSpan();
		unsigned int tmp;
		for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++)
		{
			tmp = *(it + 1) - *it;
			ret = tmp < ret ? tmp : ret;
		}
		return ret;
	}
}

Span & Span::operator=(Span const & src)
{
	this->_vect = src._vect;
	return *this;
}