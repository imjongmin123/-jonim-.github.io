#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

template<typename T>
Array<T>::Array() : array(NULL), size_(0) {}

template<typename T>
Array<T>::~Array()
{
	if (array != NULL)
		delete[] array;
}

template<typename T>
Array<T>::Array(unsigned int n) : size_(n)
{
	array = new T[size_];
	for (unsigned int i = 0; i < n; i++)
	{
		array[i] = 0;
	}
}

template<typename T>
Array<T>::Array(const Array<T>& others) : array(NULL), size_(others.size_)
{
	if (this == &others || size_ == 0)
		return ;
	array = new T[size_];
	for (unsigned int i = 0; i < size_; i++)
	{
		array[i] = others.array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& others)
{
	if (this == &others)
		return *this;
	size_ = others.size_();
	if (array != NULL)
	{
		delete[] array;
		array = NULL;
	}
	if (size_ == 0)
		return *this;
	array = new T[size_];
	for (unsigned int i = 0; i < size_; i++)
	{
		array[i] = others.array[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (size_ <= index)
		throw std::exception();
	return array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (size_ <= index)
		throw std::exception();
	return array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return size_;
}

#endif