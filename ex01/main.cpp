#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	ScavTrap Scav_1("ST");
	ScavTrap Scav_2("ST2");

	Scav_1.guardGate();
	Scav_2.guardGate();

	Scav_1.attack("ST2");
	Scav_2.takeDamage(Scav_1.getAttack());
	Scav_2.guardGate();

	while(Scav_2.getHp())
	{
		Scav_1.attack("ST2");
		Scav_2.takeDamage(Scav_1.getAttack());
	}
	Scav_2.guardGate();
}