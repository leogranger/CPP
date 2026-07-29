#include "rpn/RPN.hpp"
#include <exception>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "The program has to be used like this: \"8 9 * 9 - 9 - 9 - 4 - 1 +\" for example."
				<< std::endl << "The numbers have to be less than 10 and not negative."
				<< std::endl << "The accepted operations are \"+ - * /\"." << std::endl;
		return (1);
	}
	try
	{
		RPN polish;
		polish.calculate(av[1]);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}