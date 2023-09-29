#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[DOG] default constructor is called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	std::cout << "[Dog] destructor is called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	std::cout << "[DOG] copy constructor is called" << std::endl;
	type = dog.type;
	if (brain != NULL)
		delete brain;
	brain = new Brain(*dog.brain);
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "[DOG] operator is called" << std::endl;
	type = dog.type;
	if (brain != NULL)
		delete brain;
	brain = new Brain(*dog.brain);
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

Brain* Dog::getBrain() const
{
	std::cout << "[DOG]" << std::endl;
	return (brain);
}