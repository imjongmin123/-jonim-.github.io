#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
	std::string type;

	public:
	Weapon();
	~Weapon();
	Weapon(std::string attack);
	const std::string& getType();
	void	setType(std::string n_type);
};

#endif
