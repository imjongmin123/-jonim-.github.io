#include "Cat.hpp"


Cat::Cat()
{
	std::cout << "[CAT] default constructor is called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "[CAT] destructor is called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "[CAT] copy constructor is called" << std::endl;
	type = cat.type;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "[CAT] operator is called" << std::endl;
	type = cat.type;
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