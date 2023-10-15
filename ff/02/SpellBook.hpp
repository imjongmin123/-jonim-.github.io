#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
	std::map<std::string, ASpell*> spells;
	SpellBook(const SpellBook& others);
	SpellBook& operator=(const SpellBook& others);

	public:
	SpellBook();
	~SpellBook();

	void	learnSpell(ASpell* A_S);
	void	forgetSpell(const std::string& spell_name);
	ASpell* createSpell(const std::string& spell_name);
};

#endif
