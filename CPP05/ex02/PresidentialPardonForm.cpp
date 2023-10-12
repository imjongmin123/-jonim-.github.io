#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm(145, 137)
{
	std::cout << "[PresidentialPardonForm] default constructor is called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] destructor is called" << std::endl;
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
	if (executor.getGrade() <= getGradeSign() && executor.getGrade() <= getGradeExe())
	{
		std::ofstream treeFile;

		treeFile.open(executor.getName() + "_shrubbery");
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
		throw std::out_of_range("Form is not signed.");
}