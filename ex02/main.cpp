#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	FragTrap FT("FT_CLAP");
	ClapTrap CT("ST_CLAP");

	FT.highFivesGuys();
	FT.getStatus();

	while(1)
	{
		FT.attack("CT_CLAP");
		CT.takeDamage(FT.getAttack());
		CT.getStatus();
		if (CT.getHp() == 0)
			break;
	}
}