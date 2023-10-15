#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::~Fireball() {}

Fireball::Fireball(const Fireball& others) : ASpell(others)
{
	if (this == &others)
		return ;
}

Fireball& Fireball::operator=(const Fireball& others)
{
	if (this == &others)
		return *this;
	name = others.getName();
	effects = others.getEffects();
	return *this;
}

ASpell* Fireball::clone() const
{
	return new Fireball(*this);
}