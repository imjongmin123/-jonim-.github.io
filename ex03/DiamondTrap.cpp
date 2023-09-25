#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	FragTrap FT;

	HitPoint = FT.getHp();
	EnergyPoint = ScavTrap::getEp();
	AttackDamage = FT.getAttack();
	std::cout << "DiamondTrap Default constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std:: string name)
{
	FragTrap FT;

	Name = name +  "_clap_name";
	HitPoint = FT.getHp();
	EnergyPoint = ScavTrap::getEp();
	AttackDamage = FT.getAttack();
	std::cout << "DiamondTrap Copy constructor is called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& DT)
{
	Name = DT.Name;
	HitPoint = DT.HitPoint;
	EnergyPoint = DT.EnergyPoint;
	AttackDamage = DT.AttackDamage;
	return (*this);
}

void DiamondTrap::attack()
{
	ScavTrap::attack("anyone");
}

void DiamondTrap::whoAmi()
{
	std::cout << "my name is " << Name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::Name << std::endl;
}