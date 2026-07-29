#include "BitcoinExchange.hpp"
#include <cctype>
#include <climits>

void	strtrim(std::string &line)
{
	const std::string whiteSpace = "\t\n \r";
	size_t pos_start = line.find_first_not_of(whiteSpace);
	if (pos_start == std::string::npos)
	{
		line = "";
		return;
	}
	size_t pos_end = line.find_last_not_of(whiteSpace);
	line = line.substr(pos_start, pos_end - pos_start + 1);
}

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
	else if (date.find("-", 0) != 4 || date.find("-", 5) != 7)
	{
		std::cerr << "Error: Invalid format." << std::endl;
		return false;
	}

	char *p = NULL;
	std::string year = date.substr(0, 4);
	long convertedYear = strtol(year.c_str(), &p, 10);
	if (convertedYear > MAX_YEAR || convertedYear < MIN_YEAR
		|| *p != '\0' || errno == ERANGE)
	{
		std::cerr << "Error: Invalid year." << std::endl;
		return false;
	}

	std::string month = date.substr(5, 6);
	long convertedMonth = strtol(month.c_str(), &p, 10);
	if (convertedMonth > 12 || convertedMonth < 1 || *p != '-' || errno == ERANGE)
	{
		std::cerr << "Error: Invalid month." << std::endl;
		return false;
	}

	std::string day = date.substr(8, 9);
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
	for (std::string::iterator it = value.begin(); it != value.end(); it++)
	{
			int i = 0;
			if (*it == '.')
				i++;
			if (!std::isdigit(*it) && *it != '.' && i < 1)
			{
				std::cerr << "Error: Invalid value." << std::endl;
				return false;
			}
	}
	if (value.find(".", 0))
	{
		float convertedValue = (float)atof(value.c_str());
		if (convertedValue < 0 || convertedValue > 1000)
		{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	else
	{
		long convertedValue = strtol(value.c_str(), NULL, 10);
		if (convertedValue > 1000 || convertedValue < 0
			|| errno == ERANGE)
		{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	return true;
}

bool isValidValueData(std::string value)
{
	if (value.empty())
		return false;
	for (std::string::iterator it = value.begin(); it != value.end(); it++)
	{
		int i = 0;
		if (*it == '.')
			i++;
		if (!std::isdigit(*it) && *it != '.' && i < 1)
		{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	if (value.find(".", 0))
	{
		float convertedValue = (float)atof(value.c_str());
		if (convertedValue < 0 || convertedValue > float(INT_MAX))
		{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	else
	{
		long convertedValue = strtol(value.c_str(), NULL, 10);
		if (convertedValue > INT_MAX || convertedValue < 0
			|| errno == ERANGE)
			{
			std::cerr << "Error: Invalid value." << std::endl;
			return false;
		}
	}
	return true;
}