#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template<typename T>
int	easyfind(T container, int value)
{
	typename T::iterator it;
	int index = 0;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
			return index;
		index++;
	}
	throw std::invalid_argument("not found");
}


#endif