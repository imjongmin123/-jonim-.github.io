#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh() {}

Fwoosh::Fwoosh(const Fwoosh& others) : ASpell(others)
{
	if (this == &others)
		return ;
}

Fwoosh& Fwoosh::operator=(const Fwoosh& others)
{
	if (this == &others)
		return *this;
	name = others.getName();
	effects = others.getEffects();
	return *this;
}

ASpell* Fwoosh::clone() const
{
	return new Fwoosh(*this);
}