#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe mergeme;

	try
	{
		mergeme.CheckArg(ac, av);
		std::vector<int>	inputarray;
		inputarray = mergeme.getVec();
		mergeme.FordJohnson(inputarray, 0, inputarray.size() - 1);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}