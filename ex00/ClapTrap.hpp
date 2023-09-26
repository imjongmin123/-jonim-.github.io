#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>


class ClapTrap
{
	private:
		std::string 	Name;
		unsigned int	HitPoint;
		unsigned int	EnergyPoint;
		unsigned int	AttackDamage;

	public:
		ClapTrap();
		~ClapTrap();

		ClapTrap(std::string name_);
		ClapTrap(const ClapTrap& CT);
		ClapTrap& operator=(const ClapTrap& CT);

		void 			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void 			setAttack(unsigned int amount);
		unsigned int 	getHp();
		unsigned int	getEp();
		unsigned int	getAttack();
		void 			getStatus();
};

#endif