#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	private:
	AMateria* slot[4];

	public:
	MateriaSource();
	~MateriaSource();

	MateriaSource(const MateriaSource& materiasource);
	MateriaSource& operator=(const MateriaSource& materiasource);
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);
};

#endif
