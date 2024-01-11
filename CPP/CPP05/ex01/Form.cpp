#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

Form::Form() : grade_sign(20), grade_execute(20)
{
	std::cout << "[Form] default constructor is called" << std::endl;
	sign = false;
}

Form::~Form()
{
	std::cout << "[Form] destructor is called" << std::endl;
}

Form::Form(std::string name_, int sign, int exe) : name(name_), grade_sign(sign), grade_execute(exe)
{
	std::cout << "[Form] constructor is called" << std::endl;
	if (sign < 1 || exe < 1)
		throw GradeTooHighException();
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
		
}

Form::Form(const Form& form) : name(form.name), grade_sign(form.grade_sign), grade_execute(form.grade_execute)
{
	std::cout << "[Form] copy constructor is called" << std::endl;
	sign = form.sign;
}

Form& Form::operator=(const Form& form)
{
	std::cout << "[Form] operator is called" << std::endl;
	this->sign = form.sign;
	return (*this);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_sign)
		sign = true;
	else
	{
		sign = false;
		throw GradeTooHighException();
	}
}


std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSign() const
{
	return (sign);
}

int Form::getGradeSign() const
{
	return (grade_sign);
}

int Form::getGradeExe() const
{
	return (grade_execute);
}


std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "[Form] name is " << form.getName() << ", sign is " << form.getIsSign() << ", grade_sign is " \
	<< form.getGradeSign() << ", grade_execute is " << form.getGradeExe();
		return (os);
}
