#include "Zombie.hpp"

int	main(void)
{
    Zombie *horde;

    std::cout << "=== Horde of 5 ===\n";
    horde = zombieHorde(5, "Walker");

    for (int i = 0; i < 5; i++)
        horde[i].announce();

    delete [] horde;

    std::cout << "\n=== Horde of 1 ===\n";
    horde = zombieHorde(1, "Solo");
    horde[0].announce();
    delete [] horde;

    std::cout << "\n=== Horde of 0 ===\n";
    horde = zombieHorde(0, "Nobody");

    if (!horde)
        std::cout << "Returned NULL (good)\n";

    return 0;
}
