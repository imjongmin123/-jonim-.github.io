#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Form;

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
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	std::string  getName() const;
	unsigned int getGrade() const;
	void		 increment();
	void		 decrement();
	void		 signForm(Form& form);

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
