#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
public:

	Span(unsigned int max);
	Span(Span const & src);
	~Span();

	void addNumber(int n);
	void addPlageNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	unsigned int getMax() const;
	
	std::vector<int> & getVector();

	unsigned int longestSpan();
	unsigned int shortestSpan();


	class SizeException : public std::exception {
		virtual const char * what() const throw(){
			return "No span can be found";
		}
	};

	class MaxException : public std::exception {
		virtual const char * what() const throw(){
			return "Container max will be exceeded";
		}
	};

private:
	Span();
	Span & operator=(Span const & src);

	unsigned int const _max;
	std::vector<int> _vect;

};


#endif