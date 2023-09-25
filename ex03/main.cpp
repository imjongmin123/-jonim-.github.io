#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	DiamondTrap DT("Monster");
	FragTrap 	FT("Frag");
	ScavTrap	ST("Scav");

	DT.getStatus();
	DT.attack();
	DT.whoAmi();
	while(1)
	{
		DT.attack();
		FT.takeDamage(DT.getAttack());
		ST.takeDamage(DT.getAttack());
		if (FT.getHp() == 0 || ST.getHp() == 0)
			break ;
	}
	FT.getStatus();
	ST.getStatus();
}