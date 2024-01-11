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

AMateria::AMateria(const AMateria& amateria)
{
	std::cout << "[AMateria] copy constructor is called" << std::endl;
	name = amateria.name;
}

AMateria& AMateria::operator=(const AMateria& amateria)
{
	std::cout << "[AMateria] operator is called" << std::endl;
	name = amateria.name;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (name);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "[AMateria] "<< target.getName() << std::endl;
}