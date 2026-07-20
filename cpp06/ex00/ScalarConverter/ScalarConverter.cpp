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

static void	convertChar(const std::string &str)
{
	char c;
	if (str.length() == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(static_cast<unsigned char>(c)))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void printSpecial(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static void convertInt(const std::string &str)
{
	long	convertedInt = strtol(str.c_str(), NULL, 10);

	if (convertedInt > INT_MAX || convertedInt < INT_MIN || errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	int	nb = static_cast<int>(convertedInt);
	std::cout << "char: ";
	if (!isascii(nb))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<char>(nb)))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(nb) << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			<< static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
			<< static_cast<double>(nb) << std::endl;
}

static void	convertFloat(const std::string &str)
{
	float convertedFloat = (float)atof(str.c_str());
	std::cout << "char: ";
	if (!isascii(convertedFloat))
		std::cout << "impossible" << std::endl;
	else if (!isprint(convertedFloat))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(convertedFloat) << std::endl;
	std::cout << "int: ";
	if (static_cast<int>(convertedFloat) > INT_MAX || static_cast<int>(convertedFloat) > INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(convertedFloat) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << convertedFloat << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(convertedFloat) << std::endl;
}

static void	convertDouble(const std::string &str)
{
	double convertedDouble = atof(str.c_str());
	std::cout << "char: ";
	if (!isascii(convertedDouble))
		std::cout << "impossible" << std::endl;
	else if (!isprint(convertedDouble))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(convertedDouble) << std::endl;
	std::cout << "int: ";
	if (static_cast<int>(convertedDouble) > INT_MAX || static_cast<int>(convertedDouble) > INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(convertedDouble) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(convertedDouble) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << convertedDouble << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	int	type;

	type = checkType(literal);
	if (type == -1)
	{
		std::cout << "Wrong input." << std::endl;
		return ;
	}
	switch (type)
	{
		case CHAR :
			convertChar(literal);
			break ;
		case SPECIAL :
			printSpecial(literal);
			break ;
		case INT :
			convertInt(literal);
			break ;
		case FLOAT :
			convertFloat(literal);
			break ;
		case DOUBLE :
			convertDouble(literal);
			break ;
	}
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
5. Handle numeric limits and special values (-inff, +inff, -inf, + inf, nan, nanf)
*/