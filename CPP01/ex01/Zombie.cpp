#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name_)
{
	Zombie *newzom = new Zombie();
	newzom->name = name_;
	return (newzom);
}

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" <<  std::endl;
}
