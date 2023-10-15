#include "Warlock.hpp"


Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
	delete S_book;
}

Warlock& Warlock::operator=(const Warlock& others)
{
	if (this == &others)
		return *this;
	name = others.name;
	title = others.title;
	return *this;
}

Warlock::Warlock(std::string name_, std::string title_) : name(name_), title(title_), S_book(new SpellBook())
{
	std::cout << name_ << ": This looks like another boring day." << std::endl;
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << std::endl;
}

const std::string& Warlock::getName() const
{
	return (name);
}

const std::string& Warlock::getTitle() const
{
	return (title);
}

void	Warlock::setTitle(const std::string& title_)
{
	title = title_;
}

void	Warlock::learnSpell(ASpell* A_S)
{
	S_book->learnSpell(A_S);
}

void	Warlock::forgetSpell(std::string spell_name)
{
	S_book->forgetSpell(spell_name);	
}

void	Warlock::launchSpell(std::string spell_name, ATarget& A_T)
{
	ASpell* tempspell = S_book->createSpell(spell_name);
	if (tempspell == NULL)
	{
		return ;
	}
	tempspell->launch(A_T);
	delete tempspell;
}