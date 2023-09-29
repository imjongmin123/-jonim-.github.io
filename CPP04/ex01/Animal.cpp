#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[ANIMAL] default constructor is called" << std::endl;
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "[ANIMAL] destructor is called" << std::endl;
}

Animal::Animal(const Animal& animal)
{	
	std::cout << "[ANIMAL] copy constructor is called" << std::endl;
	this->type = animal.type;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "[ANIMAL] operator is called" << std::endl;
	this->type = animal.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "[ANIMAL] make sound~~!!!!" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

Brain* Animal::getBrain() const
{
	return (NULL);
}