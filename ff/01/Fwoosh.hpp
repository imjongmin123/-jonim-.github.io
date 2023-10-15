#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include "ASpell.hpp"


class Fwoosh : public ASpell
{
	public:
	Fwoosh();
	~Fwoosh();

	Fwoosh(const Fwoosh& others);
	Fwoosh& operator=(const Fwoosh& others);
	ASpell* clone() const;
};

#endif
