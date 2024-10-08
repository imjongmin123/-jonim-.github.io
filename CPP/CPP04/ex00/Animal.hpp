#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		~Animal();
		
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);
		virtual void makeSound() const;
		virtual std::string getType() const;
};

#endif
