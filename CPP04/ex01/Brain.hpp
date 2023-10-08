#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>


class Brain
{
	private:
	std::string ideas[100];

	public:
	Brain();
	virtual ~Brain();

	Brain(const Brain& brain);
	Brain& operator=(const Brain& brain);
	void getIdeas();
	void addIdeas(std::string idea);
};

#endif
