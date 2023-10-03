#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
	public :
	FragTrap();
	~FragTrap();

	FragTrap(std::string name);
	FragTrap(const FragTrap& FT);
	FragTrap& operator=(const FragTrap& FT);
	void highFivesGuys(void);
};

#endif