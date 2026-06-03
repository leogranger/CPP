#include "Zombie.hpp"

int	main(void)
{
	Zombie *pedro = newZombie("Pedro");
	pedro->announce();
	randomChump("Patoche");
	delete pedro;
}