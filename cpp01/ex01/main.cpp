#include "Zombie.hpp"

int	main(void)
{
	int	N = 5;
	Zombie *horde = zombieHorde(N, "Pablo");
	for (int i = 0; i < 5; i++)
    		horde[i].announce();
	delete[] horde;
}
