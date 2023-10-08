#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------ virtual 이용해서 호출한 객체 함수 이용 ------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "------ virtual 이용하지 않아 상속 클래스의 함수가 호출된 경우------" << std::endl;
	const WrongAnimal* W_meta = new WrongAnimal();
	const WrongAnimal* W_j = new WrongDog();
	const WrongAnimal* W_i = new WrongCat();
	std::cout << W_j->getType() << " " << std::endl;
	std::cout << W_i->getType() << " " << std::endl;
	W_i->makeSound();
	W_j->makeSound();
	W_meta->makeSound();

	std::cout << "------ 동적 할당 해제 ------" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete W_meta;
	delete W_j;
	delete W_i;
	return 0;
}