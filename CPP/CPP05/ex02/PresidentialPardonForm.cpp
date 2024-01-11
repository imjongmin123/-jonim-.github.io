#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 145, 137)
{
	std::cout << "[PresidentialPardonForm] default constructor is called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] destructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target_) : AForm("presidential pardon", 145, 137), target(target_)
{
	std::cout << "[PresidentialPardonForm] constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& P_P_Form) : AForm(P_P_Form.getName(), P_P_Form.getGradeSign(), P_P_Form.getGradeExe())
{
	std::cout << "[PresidentialPardonForm] copy constructor is called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& P_P_Form)
{
	std::cout << "[PresidentialPardonForm] operator is called" << std::endl;
	if (this == &P_P_Form)
		return *this;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{	
	if (getIsSign() == false)
		throw GradeTooHighException();
	if(executor.getGrade() <= getGradeExe())
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw GradeTooHighException();
}