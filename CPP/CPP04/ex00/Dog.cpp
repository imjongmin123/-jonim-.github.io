#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[DOG] default constructor is called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor is called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
	std::cout << "[DOG] copy constructor is called" << std::endl;
	type = dog.type;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "[DOG] operator is called" << std::endl;
	if (this == &dog)
		return *this;
	type = dog.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "[DOG] wal wal wallll!!" << std::endl;
}

std::string Dog::getType() const
{
	return ("[DOG] " + type);
}