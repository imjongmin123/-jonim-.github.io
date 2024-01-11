#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
	const std::string name;
	int	  grade;
	Bureaucrat();
	
	public:
	~Bureaucrat();

	Bureaucrat(std::string name_, unsigned int num);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	std::string  getName() const;
	int getGrade() const;
	void		 increment();
	void		 decrement();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
