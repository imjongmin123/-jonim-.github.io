#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low";
}

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
		throw GradeTooHighException();
	if (num > 150)
		throw GradeTooLowException();
	std::cout << "[Bureaucrat] constructor is called" << std::endl;
	grade = num;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	std::cout << "[Bureaucrat] operator is called" << std::endl;
	grade = bureaucrat.grade;
	return (*this);
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
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrement()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "<bureaucrat> couldn’t sign " << form.getName() << " because " << e.what() << std::endl;;
	}
}
