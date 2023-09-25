#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
	std::string Name;

	public :
	DiamondTrap();
	~DiamondTrap();

	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& DT);
	DiamondTrap& operator=(const DiamondTrap& DT);
	void attack();
	void whoAmi();
};

#endif
