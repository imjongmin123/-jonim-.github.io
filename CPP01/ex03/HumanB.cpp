#include "HumanB.hpp"

HumanB::HumanB(std::string name_) : name(name_), weapon(nullptr)
{
}

HumanB::~HumanB()
{
	std::cout << "is destroyed" << std::endl; 
}

void	HumanB::setWeapon(Weapon &weapon_)
{
	this->weapon = &weapon_;
}

void	HumanB::attack()
{
	std::cout << name << " ";
	std::cout << this->weapon->getType() << std::endl;
}
