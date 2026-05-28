#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "...SSSCRRRCHHCHCHHHHHSSSS...SCHRHCSCHHHH.....";
	if (!*av)
		return (1);
	for(int i = 1; i < ac; i++)
	{
		for(int j = 0; av[i][j]; j++)
			std::cout << (char)std::toupper(av[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
