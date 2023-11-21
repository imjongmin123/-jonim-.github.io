#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange BitEx;
	CheckArg		CheArg;
	if (ac != 2)
	{
		std::cout << "plz input arguments correctly" << std::endl;
		return (1);
	}
	std::ifstream data("data.csv");
	std::ifstream input(av[1]);
	if (CheArg.checkfile(data, input))
		return (1);
	if (BitEx.dataMaping(data))
	{
		std::cout << "datamaping error" << std::endl;
		return (1);
	}
	if (BitEx.Exchange(input))
		return (1);
	return (0);
}