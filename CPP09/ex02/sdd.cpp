#include <cmath>
#include <iostream>

int		getrange(int num)
{
	return pow(2, static_cast<int>(log2(num) + 1)) - 1;
}

int main()
{
	std::cout << getrange(1) << std::endl;
}