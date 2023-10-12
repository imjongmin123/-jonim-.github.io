#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45)
{
	std::cout << "[RobotomyRequestForm] default constructor is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] destructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name_) : AForm(name_, 72, 45)
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
	if(executor.getGrade() <= getGradeSign() && executor.getGrade() <= getGradeExe())
	{
		bool ran = rand() % 2;
		if (ran == 1)
		{
			std::cout << "ddddddddddd...... " << executor.getName() << " is successfully robotized" << std::endl;
		}
		else
		{
			std::cout << executor.getName() << " the robotomy failed" << std::endl;
		}
	}
	else
		throw std::out_of_range("Form is not signed.");
}