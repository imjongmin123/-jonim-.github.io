#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	FragTrap FT;

	HitPoint = FT.getHp();
	EnergyPoint = ScavTrap::getEp();
	AttackDamage = FT.getAttack();
	std::cout << "[DiamondTrap] Default constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] destructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std:: string name) : ClapTrap(name), FragTrap(), ScavTrap()
{
	FragTrap FT;

	Name = name;
	HitPoint = FT.getHp();
	EnergyPoint = ScavTrap::getEp();
	AttackDamage = FT.getAttack();
	std::cout << "[DiamondTrap] Copy constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& DT) : ClapTrap(DT.Name)
{
	std::cout << "[DiamondTrap] Copy constructor is called" << std::endl;
	Name = DT.Name;
	HitPoint = DT.HitPoint;
	EnergyPoint = DT.EnergyPoint;
	AttackDamage = DT.AttackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& DT)
{
	std::cout << "[DiamondTrap] operator is called" << std::endl;
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
	std::cout << "[DiamondTrap] my name is " << Name << std::endl;
	std::cout << "[DiamondTrap] ClapTrap name is " << ClapTrap::Name << std::endl;
}