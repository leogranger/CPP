#pragma once

# include <iostream>
# include <exception>
# include <fstream>
# include <string>
# include <map>
# include <iomanip>
# include <cerrno>
# include <cstdlib>

# define MAX_YEAR 2100
# define MIN_YEAR 2005

class BitcoinExchange
{
	private:
		std::map<std::string, double> _mapData;

	public:

	BitcoinExchange(void);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	execute(std::string InFile, std::string DataFile);

};

bool	isValidDate(std::string date);
bool	isValidValue(std::string value);
bool	isValidValueData(std::string value);
void	strtrim(std::string &line);
