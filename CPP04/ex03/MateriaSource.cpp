#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource] default constructor is called" << std::endl;
	slot[0] = NULL;
	slot[1] = NULL;
	slot[2] = NULL;
	slot[3] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] destructor is called" << std::endl;
	if (slot[0] != NULL)
		delete slot[0];
	if (slot[1] != NULL)
		delete slot[1];
	if (slot[2] != NULL)
		delete slot[2];
	if (slot[3] != NULL)
		delete slot[3];
}

MateriaSource::MateriaSource(const MateriaSource& materiasource)
{
	std::cout << "[MateriaSource] copy constructor is called" << std::endl;
	slot[0] = materiasource.slot[0];
	slot[1] = materiasource.slot[1];
	slot[2] = materiasource.slot[2];
	slot[3] = materiasource.slot[3];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiasource)
{
	std::cout << "[MateriaSource] operator is called" << std::endl;
	slot[0] = materiasource.slot[0];
	slot[1] = materiasource.slot[1];
	slot[2] = materiasource.slot[2];
	slot[3] = materiasource.slot[3];
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
		{
			if (type.compare(slot[i]->getType()) == 0)
				return (slot[i]->clone());
		}
	}
	return (NULL);
}