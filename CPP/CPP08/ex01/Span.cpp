#include "Span.hpp"

Span::Span() {}
Span::~Span() {}
Span::Span(const Span& others)
{
	if (this == &others)
		return ;
}
Span& Span::operator=(const Span& others)
{
	if (this == &others)
		return *this;
	max = others.max;
	array = others.array;
	return *this;
}

Span::Span(unsigned int N) : max(N)
{
}

void	Span::addNumber(int num)
{
	if (array.size() < max)
		array.push_back(num);
	else
	{
		throw std::out_of_range("already max");
	}
}

int	Span::shortestSpan()
{
	unsigned int s = array.size();
	if (s <= 1)
		throw std::exception();
	std::sort(array.begin(), array.end());
	int ret = array[1] - array[0];
	for (std::vector<int>::iterator it = array.begin() + 2; it < array.end(); it++)
	{
		int prev = *(it - 1);
		int temp = *it - prev;
		if (temp < ret)
			ret = temp;
	}
	return (ret);
}

int Span::longestSpan()
{
	if (array.size() <= 1)
		throw std::exception();
	std::sort(array.begin(), array.end());
	int last = array.size() - 1;
	return (array[last] - array[0]);
}
