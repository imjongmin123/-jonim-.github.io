#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
	std::string name;
	std::string title;
	ASpell*		Asp;
	Warlock();
	Warlock(const Warlock& others);
	Warlock& operator=(const Warlock& others);

	public:
	~Warlock();
	Warlock(std::string name_, std::string title_);
	const std::string& getName() const;
	const std::string& getTitle() const;
	void			   setTitle(const std::string& title_);
	void 			   introduce() const;

	void			   learnSpell(ASpell* A_S);
	void			   forgetSpell(std::string spell_name);
	void			   launchSpell(std::string spell_name, ATarget& A_S);
};

#endif
