#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy() {}

Dummy::Dummy(const Dummy& others) : ATarget(others.getType())
{
	if (this == &others)
		return ;
}

Dummy& Dummy::operator=(const Dummy& others)
{
	if (this == &others)
		return *this;
	type = others.getType();
	return *this;
}

ATarget* Dummy::clone() const
{
	return new Dummy(*this);
}