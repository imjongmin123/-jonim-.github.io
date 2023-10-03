#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon& weapon_) : name(name_), weapon(weapon_)
{
}

HumanA::~HumanA()
{
	std::cout << "is destroyed" << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " ";
	std::cout << this->weapon.getType() << std::endl;
}
