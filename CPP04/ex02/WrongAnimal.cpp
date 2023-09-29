#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WRONGANIMAL] default constructor is called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONGANIMAL] destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& Wanimal)
{
	std::cout << "[WRONGANIMAL] copy constructor is called" << std::endl;
	this->type = Wanimal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& Wanimal)
{
	std::cout << "[WRONGANIMAL] operator is called" << std::endl;
	this->type = Wanimal.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WRONGANIMAL] make sound~~!!!!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}