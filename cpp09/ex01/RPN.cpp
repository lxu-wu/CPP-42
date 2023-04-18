#include "RPN.hpp"

RPN::RPN() : _valid(false) {}

RPN::RPN(char *input) : _valid(false) {
	std::string token;
	_input << input;

	while (!_input.eof())
	{
		
		_input >> token;
		if (token.empty())
			break;
		else if (token.size() != 1 || (!_isOperator(token[0]) && !std::isdigit(token[0])))
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		else if (std::isdigit(token[0]))
		{
			_stack.push(std::stoi(token));
		}
		else
		{
			if (!_operation(token[0]))
				return ;
		}
		token.clear();
	}
	if (_stack.size() != 1)
	{
		std::cout << "your number is not correct" << std::endl;
		return ;
	}
	_valid = true;
}

RPN::RPN(const RPN &rhs) {
	*this = rhs;
}

RPN &RPN::operator=(const RPN &rhs) {
	_stack = rhs._stack;
	_input.clear();
	_input << rhs._input.str();
	_valid = rhs._valid;
	return *this;
}

RPN::~RPN() {}

void RPN::print() {
	if (!_valid)
		return ;

	std::cout << _stack.top() << std::endl;
}

bool RPN::_isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::_operation(char operation)
{
	if (_stack.size() < 2)
	{
		std::cout << "Can't do operation on 1 number" << std::endl;
		return false;
	}
	long num1, num2, result;
	num2 = _stack.top();
	_stack.pop();
	num1 = _stack.top();
	_stack.pop();

	switch (operation)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 == 0)
			{
				std::cout << "Can't divide by 0" << std::endl;
				return false;
			}
			result = num1 / num2;
			break;
	}
	if (result > INT_MAX || result < INT_MIN)
	{
		std::cout << "Result is too big or too small" << std::endl;
		return false;
	}
	_stack.push(result);
	return true;
}

bool RPN::_isSpace(std::string str)
{
	for(std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isspace(*it))
			return false;
	}
	return true;
}