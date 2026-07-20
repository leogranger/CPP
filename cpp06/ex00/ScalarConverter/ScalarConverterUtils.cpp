#include "ScalarConverter.hpp"
#include <climits>
#include <string.h>

static int	isDouble(const std::string &toCheck)
{
	unsigned long	i = 0;

	if (toCheck[i] == '+' || toCheck[i] == '-')
		i++;
	while (isdigit(toCheck[i]))
		i++;
	if (toCheck[i] == '.')
		i++;
	while (isdigit(toCheck[i]))
		i++;
	if (i != toCheck.length())
		return (-1);
	return (DOUBLE);
}

static int	isFloat(const std::string &toCheck)
{
	unsigned long	i = 0;

	if (toCheck[i] == '+' || toCheck[i] == '-')
		i++;
	while (isdigit(toCheck[i]))
		i++;
	if (toCheck[i] == '.')
		i++;
	while (isdigit(toCheck[i]))
		i++;
	if (toCheck[i] == 'f' && i + 1 == toCheck.length())
		return (FLOAT);
	return (-1);
}

static int	isInt(const std::string &toCheck)
{
	unsigned long	i = 0;

	if (toCheck[i] == '+' || toCheck[i] == '-')
		i++;
	while (isdigit(toCheck[i]))
		i++;
	if (i == toCheck.length())
		return (INT);
	else if (i != toCheck.length() && toCheck[i] == '.' && toCheck.find("f"))
		return (isFloat(toCheck));
	else if (i != toCheck.length() && toCheck[i] == '.')
		return (isDouble(toCheck));
	return (-1);
}

int	checkType(const std::string &toCheck)
{
	unsigned long	len = toCheck.length();

	if (len == 1 && !isdigit(toCheck[0]))
		return (CHAR);
	else if (len == 3 && isascii(toCheck[1]) && toCheck[0] == '\'' && toCheck[2] == '\'')
		return (CHAR);
	else if (toCheck == "-inff" || toCheck == "+inff" || toCheck == "-inf" || toCheck == "+inf"
			|| toCheck == "nan" || toCheck == "nanf")
		return (SPECIAL);
	else
		return (isInt(toCheck));
}
