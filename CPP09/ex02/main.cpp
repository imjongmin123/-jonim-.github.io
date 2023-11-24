#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe mergeme;
	mergeme.startTime();

	try
	{
		mergeme.CheckArg(ac, av);
		std::cout << "Before:  ";
		mergeme.printVec();
		mergeme.CheckTime();

		mergeme.FordJohnsonVec();
		mergeme.FordJohnsonDec();
		if (mergeme.Checksort())
			std::cout << "sorted" << std::endl;
		else
			std::cout << "not sorted" << std::endl;
		std::cout << "After:  ";
		mergeme.printVec();
		std::cout << "After:  ";
		mergeme.printDec();
		mergeme.printVecTime();
		mergeme.printDecTime();

	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}