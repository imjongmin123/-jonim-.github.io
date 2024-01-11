#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100, 50, 20)
{
	std::cout << "[ScavTrap] Default constructor is called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) 
{
	std::cout << "[ScavTrap] constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ST) : ClapTrap(ST)
{
	std::cout << "[ScavTrap] Copy constructor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ST)
{
	std::cout << "[ScavTrap] operater is called" << std::endl;
	Name = ST.Name;
	HitPoint = ST.HitPoint;
	EnergyPoint = ST.EnergyPoint;
	AttackDamage = ST.AttackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "[ScavTrap] " << Name << " attack " << target << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<< "[ScavTrap]";
	getStatus();
}

