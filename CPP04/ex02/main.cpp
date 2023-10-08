#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Cat cat;
	cat.getBrain()->addIdeas("walk");
	cat.getBrain()->getIdeas();
	Animal *i = new Dog();
	i->getBrain()->addIdeas("aaaa");
	i->getBrain()->getIdeas();
	return (0);
}