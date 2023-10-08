#ifndef FLOOR_HPP
#define FLOOR_HPP

class AMateria;

class Floor
{
	private:
	AMateria *amateria[1000];
	unsigned int num;
	Floor(const Floor& floor);
	Floor& operator=(const Floor& floor);

	public:
	Floor();
	~Floor();

	void getMateria();
	int checkFloor();
	int addMateria(AMateria* amateria_);
};

#endif 
