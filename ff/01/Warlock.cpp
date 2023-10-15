#include "Warlock.hpp"


Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
	if (Asp != NULL)
		delete Asp;
}

Warlock& Warlock::operator=(const Warlock& others)
{
	if (this == &others)
		return *this;
	name = others.name;
	title = others.title;
	return *this;
}

Warlock::Warlock(std::string name_, std::string title_) : name(name_), title(title_), Asp(NULL)
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
	if (this->Asp != NULL)
		delete Asp;
	Asp = A_S;
}

void	Warlock::forgetSpell(std::string spell_name)
{
	if (spell_name != Asp->getName())
		return ;
	delete Asp;
	Asp = NULL;
}

void	Warlock::launchSpell(std::string spell_name, ATarget& A_s)
{
	if (Asp == NULL)
		return ;
	if (spell_name != Asp->getName())
	{
		return ;
	}
	Asp->launch(A_s);
}