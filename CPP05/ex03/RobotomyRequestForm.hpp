#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
	RobotomyRequestForm();
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string name_);
	RobotomyRequestForm(const RobotomyRequestForm& S_C_Form);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& S_C_Form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
