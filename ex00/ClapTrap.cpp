#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "Default constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name_) : HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "constructor is called" << std::endl;
	this->Name = name_;
}

ClapTrap::ClapTrap(const ClapTrap& CT)
{
	std::cout << "Copy constructor is called" << std::endl;
	Name = CT.Name;
	HitPoint = CT.HitPoint;
	EnergyPoint = CT.EnergyPoint;
	AttackDamage = CT.AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& CT)
{
	std::cout << "Operator is called" << std::endl;
	Name = CT.Name;
	HitPoint = CT.HitPoint;
	EnergyPoint = CT.EnergyPoint;
	AttackDamage = CT.AttackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoint == 0)
	{
		std::cout << Name << "is died" << std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout << Name << "Energy Point is 0" << std::endl;
		return ;
	}
	if (EnergyPoint < AttackDamage)
		AttackDamage = EnergyPoint;
	EnergyPoint -= AttackDamage;
	std::cout << "ClapTrap " << Name << " attacks " \
	<< target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoint == 0)
	{
		std::cout << Name << " is died" << std::endl;
		return ;
	}
	std::cout << Name << " take damage " << amount << std::endl;
	if (HitPoint < amount)
		HitPoint = 0;
	else
		HitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoint == 0)
	{
		std::cout << Name << " is died" << std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout << Name << "'s Energy Point is 0" << std::endl;
		return ;
	}
	if (EnergyPoint < amount)
		amount = EnergyPoint;
	std::cout << Name << " be repaired " << amount << std::endl;
	HitPoint += amount;
	EnergyPoint -= amount;
}

void ClapTrap::setAttack(unsigned int amount)
{
	AttackDamage = amount;
}

void ClapTrap::getStatus()
{
	std::cout << "Name is " << Name << ", " << "Hit point is " << HitPoint \
	<< " Energy Point is " << EnergyPoint << " Attack Damage is " << AttackDamage << std::endl;;
}

unsigned int ClapTrap::getHp()
{
	return (HitPoint);
}

unsigned int ClapTrap::getEp()
{
	return (EnergyPoint);
}

unsigned int ClapTrap::getAttack()
{
	return (AttackDamage);	
}
