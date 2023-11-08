#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span
{
	private:
	unsigned int max;
	std::vector<int> array;

	public:
	Span();
	~Span();
	Span(const Span& others);
	Span& operator=(const Span& others);

	Span(unsigned int N);

	void	addNumber(int num);
	template<typename vec>
	void	addRange(vec begin, vec end) { array.insert(array.end(), begin, end);};
	int		shortestSpan();
	int		longestSpan();
};

#endif