#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
	WrongDog();
	~WrongDog();

	WrongDog(const WrongDog& Wrongdog);
	WrongDog& operator=(const WrongDog& Wrongdog);
	void makeSound() const;
	std::string getType() const;
};

#endif