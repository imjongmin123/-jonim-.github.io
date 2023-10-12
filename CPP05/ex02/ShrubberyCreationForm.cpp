#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(25, 5)
{
	std::cout << "[ShrubberyCreationForm] default constructor is called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] destructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& S_C_Form) : AForm(S_C_Form.getName(), S_C_Form.getGradeSign(), S_C_Form.getGradeExe())
{
	std::cout << "[ShrubberyCreationForm] copy constructor is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& S_C_Form)
{
	std::cout << "[ShrubberyCreationForm] operator is called" << std::endl;
	if (this == &S_C_Form)
		return *this;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() <= getGradeSign() && executor.getGrade() <= getGradeExe())
	{
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw std::out_of_range("Form is not signed.");
}