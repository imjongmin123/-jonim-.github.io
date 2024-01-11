#include "Zombie.hpp"

int	main(void)
{
	int b = 10;
	auto a = b;
	Zombie zombie("zom");
	zombie.announce();
	zombie.randomChump("zom2");
	Zombie *zombie3 = zombie.newZombie("zom3");
	zombie3->announce();
	delete zombie3;
	return (0);
}
