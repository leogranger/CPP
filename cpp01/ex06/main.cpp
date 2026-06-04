#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Only one argument is accepted." << std::endl;
		return (0);
	}
	Harl		harl;
	std::string	cry(av[1]);
	harl.complain(cry);
	return (0);
}