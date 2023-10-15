#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
#include "ATarget.hpp"


class BrickWall : public ATarget
{
	public:
	BrickWall();
	~BrickWall();

	BrickWall(const BrickWall& others);
	BrickWall& operator=(const BrickWall& others);
	ATarget* clone() const;
};

#endif
