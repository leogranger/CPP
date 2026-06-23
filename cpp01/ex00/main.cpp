#include "Zombie.hpp"

int main(void)
{
	Zombie stackZombie("StackGuy");
	stackZombie.announce();

	Zombie *heapZombie = newZombie("HeapGuy");
	heapZombie->announce();

	randomChump("RandomGuy");

	delete heapZombie;

	std::cout << "\n--- Scope test ---\n";

        Zombie local("ScopedZombie");
	local.announce();
	std::cout << "--- End of program ---\n";
}
