#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
	const std::string  name;
	bool			   sign;
	const unsigned int grade_sign;
	const unsigned int grade_execute;

	public:
	AForm();
	virtual ~AForm();

	AForm(std::string name_, unsigned int sign, unsigned int exe);
	AForm(unsigned int sign, unsigned int exe);
	AForm(const AForm& AForm);
	AForm* operator=(const AForm& AForm);
	void	beSigned(Bureaucrat bureaucrat);
	std::string getName() const;
	bool		getIsSign() const;
	unsigned int getGradeSign() const;
	unsigned int getGradeExe() const;
	virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
