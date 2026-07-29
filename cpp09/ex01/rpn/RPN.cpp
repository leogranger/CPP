#include "RPN.hpp"
#include <stdexcept>

RPN::RPN(void)
{
	//std::cout << "RPN constructor called." << std::endl;
}

RPN::~RPN(void)
{
	//std::cout << "RPN destructor called." << std::endl;
}

RPN::RPN(const RPN& other)
	:_stack(other._stack)
{
	//std::cout << "RPN copy constructor called." << std::endl;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	//std::cout << "RPN copy assignment operator called." << std::endl;
	return (*this);
}

double	RPN::popValue()
{
	if (this->_stack.empty())
	{
		throw std::invalid_argument("Error: wrong input.");
	}
	double x = _stack.top();
	_stack.pop();
	return (x);
}

void	RPN::calculate(char *str)
{
	if (!str)
	{
		throw std::invalid_argument("Error: empty input.");
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			continue ;
		if (isdigit(str[i]))
		{
			this->_stack.push(static_cast<double>(str[i] - '0'));
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			double y = popValue();
			double x = popValue();
			switch(str[i])
			{
				case '+': this->_stack.push(x + y); break ;
				case '-': this->_stack.push(x - y); break ;
				case '*': this->_stack.push(x * y); break ;
				case '/':
					if (y == 0)
						throw std::invalid_argument("Error: division by 0.");
					this->_stack.push(x / y);
					break ;
			}
		}
		else
		{
			throw std::invalid_argument("Error: wrong input, only numbers < 10 and operation signs are accepted.");
		}
	}
	if (this->_stack.size() > 1 || this->_stack.size() == 0)
	{
		throw std::invalid_argument("Error: wrong input.");
	}
	else
	{
		std::cout << this->_stack.top() << std::endl;
	}
}
