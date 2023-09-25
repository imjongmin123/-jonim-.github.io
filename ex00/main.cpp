#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Trap_a("marin_1");
	ClapTrap Trap_b("marin_2");

	
	Trap_a.attack("marin_2");
	Trap_b.takeDamage(Trap_a.getAttack());
	Trap_b.beRepaired(1);

	Trap_a.setAttack(1);
	Trap_a.attack("marin_2");
	Trap_b.takeDamage(Trap_a.getAttack());
	Trap_b.beRepaired(1);
	Trap_b.getStatus();

	while(Trap_b.getHp())
	{
		Trap_a.attack("marin_2");
		Trap_b.takeDamage(Trap_a.getAttack());
	}
	Trap_a.attack("marin_2");
	Trap_b.takeDamage(Trap_a.getAttack());
	Trap_b.getStatus();
}