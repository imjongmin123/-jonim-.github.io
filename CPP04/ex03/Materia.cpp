#include "Materia.hpp"

Materia::Materia()
{
	std::cout << "[Materia] default constructor is called" << std::endl;
}

Materia::~Materia()
{
	std::cout << "[Materia] destructor is called" << std::endl;
}

Materia::Materia(const Materia& materia)
{
	std::cout << "[Materia] copy constructor is called" << std::endl;
}


Materia& Materia::operator=(const Materia& materia)
{
	std::cout << "[Materia] operator is called" << std::endl;
	return (*this);
}

AMateria* Materia::clone() const
{

}

void Materia::use(ICharacter& target)
{
	
}