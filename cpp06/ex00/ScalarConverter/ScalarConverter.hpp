#pragma once

#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter(void);
		static void	convert(std::string literal);
};

// to char: c_str()
// to int : stoi()
// to float: atof()
// to double: stod()