#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	DiamondTrap DT("Monster");
	std::cout << "---" << std::endl;
	DiamondTrap DT2(DT);
	DiamondTrap DT3 = DT;
	std::cout << "---" << std::endl;
	DT.whoAmi();
	DT2.whoAmi();
	DT3.whoAmi();
	std::cout << "---" << std::endl;
	DT.getStatus();
	DT2.getStatus();
	DT3.getStatus();
	std::cout << "---" << std::endl;
	DT.attack();
	DT2.attack();
	DT3.attack();
	std::cout << "---" << std::endl;
}