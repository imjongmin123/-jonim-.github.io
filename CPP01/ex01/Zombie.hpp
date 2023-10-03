#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
	std::string	name;

	public:
	Zombie();
	~Zombie();
	void announce(void);
	static Zombie* newZombie(std::string name);
	static Zombie* zombieHorde(int n, std::string name);
};

#endif
