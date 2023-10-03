#ifndef FLOOR_HPP
#define FLOOR_HPP

class AMateria;

class Floor
{
	private:
	AMateria *amateria[1000];
	unsigned int num;

	public:
	Floor();
	~Floor();

	Floor(const Floor& floor);
	Floor& operator=(const Floor& floor);
	void getMateria();
	int checkFloor();
	AMateria* addMateria(AMateria* amateria_);
};

#endif 
