#pragma once

#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <errno.h>
#include <string>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL
} literalType;

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter(void);
		static void	convert(const std::string &literal);
};

int	checkType(const std::string &toCheck);
