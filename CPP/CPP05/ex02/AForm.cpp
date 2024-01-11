#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

AForm::AForm() : grade_sign(20), grade_execute(20)
{
	std::cout << "[AForm] default constructor is called" << std::endl;
	sign = false;
}

AForm::~AForm()
{
	std::cout << "[AForm] destructor is called" << std::endl;
}

AForm::AForm(std::string name_, int sign, int exe) : name(name_), grade_sign(sign), grade_execute(exe)
{
	std::cout << "[AForm] constructor is called" << std::endl;
	if (sign < 1 || exe < 1)
		throw GradeTooHighException();
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
}

AForm::AForm(int sign, int exe) : grade_sign(sign), grade_execute(exe)
{
	std::cout << "[AForm] constructor is called" << std::endl;
	if (sign < 1 || exe < 1)
		throw GradeTooHighException();
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& AForm) : name(AForm.name), grade_sign(AForm.grade_sign), grade_execute(AForm.grade_execute)
{
	std::cout << "[AForm] copy constructor is called" << std::endl;
	sign = AForm.sign;
}

AForm& AForm::operator=(const AForm& AForm)
{
	std::cout << "[AForm] operator is called" << std::endl;
	this->sign = AForm.sign;
	return (*this);
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_sign)
		sign = true;
	else
	{
		sign = false;
		throw GradeTooLowException();
	}
}


std::string AForm::getName() const
{
	return (name);
}

bool AForm::getIsSign() const
{
	return (sign);
}

int AForm::getGradeSign() const
{
	return (grade_sign);
}

int AForm::getGradeExe() const
{
	return (grade_execute);
}


std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "[AForm] name is " << AForm.getName() << ", sign is " << AForm.getIsSign() << ", grade_sign is " \
	<< AForm.getGradeSign() << ", grade_execute is " << AForm.getGradeExe();
		return (os);
}
