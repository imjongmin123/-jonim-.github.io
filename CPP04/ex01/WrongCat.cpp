#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WRONGCAT] default constructor is called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "[WRONGCAT] destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WCat) : WrongAnimal(WCat)
{
	std::cout << "[WRONGCAT] copy constructor is called" << std::endl;
	type = WCat.type;
}

WrongCat& WrongCat::operator=(const WrongCat& WCat)
{
	std::cout << "[WRONGCAT] operator is called" << std::endl;
	type = WCat.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "[WRONGCAT] meeeeeeeeeaawwwwwwww" << std::endl;
}

std::string WrongCat::getType() const
{
	return (type);
}