#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::vector<int> arrayrange;
	// for (unsigned int i = 0; i < 1000; i++)
	// {
	// 	arrayrange.push_back(i);
	// }
	// Span ssp(1004);
	// ssp.addRange(arrayrange.begin(), arrayrange.end());
	// for(unsigned int i = 0; i < 1000; i++)
	// {
	// 	std::cout << arrayrange[i] << std::endl;
	// }
	return 0;
}