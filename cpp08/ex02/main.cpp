#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "---- Pdf Tests Mutanstack -----" << std::endl;
	{
		MutantStack<int> mstack;

		MutantStack<int> c = mstack;
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;

		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	
	std::cout << std::endl <<"---- Tests list -----" << std::endl;
	{
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;
		
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	std::cout << std::endl <<"---- Tests vector -----" << std::endl;
	{
		std::vector<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::vector<int> s(mstack);
	}

	std::cout << std::endl <<"---- Tests overload =  -----" << std::endl;
	{
		MutantStack<int> mstack;

		MutantStack<int> c = mstack;
		c.push(5);
		c.push(17);
		
		std::cout << c.top() << std::endl;

		c.pop();
		
		std::cout << c.size() << std::endl;
		
		c.push(3);
		c.push(5);
		c.push(737);
		//[...]
		c.push(0);
		
		MutantStack<int>::iterator it = c.begin();
		MutantStack<int>::iterator ite = c.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(c);
	}

	
	return 0;
}
