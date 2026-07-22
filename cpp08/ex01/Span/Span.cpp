#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span(unsigned int N)
	:_N(N)
{
	//std::cout << "Span constructor called." << std::endl;
}

Span::Span(const Span& other)
	:_N(other._N)
	,_span(other._span)
{
	//std::cout << "Span copy constructor called." << std::endl;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_span = other._span;
	}
	//std::cout << "Span copy assignment operator called." << std::endl;
	return (*this);
}

Span::~Span(void)
{
	//std::cout << "Span destructor called." << std::endl;
}

void	Span::addNumber(int nb)
{
	if (_N > _span.size())
		_span.push_back(nb);
	else
		throw std::invalid_argument("Vector is full.");
}

void	Span::addRange(std::vector<int> range)
{
	if (range.size() + _span.size() > _N)
		throw std::invalid_argument("Vector is full.");
	_span.insert(_span.end(), range.begin(), range.end());
}

int		Span::shortestSpan(void) const
{
	std::vector<int> copy;
	if (_span.size() <= 1)
		throw std::invalid_argument("The vector doesn't contain enough numbers to have a span.");
	copy = this->_span;
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
	return (*std::min_element(copy.begin() + 1, copy.end()));
}

int		Span::longestSpan(void) const
{
	if (_span.size() <= 1)
		throw std::invalid_argument("The vector doesn't contain enough numbers to have a span.");
	return ((*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end())));
}