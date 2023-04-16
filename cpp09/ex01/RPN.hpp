#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

class RPN {

	private:

		std::stack<int> _stack;
		std::stringstream _input;
		bool _valid;

	public:

		RPN();
		RPN(char *input);
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
		virtual ~RPN();

		void print();

	private:

		bool _isOperator(char c) const;
		bool _operation(char c);


};

#endif