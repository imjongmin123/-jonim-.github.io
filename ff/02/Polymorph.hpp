#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
	Polymorph();
	~Polymorph();

	Polymorph(const Polymorph& others);
	Polymorph& operator=(const Polymorph& others);
	ASpell* clone() const;
};

#endif
