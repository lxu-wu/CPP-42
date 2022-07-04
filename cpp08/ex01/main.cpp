#include "Span.hpp"
# include <set>

int main()
{
	std::vector<int> a{100, 20, 30};

	// sort(a.begin(), a.end());
	a.push_back(2);
	a.push_back(2);

	for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}