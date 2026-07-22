#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cstdlib>

static bool isLeap(long year)
{
	if (year % 400 == 0 || year % 100 == 0 || year % 4 == 0)
		return (true);
	return (false);
}

bool isValidDate(std::string date)
{
	if (date.empty())
		return false;
	else if (date.find("-", 0) != 4 || date.find("-", 5) != 8)
	{
		std::cerr << "Error: Invalid format." << std::endl;
		return false;
	}

	char *p = NULL;
	std::string year = date.substr(0, 3);
	long convertedYear = strtol(year.c_str(), &p, 10);
	if (convertedYear > MAX_YEAR || convertedYear < MIN_YEAR
		|| *p != '\0' || errno == ERANGE)
	{
		std::cerr << "Error: Invalid year." << std::endl;
		return false;
	}

	std::string month = date.substr(6, 7);
	long convertedMonth = strtol(month.c_str(), &p, 10);
	if (convertedMonth > 12 || convertedMonth < 1 || *p != '\0' || errno == ERANGE)
	{
		std::cerr << "Error: Invalid month." << std::endl;
		return false;
	}

	std::string day = date.substr(9, 10);
	long convertedDay = strtol(day.c_str(), &p, 10);
	if (convertedDay > 31 || convertedDay < 1 || *p != '\0' || errno == ERANGE)
	{
		std::cerr << "Error: Invalid day." << std::endl;
		return false;
	}

	if ((convertedMonth == 4 || convertedMonth == 6
		|| convertedMonth == 9 || convertedMonth == 11)
		&& convertedDay > 30)
	{
		std::cerr << "Error: Invalid date." << std::endl;
		return false;
	}
	if (convertedMonth == 2 && convertedDay > 28
		&& convertedDay != 29 && !isLeap(convertedYear))
	{
		std::cerr << "Error: Invalid date." << std::endl;
		return false;
	}
	return true;
}

bool isValidValue(std::string value)
{
	if (value.empty())
		return false;
	char *p = NULL;
	if (value.find(".", 0))
	{
		float convertedValue = (float)atof(value.c_str());
		if (convertedValue < 0 || convertedValue > 1000
			|| convertedValue != value.size())
		{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	else
	{
		long convertedValue = strtol(value.c_str(), &p, 10);
		if (convertedValue > 1000 || convertedValue < 0
			|| *p != '\0' || errno == ERANGE)
		{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	return true;
}