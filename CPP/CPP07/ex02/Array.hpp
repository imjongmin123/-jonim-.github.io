#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
	private:
	T*	array;
	unsigned int size_;

	public:
	Array();
	Array(unsigned int n);
	~Array();

	Array(const Array& others);
	Array<T>& operator=(const Array<T>& others);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int	size() const;
};

#endif