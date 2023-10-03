#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "[AMateria] default constructor is called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] destructor is called" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "[AMateria] constructor is called" << std::endl;
	name = type;
}

std::string const& AMateria::getType() const
{
	return (name);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "[AMateria] "<< target.getName() << std::endl;
}