#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "[FragTrap] Default constructor is called" << std::endl;
	HitPoint = 100;
	EnergyPoint = 100;
	AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "[FragTrap] constructor is called" << std::endl;
	Name = name;
	HitPoint = 100;
	EnergyPoint = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& FT) : ClapTrap(FT)
{
	std::cout << "[FragTrap] Copy constructor is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& FT)
{
	std::cout << "[FragTrap] operator is called" << std::endl;
	Name = FT.Name;
	HitPoint = FT.HitPoint;
	EnergyPoint = FT.EnergyPoint;
	AttackDamage = FT.AttackDamage;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] high fives" << std::endl;
}