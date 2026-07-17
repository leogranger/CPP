#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "ScalarConverter copy assignment operator called." << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}


void	ScalarConverter::convert(std::string literal)
{
	
}

// to char: c_str()
// to int : stoi()
// to float: atof()
// to double: stod()

/*
TO DO :
1. Parse the string we receive and return the corresponding type (int, char, float, double)
2. Create converter functions
3. Convert to its actual type
4. Convert to the 3 other types, if a conversion doesnt make any sense -> print impossible
5. Hanfdle numeric limits and special values (-inff, +inff, -inf, + inf, nan, nanf)
*/