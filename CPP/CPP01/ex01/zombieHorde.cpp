#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int n, std::string name_)
{
	Zombie *horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		horde[i].name = name_;
	}
	return (horde);
}
