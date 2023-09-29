#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"


class Animal
{
	protected :
		std::string type;
		Animal();
		virtual ~Animal();
		
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);
		virtual void makeSound() const;
		virtual std::string getType() const;
		virtual Brain* getBrain() const;
	
	public :
		
};

#endif
