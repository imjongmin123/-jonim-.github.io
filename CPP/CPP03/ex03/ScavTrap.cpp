#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap] Default constructor is called" << std::endl;
	HitPoint = 100;
	EnergyPoint = 50;
	AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "[ScavTrap] constructor is called" << std::endl;
	Name = name;
	HitPoint = 100;
	EnergyPoint = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& ST) : ClapTrap(ST)
{
	std::cout << "[ScavTrap] Copy constructor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ST)
{
	std::cout << "[ScavTrap] operator is called" << std::endl;
	Name = ST.Name;
	HitPoint = ST.HitPoint;
	EnergyPoint = ST.EnergyPoint;
	AttackDamage = ST.AttackDamage;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout<< "[ScavTrap]";
	getStatus();
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "[ScavTrap] " << Name << " attack " << target << std::endl;
}

unsigned int ScavTrap::getEp()
{
	return (EnergyPoint);
}