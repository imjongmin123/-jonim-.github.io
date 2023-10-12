#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>


class Bureaucrat
{
	private:
	const std::string name;
	unsigned int	  grade;
	
	public:
	Bureaucrat();
	~Bureaucrat();

	Bureaucrat(std::string name_, unsigned int num);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat* operator=(const Bureaucrat& bureaucrat);
	std::string  getName() const;
	unsigned int getGrade() const;
	void		 increment();
	void		 decrement();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
