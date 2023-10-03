#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	FragTrap FT("FT_CLAP");
	ClapTrap CT("CT_CLAP");
	ScavTrap ST("ST_CLAP");
	ScavTrap ST2(ST);

	ST2.getStatus();
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
	ST.attack("FT_CLAP");
	FT.takeDamage(ST.getAttack());
	while(1)
	{
		FT.attack("ST_CLAP");
		ST.takeDamage(FT.getAttack());
		ST.getStatus();
		if (CT.getHp() == 0)
			break ;
	}
}