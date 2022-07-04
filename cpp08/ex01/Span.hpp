#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
public:

	Span();
	Span(unsigned int max);
	Span(Span const & src);
	~Span();

	Span & operator=(Span const & src);


private:

	unsigned int const _max;
	std::vector<int> _vect;

};


#endif