#pragma once

# include <iostream>
# include <exception>
# include <fstream>
# include <string>
# include <map>

# define MAX_YEAR 2100
# define MIN_YEAR 2005

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> _map;

	public:

	BitcoinExchange(void);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);

	bool	isValid(std::string InFile, std::string DataFile);
	void	execute(std::string InFile, std::string DataFile);

};

bool isValidDate(std::string date);
bool isValidValue(std::string value);
