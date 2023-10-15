#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}
SpellBook::SpellBook(const SpellBook& others)
{
	if (this == &others)
		return ;
}
SpellBook& SpellBook::operator=(const SpellBook& others)
{
	if (this == &others)
		return *this;
	return *this;
}

void	SpellBook::learnSpell(ASpell* A_S)
{
	if (spells.find(A_S->getName()) != spells.end())
		return ;
	spells[A_S->getName()] = A_S->clone();
}

void	SpellBook::forgetSpell(const std::string& spell_name)
{
	std::map<std::string, ASpell*>::iterator it = spells.find(spell_name);
	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(const std::string& spell_name)
{
	std::map<std::string, ASpell*>::iterator it = spells.find(spell_name);
	if (it == spells.end())
	{
		return NULL;
	}
	return (it->second->clone());
}