#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap default constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called" << std::endl;
}

ClapTrap::ClapTrap(unsigned int Hp, unsigned int Ep, unsigned int Ad)
{
	HitPoint = Hp;
	EnergyPoint = Ep;
	AttackDamage = Ad;
	std::cout << "ClapTrap constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name_) : HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap constructor is called" << std::endl;
	this->Name = name_;
}

ClapTrap::ClapTrap(std::string name_, unsigned int Hp, unsigned int Ep, unsigned int Ad)\
 : Name(name_), HitPoint(Hp), EnergyPoint(Ep), AttackDamage(Ad)
{
}

ClapTrap::ClapTrap(const ClapTrap& CT)
{
	std::cout << "ClapTrap Copy constructor is called" << std::endl;
	Name = CT.Name;
	HitPoint = CT.HitPoint;
	EnergyPoint = CT.EnergyPoint;
	AttackDamage = CT.AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& CT)
{
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
	if (HitPoint == 10)
	{
		std::cout << Name << " Hit Point is already 10" << std::endl;
		return ;
	}
	std::cout << Name << " be repaired " << amount << std::endl;
	HitPoint += amount;
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
