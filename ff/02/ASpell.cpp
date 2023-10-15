#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(std::string name_, std::string effects_) : name(name_), effects(effects_)
{}

ASpell::ASpell(const ASpell& others)
{
	if (this == &others)
		return ;
	name = others.getName();
	effects = others.getEffects();
}

ASpell& ASpell::operator=(const ASpell& others)
{
	if (this == &others)
		return *this;
	name = others.getName();
	effects = others.getEffects();
	return (*this);
}

std::string ASpell::getName() const
{
	return name;
}

std::string ASpell::getEffects() const
{
	return effects;
}


void	ASpell::launch(const ATarget& A_T) const
{
	A_T.getHitBySpell(*this);
}