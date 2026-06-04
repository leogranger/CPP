#include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "This program needs 3 arguments : a filename and two strings." << std::endl;
		return (0);
	}
	std::string	filename(av[1]);
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	Sed	sed(filename, s1, s2);
	sed.findAndReplace();
	return (0);
}
