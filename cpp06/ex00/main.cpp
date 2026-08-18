#include "ScalarConverter/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Needs one argument." << std::endl;
		return (1);
	}
	if (!av || !*av)
	{
		std::cout << "The argument is empty." << std::endl;
		return (1);
	}
	ScalarConverter Conv;
	std::string str = av[1];
	Conv.convert(str);
}