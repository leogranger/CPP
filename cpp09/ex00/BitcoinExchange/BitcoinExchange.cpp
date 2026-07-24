#include "BitcoinExchange.hpp"
#include <stdexcept>

BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange constructor called." << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange destructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	:_mapData(other._mapData)
{
	//std::cout << "BitcoinExchange copy constructor called." << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_mapData = other._mapData;
	}
	//std::cout << "BitcoinExchange copy assignment operator called." << std::endl;
	return (*this);
}

void	BitcoinExchange::execute(std::string InFile, std::string DataFile)
{
	std::string line;
	if (DataFile.find(".csv", 1) == std::string::npos)
		throw std::invalid_argument("The data file name has to be a csv format.");
	std::ifstream Data(DataFile.c_str());
	if (!Data.is_open())
		throw std::invalid_argument("Couldn't open the data file.");
	while (getline(Data, line))
	{
		strtrim(line);
		if (line.empty() || line == "date,exchange_rate")
			continue ;
		size_t pos = line.find(",");
		if (pos == std::string::npos)
		{
			throw std::invalid_argument("Input content is formatted wrong.");
			continue ;
		}
		std::string date = line.substr(0, pos);
		strtrim(date);
		std::string value = line.substr(pos + 1, std::string::npos);
		strtrim(value);
		if (!isValidDate(date) || !isValidValue(value))
			continue ;
		double val = strtol(value.c_str(), NULL, 0);
		this->_mapData[date] = val;
	}

	std::ifstream Input(InFile.c_str());
	if (!Input.is_open())
		throw std::invalid_argument("Couldn't open the input file.");

	while (getline(Input, line))
	{
		if (line.empty() || line == "date | value")
			continue ;
		strtrim(line);
		size_t pos = line.find("|");
		if (pos == std::string::npos)
		{
			throw std::invalid_argument("Input content is formatted wrong.");
			continue ;
		}
		std::string date = line.substr(0, pos);
		strtrim(date);
		std::string value = line.substr(pos + 1, std::string::npos);
		strtrim(value);
		if (!isValidDate(date) || !isValidValue(value))
			continue ;
		double val = strtol(value.c_str(), NULL, 0);
		std::map<std::string, double>::iterator	it = this->_mapData.lower_bound(date);
		if (it != _mapData.end() && it->first == date)
			std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (val * it->second) << std::endl;
		else if (it == _mapData.begin())
			std::cout << "Error: no date available for this value: " << date << std::endl;
		else
		{
			--it;
			std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (val * it->second) << std::endl;
		}
	}
}
