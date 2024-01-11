#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
	std::cout << "[RobotomyRequestForm] default constructor is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] destructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_) : AForm("robotomy request", 72, 45), target(target_)
{
	std::cout << "[RobotomyRequestForm] constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& R_R_Form) : AForm(R_R_Form.getName(), R_R_Form.getGradeSign(), R_R_Form.getGradeExe())
{
	std::cout << "[RobotomyRequestForm] copy constructor is called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& R_R_Form)
{
	std::cout << "[RobotomyRequestForm] operator is called" << std::endl;
	if (this == &R_R_Form)
		return *this;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getIsSign() == false)
		throw GradeTooHighException();
	if(executor.getGrade() <= getGradeExe())
	{
		std::srand(std::time(0));
		bool ran = rand() % 2;
		if (ran == 1)
		{
			std::cout << "ddddddddddd...... " << target << " is successfully robotized" << std::endl;
		}
		else
		{
			std::cout << target << " the robotomy failed" << std::endl;
		}
	}
	else
		throw GradeTooHighException();
}