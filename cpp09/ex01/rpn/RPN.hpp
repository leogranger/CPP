#pragma once

# include <iostream>
# include <stack>
# include <exception>

class RPN
{
	private:
		std::stack<double> _stack;

	public:

		RPN(void);
		~RPN(void);
		RPN(const RPN& other);
		RPN&operator=(const RPN& other);
		double	popValue();
		void	calculate(char *str);

};