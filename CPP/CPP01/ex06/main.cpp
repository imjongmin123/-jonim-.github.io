#include "Harl.hpp"

int	main(int ac, char **av)
{
	int a;
	
	if (ac != 2)
	{
		std::cout << "plz input filter message" << std::endl; 
		return (1);
	}
	Harl Harl;

	Harl.complain(av[1]);
}
