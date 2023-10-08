#include "Cure.hpp"
#include "ICharacter.hpp"


Cure::Cure()
{
	std::cout << "[Cure] default constructor is called" << std::endl;
	name = "cure";
}

Cure::~Cure()
{
	std::cout << "[Cure] destructor is called" << std::endl;
}

Cure::Cure(const Cure& Cure) : AMateria()
{
	std::cout << "[Cure] copy constructor is called" << std::endl;
	if (Cure.name == "")
		return ;
}

Cure& Cure::operator=(const Cure& Cure)
{
	std::cout << "[Cure] operator is called" << std::endl;
	if (Cure.getType() != "cure")
		return (*this);
	return (*this);
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
