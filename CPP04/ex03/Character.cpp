#include "Character.hpp"
#include "AMateria.hpp"

Floor Character::field;

Character::Character()
{
	std::cout << "[Character] default constructor is called" << std::endl;
	slot[0] = NULL;
	slot[1] = NULL;
	slot[2] = NULL;
	slot[3] = NULL;
}

Character::~Character()
{
	std::cout << "[Character] destructor is called" << std::endl;
	if (slot[0] != NULL)
		delete slot[0];
	if (slot[1] != NULL)
		delete slot[1];
	if (slot[2] != NULL)
		delete slot[2];
	if (slot[3] != NULL)
		delete slot[3];
}

Character::Character(std::string name_)
{
	std::cout << "[Character]constructor is called" << std::endl;
	name = name_;
	slot[0] = NULL;
	slot[1] = NULL;
	slot[2] = NULL;
	slot[3] = NULL;
}

Character::Character(const Character& character)
{
	std::cout << "[Character] copy constructor is called" << std::endl;
	slot[0] = NULL;
	slot[1] = NULL;
	slot[2] = NULL;
	slot[3] = NULL;
	if (character.slot[0] != NULL)
		slot[0] = character.slot[0]->clone();
	if (character.slot[1] != NULL)
		slot[1] = character.slot[1]->clone();
	if (character.slot[2] != NULL)
		slot[2] = character.slot[2]->clone();
	if (character.slot[3] != NULL)
		slot[3] = character.slot[3]->clone();
	name = character.name;
}

Character& Character::operator=(const Character& character)
{
	std::cout << "[Character] -------operator is called-------" << std::endl;
	if (this == &character)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (character.slot[i] != NULL)
			slot[i] = character.slot[i]->clone();
		else
			slot[i] = NULL;
	}
	name = character.name;
	return (*this);
}

std::string const& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (slot[idx] == NULL)
		return ;
	if (field.addMateria(slot[idx]) == 0)
	{
		std::cout << "field is full" << std::endl;
		return ;
	}
	slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (slot[idx] != NULL)
		slot[idx]->use(target);
	else
		std::cout << "inventory is empty" << std::endl;
	return ;
}