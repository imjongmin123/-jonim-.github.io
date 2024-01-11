#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 25, 5)
{
	std::cout << "[ShrubberyCreationForm] default constructor is called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] destructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_) : AForm("shrubbery creation", 25, 5), target(target_)
{
	std::cout << "[ShrubberyCreationForm] constructor is called" << std::endl;
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
	if (getIsSign() == false)
		throw GradeTooHighException();
	if (executor.getGrade() <= getGradeExe())
	{
		std::ofstream treeFile;

		treeFile.open(target + "_shrubbery");
		if (treeFile.is_open())
		{
			treeFile << "   *\n";
			treeFile << "  ***\n";
            treeFile << " *****\n";
        	treeFile << "*******\n";
            treeFile << "  ***\n";
			treeFile.close();
		}
		else
		{
			std::cerr << "con not open file" << std::endl;
		}
	}
	else
		throw GradeTooHighException();
}