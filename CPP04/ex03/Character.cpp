#include "Character.hpp"
#include "AMateria.hpp"

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
	slot[0] = NULL;
	slot[1] = NULL;
	slot[2] = NULL;
	slot[3] = NULL;
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

Character::Character(const Character& Character)
{
	std::cout << "[Character] copy constructor is called" << std::endl;
	slot[0] = Character.slot[0]->clone();
	slot[1] = Character.slot[1]->clone();
	slot[2] = Character.slot[2]->clone();
	slot[3] = Character.slot[3]->clone();
	name = Character.name;

}

Character& Character::operator=(const Character& character)
{
	std::cout << "[Character] operator is called" << std::endl;
	slot[0] = character.slot[0];
	slot[1] = character.slot[1];
	slot[2] = character.slot[2];
	slot[3] = character.slot[3];
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