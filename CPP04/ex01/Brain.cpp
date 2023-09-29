#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[BRAIN] default constructor is called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
}

Brain::~Brain()
{
	std::cout << "[BRAIN] destructor is called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "[BRAIN] copy constructor is called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "[BRAIN] operator is called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

void	Brain::getIdeas()
{
	int i = 0;
	while (i < 100)
	{
		if (ideas[i] == "")
			break ;
		std::cout << ideas[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

void	Brain::addIdeas(std::string idea)
{
	int i = 0;
	while (i < 100)
	{
		if (ideas[i] == "")
		{
			ideas[i] = idea;
			return ;
		}
		i++;
	}
	std::cout << "Brain is full" << std::endl;
}