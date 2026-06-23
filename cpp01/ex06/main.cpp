#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "You need one and only one argument." << std::endl;
		return (0);
	}
	Harl		harl;
	std::string	cry(av[1]);
	harl.complain(cry);
	return (0);
}