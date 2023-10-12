#include "Form.hpp"

Form::Form() : grade_sign(20), grade_execute(20)
{
	std::cout << "[Form] default constructor is called" << std::endl;
	sign = false;
}

Form::~Form()
{
	std::cout << "[Form] destructor is called" << std::endl;
}

Form::Form(std::string name_, unsigned int sign, unsigned int exe) : name(name_), grade_sign(sign), grade_execute(exe)
{
	std::cout << "[Form] constructor is called" << std::endl;
	if (sign < 1 || exe < 1)
		throw std::out_of_range("Form::GradeTooHighException");
	if (sign > 150 || exe > 150)
		throw std::out_of_range("Form::GradeTooLowException");
}

Form::Form(const Form& form) : name(form.name), grade_sign(form.grade_sign), grade_execute(form.grade_execute)
{
	std::cout << "[Form] copy constructor is called" << std::endl;
	sign = form.sign;
}

Form* Form::operator=(const Form& form)
{
	std::cout << "[Form] operator is called" << std::endl;
	this->sign = form.sign;
	return (this);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_sign && bureaucrat.getGrade() <= grade_execute)
		sign = true;
	else
		throw std::out_of_range("Form::GradeTooLowException");
}


std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSign() const
{
	return (sign);
}

unsigned int Form::getGradeSign() const
{
	return (grade_sign);
}

unsigned int Form::getGradeExe() const
{
	return (grade_execute);
}


std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "[Form] name is " << form.getName() << ", sign is " << form.getIsSign() << ", grade_sign is " \
	<< form.getGradeSign() << ", grade_execute is " << form.getGradeExe();
		return (os);
}
