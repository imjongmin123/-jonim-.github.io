#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string n_type)
{
	this->type = n_type;
}

Weapon::Weapon(std::string attack) : type(attack)
{
}


Weapon::Weapon()
{

}

Weapon::~Weapon()
{
	std::cout << type << " is destroyed" << std::endl;
}
