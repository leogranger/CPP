#pragma once

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:

		unsigned int				_N;
		std::vector<int>	_span;

	public:

		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span(void);
		void	addNumber(int nb);
		void	addRange(std::vector<int> range);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

};