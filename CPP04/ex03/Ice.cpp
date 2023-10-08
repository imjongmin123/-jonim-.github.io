#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	std::cout << "[Ice] default constructor is called" << std::endl;
	name = "ice";
}

Ice::~Ice()
{
	std::cout << "[Ice] destructor is called" << std::endl;
}

Ice::Ice(const Ice& Ice) : AMateria()
{
	std::cout << "[Ice] copy constructor is called" << std::endl;
	if (Ice.name == "")
		return ;
}

Ice& Ice::operator=(const Ice& Ice)
{
	std::cout << "[Ice] operator is called" << std::endl;
	if (Ice.getType() != "ice")
		return (*this);
	return (*this);
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
