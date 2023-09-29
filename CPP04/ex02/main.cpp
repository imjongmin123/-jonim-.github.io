#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Cat cat;
	cat.getBrain()->addIdeas("walk");
	cat.getBrain()->getIdeas();
}