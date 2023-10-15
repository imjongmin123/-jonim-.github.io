#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::~BrickWall() {}

BrickWall::BrickWall(const BrickWall& others) : ATarget(others.getType())
{
	if (this == &others)
		return ;
}

BrickWall& BrickWall::operator=(const BrickWall& others)
{
	if (this == &others)
		return *this;
	type = others.getType();
	return *this;
}

ATarget* BrickWall::clone() const
{
	return new BrickWall(*this);
}