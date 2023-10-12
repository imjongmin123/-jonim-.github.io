#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "[Bureaucrat] default constructor is called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] destructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
	std::cout << "[Bureaucrat] copy constructor is called" << std::endl;
	grade = bureaucrat.grade;
}

Bureaucrat::Bureaucrat(std::string name_, unsigned int num) : name(name_)
{
	if (num < 1)
		throw std::out_of_range("Bureaucrat::GradeTooHighException");
	if (num > 150)
		throw std::out_of_range("Bureaucrat::GradeTooLowException");
	std::cout << "[Bureaucrat] constructor is called" << std::endl;
	grade = num;
}

Bureaucrat* Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	std::cout << "[Bureaucrat] operator is called" << std::endl;
	grade = bureaucrat.grade;
	return (this);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::increment()
{
	if (grade == 1)
		throw std::out_of_range("Bureaucrat::GradeTooHighException");
	grade--;
}

void	Bureaucrat::decrement()
{
	if (grade == 150)
		throw std::out_of_range("Bureaucrat::GradeTooLowException");
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getIsSign() == 1)
	{
		std::cout << "<bureaucrat> signed "<< form.getName() << std::endl;
		return ;
	}
	else
		std::cout << "<bureaucrat> couldn’t sign " << form.getName() << " because Bureaucrat::GradeTooLowException" << std::endl;;
	
}
