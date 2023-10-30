#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <stdexcept>

template<typename T>
void	myprint(const T &a)
{
	std::cout << a << std::endl;
}

template<typename T>
void	plus(T &a)
{
	a++;
	std::cout << a << std::endl;
}

template<typename T>
void	iter(T* array, std::size_t len, void (*f)(T&))
{
	for(std::size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}
template<typename T>
void	iter(const T* array, std::size_t len, void (*f)(const T&))
{
	for(std::size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void	iter(volatile T* array, std::size_t len, void (*f)(volatile T&))
{
	for(std::size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}
template<typename T>
void	iter(volatile const T* array, std::size_t len, void (*f)(volatile const T&))
{
	for(std::size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

#endif

