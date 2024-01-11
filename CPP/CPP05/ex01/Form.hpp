#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

class Form
{
	private:
	const std::string  name;
	bool			   sign;
	const int grade_sign;
	const int grade_execute;
	Form();
	Form(const Form& form);
	Form& operator=(const Form& form);

	public:
	~Form();

	Form(std::string name_, int sign, int exe);
	void	beSigned(Bureaucrat bureaucrat);
	std::string getName() const;
	bool		getIsSign() const;
	int getGradeSign() const;
	int getGradeExe() const;

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
