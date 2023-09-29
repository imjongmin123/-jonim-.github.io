#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal* array_animal[10];

	for(int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			array_animal[i] = new Dog();
			array_animal[i]->getBrain()->addIdeas("walk");
		}
		else
		{
			array_animal[i] = new Cat();
			array_animal[i]->getBrain()->addIdeas("chur");	
		}
	}
	std::cout << "-----" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		array_animal[i]->getBrain()->getIdeas();
	}
	for(int i = 0; i < 10; i++)
	{
		delete array_animal[i];
	}
}