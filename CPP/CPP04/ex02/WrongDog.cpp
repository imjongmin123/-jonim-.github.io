#include "WrongDog.hpp"

WrongDog::WrongDog()
{
	std::cout << "[WRONGDOG] default constructor is called" << std::endl;
	type = "WrongDog";
}

WrongDog::~WrongDog()
{
	std::cout << "[WRONGDOG] destructor is called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& Wdog) : WrongAnimal()
{
	std::cout << "[WRONGDOG] copy constructor is called" << std::endl;
	type = Wdog.type;
}

WrongDog& WrongDog::operator=(const WrongDog& Wdog)
{
	std::cout << "[WRONGDOG] operator is called" << std::endl;
	if (this == &Wdog)
		return *this;
	type = Wdog.type;
	return (*this);
}

void	WrongDog::makeSound() const
{
	std::cout << "[WRONGDOG] wal wal wallll!!" << std::endl;
}

std::string WrongDog::getType() const
{
	return (type);
}