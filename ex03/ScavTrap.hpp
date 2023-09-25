#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"


class ScavTrap : public virtual ClapTrap
{
	private:

	public:
	ScavTrap();
	~ScavTrap();

	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& ST);
	ScavTrap& operator=(const ScavTrap& ST);
	void guardGate();
	unsigned int getEp();
};

#endif
