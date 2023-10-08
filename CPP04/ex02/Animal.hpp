#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"


class Animal
{
	protected :
		std::string type;
	
	public :
		Animal();
		virtual ~Animal();
		
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);
		virtual std::string getType() const;
		virtual Brain* getBrain() const;
		virtual void makeSound() const = 0;
};

#endif
