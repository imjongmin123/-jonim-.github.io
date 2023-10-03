#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "floor.hpp"

class Character : public ICharacter
{
	private :
	AMateria* slot[4];
	std::string name;

	public :
	Character();
	~Character();

	Character(std::string name_);
	Character(const Character& Character);
	Character& operator=(const Character& character);
	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
