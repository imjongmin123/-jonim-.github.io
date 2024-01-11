#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& others);
	Serializer& operator=(const Serializer& others);

	public:
	static	uintptr_t serialize(Data* ptr);
	static	Data* deserialize(uintptr_t raw);

};

#endif
