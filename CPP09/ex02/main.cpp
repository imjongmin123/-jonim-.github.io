#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe mergeme;
	mergeme.startTime();

	try
	{
		mergeme.CheckArg(ac, av);
		std::cout << "Before:  ";
		mergeme.printResult();
		mergeme.CheckTime();

		mergeme.FordJohnsonVec();
		mergeme.FordJohnsonDec();
		std::cout << "After:  ";
		mergeme.printResult();
		mergeme.printVecTime();
		mergeme.printDecTime();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}