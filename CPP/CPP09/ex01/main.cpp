#include "RPN.hpp"

int main(int ac, char** av)
{
	RPN	polish;
	if (ac != 2)
		return (1);
	if (!polish.check(ac, av))
	{
		std::cout << "Error" << std::endl;
		return (FAIL);
	}
	polish.cal(av[1]);
}