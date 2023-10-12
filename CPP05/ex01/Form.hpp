#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
	const std::string  name;
	bool			   sign;
	const unsigned int grade_sign;
	const unsigned int grade_execute;

	public:
	Form();
	~Form();

	Form(std::string name_, unsigned int sign, unsigned int exe);
	Form(const Form& form);
	Form* operator=(const Form& form);
	void	beSigned(Bureaucrat bureaucrat);
	std::string getName() const;
	bool		getIsSign() const;
	unsigned int getGradeSign() const;
	unsigned int getGradeExe() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
