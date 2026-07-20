#include "ScalarConverter/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	ScalarConverter Conv;
	std::string str = av[1];
	if (ac != 2)
		return (1);
	if (!av || !*av)
		return (1);
	Conv.convert(str);
}