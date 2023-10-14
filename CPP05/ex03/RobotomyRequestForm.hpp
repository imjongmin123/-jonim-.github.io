#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	std::string target;

	public:
	RobotomyRequestForm();
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string target_);
	RobotomyRequestForm(const RobotomyRequestForm& S_C_Form);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& S_C_Form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
