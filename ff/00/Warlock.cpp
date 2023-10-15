#include "Warlock.hpp"


Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock& Warlock::operator=(const Warlock& others)
{
	if (this == &others)
		return *this;
	name = others.name;
	title = others.title;
	return *this;
}

Warlock::Warlock(std::string name_, std::string title_) : name(name_), title(title_)
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