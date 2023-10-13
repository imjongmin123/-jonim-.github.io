#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>

class ATarget;

class ASpell
{
	protected:
	std::string name;
	std::string effects;

	public:
	ASpell();
	virtual ~ASpell();

	ASpell(std::string name_, std::string effects_);
	ASpell(const ASpell& others);
	ASpell& operator=(const ASpell& others);
	std::string getName() const;
	std::string getEffects() const;
	virtual ASpell* clone() const = 0;
	void			launch(const ATarget& A_T) const;
};

#endif
