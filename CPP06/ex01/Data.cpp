#include "Data.hpp"

Data::Data() : value(0) {}
Data::~Data() {}
Data::Data(const Data& others) : value(others.value) {}
Data& Data::operator=(const Data& others)
{
	if (this == &others)
		return *this;
	value = others.value;
	return *this;
}

Data::Data(int val) : value(val) {}

int Data::getvalue()
{
	return value;
}