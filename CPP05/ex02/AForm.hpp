#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
	const std::string  name;
	bool			   sign;
	const int grade_sign;
	const int grade_execute;
	AForm();

	public:
	virtual ~AForm();

	AForm(std::string name_, int sign, int exe);
	AForm(int sign, int exe);
	AForm(const AForm& AForm);
	AForm& operator=(const AForm& AForm);
	void	beSigned(Bureaucrat bureaucrat);
	std::string getName() const;
	bool		getIsSign() const;
	int getGradeSign() const;
	int getGradeExe() const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
