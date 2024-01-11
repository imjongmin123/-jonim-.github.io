#include "Floor.hpp"
#include "AMateria.hpp"

Floor::Floor()
{
	std::cout << "[Floor] default constructor is called" << std::endl;
	for (int i = 0; i < 1000; i++)
	{
		amateria[i] = NULL;
	}
	num = 0;
}

Floor::~Floor()
{
	std::cout << "[Floor] destructor is called" << std::endl;
	for (int i = 0; i < 1000; i++)
	{
		if (amateria[i] != NULL)
			delete amateria[i];
	}
}

Floor::Floor(const Floor& floor)
{
	std::cout << "[AMateria] constructor is called" << std::endl;
	for(int i = 0; i < 1000; i++)
	{
		if (floor.amateria[i] != NULL)
			amateria[i] = floor.amateria[i];
	}
	num = floor.num;
}

Floor& Floor::operator=(const Floor& floor)
{
	std::cout << "[Floor] constructor is called" << std::endl;
	for(int i = 0; i < 1000; i++)
	{
		if (floor.amateria[i] != NULL)
			amateria[i] = floor.amateria[i];
	}
	num = floor.num;
	return (*this);
}

void Floor::getMateria()
{
	for (unsigned int i = 0; i < 1000; i++)
	{
		if (amateria[i] != NULL)
			std::cout << "NUMBER is : " << i << "   [MATERIA] is : " << amateria[i]->getType() << std::endl;
	}
}



int Floor::checkFloor()
{
	if (num < 1000)
		return (1);
	return (0);	
}

int Floor::addMateria(AMateria* amateria_)
{
	for (int i = 0; i < 1000; i++)
	{
		if (amateria[i] == NULL)
		{
			amateria[i] = amateria_;
			num++;
			return (1);
		}
	}
	return (0);
}