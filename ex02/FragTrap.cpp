#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap Default constructor is called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& FT) : ClapTrap(FT)
{
	std::cout << "FragTrap Copy constructor is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& FT)
{
	Name = FT.Name;
	HitPoint = FT.HitPoint;
	EnergyPoint = FT.EnergyPoint;
	AttackDamage = FT.AttackDamage;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "highFivesGuys!!!" << std::endl;
}