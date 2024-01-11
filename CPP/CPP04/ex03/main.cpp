#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Floor.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* a = new Character("a");
	ICharacter* you = new Character("you");
	src->learnMateria(new (Ice));
	src->learnMateria(new (Cure));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	*dynamic_cast<Character *>(you) = *dynamic_cast<Character *>(me);
	delete me;
	you->use(0, *a);


	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// me->unequip(1);

	// delete bob;
	delete you;
	
	delete src;

	return 0; 
}