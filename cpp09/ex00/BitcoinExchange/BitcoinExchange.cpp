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
	:_mapInput(other._mapInput)
	,_mapData(other._mapData)
{
	//std::cout << "BitcoinExchange copy constructor called." << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_mapInput = other._mapInput;
		this->_mapData = other._mapData;
	}
	//std::cout << "BitcoinExchange copy assignment operator called." << std::endl;
	return (*this);
}

void	BitcoinExchange::isValid(std::string InFile, std::string DataFile)
{
	std::string line;
	if (DataFile.find(".csv", 1) == std::string::npos)
		throw std::invalid_argument("The data file name has to be a csv format.");

	std::ifstream Input(InFile.c_str());
	if (!Input.is_open())
		throw std::invalid_argument("Couldn't open the input file.");

	while (getline(Input, line))
	{
		if (line.empty() || line == "date | value")
			continue ;
		size_t pos = line.find("|");
		if (pos == std::string::npos)
			throw std::invalid_argument("Input content is formatted wrong.");
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos, std::string::npos);
		if (!isValidDate(date) || !isValidValue(value))
		{
			std::cout << "An entry of the input file was skipped because of an error." << std::endl;
			continue ;
		}
		this->_mapInput.insert(date, value);
	}

	std::ifstream Data(DataFile.c_str());
	if (!Data.is_open())
		throw std::invalid_argument("Couldn't open the data file.");
	while (getline(Data, line))
	{
		if (line.empty() || line == "date | value")
			continue ;
		size_t pos = line.find("|");
		if (pos == std::string::npos)
			throw std::invalid_argument("Input content is formatted wrong.");
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos, std::string::npos);
		if (!isValidDate(date) || !isValidValue(value))
		{
			std::cout << "An entry of the input file was skipped because of an error." << std::endl;
			continue ;
		}
		this->_mapData.insert(date, value);
	}
	
}

void	BitcoinExchange::execute(std::string InFile, std::string DataFile)
{

}

