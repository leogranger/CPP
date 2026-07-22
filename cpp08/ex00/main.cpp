#include "easyfind.hpp"
#include <vector>
#include <list>

int	main(void)
{
	std::vector<int> v;
	for (int i = 0; i < 6; i++)
		v.push_back(i);
	std::list<int> l;
	for (int i = 0; i < 6; i++)
		l.push_back(i);
	int	right = 2;
	int	wrong = 7;

	std::cout << "==== NUMBER EXISTS IN CONTAINER ====" << std::endl;
	try{
		easyfind(v, right);
		std::cout << "Number was found in vector." << std::endl;
		easyfind(l, right);
		std::cout << "Number was found in list." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "==== NUMBER DOESN'T EXIST IN CONTAINER ====" << std::endl;
	try{
		easyfind(v, wrong);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		easyfind(l, wrong);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "==== EMPTY CONTAINER ====" << std::endl;
	try{
		std::vector<int> empty;
		easyfind(empty, right);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		std::list<int> empty;
		easyfind(empty, right);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}