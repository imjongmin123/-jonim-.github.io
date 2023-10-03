#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = Zombie::zombieHorde(5, "zom");
	for(int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	Zombie *horde2 = Zombie::zombieHorde(5, "zom2");
	for(int i = 0; i < 5; i++)
	{
		horde2[i].announce();
	}
	delete[] horde;
	delete[] horde2;
	return (0);
}
