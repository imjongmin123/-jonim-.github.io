#include "Cat.hpp"


Cat::Cat()
{
	std::cout << "[CAT] default constructor is called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	delete brain;
	std::cout << "[CAT] destructor is called" << std::endl;
}

Cat::Cat(const Cat& cat)
{
	std::cout << "[CAT] copy constructor is called" << std::endl;
	type = cat.type;
	if (brain != NULL)
		delete brain;
	brain = new Brain(*cat.brain);
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "[CAT] operator is called" << std::endl;
	type = cat.type;
	if (brain != NULL)
		delete brain;
	brain = new Brain(*cat.brain);
	return (*this);
}


void	Cat::makeSound() const
{
	std::cout << "[CAT] meeeeeeeeeaawwwwwwww" << std::endl;
}

std::string Cat::getType() const
{
	return ("[CAT] " + type);
}

Brain* Cat::getBrain() const
{
	std::cout << "[CAT]" << std::endl;
	return (brain);
}