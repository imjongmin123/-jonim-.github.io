#ifndef MATERIA_HPP
#define MATERIA_HPP
#include "AMateria.hpp"


class Materia : public AMateria
{
	public:
	Materia();
	~Materia();

	Materia(const Materia& materia);
	Materia& operator=(const Materia& materia);
	AMateria* clone() const;
	void	  use(ICharacter& target);
};

#endif
