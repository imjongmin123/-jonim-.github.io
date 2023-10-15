#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"


int	main()
{
	Warlock richard("Richad", "foo");
	richard.setTitle("Hello, I'm Richad the Warlock!");
	BrickWall model1;

	Polymorph* poly = new Polymorph();
	TargetGenerator targen;

	targen.learnTargetType(&model1);
	richard.learnSpell(poly);

	Fireball* fire = new Fireball();
	richard.learnSpell(fire);

	ATarget* wall = targen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
}