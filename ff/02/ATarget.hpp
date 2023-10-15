#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ATarget
{
	protected:
	std::string type;
	ATarget();
	ATarget(const ATarget& others);
	ATarget& operator=(const ATarget& others);

	public:
	virtual ~ATarget();
	ATarget(std::string type_);
	const std::string getType() const;
	virtual ATarget* clone () const = 0;
	void getHitBySpell(const ASpell& asp) const;
};

#endif
