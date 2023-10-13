#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(const ATarget& others) {
	if (this == &others)
		return ;
}
ATarget& ATarget::operator=(const ATarget& others) 
{
	if (this == &others)
		return *this;
	return *this;
}

ATarget::~ATarget() {}


ATarget::ATarget(std::string type_) : type(type_)
{

}

const std::string ATarget::getType() const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell& asp) const
{
	std::cout << type << " has been " << asp.getEffects() << "!"<< std::endl;
}
