#include "BitcoinExchange/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "This program takes a input file name as argument." << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	try
	{
		btc.execute(av[1], "data.csv");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}