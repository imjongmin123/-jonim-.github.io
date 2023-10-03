#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "floor.hpp"

// void v()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(v);
	Floor *field = new Floor();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");

	me->equip(field->addMateria(tmp));
	tmp = src->createMateria("cure");
	me->equip(field->addMateria(tmp));

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	delete field;

	
	// std::cout << "-------" << std::endl;
	// //test1 무기 1000회 장착하고 버리기
	// ICharacter* hero = new Character("Ironman");
	// ICharacter* tor = new Character("tor");
	// IMateriaSource*  smith = new MateriaSource();
	// Floor* 			 field = new Floor();
	// smith->learnMateria(new Ice());
	// smith->learnMateria(new Cure());
	// while (1)
	// {
	// 	hero->equip(field->addMateria((smith->createMateria("ice"))));
	// 	hero->equip(field->addMateria((smith->createMateria("cure"))));
	// 	hero->equip(field->addMateria((smith->createMateria("ice"))));
	// 	hero->equip(field->addMateria((smith->createMateria("cure"))));
	// 	hero->unequip(0);
	// 	hero->unequip(1);
	// 	hero->unequip(2);
	// 	hero->unequip(3);
	// 	if (field->checkFloor() == 0)
	// 		break ;
	// }
	// field->getMateria();
	// delete field;
	// delete hero;
	// delete tor;
	// delete smith;

	return 0; 
}