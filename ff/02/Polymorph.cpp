#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::~Polymorph() {}

Polymorph::Polymorph(const Polymorph& others) : ASpell(others)
{
	if (this == &others)
		return ;
}

Polymorph& Polymorph::operator=(const Polymorph& others)
{
	if (this == &others)
		return *this;
	name = others.getName();
	effects = others.getEffects();
	return *this;
}

ASpell* Polymorph::clone() const
{
	return new Polymorph(*this);
}