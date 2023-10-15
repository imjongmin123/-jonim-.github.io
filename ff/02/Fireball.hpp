#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
	Fireball();
	~Fireball();

	Fireball(const Fireball& others);
	Fireball& operator=(const Fireball& others);
	ASpell* clone() const;
};

#endif
